#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "alcd.h"
#include "uart.h"
#include "led.h"

int main(void){
    char text[16];

    led_init(0);

    alcd_init();
    alcd_clear();
    sprintf(text,"test");
    alcd_printf(0,0,text);

    uart_init();
    printf("system run \n\r");

    while(1){
        led_toggle(0);
        _delay_ms(200);
    }
    return 0;
}
