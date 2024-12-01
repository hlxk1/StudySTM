#include "usart.h"

void USART1_Init(uint32_t B)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_10;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	USART_InitStruct.USART_BaudRate=B;
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;
	USART_InitStruct.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStruct.USART_StopBits=USART_StopBits_1;
	USART_InitStruct.USART_Parity=USART_Parity_No;
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Init(USART1,&USART_InitStruct);
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//接收中断
	
	NVIC_InitStruct.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=2;
	NVIC_Init(&NVIC_InitStruct);
	
	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	
	USART_Cmd(USART1,ENABLE);
	
	
}

uint8_t USART1_RX_BUF[USART1_REC_LEN];//接收缓冲,最大 USART_REC_LEN 个字节.
uint16_t USART1_RX_STA=0;//接收状态标记
void USART1_IRQHandler()
{
	uint8_t read;
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)//接收中断
	{
		read=USART_ReceiveData(USART1);;//(USART1->DR); //读取接收到的数据
		if((USART1_RX_STA&0x8000)==0)//接收未完成
		{
			if(USART1_RX_STA&0x4000)//接收到了 0x0d
			{
				if(read!=0x0a)USART1_RX_STA=0;//接收错误,重新开始
				else USART1_RX_STA|=0x8000; //接收完成了
			}else{//还没收到 0X0D
				if(read==0x0d)USART1_RX_STA|=0x4000;
				else{
					USART1_RX_BUF[USART1_RX_STA&0X3FFF]=read;
					USART1_RX_STA++;
					if(USART1_RX_STA>(USART1_REC_LEN-1))USART1_RX_STA=0;//接收数据错误,重新开始接收
				}
			} 
		}
	}
}

uint16_t USART_SEND_LEN;
void USARTx_SendData()
{
	if(USART1_RX_STA&0x8000)
	{
		USART_SEND_LEN=USART1_RX_STA&0x3fff;//得到此次接收到的数据长度
		for(uint16_t t=0;t<USART_SEND_LEN;t++)
		{
			USART_SendData(USART1, USART1_RX_BUF[t]); //向串口 1 发送数据
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
		}
		USART1_RX_STA=0;
	}
}

int fputc(int ch,FILE *p) //函数默认的，在使用 printf 函数时自动调用
{
	USART_SendData(USART1,(u8)ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	return ch;
}
