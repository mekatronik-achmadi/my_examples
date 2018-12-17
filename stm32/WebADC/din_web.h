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

/**
 * @file    din_web.h
 * @brief   Web server routine header.
 *
 * @addtogroup Communication
 * @{
 */

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

/**
 * @brief   Notification Message.
 */
#ifndef SERVER_NOTIF
    #define SERVER_NOTIF TRUE
#endif

void d_web_start(void);
void d_web_term(void);
void d_web_setup(void);

#endif // DIN_WEB_H
/** @} */
