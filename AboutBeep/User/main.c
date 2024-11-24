#include "system.h"
#include "led.h"
#include "systick.h"
#include "beep.h"

int main(){
	SysTick_Init(72);
	LED_Init();
	Beep_Init();
	while(1){
		LED1=!LED1;
		
	}
}
