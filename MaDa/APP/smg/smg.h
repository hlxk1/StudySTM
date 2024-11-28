#ifndef _SMG_H
#define _SMG_H

#include "system.h"
#include "systick.h"

#define LSA_PORT GPIOB
#define LSA_PIN GPIO_Pin_5
#define LSA_PORT_RCC RCC_APB2Periph_GPIOB

#define LSB_PORT GPIOB
#define LSB_PIN GPIO_Pin_4
#define LSB_PORT_RCC RCC_APB2Periph_GPIOB

#define LSC_PORT GPIOB
#define LSC_PIN GPIO_Pin_3
#define LSC_PORT_RCC RCC_APB2Periph_GPIOB

#define SMG_A_DP_PORT GPIOA
#define SMG_A_DP_PIN GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
#define SMG_A_DP_PORT_RCC RCC_APB2Periph_GPIOB

#define LSA PBout(5)
#define LSB PBout(4)
#define LSC PBout(3)

extern uint8_t gsmg_code[17];

void Smg_Init(void);
void SMG_Dispaly(u8 dat[],u8 pos);
void SMG_Write_Data(u16 GPIO_Pin,u8 data);
	
#endif
