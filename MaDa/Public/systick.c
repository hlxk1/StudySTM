#include "systick.h"

u8 fac_us=0;
u16 fac_ms=0;

void SysTick_Init(u8 SYSCLK) // SYSCLK ��ʾϵͳʱ��Ƶ����72MHz
{ 
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);// ����Systickʱ��Դ72MHz/8div�˷�Ƶ
	fac_us=SYSCLK/8;   // �磺72/8 = 9 ��1us�ʹ�
	fac_ms=fac_us*1000;
}

void delay_us(u32 nus)
{
	u32 temp; // ������ȡCTRL�Ĵ�����ֵ
	SysTick->LOAD=nus*fac_us; // ��װ��ֵ����Ϊ����ֵ
	SysTick->VAL=0; // ����ǰ����ֵ����
	SysTick->CTRL|=0x01; // Ϊ�˲�Ӱ������λͨ��|������������ΪΪ1ʹ�ܶ�ʱ��
	do
	{
		temp=SysTick->CTRL;
		//temp&(1<<16)��Ϊ��ʮ��λ��������Ϊ1��˵��������������Ҫ����ѭ����Ҫ����������0
	}while((temp&0x01)&&!(temp&(1<<16)));
	SysTick->CTRL&=~(0x1); // ���λ����Ϊ0���ر�ʹ��
	SysTick->VAL=0; // ����ǰ����ֵ����
}
void delay_ms(u32 nms)
{
	u32 temp; // ������ȡCTRL�Ĵ�����ֵ
	SysTick->LOAD=nms*fac_ms; // ��װ��ֵ����Ϊ����ֵ
	SysTick->VAL=0; // ����ǰ����ֵ����
	SysTick->CTRL|=0x01; // Ϊ�˲�Ӱ������λͨ��|������������ΪΪ1ʹ�ܶ�ʱ��
	do
	{
		temp=SysTick->CTRL;
		//temp&(1<<16)��Ϊ��ʮ��λ��������Ϊ1��˵��������������Ҫ����ѭ����Ҫ����������0
	}while((temp&0x01)&&!(temp&(1<<16)));
	SysTick->CTRL&=~(0x1); // ���λ����Ϊ0���ر�ʹ��
	SysTick->VAL=0; // ����ǰ����ֵ����
}
