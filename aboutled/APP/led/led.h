#ifndef _LED_H
#define _LED_H

#include "stm32f10x.h"

#define LED0_PORT GPIOC
#define LED0_PIN GPIO_Pin_13
#define LED0_PORT_RCC RCC_APB2Periph_GPIOC

#define LED0 PCout(13)


void LED_Init(void);

#endif
