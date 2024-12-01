#ifndef _BEEP_H
#define _BEEP_H

#include "system.h"
#include "systick.h"

#define BEEP_PORT GPIOB
#define BEEP_PIN GPIO_Pin_0
#define BEEP_PORT_RCC RCC_APB2Periph_GPIOB

#define BEEP PBout(0)

void Beep_Init(void);
void Beep_Alarm(u8 times,uint8_t us);

#endif
