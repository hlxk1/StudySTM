#include "wakeup.h"

void Enter_Standby_Mode()
{
	RCC_APB1PeriphResetCmd(RCC_APB1Periph_PWR, ENABLE);
	
	PWR_ClearFlag(PWR_FLAG_WU);//清除 Wake-up 标志
	
	PWR_WakeUpPinCmd(ENABLE);
	
	PWR_EnterSTANDBYMode();//进入待机模式
}
