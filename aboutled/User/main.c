#include "system.h"
#include "led.h"


void delay(u32 i){
	while(i--);
}
int main(){
	RCC_HSE_Config(RCC_PLLSource_HSE_Div2,RCC_PLLMul_16);
	LED_Init();
	
	while(1){
		LED0=0;
		delay(6000000);
		LED0=!LED0;
		delay(6000000);
	}
}
