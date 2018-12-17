#include "din_accel.h"

static const I2CConfig i2cfg = {
    OPMODE_I2C,
    400000,
    FAST_DUTY_CYCLE_2,
};

void d_accel_start(void){
    palSetPadMode(GPIOB, 8, PAL_MODE_STM32_ALTERNATE_OPENDRAIN );   /* SCL */
    palSetPadMode(GPIOB, 9, PAL_MODE_STM32_ALTERNATE_OPENDRAIN );   /* SDA */
    i2cStart(&I2CD1, &i2cfg);

    MPU6050(0x69);
    chThdSleepMilliseconds(100);
    MPUinitialize();

    if(MPUtestConnection()==TRUE){
        chprintf((BaseSequentialStream *)&SD1,"MPU6050 Connected\r\n");
    }
    else{
        chprintf((BaseSequentialStream *)&SD1,"MPU6050 Failed\r\n");
    }
}
