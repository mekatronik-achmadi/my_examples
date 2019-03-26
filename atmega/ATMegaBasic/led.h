#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

#include <avr/io.h>
#include <util/delay.h>

void led_init(char pled);
void led_toggle(char pled);

#endif // LED_H_INCLUDED
