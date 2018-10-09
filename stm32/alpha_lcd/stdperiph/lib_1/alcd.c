#include "alcd.h"

//--------------------------------------------------------------
// Internal Function
//--------------------------------------------------------------
void ALCD_InitIO(void);
void ALCD_PinLo(TLCD_NAME_t lcd_pin);
void ALCD_PinHi(TLCD_NAME_t lcd_pin);
void ALCD_Clk(void);
void ALCD_InitSequens(void);
void ALCD_Cmd(uint8_t reg);
void ALCD_Data(uint8_t reg);
void ALCD_Cursor(uint8_t x, uint8_t y);
void ALCD_Delay(volatile uint32_t nCount);

//--------------------------------------------------------------
// Hardware dependent
//--------------------------------------------------------------
//--------------------------------------------------------------
// PIN References
//--------------------------------------------------------------
ALCD_t LCD_PINS[] = {
 // Name   ,PORT , PIN       , CLOCK              , Init
  {TLCD_RS ,GPIOE,GPIO_Pin_4 ,RCC_AHB1Periph_GPIOE,Bit_RESET},
  {TLCD_E  ,GPIOE,GPIO_Pin_5 ,RCC_AHB1Periph_GPIOE,Bit_RESET},
  {TLCD_D4 ,GPIOE,GPIO_Pin_3 ,RCC_AHB1Periph_GPIOE,Bit_RESET},
  {TLCD_D5 ,GPIOE,GPIO_Pin_1 ,RCC_AHB1Periph_GPIOE,Bit_RESET},
  {TLCD_D6 ,GPIOB,GPIO_Pin_9 ,RCC_AHB1Periph_GPIOB,Bit_RESET},
  {TLCD_D7 ,GPIOE,GPIO_Pin_2 ,RCC_AHB1Periph_GPIOE,Bit_RESET},
};

void ALCD_InitIO(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  TLCD_NAME_t lcd_pin;
  
  for(lcd_pin=0;lcd_pin<LCD_PINAMT;lcd_pin++) {

    RCC_AHB1PeriphClockCmd(LCD_PINS[lcd_pin].TLCD_CLK, ENABLE);

    GPIO_InitStructure.GPIO_Pin = LCD_PINS[lcd_pin].TLCD_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(PINS[lcd_pin].TLCD_PORT, &GPIO_InitStructure);

    if(LCD_PINS[lcd_pin].TLCD_INIT==Bit_RESET) {
      ALCD_PinLo(lcd_pin);
    }
    else {
      ALCD_PinHi(lcd_pin);
    }
  }  
}

//--------------------------------------------------------------
// Hardware independent
//--------------------------------------------------------------
//--------------------------------------------------------------
// ALCD Initialisation
//--------------------------------------------------------------
void ALCD_Init(void){
	ALCD_InitIO();
	ALCD_Delay(TLCD_INIT_PAUSE);
	ALCD_InitSequens();
	ALCD_Cmd(TLCD_CMD_INIT_DISPLAY);
	ALCD_Cmd(TLCD_CMD_ENTRY_MODE);
	ALCD_Cmd(TLCD_CMD_DISP_M1);
	ALCD_Cmd(TLCD_CMD_CLEAR);
	ALCD_Delay(TLCD_PAUSE);
}

void P_LCD_2x16_InitSequens(void)
{
  
  P_LCD_2x16_PinHi(TLCD_D4);
  P_LCD_2x16_PinHi(TLCD_D5);
  P_LCD_2x16_PinLo(TLCD_D6);
  P_LCD_2x16_PinLo(TLCD_D7);
  
  P_LCD_2x16_Clk();
  P_LCD_2x16_Delay(TLCD_PAUSE);
  
  P_LCD_2x16_Clk();
  P_LCD_2x16_Delay(TLCD_PAUSE);
  
  P_LCD_2x16_Clk();
  P_LCD_2x16_Delay(TLCD_PAUSE);
  
  P_LCD_2x16_PinLo(TLCD_D4);
  P_LCD_2x16_PinHi(TLCD_D5);
  P_LCD_2x16_PinLo(TLCD_D6);
  P_LCD_2x16_PinLo(TLCD_D7);
  P_LCD_2x16_Clk();
  P_LCD_2x16_Delay(TLCD_PAUSE);
}

//--------------------------------------------------------------
// ALCD Clear
//--------------------------------------------------------------
void ALCD_Clear(void)
{
  ALCD_Cmd(TLCD_CMD_CLEAR);
  ALCD_Delay(TLCD_PAUSE);
}

//--------------------------------------------------------------
// ALCD Mode
//--------------------------------------------------------------
void ALCD_SetMode(TLCD_MODE_t mode)
{
  if(mode==TLCD_OFF) ALCD_Cmd(TLCD_CMD_DISP_M0);
  if(mode==TLCD_ON) ALCD_Cmd(TLCD_CMD_DISP_M1);
  if(mode==TLCD_CURSOR) ALCD_Cmd(TLCD_CMD_DISP_M2);
  if(mode==TLCD_BLINK) ALCD_Cmd(TLCD_CMD_DISP_M3);
}

//--------------------------------------------------------------
// Display a string
//--------------------------------------------------------------
void ALCD_String(uint8_t x, uint8_t y, char *ptr)
{
  ALCD_Cursor(x,y);
  
  while (*ptr != 0) {
    ALCD_Data(*ptr);
    ptr++;
  }
}

//--------------------------------------------------------------
// Pin Control Functions
//--------------------------------------------------------------
void ALCD_PinLo(TLCD_NAME_t lcd_pin)
{
  LCD_PINS[lcd_pin].TLCD_PORT->BSRRH = LCD_PINS[lcd_pin].TLCD_PIN;
}

void ALCD_PinHi(TLCD_NAME_t lcd_pin)
{
  LCD_PINS[lcd_pin].TLCD_PORT->BSRRL = LCD_PINS[lcd_pin].TLCD_PIN;
}

//--------------------------------------------------------------
// ALCD ClockWait and Delay
//--------------------------------------------------------------
void ALCD_Clk(void)
{
  ALCD_PinHi(TLCD_E);
  ALCD_Delay(TLCD_CLK_PAUSE);
  ALCD_PinLo(TLCD_E);
  ALCD_Delay(TLCD_CLK_PAUSE);  
}

void ALCD_Delay(volatile uint32_t nCount)
{
  while(nCount--)
  {
  }
}

//--------------------------------------------------------------
// Cursor Set Function
//--------------------------------------------------------------
void P_LCD_2x16_Cursor(uint8_t x, uint8_t y)
{
	//uint8_t wert;
	//wert=(y<<6);
	//wert|=x;
	//wert|=0x80;
	//P_LCD_2x16_Cmd(wert);

	register uint8_t DDRAMAddr;
	
	if(x>=TLCD_MAXX) x=0;
	if(y>=TLCD_MAXY) y=0;

	switch(y)
	{
		case 0: DDRAMAddr = LCD_LINE0_DDRAMADDR+x; break;
		case 1: DDRAMAddr = LCD_LINE1_DDRAMADDR+x; break;
		case 2: DDRAMAddr = LCD_LINE2_DDRAMADDR+x; break;
		case 3: DDRAMAddr = LCD_LINE3_DDRAMADDR+x; break;
		default: DDRAMAddr = LCD_LINE0_DDRAMADDR+x;
	}
	ALCD_Cmd(1<<LCD_DDRAM | DDRAMAddr);
}

//--------------------------------------------------------------
// ALCD Commands and Data Protocol
//--------------------------------------------------------------
void ALCD_Cmd(uint8_t reg)
{
  
  ALCD_PinLo(TLCD_RS);
          
  if((reg&0x80)!=0) ALCD_PinHi(TLCD_D7); else ALCD_PinLo(TLCD_D7);
  if((reg&0x40)!=0) ALCD_PinHi(TLCD_D6); else ALCD_PinLo(TLCD_D6);
  if((reg&0x20)!=0) ALCD_PinHi(TLCD_D5); else ALCD_PinLo(TLCD_D5);
  if((reg&0x10)!=0) ALCD_PinHi(TLCD_D4); else ALCD_PinLo(TLCD_D4);
  ALCD_Clk();
          
  if((reg&0x08)!=0) ALCD_PinHi(TLCD_D7); else ALCD_PinLo(TLCD_D7);
  if((reg&0x04)!=0) ALCD_PinHi(TLCD_D6); else ALCD_PinLo(TLCD_D6);
  if((reg&0x02)!=0) ALCD_PinHi(TLCD_D5); else ALCD_PinLo(TLCD_D5);
  if((reg&0x01)!=0) ALCD_PinHi(TLCD_D4); else ALCD_PinLo(TLCD_D4);
  ALCD_Clk();  
}

void ALCD_Data(uint8_t reg)
{
  ALCD_PinHi(TLCD_RS);
         
  if((reg&0x80)!=0) ALCD_PinHi(TLCD_D7); else ALCD_PinLo(TLCD_D7);
  if((reg&0x40)!=0) ALCD_PinHi(TLCD_D6); else ALCD_PinLo(TLCD_D6);
  if((reg&0x20)!=0) ALCD_PinHi(TLCD_D5); else ALCD_PinLo(TLCD_D5);
  if((reg&0x10)!=0) ALCD_PinHi(TLCD_D4); else ALCD_PinLo(TLCD_D4);
  ALCD_Clk();
         
  if((reg&0x08)!=0) ALCD_PinHi(TLCD_D7); else ALCD_PinLo(TLCD_D7);
  if((reg&0x04)!=0) ALCD_PinHi(TLCD_D6); else ALCD_PinLo(TLCD_D6);
  if((reg&0x02)!=0) ALCD_PinHi(TLCD_D5); else ALCD_PinLo(TLCD_D5);
  if((reg&0x01)!=0) ALCD_PinHi(TLCD_D4); else ALCD_PinLo(TLCD_D4);
  ALCD_Clk();  
}
