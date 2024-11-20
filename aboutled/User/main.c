#include "stm32f10x.h"
#include "led.h"
int main(){
	
	LED_Init();
	GPIO_ResetBits(LED0_PORT,LED0_PIN);
	while(1){
		;
	}
}
