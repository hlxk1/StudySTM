#include "system.h"
#include "led.h"
#include "systick.h"


int main(){
	SysTick_Init(72);
	LED_Init();
	u8 dat=0x01;
	u8 i=0;
	while(1){
			LED_Write_Data(GPIO_Pin_0,~(dat<<i));
			i++;
			if(i>=8)i=0;
			delay_ms(500);
	}
}
