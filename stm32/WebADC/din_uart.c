#include "din_uart.h"

void d_uart_start(void){
    palSetPadMode(GPIOA,9,PAL_MODE_STM32_ALTERNATE_PUSHPULL); //TX
    palSetPadMode(GPIOA,10,PAL_MODE_INPUT); //RX
    sdStart(&SD1,NULL);
}
