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

int main(){
	u8 i=0;
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	LED_Init();
	TIM3_CH2_PWM_Init(500,72-1);
	u16 j=0;
	u8 fx=0;
	while(1){
		if(fx==0){
			j++;
			if(j>=499)fx=1;
		}else{
			j--;
			if(j==0)fx=0;
		}
		TIM_SetCompare2(TIM3,j);//设置频道2的占空比值
		i++;
		if(i%10==0)
			LED0=!LED0;
		delay_ms(10);
	}
}
