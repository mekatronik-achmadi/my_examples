/*
              DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE

 Copyright (C) 2018 Achmadi S.T.

 Everyone is permitted to copy and distribute verbatim or modified
 copies of this license document, and changing it is allowed as long
 as the name is changed.

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

  0. You just DO WHAT THE FUCK YOU WANT TO.
 */

#ifndef DIN_ACCEL_H
#define DIN_ACCEL_H

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "shell.h"

#include "math.h"
#include "stdlib.h"
#include "stdio.h"

#include "reg_accel.h"

#define MPU_DEBUG   TRUE
#define MPU_ADDR    MPU_ADDR_LO

void d_mpu_start(void);
void d_mpu_setup(void);
void d_mpu_whoAmI(void);

void d_mpu_i2cWrite(u_int8_t addr, u_int8_t value);
void d_mpu_i2cReadData(u_int8_t addr, u_int8_t length);

#endif // DIN_ACCEL_H
