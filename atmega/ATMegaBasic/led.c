#include "led.h"

void led_init(char pled){
    DDRC |= 1<<pled;
}

void led_toggle(char pled){
    PORTC ^= 1<<pled;
}
