#include "wakeup.h"

void Enter_Standby_Mode()
{
	RCC_APB1PeriphResetCmd(RCC_APB1Periph_PWR, ENABLE);
	
	PWR_ClearFlag(PWR_FLAG_WU);//��� Wake-up ��־
	
	PWR_WakeUpPinCmd(ENABLE);
	
	PWR_EnterSTANDBYMode();//�������ģʽ
}
