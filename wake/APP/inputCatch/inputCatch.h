#ifndef _INPUTCATCH_H
#define _INPUTCATCH_H

#include "system.h"

extern uint8_t TIM2_CH2_CAPTURE_STA;
extern uint16_t TIM2_CH2_CAPTURE_VAL;

void TIM2_CH2_Input_Init(uint16_t per,uint16_t psc);

#endif
