#include "step_motor.h"

void STEP_MOTOR_Init()
{
	// 结构体定义
	GPIO_InitTypeDef GPIO_InitStruct;
	// 开启时钟GPIO挂接的时钟
	RCC_APB2PeriphClockCmd(MOTOR_IN1_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(MOTOR_IN2_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(MOTOR_IN3_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(MOTOR_IN4_PORT_RCC, ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=MOTOR_IN1_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(MOTOR_IN1_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=MOTOR_IN2_PIN;
	GPIO_Init(MOTOR_IN2_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=MOTOR_IN3_PIN;
	GPIO_Init(MOTOR_IN3_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=MOTOR_IN4_PIN;
	GPIO_Init(MOTOR_IN4_PORT, &GPIO_InitStruct);
	
}

void Step_Motor_Run_8Step(u8 dir,u8 speed,u8 stat)//dir==0顺时针 speed只能是5-10ms stat为使能电机0or1
{
	u8 i=0;
	int8_t j=7;
	if(stat==1){
		if(dir==0){
			for(i=0;i<8;i++){
				switch(i)
				{
					case 0:MOTOR_IN1=1;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=0;break;
					case 1:MOTOR_IN1=1;MOTOR_IN2=1;MOTOR_IN3=0;MOTOR_IN4=0;break;
					case 2:MOTOR_IN1=0;MOTOR_IN2=1;MOTOR_IN3=0;MOTOR_IN4=0;break;
					case 3:MOTOR_IN1=0;MOTOR_IN2=1;MOTOR_IN3=1;MOTOR_IN4=0;break;
					case 4:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=1;MOTOR_IN4=0;break;
					case 5:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=1;MOTOR_IN4=1;break;
					case 6:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=1;break;
					case 7:MOTOR_IN1=1;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=1;break;
				}
				delay_ms(speed);
			}	
		}else{
			for(j=0;j>=0;j--){
				switch(i)
				{
					case 0:MOTOR_IN1=1;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=0;break;
					case 1:MOTOR_IN1=1;MOTOR_IN2=1;MOTOR_IN3=0;MOTOR_IN4=0;break;
					case 2:MOTOR_IN1=0;MOTOR_IN2=1;MOTOR_IN3=0;MOTOR_IN4=0;break;
					case 3:MOTOR_IN1=0;MOTOR_IN2=1;MOTOR_IN3=1;MOTOR_IN4=0;break;
					case 4:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=1;MOTOR_IN4=0;break;
					case 5:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=1;MOTOR_IN4=1;break;
					case 6:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=1;break;
					case 7:MOTOR_IN1=1;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=1;break;
				}
				delay_ms(speed);
			}			
		}
	
	}else{
		MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=0;
	}
}
void Step_Motor_Run_4Or8Step(u8 step,u8 dir,u8 speed,u8 stat)//step代表几步4或8
{
	u8 i=0;
	int8_t j=7;
	if(stat==1){
		if(dir==0){
			for(i=0;i<8;i+=(8/step)){
				switch(i)
				{
					case 0:MOTOR_IN1=1;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=0;break;
					case 1:MOTOR_IN1=1;MOTOR_IN2=1;MOTOR_IN3=0;MOTOR_IN4=0;break;
					case 2:MOTOR_IN1=0;MOTOR_IN2=1;MOTOR_IN3=0;MOTOR_IN4=0;break;
					case 3:MOTOR_IN1=0;MOTOR_IN2=1;MOTOR_IN3=1;MOTOR_IN4=0;break;
					case 4:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=1;MOTOR_IN4=0;break;
					case 5:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=1;MOTOR_IN4=1;break;
					case 6:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=1;break;
					case 7:MOTOR_IN1=1;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=1;break;
				}
				delay_ms(speed);
			}	
		}else{
			for(j=0;j>=0;j-=(8/step)){
				switch(i)
				{
					case 0:MOTOR_IN1=1;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=0;break;
					case 1:MOTOR_IN1=1;MOTOR_IN2=1;MOTOR_IN3=0;MOTOR_IN4=0;break;
					case 2:MOTOR_IN1=0;MOTOR_IN2=1;MOTOR_IN3=0;MOTOR_IN4=0;break;
					case 3:MOTOR_IN1=0;MOTOR_IN2=1;MOTOR_IN3=1;MOTOR_IN4=0;break;
					case 4:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=1;MOTOR_IN4=0;break;
					case 5:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=1;MOTOR_IN4=1;break;
					case 6:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=1;break;
					case 7:MOTOR_IN1=1;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=1;break;
				}
				delay_ms(speed);
			}			
		}	
	
	}else{
		MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=0;
	}
}

/*
输 入 : step：指定步进控制节拍，可选值 4 或 8
			dir：方向选择,1：顺时针,0：逆时针
			speed：速度 1-5
			angle：角度选择 0-360
			sta：电机运行状态，1 启动，0 停止
*/
void Step_Motor_Run(u8 step,u8 dir,u8 speed,u16 angle,u8 sta)
{
	char i=0;
	u16 j=0;
	if(sta==1)
	{
		if(dir==0) //如果为逆时针旋转
			{
			for(j=0;j<64*angle/45;j++)
			{
				for(i=0;i<8;i+=(8/step))
				{
					switch(i)//8 个节拍控制：A->AB->B->BC->C->CD->D->DA
					{
						case 0:MOTOR_IN1=1;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=0;break;
						case 1:MOTOR_IN1=1;MOTOR_IN2=1;MOTOR_IN3=0;MOTOR_IN4=0;break;
						case 2:MOTOR_IN1=0;MOTOR_IN2=1;MOTOR_IN3=0;MOTOR_IN4=0;break;
						case 3:MOTOR_IN1=0;MOTOR_IN2=1;MOTOR_IN3=1;MOTOR_IN4=0;break;
						case 4:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=1;MOTOR_IN4=0;break;
						case 5:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=1;MOTOR_IN4=1;break;
						case 6:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=1;break;
						case 7:MOTOR_IN1=1;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=1;break;
					}
					delay_ms(speed);
				}
			}
		}
		else//如果为顺时针旋转
		{
			for(j=0;j<64*angle/45;j++)
			{
				for(i=0;i<8;i+=(8/step))
				{
					switch(i)//8 个节拍控制：A->AB->B->BC->C->CD->D->DA
					{
						case 0:MOTOR_IN1=1;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=1;break;
						case 1:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=1;break;
						case 2:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=1;MOTOR_IN4=1;break;
						case 3:MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=1;MOTOR_IN4=0;break;
						case 4:MOTOR_IN1=0;MOTOR_IN2=1;MOTOR_IN3=1;MOTOR_IN4=0;break;
						case 5:MOTOR_IN1=0;MOTOR_IN2=1;MOTOR_IN3=0;MOTOR_IN4=0;break;
						case 6:MOTOR_IN1=1;MOTOR_IN2=1;MOTOR_IN3=0;MOTOR_IN4=0;break;
						case 7:MOTOR_IN1=1;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=0;break;
					}
					delay_ms(speed);
				}
			}
		}
	}else
	{
		MOTOR_IN1=0;MOTOR_IN2=0;MOTOR_IN3=0;MOTOR_IN4=0;
	}
}