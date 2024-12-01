#ifndef _PWM_H
#define _PWM_H

#include "system.h"
#include "led.h"

void TIM3_CH2_PWM_Init(uint16_t per,uint16_t psc);

#endif
