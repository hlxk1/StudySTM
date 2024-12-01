#include "iwdg.h"

void IWDG_Init(uint8_t pre,uint16_t rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(pre);
	IWDG_SetReload(rlr); // 12λ
	IWDG_ReloadCounter();// ι��
	IWDG_Enable();// ʹ��IWDG
}
