#include "beep.h"

void Beep_Init()
{
		// �ṹ�嶨��
	GPIO_InitTypeDef GPIO_InitStruct;
	// ����ʱ��GPIO�ҽӵ�ʱ��
	RCC_APB2PeriphClockCmd(BEEP_PORT_RCC, ENABLE);
	// GPIO�ṹ������
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=BEEP_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(BEEP_PORT, &GPIO_InitStruct);
	// ���õ͵�ƽ�������̬
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
