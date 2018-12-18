#ifndef DIN_FUZZY_H
#define DIN_FUZZY_H

#include "ch.h"
#include "hal.h"

#include "math.h"
#include "stdlib.h"
#include "stdio.h"

#define RULE_SIZE 9

#define OUT_BIASA 0
#define OUT_AWAS  1
#define OUT_JATUH 2

u_int16_t d_fuzzy(void);

#endif // DIN_FUZZY_H
