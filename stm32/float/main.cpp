#include "ch.hpp"
#include "hal.h"
#include "chprintf.h"
#include "AHRS.hpp"

using namespace chibios_rt;

class BlinkerThread : public EnhancedThread<128> {
private:
    uint16_t delay_ms;
protected:
  virtual msg_t Main(void) {
	  while(true) {
		palSetPad(GPIOD, GPIOD_LED3);
		chThdSleepMilliseconds(delay_ms);
		palClearPad(GPIOD, GPIOD_LED3);
		chThdSleepMilliseconds(delay_ms);
	  }
	  
	  return 0;
  }

public:
  BlinkerThread(int delay) : EnhancedThread<128>("blinker"), delay_ms(delay) {}
};

/*
 * Application entry point.
 */
int main(void) {
	halInit();
	System::Init();
	
	/*
	* Activates the serial driver 2 using the driver default configuration.
	* PA2(TX) and PA3(RX) are routed to USART2.
	*/
	sdStart(&SD2, NULL);
	palSetPadMode(GPIOA, 2, PAL_MODE_ALTERNATE(7));
	palSetPadMode(GPIOA, 3, PAL_MODE_ALTERNATE(7));

	BlinkerThread blinker(200);
	
	sdStart(&SD2, NULL);

	AHRSDataGeneric d;
	d.q[0] = 1.0f;
	float Q = 1.0f;
	while(true) {
		float *q = d.getQuatern();
		/* un comment the following line to crash system */
		//chprintf((BaseChannel *)&SD1, "%d\r\n", (int)(q[0]*(float)23.232f));
		/* this one works */
		chprintf((BaseChannel *)&SD1, "%d\r\n", (int)(Q*(float)23.232f));
		chThdSleepMilliseconds(1000);
	}

	return 0;
}
