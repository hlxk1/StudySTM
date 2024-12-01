#ifndef _KEY_H
#define _KEY_H

#include "system.h"
#include "systick.h"

#define KEY1_PORT GPIOA
#define KEY1_PIN GPIO_Pin_15
#define KEY1_PORT_RCC RCC_APB2Periph_GPIOA

#define KEY2_PORT GPIOA
#define KEY2_PIN GPIO_Pin_14
#define KEY2_PORT_RCC RCC_APB2Periph_GPIOA

#define KEY3_PORT GPIOA
#define KEY3_PIN GPIO_Pin_13
#define KEY3_PORT_RCC RCC_APB2Periph_GPIOA

#define KEY4_PORT GPIOA
#define KEY4_PIN GPIO_Pin_12
#define KEY4_PORT_RCC RCC_APB2Periph_GPIOA

#define KEY1 PAin(15)
#define KEY2 PAin(14)
#define KEY3 PAin(13)
#define KEY4 PAin(12)

#define KEY1_Press 1
#define KEY2_Press 2
#define KEY3_Press 3
#define KEY4_Press 4

void KEY_Init(void);
uint8_t KEY_Scan(void);

#endif
