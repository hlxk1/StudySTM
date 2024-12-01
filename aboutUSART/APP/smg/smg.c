#include "smg.h"

//共阴极数码管显示 0~F 的段码数据 0-9 A-F
uint8_t gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void Smg_Init()
{
		// 结构体定义
	GPIO_InitTypeDef GPIO_InitStruct;
	// 开启时钟GPIO挂接的时钟
	RCC_APB2PeriphClockCmd(LSA_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(LSB_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(LSC_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(SMG_A_DP_PORT_RCC, ENABLE);
	// 开启复用，才能配置重映射关闭两个功能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	// 重映射
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=LSA_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LSA_PORT, &GPIO_InitStruct);


	GPIO_InitStruct.GPIO_Pin=LSB_PIN;
	GPIO_Init(LSB_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=LSC_PIN;
	GPIO_Init(LSC_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=SMG_A_DP_PIN;
	GPIO_Init(SMG_A_DP_PORT, &GPIO_InitStruct);
	
	
}

void SMG_Dispaly(u8 dat[],u8 pos)
{
	uint8_t i=0;
	// pos从第几个数码管开始，比如只显示最后两个的数码管就是6
	uint8_t pos_temp=pos;
	for(i=pos_temp;i<8;i++)
	{
		switch(i)
		{
			case 0:LSA=1;LSB=1;LSC=1;break;
			case 1:LSA=0;LSB=1;LSC=1;break;
			case 2:LSA=1;LSB=0;LSC=1;break;
			case 3:LSA=0;LSB=0;LSC=1;break;
			case 4:LSA=1;LSB=1;LSC=0;break;
			case 5:LSA=0;LSB=1;LSC=0;break;
			case 6:LSA=1;LSB=0;LSC=0;break;
			case 7:LSA=0;LSB=0;LSC=0;break;
		}
		SMG_Write_Data(GPIO_Pin_0,dat[i-pos_temp]);
		delay_ms(1);
		SMG_Write_Data(GPIO_Pin_0,0x00);// 消隐
	}
}
void SMG_Write_Data(u16 GPIO_Pin,u8 data)
{
    u8 i,j=GPIO_Pin;
    for(i=0;i<8;i++)
    {
        if(data&0x01)
        	GPIO_WriteBit(SMG_A_DP_PORT, j<<i ,Bit_SET);
        else
        	GPIO_WriteBit(SMG_A_DP_PORT, j<<i ,Bit_RESET);
        data = data >> 1 ;
    }
}
