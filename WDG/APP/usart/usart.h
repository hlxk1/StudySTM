#ifndef _USART_H
#define _USART_H

#include "system.h"
#include "systick.h"
#include <stdio.h>
#define USART1_REC_LEN 200

extern uint8_t USART1_RX_BUF[USART1_REC_LEN];
extern uint16_t USART1_RX_STA;
extern uint16_t USART_SEND_LEN;
void USARTx_SendData(void);

void USART1_Init(uint32_t B);

#endif
