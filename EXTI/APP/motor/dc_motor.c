#include "dc_motor.h"
void DC_MOTOR_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	// 开启时钟GPIO挂接的时钟
	RCC_APB2PeriphClockCmd(DC_MOTOR_PORT_RCC, ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=DC_MOTOR_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(DC_MOTOR_PORT, &GPIO_InitStruct);
	GPIO_ResetBits(DC_MOTOR_PORT,DC_MOTOR_PIN);
}
