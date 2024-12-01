#ifndef _DC_MOTOR_H
#define _DC_MOTOR_H

#include "system.h"
#include "systick.h"

#define DC_MOTOR_PORT GPIOB
#define DC_MOTOR_PIN GPIO_Pin_8
#define DC_MOTOR_PORT_RCC RCC_APB2Periph_GPIOB

#define DC_MOTOR PBout(8)

void DC_MOTOR_Init(void);

#endif
