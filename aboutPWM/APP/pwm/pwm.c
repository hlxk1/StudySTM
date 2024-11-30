#include "pwm.h"

void TIM3_CH2_PWM_Init(uint16_t per,uint16_t psc)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_OCInitTypeDef TIM_OCInitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period=per;
	TIM_TimeBaseInitStruct.TIM_Prescaler=psc;
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;//不分频
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	
	TIM_OCInitStruct.TIM_OCMode=TIM_OCMode_PWM1; // 输出模式
	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable; 
	TIM_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_Low;// 低极性
	TIM_OC2Init(TIM3,&TIM_OCInitStruct);
	
	TIM_ARRPreloadConfig(TIM3,ENABLE);
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
	
	TIM_Cmd(TIM3,ENABLE);
	
}
