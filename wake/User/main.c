#include "system.h"
#include "led.h"
#include "systick.h"
#include "beep.h"
#include "smg.h"
#include "key.h"
#include "dc_motor.h"
#include "step_motor.h"
#include "EXTI.h"
#include "TIM.h"
#include "pwm.h"
#include "usart.h"
#include "iwdg.h"
#include "wwdg.h"
#include "inputCatch.h"
#include "wakeup.h"

int main(){
	u8 i=0;
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	USART1_Init(115200);
	LED_Init();
	KEY_Init();
	LED1=0;
	while(1){
		if(KEY_Scan()==KEY1_Press)
		{
			Enter_Standby_Mode();
		}	
		i++;
		if(i%10==0)
			LED0=!LED0;
		delay_ms(10);
		
	}
	
}
