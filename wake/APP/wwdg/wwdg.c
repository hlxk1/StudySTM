#include "wwdg.h"

void WWDG_Init()
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	WWDG_SetWindowValue(0x5f);
	WWDG_SetPrescaler(WWDG_Prescaler_8);
	
	
	NVIC_InitStruct.NVIC_IRQChannel=WWDG_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=3;
	NVIC_Init(&NVIC_InitStruct);
	
	WWDG_Enable(0x7f);//使能窗口看门狗并初始化计数器值
	WWDG_ClearFlag();// 必须要清状态标记位否则进入不了中断
	WWDG_EnableIT();
	
	
}
void WWDG_IRQHandler(void)
{
	WWDG_SetCounter(0x7f); //重新赋值
	WWDG_ClearFlag(); //清除窗口看门狗状态标志
	LED1=!LED1;

}
