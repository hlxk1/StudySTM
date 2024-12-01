#include "iwdg.h"

void IWDG_Init(uint8_t pre,uint16_t rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(pre);
	IWDG_SetReload(rlr); // 12Î»
	IWDG_ReloadCounter();// Î¹¹·
	IWDG_Enable();// Ê¹ÄÜIWDG
}
