#include "inputCatch.h"

void TIM2_CH2_Input_Init(uint16_t per,uint16_t psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_ICInitTypeDef TIM_ICInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPD;//采集高电平脉宽，所以下拉默认低电平
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_1;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period=per;
	TIM_TimeBaseInitStruct.TIM_Prescaler=psc;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
	
	TIM_ICInitStruct.TIM_Channel=TIM_Channel_2;
	TIM_ICInitStruct.TIM_ICFilter=0;
	TIM_ICInitStruct.TIM_ICPolarity=TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICPrescaler=TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICSelection=TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM2,&TIM_ICInitStruct);
	
	TIM_ITConfig(TIM2,TIM_IT_Update|TIM_IT_CC2,ENABLE);
	
	NVIC_InitStruct.NVIC_IRQChannel=TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=3;
	NVIC_Init(&NVIC_InitStruct);
	
	TIM_Cmd(TIM2,ENABLE);
}

uint8_t TIM2_CH2_CAPTURE_STA=0;
uint16_t TIM2_CH2_CAPTURE_VAL=0;
void TIM2_IRQHandler(void)
{
	if((TIM2_CH2_CAPTURE_STA&0x80)==0) //还未成功捕获
	{
		if(TIM_GetITStatus(TIM2,TIM_IT_Update)) //发生更新中断
		{
			if(TIM2_CH2_CAPTURE_STA&0X40)//捕获到了高电平
			{
				if((TIM2_CH2_CAPTURE_STA&0x3f)==0x3f) //高电平时间太长
				{
					TIM2_CH2_CAPTURE_STA|=0x80; //标志一次捕获成功
					TIM2_CH2_CAPTURE_VAL=0xffff;
				}
				else
				{
					TIM2_CH2_CAPTURE_STA++;
				}
			}
		}
		if(TIM_GetITStatus(TIM2,TIM_IT_CC2)) //发生捕获中断
		{
			if(TIM2_CH2_CAPTURE_STA&0X40)//捕获到了低电平
			{
				TIM2_CH2_CAPTURE_STA|=0x80; //成功捕获一次高电平
				TIM2_CH2_CAPTURE_VAL=TIM_GetCapture2(TIM2);
				TIM_OC2PolarityConfig(TIM2,TIM_ICPolarity_Rising); //设置上升沿捕获
			}
			else
			{
				TIM2_CH2_CAPTURE_STA=0;
				TIM2_CH2_CAPTURE_VAL=0;
				TIM2_CH2_CAPTURE_STA|=0x40; //捕获到高电平 标志
				TIM_Cmd(TIM2,DISABLE);
				TIM_SetCounter(TIM2,0); //定时器初值为0
				TIM_OC2PolarityConfig(TIM2,TIM_ICPolarity_Falling); //设置下降沿捕获
				TIM_Cmd(TIM2,ENABLE);
			}
		}
	}
	TIM_ClearITPendingBit(TIM2,TIM_IT_CC2|TIM_IT_Update);
}
