#include "system.h"
#include "led.h"
#include "systick.h"
#include "beep.h"
#include "smg.h"
#include "key.h"
#include "dc_motor.h"
#include "step_motor.h"

int main(){
    SysTick_Init(72);
    KEY_Init();
    LED_Init();
    DC_MOTOR_Init();
    u8 i=0;
    u8 key=0;
    u8 run=0;
    u8 dir=0;
    u8 speed=0;
    while(1){
        key=KEY_Scan();
        if(key==KEY1_Press){
            run=!run;
        }else if(key==KEY2_Press){
            dir=!dir;
        }else if(key==KEY3_Press){
            if(speed>5){
                speed=0;
            }
            speed++;
        }
        Step_Motor_Run(8,dir,speed,360,run);
    }
}
