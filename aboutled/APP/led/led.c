#include "led.h"

void LED_Init(){
	// �ṹ�嶨��
	GPIO_InitTypeDef GPIO_InitStruct;
	// ����ʱ��GPIO�ҽӵ�ʱ��
	RCC_APB2PeriphClockCmd(LED0_PORT_RCC, ENABLE);
	// GPIO�ṹ������
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=LED0_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED0_PORT, &GPIO_InitStruct);
	// ���øߵ��ƽ��֤����
	GPIO_SetBits(LED0_PORT,LED0_PIN);
	
}
