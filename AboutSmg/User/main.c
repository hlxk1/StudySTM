#include "system.h"
#include "led.h"
#include "systick.h"
#include "beep.h"
#include "smg.h"

int main(){
	SysTick_Init(72);
	LED_Init();
	Smg_Init();
	uint8_t smgbuf[8];
	while(1){
		for(uint8_t i=0;i<8;i++)
			smgbuf[i]=gsmg_code[i];
		SMG_Dispaly(smgbuf,0);
		delay_ms(1);
	}
}
