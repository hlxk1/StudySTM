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

int main(){
	u8 i=0;
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	USART1_Init(115200);
	LED_Init();
	u32 indata=0;
	TIM2_CH2_Input_Init(0xffff,71);  //以1M频率计数
	while(1){
		if(TIM2_CH2_CAPTURE_STA&0x80) //成功捕获
		{
			indata=TIM2_CH2_CAPTURE_STA&0x3f;
			indata*=0xffff; //溢出次数乘以一次的计数次数时间 us
			indata+=TIM2_CH2_CAPTURE_VAL;//加上高电平捕获的时间
			printf("高电平持续时间：%d us\r\n",indata); //总的高电平时间
			TIM2_CH2_CAPTURE_STA=0; //开始下一次捕获
		}
		i++;
		if(i%10==0)
			LED0=!LED0;
		delay_ms(10);
	}
}
