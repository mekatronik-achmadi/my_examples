static msg_t Thread_Accelerometer(void *arg)
{
   UNUSED(arg);
   chRegSetThreadName("Accelerometer");

   spiStart(&SPID1, &spi1cfg);
   //spiStart(&SPID2, &spi2cfg);

   /*******************************************************
   * Initializes the LIS302DL Accelerometer
   ********************************************************/
   //  CTRL_REG1
   //   DR | PD | FS | STP | STM | Zen | Yen | Xen |
   //   0  | 1  | 0  |  0  |  0  |  0  |  1  |  1  | = 0x43
   //   0  | 1  | 0  |  0  |  0  |  1  |  1  |  1  | = 0x47
   lis302dlWriteRegister(&SPID1, LIS302DL_CTRL_REG1, 0x43);
   lis302dlWriteRegister(&SPID1, LIS302DL_CTRL_REG2, 0x00);
   lis302dlWriteRegister(&SPID1, LIS302DL_CTRL_REG3, 0x00);

   static sint8  x_Accelero_si8, y_Accelero_si8;
   char data[] = "Data Accelerometer on SD3 : \r\n";

   while (TRUE)
   {
      palClearPad(GPIOD, GPIOD_LED4);

      /* Reading MEMS accelerometer X and Y registers */
      x_Accelero_si8 = lis302dlReadRegister(&SPID1, LIS302DL_OUTX);
      y_Accelero_si8 = lis302dlReadRegister(&SPID1, LIS302DL_OUTY);

      //if(x_Accelero_si8 >0) {palSetPad(GPIOD, LED_RED);} else {palClearPad(GPIOD, LED_RED);}
      //if(y_Accelero_si8 >0) {palSetPad(GPIOD, LED_RED);} else {palClearPad(GPIOD, LED_RED);}


      chprintf((BaseSequentialStream *) &SD3, "%s", data);
      chprintf((BaseSequentialStream *) &SD3, "x_Accelero : %.2f \r\n", x_Accelero_si8);
      chprintf((BaseSequentialStream *) &SD3, "y_Accelero : %.2f \r\n", y_Accelero_si8);


       /* Transmitting accelerometer data over SPI2 */
       //spiSelect(&SPID2);
       //spiStartSendI(&SPID2, 20, &data);
       //spiUnselect(&SPID2);

      palClearPad(GPIOD, LED_GREEN);
      chThdSleepMilliseconds(500);
      palSetPad(GPIOD, LED_GREEN);
      chThdSleepMilliseconds(500);
   }
   return 0;
}