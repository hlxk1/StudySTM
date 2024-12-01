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
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//�����ж�
	
	NVIC_InitStruct.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=2;
	NVIC_Init(&NVIC_InitStruct);
	
	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	
	USART_Cmd(USART1,ENABLE);
	
	
}

uint8_t USART1_RX_BUF[USART1_REC_LEN];//���ջ���,��� USART_REC_LEN ���ֽ�.
uint16_t USART1_RX_STA=0;//����״̬���
void USART1_IRQHandler()
{
	uint8_t read;
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET)//�����ж�
	{
		read=USART_ReceiveData(USART1);;//(USART1->DR); //��ȡ���յ�������
		if((USART1_RX_STA&0x8000)==0)//����δ���
		{
			if(USART1_RX_STA&0x4000)//���յ��� 0x0d
			{
				if(read!=0x0a)USART1_RX_STA=0;//���մ���,���¿�ʼ
				else USART1_RX_STA|=0x8000; //���������
			}else{//��û�յ� 0X0D
				if(read==0x0d)USART1_RX_STA|=0x4000;
				else{
					USART1_RX_BUF[USART1_RX_STA&0X3FFF]=read;
					USART1_RX_STA++;
					if(USART1_RX_STA>(USART1_REC_LEN-1))USART1_RX_STA=0;//�������ݴ���,���¿�ʼ����
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
		USART_SEND_LEN=USART1_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
		for(uint16_t t=0;t<USART_SEND_LEN;t++)
		{
			USART_SendData(USART1, USART1_RX_BUF[t]); //�򴮿� 1 ��������
			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
		}
		USART1_RX_STA=0;
	}
}

int fputc(int ch,FILE *p) //����Ĭ�ϵģ���ʹ�� printf ����ʱ�Զ�����
{
	USART_SendData(USART1,(u8)ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	return ch;
}
