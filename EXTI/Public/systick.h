#ifndef _SYSTICK_H
#define _SYSTICK_H

#include "system.h"


void SysTick_Init(u8 SYSCLK);// SYSCLK ��ʾϵͳʱ��Ƶ����72MHz
void delay_us(u32 nus);
void delay_ms(u32 nms);
#endif
