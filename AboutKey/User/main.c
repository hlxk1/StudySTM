#include "system.h"
#include "led.h"
#include "systick.h"
//#include "beep.h"
//#include "smg.h"
#include "key.h"

int main(){
	SysTick_Init(72);
	LED_Init();
	KEY_Init();
	
	uint8_t key=0;
	while(1){
		key=KEY_Scan();
		if(key==KEY1_Press){
			LED1=!LED1;
		}else if(key==KEY2_Press){
			LED2=!LED2;
		}else if(key==KEY3_Press){
			LED3=!LED3;
		}else if(key==KEY4_Press){
			LED4=!LED4;
		}
		
	}
}
