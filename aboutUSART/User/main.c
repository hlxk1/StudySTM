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


int main(){
	u8 i=0;
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	LED_Init();
	USART1_Init(115200);
	while(1){
		USARTx_SendData();
		i++;
		if(i%10==0)
			LED0=!LED0;
			printf("hello usart,hi pc");
		delay_ms(10);
	}
}
