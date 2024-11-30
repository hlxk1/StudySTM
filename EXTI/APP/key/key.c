#include "key.h"

void KEY_Init()
{
	// �ṹ�嶨��
	GPIO_InitTypeDef GPIO_InitStruct;
	// ����ʱ��GPIO�ҽӵ�ʱ��
	RCC_APB2PeriphClockCmd(KEY1_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(KEY2_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(KEY3_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(KEY4_PORT_RCC, ENABLE);
	// �������ã�����������ӳ��ر���������
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	// ��ӳ��
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);	
	// GPIO�ṹ������
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU; // ��������
	GPIO_InitStruct.GPIO_Pin=KEY1_PIN;
	GPIO_Init(KEY1_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=KEY2_PIN;
	GPIO_Init(KEY2_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=KEY3_PIN;
	GPIO_Init(KEY3_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=KEY4_PIN;
	GPIO_Init(KEY4_PORT, &GPIO_InitStruct);	
	
}

// ��ȡ����״̬����

uint8_t KEY_Scan(void)
{
	static uint8_t key=1;
	if(key==1 && (KEY1==0 || KEY2==0 || KEY4==0 || KEY3==0)){
		delay_ms(10);	
		key=0;
		if(KEY1==0)
		{
			return KEY1_Press;
		}else if(KEY2==0)
		{
			return KEY2_Press;
		}else if(KEY3==0)
		{
			return KEY3_Press;
		}else if(KEY4==0)
		{
			return KEY4_Press;
		}
	}else if(KEY1==1 && KEY2==1 && KEY3==1 && KEY3==1){
		key=1;
	}
	return 0;
}
