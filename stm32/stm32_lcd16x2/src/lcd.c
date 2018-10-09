#include "stm32f10x_conf.h"

#define LCD_RS		0
#define LCD_RW		1
#define LCD_EN		2
#define LCD_D4		4
#define LCD_D5		5
#define LCD_D6		6
#define LCD_D7		7

#define LDP		GPIOC->ODR
#define LCP		GPIOC->ODR
#define LDDR	DDRD
#define LCDR	DDRD

#define LCD_CGRAM 6
#define LCD_DDRAM 7
#define LCD_CLR   0
#define LCD_LINE0_DDRAMADDR		0x00
#define LCD_LINE1_DDRAMADDR		0x40
#define LCD_LINE2_DDRAMADDR		0x14
#define LCD_LINE3_DDRAMADDR		0x54

//========================== Retarget printf() to LCD =========================

struct __FILE {
  int handle; 
};

FILE __stdout;

int fputc (int ch, FILE *f){ 
	
	Lcd_Write_Data(ch);

  return ch;
}

void _ttywrch(int ch){

 Lcd_Write_Data(ch);
}

int _ferror(FILE *f) {
                     
  return EOF;
}

void _sys_exit(int return_code) {

 label:  goto label; 
}

//========================================== LCD Functions ==============================

void tes_pin(void){
		GPIO_InitTypeDef GPIO_InitStructure;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2 ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 |GPIO_Pin_7 ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
	
		GPIO_WriteBit(GPIOC,GPIO_Pin_0 | GPIO_Pin_2,Bit_SET);
		GPIO_WriteBit(GPIOC,GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 |GPIO_Pin_7,Bit_SET);
}
 
 void Example_LCD1602(void){
		int val=2013;
    Lcd_Init();                       
    lcd_clear(); 
		Delay(0xFFFF);
		Lcd_Cursor(0,0);
    lcd_print ("Welcome");
		Lcd_Cursor(0,1);
		printf("IEMC %i",val);
}

void Delay(__IO uint32_t nCount){
  for(; nCount != 0; nCount--);
}

 void LCD_DATA_DIR_OUT(void){
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 |GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

 void Lcd_Write_Command(uint8_t cmd){
  LDP=(cmd&0xF0);
	LCP|=1<<LCD_EN;		
	Delay(0xFFFF);
	LCP&=~(1<<LCD_EN);
	Delay(0xFFFF);
	LDP=((cmd&0x0F)<<4);	
	LCP|=1<<LCD_EN;		
	Delay(0xFFFF);
	LCP&=~(1<<LCD_EN);
	Delay(0xFFFF);
}

 void Lcd_Write_Data(uint8_t ch){
  LDP=(ch&0xF0);
	LCP|=1<<LCD_RS;
	LCP|=1<<LCD_EN;		
	Delay(0xFFFF);
	LCP&=~(1<<LCD_EN);	
	LCP&=~(1<<LCD_RS);
	Delay(0xFFFF);
	LDP=((ch&0x0F)<<4);
	LCP|=1<<LCD_RS;
	LCP|=1<<LCD_EN;		
	Delay(0xFFFF);
	LCP&=~(1<<LCD_EN);	
	LCP&=~(1<<LCD_RS);
	Delay(0xFFFF);
}

 void Lcd_Cursor(uint8_t column, uint8_t line){
  register uint8_t DDRAMAddr;
	switch(line){
	case 0: DDRAMAddr = LCD_LINE0_DDRAMADDR+column; break;
	case 1: DDRAMAddr = LCD_LINE1_DDRAMADDR+column; break;
	case 2: DDRAMAddr = LCD_LINE2_DDRAMADDR+column; break;
	case 3: DDRAMAddr = LCD_LINE3_DDRAMADDR+column; break;
	default: DDRAMAddr = LCD_LINE0_DDRAMADDR+column;
	}
	Lcd_Write_Command(1<<LCD_DDRAM | DDRAMAddr);
}

 void Lcd_Init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
		LCD_DATA_DIR_OUT();
		Delay(0xAFFFF);
		LDP=0x00;
		LCP=0x00;

		LDP|=1<<LCD_D5; 
		LCP|=1<<LCD_EN;		
		Delay(0xFFFF);
		LCP&=~(1<<LCD_EN);
		Delay(0xFFFF);

    
		Lcd_Write_Command(0x28); 
		Lcd_Write_Command(0x0C);
		Lcd_Write_Command(0x06); 
}

 void lcd_print (char *string){
    while (*string) {
        Lcd_Write_Data (*string++);
    }
}

 void lcd_clear (void){
    Lcd_Write_Command(0x01);                  /* Display clear                      */
    Lcd_Cursor(0,0);
}
