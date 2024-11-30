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

int main(){
	u8 i=0;
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	KEY_Init();
	LED_Init();
	myEXTI_Init();
	TIM4_Init(1000,36000-1);//500ms

	while(1){
		i++;
		if(i%10==0)
			LED0=!LED0;
		delay_ms(10);
	}
}
