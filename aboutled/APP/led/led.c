#include "led.h"

void LED_Init(){
	// �ṹ�嶨��
	GPIO_InitTypeDef GPIO_InitStruct;
	// ����ʱ��GPIO�ҽӵ�ʱ��
	RCC_APB2PeriphClockCmd(LED0_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// GPIO�ṹ������
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=LED0_PIN|LED1_PIN|LED2_PIN|LED3_PIN|LED4_PIN|LED5_PIN|LED6_PIN|LED7_PIN|LED8_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED0_PORT, &GPIO_InitStruct);
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	// ���øߵ��ƽ��֤����
	GPIO_SetBits(LED0_PORT,LED0_PIN|LED1_PIN|LED2_PIN|LED3_PIN|LED4_PIN|LED5_PIN|LED6_PIN|LED7_PIN|LED8_PIN);
	
}
//LED �˿� 8 λ����ͬʱ��������Ӱ���λ
//д�����ݵ� 8 λ�˿ڣ����ݵ�λ��Ӧ�˿ڵ�����
//GPIO_Pin��8 λ�˿ڵ�λ����
//data��д������
void LED_Write_Data(u16 GPIO_Pin,u8 data)
{
    u8 i,j=GPIO_Pin;
    for(i=0;i<8;i++)
    {
        if(data&0x01)
        	GPIO_WriteBit(GPIOA, j<<i ,Bit_SET);
        else
        	GPIO_WriteBit(GPIOA, j<<i ,Bit_RESET);
        data = data >> 1 ;
    }
}
