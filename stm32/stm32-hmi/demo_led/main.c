/******************************************************************************/
/* This file has been generated by the uGFX-Studio                            */
/*                                                                            */
/* http://ugfx.org                                                            */
/******************************************************************************/

#include "gui.h"
#include "gfx.h"

#include "ch.h"
#include "hal.h"

static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;

  chRegSetThreadName("blinker");
  while (true) {
    palSetPad(GPIOE, 5);
    chThdSleepMilliseconds(500);
    palClearPad(GPIOE, 5);
    chThdSleepMilliseconds(500);
  }
}

int main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;

	halInit();
	chSysInit();
	gfxInit();

	palSetPadMode(GPIOE,5,PAL_MODE_OUTPUT_PUSHPULL);
	chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO+1, Thread1, NULL);

	gdispSetBacklight(100);
	gdispSetContrast(100);

	geventListenerInit(&glistener);
	gwinAttachListener(&glistener);

	guiCreate();

	while (1) {
		guiEventLoop();
	}

	return 0;
}


