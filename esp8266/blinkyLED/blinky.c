#include "ets_sys.h"
#include "osapi.h"
#include "gpio.h"
#include "os_type.h"

static const int pin = 2;
static os_timer_t ledtimer;

void blink_timerfunc(void *arg){
  if (GPIO_REG_READ(GPIO_OUT_ADDRESS) & (1 << pin))  {
    gpio_output_set(0, (1 << pin), 0, 0);
  }
  else {
    gpio_output_set((1 << pin), 0, 0, 0);
  }
}

void ICACHE_FLASH_ATTR user_init(){
  gpio_init();

  PIN_FUNC_SELECT(PERIPHS_IO_MUX_U0TXD_U, FUNC_GPIO1);
  gpio_output_set(0, 0, (1 << pin), 0);

  os_timer_setfn(&ledtimer, (os_timer_func_t *)blink_timerfunc, NULL);
  os_timer_arm(&ledtimer, 100, 1);
}
