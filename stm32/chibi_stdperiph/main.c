/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"
//#include "test.h"

#include "stm32f10x_conf.h" //PAKAI_STD_PERIPH_DRIVER

#define LED4 GPIO_Pin_8 //PAKAI_STD_PERIPH_DRIVER
#define LED3 GPIO_Pin_9 //PAKAI_STD_PERIPH_DRIVER
/*
 * Blinker thread #1.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;

  chRegSetThreadName("blinker_1");
  while (true) {
    GPIOC->ODR ^= LED3; //PAKAI_STD_PERIPH_DRIVER
    chThdSleepMilliseconds(250);
  }
}

/*
 * Blinker thread #2.
 */
static THD_WORKING_AREA(waThread2, 128);
static THD_FUNCTION(Thread2, arg) {

  (void)arg;

  chRegSetThreadName("blinker_2");
  while (true) {
    GPIOC->ODR ^= LED4; //PAKAI_STD_PERIPH_DRIVER
    chThdSleepMilliseconds(500);
  }
}

void Init_GPIO(void){
    GPIO_InitTypeDef GPIO_InitStructure; //PAKAI_STD_PERIPH_DRIVER

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); //PAKAI_STD_PERIPH_DRIVER

    GPIO_InitStructure.GPIO_Pin = LED3 | LED4; //PAKAI_STD_PERIPH_DRIVER
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //PAKAI_STD_PERIPH_DRIVER
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //PAKAI_STD_PERIPH_DRIVER
    GPIO_Init(GPIOC, &GPIO_InitStructure); //PAKAI_STD_PERIPH_DRIVER
}

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  Init_GPIO();
  GPIOC->ODR &= ~(LED3 | LED4); //PAKAI_STD_PERIPH_DRIVER

  /*
   * Activates the serial driver 1 using the driver default configuration.
   * PA9(TX) and PA10(RX) are routed to USART1.
   */
//  sdStart(&SD1, NULL);

  /*
   * Creates the example threads.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO+1, Thread1, NULL);
  chThdCreateStatic(waThread2, sizeof(waThread2), NORMALPRIO+1, Thread2, NULL);

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state, when the button is
   * pressed the test procedure is launched.
   */
  while (true) {
//    if (palReadPad(GPIOA, GPIOA_BUTTON))
//      TestThread(&SD1);
//    chThdSleepMilliseconds(500);
  }
}
