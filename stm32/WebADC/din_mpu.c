#include "din_mpu.h"

/////////////////////////////////////// Rutin MPU60x0 (hasil nyolong kerjaan orang) ////////////////

float ax,ay,az,mag;
float rangePerDigit = .000061f; //2G

static u_int8_t smplrt_div= 0;
static u_int8_t mpu_config = 0;
static u_int8_t gyro_config = 0;
static u_int8_t accel_config = 0;
static u_int8_t user_control = 0x00;
static u_int8_t power_mgmt1 = 0x00;
//static u_int8_t fifo_enable = 0x00;
//static u_int8_t int_pin_config = 0x00;
//static u_int8_t int_pin_enable = 0x00;
//static u_int8_t signal_path_reset = 0x00;
//static u_int8_t power_mgmt2  = 0x00;
//static u_int8_t aux_vddio = 0x00;

/*
 * This function defines value for SMPRT_DIV register.
 * Sample Rate = Gyroscope Output Rate / (1 + SMPLRT_DIV)
 */
static u_int8_t d_mpu_setSampleRate(u_int8_t samplerate_divisor){
    smplrt_div = samplerate_divisor;
#if MPU_DEBUG
    chprintf((BaseSequentialStream *)&SD1,"Sample rate value: 0x%x\r\n", smplrt_div);
#endif
    return smplrt_div;
}

/*
 * This function sets value for CONFIG register. This register controls FSYNC and bandwidth of gyro and
 * accelerometer.
 * Typical function call: set_mpu_config_register(EXT_SYNC_SET0, DLPF_CFG0);
 */
static u_int8_t d_mpu_configRegister(u_int8_t ext_sync_set, u_int8_t dlpf_cfg){
    mpu_config = 0x00;
    mpu_config = ext_sync_set | dlpf_cfg;
#if MPU_DEBUG
    chprintf((BaseSequentialStream *)&SD1,"CONFIG Register value: 0x%x\r\n", mpu_config);
#endif
    return mpu_config;
}

/*
 * This function defines value for GYRO_CONFIG register. This register controls
 * self test and  range of gyroscopes.
 * Typical function call: set_mpu_gyro(XG_ST_EN, YG_ST_EN, ZG_ST_EN, FS_SEL250)
 */
static u_int8_t d_mpu_setGyro(u_int8_t xgyro_st, u_int8_t ygyro_st, u_int8_t zgyro_st, u_int8_t gyro_range){
    gyro_config = 0x00;
    gyro_config = xgyro_st | ygyro_st | zgyro_st | gyro_range;
#if MPU_DEBUG
    chprintf((BaseSequentialStream *)&SD1,"Gyro Config value: 0x%x\r\n", gyro_config);
#endif
    return gyro_config;
}

/*
 * This function defines value for ACCEL_CONFIG register. This register controls
 * self test, accelerometer range and DHPF for accelerometer.
 * Typical function call: set_mpu_accel(XA_ST_EN/DIS, YA_ST_EN/DIS, ZA_ST_EN/DIS, AFS_SEL0, ACCEL_HPF0)
 */
static u_int8_t d_mpu_setAccel(u_int8_t xaccel_st, u_int8_t yaccel_st, u_int8_t zaccel_st, u_int8_t accel_range, u_int8_t dhpf_accel){
    accel_config = 0x00;
    accel_config = xaccel_st | yaccel_st | zaccel_st | accel_range | dhpf_accel;
#if MPU_DEBUG
    chprintf((BaseSequentialStream *)&SD1,"Accelerometer Config value: 0x%x\r\n", accel_config);
#endif
    return accel_config;
}

/*
 * This function defines value for FIFO_EN register. This register controls which sensor output to be
 * written in fifo regiser.
 * Typical funciton call: set_mpu_fifo_register(TEMP_FIFO_EN/DIS, XG_FIFO_EN/DIS, YG_FIFO_EN/DIS, ACCLE_FIFO_EN/DIS, SLVx_FIFO_EN/DIS...)
 */
//static u_int8_t d_mpu_fifoRegister(u_int8_t temperature_fifo, u_int8_t xg_fifo, u_int8_t yg_fifo, u_int8_t zg_fifo, u_int8_t accel_fifo, u_int8_t slv2_fifo, u_int8_t slv1_fifo,u_int8_t slv0_fifo){
//    fifo_enable = 0x00;
//    fifo_enable = temperature_fifo | xg_fifo | yg_fifo | zg_fifo | accel_fifo | slv2_fifo | slv1_fifo | slv0_fifo;
//#if MPU_DEBUG
//    chprintf((BaseSequentialStream *)&SD1,"FIFO Enable value: 0x%x\r\n", fifo_enable);
//#endif
//    return fifo_enable;
//}

/*
 * This function defines value for INT_PIN_CFG register. This controls behavior of Interrupt PIN
 */
//static u_int8_t d_mpu_intBehavior(u_int8_t int_level, u_int8_t int_pin_mode, u_int8_t latch_int, u_int8_t int_status_bits, u_int8_t fsync_level, u_int8_t fsync_enable, u_int8_t i2c_bypass, u_int8_t clock){
//    int_pin_config = 0x00;
//    int_pin_config = int_level | int_pin_mode | latch_int | int_status_bits | fsync_level | fsync_enable | i2c_bypass |clock;
//#if MPU_DEBUG
//    chprintf((BaseSequentialStream *)&SD1,"Interrupt behavior value: 0x%x\r\n", int_pin_config);
//#endif
//    return int_pin_config;
//}

/*
 * This function defines value for INT_ENABLE register. This register controls source of interrupt.
 * Typical function call: set_mpu_interrupt_sources(FF_EN/DIS, MOT_EN/DIS,.......,DATA_RDY_EN/DIS)
 */
//static u_int8_t d_mpu_intSource(u_int8_t free_fall, u_int8_t motion_threshold, u_int8_t zero_motion, u_int8_t fifo_overflow, u_int8_t i2c_mst, u_int8_t data_ready){
//    int_pin_enable = 0x00;
//    int_pin_enable = free_fall | motion_threshold | zero_motion | fifo_overflow | i2c_mst | data_ready;
//#if MPU_DEBUG
//    chprintf((BaseSequentialStream *)&SD1,"Interrupt Pin Source value value: 0x%x\r\n", int_pin_enable);
//#endif
//    return int_pin_enable;
//}

/*
 * This function defines value for SIGNAL_PATH_RESET register. This register can reset gyro, accelerometer and
 * temperature sensors' digital and analog signal path.
 * Typical function call: reset_mpu_signal_path(GYRO_RESET_EN/DIS, ACCEL_RESET_EN/DIS, TEMP_RESET_EN/DIS)
 */
//static u_int8_t d_mpu_Reset(u_int8_t gyro_reset, u_int8_t accel_reset, u_int8_t temperature_reset){
//    signal_path_reset = 0x00;
//    signal_path_reset = gyro_reset | accel_reset | temperature_reset;
//#if MPU_DEBUG
//    chprintf((BaseSequentialStream *)&SD1,"Signal Path Reset value: 0x%x\r\n", signal_path_reset);
//#endif
//    return signal_path_reset;
//}

/*
 * This function defines value for USER_CTRL register.
 * Typical Function Call: set_mpu_user_control(USER_FIFO_EN/DIS,I2C_MST_EN/DIS,I2C_IF_EN/DIS,FIFO_RESET_EN/DIS,I2C_MST_RESET_EN/DIS,SIG_COND_RESET_EN/DIS);
 */
static u_int8_t d_mpu_userControl(u_int8_t fifo_operation, u_int8_t aux_i2c, u_int8_t bus_select, u_int8_t fifo_reset, u_int8_t i2c_reset, u_int8_t signal_cond_reset){
    user_control = 0x00;
    user_control = fifo_operation | aux_i2c | bus_select | fifo_reset | i2c_reset | signal_cond_reset;
#if MPU_DEBUG
    chprintf((BaseSequentialStream *)&SD1,"User Control value: 0x%x\r\n", user_control);
#endif
    return user_control;
}

/*
 * This fucntion defines value for PWR_MGMT_1 register. This register controls device reset, sleep mode, cycle
 * between different mode and clock source.
 * Typical Function Call: set_mput_power_mgmt1(DEVICE_RESET_EN/DIS, SLEEP_EN/DIS, CYCLE_EN/DIS, TEMPERATURE_EN/DIS, CLKSEL_XG)
 *
 */
static u_int8_t d_mpu_powerMGMT1(u_int8_t device_reset, u_int8_t sleep, u_int8_t cycle, u_int8_t temperature, u_int8_t clock_source){
    power_mgmt1 = 0x00;
    power_mgmt1 = device_reset | sleep | cycle | temperature | clock_source;
#if MPU_DEBUG
    chprintf((BaseSequentialStream *)&SD1,"Power Managemen1 value: 0x%x\r\n", power_mgmt1);
#endif
    return power_mgmt1;
}

/*
 * This function writes value of sampling rate into SMPRT_DIV register.
 */
static void d_mpu_writeSampleRate(void){
     d_mpu_i2cWrite(SMPRT_DIV, smplrt_div);
}

/*
 * This function writes value of configuration into CONFIG register.
 */
//static void d_mpu_writeConfigRegister(){
//    d_mpu_i2cWrite(CONFIG, mpu_config);
//}

/*
 * This function writes value of gyro_config into GYRO_CONFIG register.
 */
static void d_mpu_writeGyro(void){
    d_mpu_i2cWrite(GYRO_CONFIG, gyro_config);
}

/*
 * This function writes value of accel_config into ACCEL_CONFIG register.
 */
static void d_mpu_writeAccel(void){
    d_mpu_i2cWrite(ACCEL_CONFIG, accel_config);
}

/*
 * This function writes value of power_mgmt1 into PWR_MGMT_1 register.
 */
static void d_mpu_writePowerMGMT1(void){
    d_mpu_i2cWrite(PWR_MGMT_1, power_mgmt1);
}

/*
 * This function writes value of user_control into USER_CTRL register.
 */
//static void d_mpu_writeUserControl(void){
//    d_mpu_i2cWrite(USER_CTRL, user_control);
//}

/*
 * Call to ChibiOS I2C function.
 */
void d_mpu_i2cWrite(u_int8_t addr, u_int8_t value){
    u_int8_t mpu_txbuf[10], mpu_rxbuf[10];
    mpu_txbuf[0] = addr;
    mpu_txbuf[1] = value;

#if MPU_DEBUG
    chprintf((BaseSequentialStream *)&SD1,"Address: 0x%x Value: 0x%x\r\n", mpu_txbuf[0],mpu_txbuf[1]);
#endif

    i2cAcquireBus(&I2CD2);
    i2cMasterTransmit(&I2CD2, MPU_ADDR, mpu_txbuf, 2, mpu_rxbuf, 0);
    i2cReleaseBus(&I2CD2);

    chThdSleepMilliseconds(100);
}

/*
 * This function reads data from MPU60X0.
 * Input is register address and lenght of buffer to be read.
 *
 * First three values are accelerometer.
 * Fourth one is temperature sensor.
 * Last three are gyro values.
 *
 * Havent explored FIFO and interrupt part yet.
 *
 * For this part addr = 0x3B and length = 14.
 */
void d_mpu_i2cReadData(u_int8_t addr, u_int8_t length){
    u_int8_t mpu_txbuf[20], mpu_rxbuf[20], i = 0;
    u_int16_t mpu_val[10];

    mpu_txbuf[0] = addr;
    for(i=0;i<length;i++)mpu_rxbuf[i] = 0x00;

    i2cAcquireBus(&I2CD2);
    i2cMasterTransmit(&I2CD2, MPU_ADDR, mpu_txbuf, 1, mpu_rxbuf, length);
    i2cReleaseBus(&I2CD2);

    mpu_val[0] = (mpu_rxbuf[0] << 8) + mpu_rxbuf[1];
    mpu_val[1] = (mpu_rxbuf[2] << 8) + mpu_rxbuf[3];
    mpu_val[2] = (mpu_rxbuf[4] << 8) + mpu_rxbuf[5];
    mpu_val[3] = (mpu_rxbuf[6] << 8) + mpu_rxbuf[7];
    mpu_val[4] = (mpu_rxbuf[8] << 8) + mpu_rxbuf[9];
    mpu_val[5] = (mpu_rxbuf[10] << 8) + mpu_rxbuf[11];
    mpu_val[6] = (mpu_rxbuf[12] << 8) + mpu_rxbuf[13];

    ax = mpu_val[0] * rangePerDigit * 9.80665f;
    ay = mpu_val[1] * rangePerDigit * 9.80665f;
    az = mpu_val[2] * rangePerDigit * 9.80665f;
    mag = d_mpu_vectorMag(ax,ay,az);

#if MPU_DEBUG
    chprintf((BaseSequentialStream *)&SD1, "Result:");
    chprintf((BaseSequentialStream *)&SD1, "\t%5.2f\t%5.2f\t%5.2f",ax,ay,az);
    chprintf((BaseSequentialStream *)&SD1, "\r\n");
#endif

}

///////////////////////////////////////////////////////////////////////////////////////////

static const I2CConfig i2cfg = {
    OPMODE_I2C,
    400000,
    FAST_DUTY_CYCLE_2,
};

float d_mpu_vectorMag(float vx, float vy, float vz){
    return sqrt( pow(vx,2) + pow(vy,2) + pow(vz,2) );
}

void d_mpu_whoAmI(void){
    u_int8_t tx_buff[8];
    u_int8_t rx_buff[8];

#if MPU_DEBUG
    i2cflags_t errors = 0;
    msg_t status = MSG_OK;
#endif

    tx_buff[0] = 0x75;

    i2cAcquireBus(&I2CD2);
#if MPU_DEBUG
    status = i2cMasterTransmit(&I2CD2, MPU_ADDR, tx_buff, 1, rx_buff, 2); //rx_buff length 1 failed
#else
    i2cMasterTransmit(&I2CD2, MPU_ADDR, tx_buff, 1, rx_buff, 2); //rx_buff length 1 failed
#endif
    i2cReleaseBus(&I2CD2);

#if MPU_DEBUG
    if (status != MSG_OK){
        errors = i2cGetErrors(&I2CD2);
        chprintf((BaseSequentialStream *)&SD1,"s=%i | e=%i\r\n",status,errors);
    }
    else{
        chprintf((BaseSequentialStream *)&SD1,"id: 0x%x\r\n",rx_buff[0]);
        chprintf((BaseSequentialStream *)&SD1,"i2c accel oke\r\n");
    }
#endif

}

static THD_WORKING_AREA(waMPU, 256);
static THD_FUNCTION(thdMPU, arg) {

    (void)arg;

    chRegSetThreadName("MPU Sensing");
    while (true) {
        d_mpu_i2cReadData(0x3B, 14);
        chThdSleepMilliseconds(200);
    }
}

void d_mpu_setup(void){
    d_mpu_setSampleRate(9);
    d_mpu_configRegister(EXT_SYNC_SET0,DLPF_CFG0);
    d_mpu_setGyro(XG_ST_DIS,YG_ST_DIS,ZG_ST_DIS,FS_SEL_250);
    d_mpu_setAccel(XA_ST_DIS,YA_ST_DIS,ZA_ST_DIS,AFS_SEL_2g,ACCEL_HPF0);
    d_mpu_powerMGMT1(DEVICE_RESET_DIS,SLEEP_DIS,CYCLE_DIS,TEMPERATURE_EN,CLKSEL_XG);
    d_mpu_userControl(USER_FIFO_DIS, I2C_MST_DIS, I2C_IF_DIS, FIFO_RESET_DIS, I2C_MST_RESET_DIS, SIG_COND_RESET_DIS);

    d_mpu_writePowerMGMT1();
    d_mpu_writeGyro();
    d_mpu_writeAccel();
    d_mpu_writeSampleRate();
}

void d_mpu_start(void){
    palSetPadMode(GPIOB, 10, PAL_MODE_STM32_ALTERNATE_OPENDRAIN );   /* SCL */
    palSetPadMode(GPIOB, 11, PAL_MODE_STM32_ALTERNATE_OPENDRAIN );   /* SDA */
    i2cStart(&I2CD2, &i2cfg);

    chThdSleepMilliseconds(200);
    d_mpu_setup();

    chThdSleepMilliseconds(200);
    d_mpu_whoAmI();

    chThdSleepMilliseconds(200);
    chThdCreateStatic(waMPU, sizeof(waMPU), NORMALPRIO, thdMPU, NULL);
}
