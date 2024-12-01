#include "beep.h"

void Beep_Init()
{
		// 结构体定义
	GPIO_InitTypeDef GPIO_InitStruct;
	// 开启时钟GPIO挂接的时钟
	RCC_APB2PeriphClockCmd(BEEP_PORT_RCC, ENABLE);
	// GPIO结构体配置
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=BEEP_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(BEEP_PORT, &GPIO_InitStruct);
	// 设置低电平输出高阻态
	GPIO_ResetBits(BEEP_PORT,BEEP_PIN);
	
}

void Beep_Alarm(u8 times,uint8_t us)
{
	while(times--)
	{
		BEEP=!BEEP;
		delay_us(us);
	}
}
