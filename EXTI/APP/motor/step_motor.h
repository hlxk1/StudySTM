#ifndef _STEP_MOTOR_H
#define _STEP_MOTOR_H

#include "system.h"
#include "systick.h"


#define MOTOR_IN1_PORT GPIOB
#define MOTOR_IN1_PIN GPIO_Pin_8
#define MOTOR_IN1_PORT_RCC RCC_APB2Periph_GPIOB

#define MOTOR_IN2_PORT GPIOB
#define MOTOR_IN2_PIN GPIO_Pin_9
#define MOTOR_IN2_PORT_RCC RCC_APB2Periph_GPIOB

#define MOTOR_IN3_PORT GPIOB
#define MOTOR_IN3_PIN GPIO_Pin_12
#define MOTOR_IN3_PORT_RCC RCC_APB2Periph_GPIOB

#define MOTOR_IN4_PORT GPIOB
#define MOTOR_IN4_PIN GPIO_Pin_13
#define MOTOR_IN4_PORT_RCC RCC_APB2Periph_GPIOB

#define MOTOR_IN1 PBout(8)
#define MOTOR_IN2 PBout(9)
#define MOTOR_IN3 PBout(12)
#define MOTOR_IN4 PBout(13)

void STEP_MOTOR_Init(void);
void Step_Motor_Run_8Step(u8 dir,u8 speed,u8 stat);
void Step_Motor_Run_4Or8Step(u8 step,u8 dir,u8 speed,u8 stat);
void Step_Motor_Run(u8 step,u8 dir,u8 speed,u16 angle,u8 sta);

#endif
