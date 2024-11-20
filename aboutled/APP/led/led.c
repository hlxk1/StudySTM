#include "led.h"

void LED_Init(){
	// 结构体定义
	GPIO_InitTypeDef GPIO_InitStruct;
	// 开启时钟GPIO挂接的时钟
	RCC_APB2PeriphClockCmd(LED0_PORT_RCC, ENABLE);
	// GPIO结构体配置
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=LED0_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED0_PORT, &GPIO_InitStruct);
	// 设置高点电平保证灯灭
	GPIO_SetBits(LED0_PORT,LED0_PIN);
	
}
