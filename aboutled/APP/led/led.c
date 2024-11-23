#include "led.h"

void LED_Init(){
	// 结构体定义
	GPIO_InitTypeDef GPIO_InitStruct;
	// 开启时钟GPIO挂接的时钟
	RCC_APB2PeriphClockCmd(LED0_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// GPIO结构体配置
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=LED0_PIN|LED1_PIN|LED2_PIN|LED3_PIN|LED4_PIN|LED5_PIN|LED6_PIN|LED7_PIN|LED8_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED0_PORT, &GPIO_InitStruct);
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	// 设置高点电平保证灯灭
	GPIO_SetBits(LED0_PORT,LED0_PIN|LED1_PIN|LED2_PIN|LED3_PIN|LED4_PIN|LED5_PIN|LED6_PIN|LED7_PIN|LED8_PIN);
	
}
//LED 端口 8 位数据同时操作，不影响高位
//写入数据到 8 位端口，数据低位对应端口低引脚
//GPIO_Pin：8 位端口低位引脚
//data：写入数据
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
