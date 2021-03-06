//id:textlcd.h,textlcd,2-8-2012,sidiknur@yahoo.com
#ifndef TEXTLCD_H_INCLUDED
#define TEXTLCD_H_INCLUDED

#include <util/delay.h>
#include "pinout.h"
#include "textlcd_config.h"


#define	LCD_DLY_PLUS	5	//(us)
#define nible_hi(byte)	(byte>>4)
#define	nible_lo(byte)	(byte & 0x0f)
#define	ir_select()		RS::Clear()
#define dr_select()		RS::Set()


template <port_id_t pRS, uint8_t bRS,
          port_id_t pEN, uint8_t bEN,
          port_id_t pD4, uint8_t bD4,
          port_id_t pD5, uint8_t bD5,
          port_id_t pD6, uint8_t bD6,
          port_id_t pD7, uint8_t bD7,
          uint8_t col_num = 16>
class TextLCD : PinOut<pRS, bRS>,
                PinOut<pEN, bEN>,
                PinOut<pD4, bD4>,
                PinOut<pD5, bD5>,
                PinOut<pD6, bD6>,
                PinOut<pD7, bD7>
{
public:
    TextLCD(){

        _delay_us(1500+LCD_DLY_PLUS);
        lcd_write_ir_nible( nible_hi(LCD_8BIT) );
        _delay_us(4100+LCD_DLY_PLUS);
        lcd_write_ir_nible( nible_hi(LCD_8BIT) );
        _delay_us(100+LCD_DLY_PLUS);
        lcd_write_ir_nible( nible_hi(LCD_8BIT) );

        lcd_write_ir_nible( nible_hi(LCD_4BIT) );
        lcd_write_ir_byte(LCD_4BIT);
        lcd_write_ir_byte(LCD_DISPLAY_ON | LCD_CURSOR_OFF\
                          | LCD_POSITION_NOTBLINK);
        lcd_write_ir_byte(LCD_ENTRY_INCREMENT);

    }

    void PutChar(const char chr){
        lcd_write_dr_byte(chr);
    }

    void PutStr(const char* str){
        while(*str){
            PutChar(*str++);
        }
    }

#define lcd_row_addr(row) (row%2? (row>>1)*col_num+0x40:\
						  (row>>1)*col_num )

    void GotoXY(uint8_t row, uint8_t col){
        row--;
        col--;
        lcd_write_ir_byte(LCD_DDRAM_ADDR_SET | \
                            lcd_row_addr(row) | col );
    }

    void DisplayClear(void){
        lcd_write_ir_byte(LCD_DISPLAY_CLEAR);
    }

    void GoHome(void){
        lcd_write_ir_byte(LCD_CURSOR_HOME);
    }

    void CursorOffBlinkOff(void){
        lcd_write_ir_byte(LCD_DISPLAY_ON | LCD_CURSOR_OFF\
                          | LCD_POSITION_NOTBLINK);
    }

    void CursorOnBlinkOn(void){
        lcd_write_ir_byte(LCD_DISPLAY_ON | LCD_CURSOR_ON \
                          | LCD_POSITION_BLINK);
    }
    void Command(uint8_t cmd){
        lcd_write_ir_byte(cmd);
    }
private:
    typedef PinOut<pRS, bRS> RS;
    typedef PinOut<pEN, bEN> EN;
    typedef PinOut<pD4, bD4> D4;
    typedef PinOut<pD5, bD5> D5;
    typedef PinOut<pD6, bD6> D6;
    typedef PinOut<pD7, bD7> D7;

    void lcd_write_nible(const uint8_t nible){

        EN::Set();

        if(nible & _BV(0)) D4::Set(); else D4::Clear();
        if(nible & _BV(1)) D5::Set(); else D5::Clear();
        if(nible & _BV(2)) D6::Set(); else D6::Clear();
        if(nible & _BV(3)) D7::Set(); else D7::Clear();
        EN::Clear();

        _delay_us(40);
    }

    void lcd_write_byte(const uint8_t byte){
        lcd_write_nible(nible_hi(byte));
        lcd_write_nible(nible_lo(byte));
    }

    void lcd_write_ir_nible(const uint8_t cmd){
        ir_select();
        lcd_write_nible(cmd);
    }


    void lcd_write_dr_byte(const uint8_t data){
        dr_select();
        lcd_write_byte(data);
    }

    void lcd_write_ir_byte(const uint8_t cmd){
        ir_select();
        lcd_write_byte(cmd);

        if(cmd==LCD_DISPLAY_CLEAR || cmd==LCD_CURSOR_HOME)
            _delay_us(1600);
    }


};
#endif // TEXTLCD_H_INCLUDED
