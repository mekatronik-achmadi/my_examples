#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "alcd.h"
#include "uart.h"

int main(void){
    char text[16];

    alcd_init();
    alcd_clear();
    sprintf(text,"test");
    alcd_printf(0,0,text);

    uart_init();
    printf("system run \n\r");

    while(1){
        _delay_ms(200);
    }
    return 0;
}
