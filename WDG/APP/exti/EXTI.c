#include "EXTI.h"

void myEXTI_Init()
{
	NVIC_InitTypeDef NVIC_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource15);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource14);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource13);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource12);

	NVIC_InitStruct.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=3;
	
	NVIC_Init(&NVIC_InitStruct);

	EXTI_InitStruct.EXTI_Line=EXTI_Line12|EXTI_Line14|EXTI_Line13|EXTI_Line15;
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStruct);
	
	
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line12)==SET){
		delay_ms(10);
		if(KEY4==0){
			LED2=1;
		}
	}else if(EXTI_GetITStatus(EXTI_Line13)==SET){
		delay_ms(10);
		if(KEY3==0){
			LED2=0;
		}
	}else if(EXTI_GetITStatus(EXTI_Line14)==SET){
		delay_ms(10);
		if(KEY2==0){
			LED1=1;
		}
	}else if(EXTI_GetITStatus(EXTI_Line15)==SET){
		delay_ms(10);
		if(KEY1==0){
			LED1=0;
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line12|EXTI_Line14|EXTI_Line13|EXTI_Line15);
}
