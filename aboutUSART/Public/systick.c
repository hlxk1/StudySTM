#include "systick.h"

u8 fac_us=0;
u16 fac_ms=0;

void SysTick_Init(u8 SYSCLK) // SYSCLK 表示系统时钟频率如72MHz
{ 
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);// 配置Systick时钟源72MHz/8div八分频
	fac_us=SYSCLK/8;   // 如：72/8 = 9 即1us就此
	fac_ms=fac_us*1000;
}

void delay_us(u32 nus)
{
	u32 temp; // 用来获取CTRL寄存器的值
	SysTick->LOAD=nus*fac_us; // 重装载值，即为计数值
	SysTick->VAL=0; // 将当前计数值清零
	SysTick->CTRL|=0x01; // 为了不影响其他位通过|运算符，让最低为为1使能定时器
	do
	{
		temp=SysTick->CTRL;
		//temp&(1<<16)即为第十七位，相与结果为1就说明计数结束，就要跳出循环即要！非运算至0
	}while((temp&0x01)&&!(temp&(1<<16)));
	SysTick->CTRL&=~(0x1); // 最低位设置为0，关闭使能
	SysTick->VAL=0; // 将当前计数值清零
}
void delay_ms(u32 nms)
{
	u32 temp; // 用来获取CTRL寄存器的值
	SysTick->LOAD=nms*fac_ms; // 重装载值，即为计数值
	SysTick->VAL=0; // 将当前计数值清零
	SysTick->CTRL|=0x01; // 为了不影响其他位通过|运算符，让最低为为1使能定时器
	do
	{
		temp=SysTick->CTRL;
		//temp&(1<<16)即为第十七位，相与结果为1就说明计数结束，就要跳出循环即要！非运算至0
	}while((temp&0x01)&&!(temp&(1<<16)));
	SysTick->CTRL&=~(0x1); // 最低位设置为0，关闭使能
	SysTick->VAL=0; // 将当前计数值清零
}
