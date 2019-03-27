#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "alcd.h"

int main(void){
    char text[16];

    alcd_init();
    alcd_clear();
    sprintf(text,"test");
    alcd_printf(0,0,text);

    while(1){
        _delay_ms(200);
    }
    return 0;
}
