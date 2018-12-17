#ifndef DIN_WEB_H
#define DIN_WEB_H

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "shell.h"

#include "math.h"
#include "stdlib.h"
#include "stdio.h"

#include "din_adc.h"

#ifndef SERVER_NOTIF
    #define SERVER_NOTIF TRUE
#endif

void d_web_start(void);
void d_web_term(void);
void d_web_setup(void);

#endif // DIN_WEB_H
