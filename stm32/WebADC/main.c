#include "ch.h"
#include "hal.h"

#include "din_adc.h"
#include "din_web.h"
#include "din_uart.h"

static THD_WORKING_AREA(waLED, 128);
static THD_FUNCTION(thdLED, arg) {

    (void)arg;

    chRegSetThreadName("blinker");
    while (true) {
        palTogglePad(GPIOC,13);
        chThdSleepMilliseconds(500);
    }
}

int main(void) {

  halInit();
  chSysInit();

  d_adc_start();
  d_uart_start();
  d_web_start();

  palSetPadMode(GPIOC,13,PAL_MODE_OUTPUT_PUSHPULL);
  palClearPad(GPIOC,13);

  chThdCreateStatic(waLED, sizeof(waLED), NORMALPRIO, thdLED, NULL);

  d_uart_info();
#if SERVER_NOTIF
  chprintf((BaseSequentialStream *)&SD1,"All Setup Finished\r\n");
#endif

  while(true){
    d_web_term();
    chThdSleepMilliseconds(100);
  }
}
