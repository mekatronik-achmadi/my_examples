#include "stm32f10x_conf.h"

int main(void){
		int time=0;
		//tes_pin();
		Example_LCD1602();
		Delay(0xFFFFF);
		lcd_clear();
		Lcd_Cursor(0,0);
		printf("time");
		while(1){
			Delay(0xFFFF);
			time++;
			if(time==100){time=0;}
			Lcd_Cursor(0,1);
			printf("%3i",time);
		};

}
