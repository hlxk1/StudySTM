#include "step_motor.h"

void STEP_MOTOR_Init()
{
	// �ṹ�嶨��
	GPIO_InitTypeDef GPIO_InitStruct;
	// ����ʱ��GPIO�ҽӵ�ʱ��
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

void Step_Motor_Run_8Step(u8 dir,u8 speed,u8 stat)//dir==0˳ʱ�� speedֻ����5-10ms statΪʹ�ܵ��0or1
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
void Step_Motor_Run_4Or8Step(u8 step,u8 dir,u8 speed,u8 stat)//step������4��8
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
�� �� : step��ָ���������ƽ��ģ���ѡֵ 4 �� 8
			dir������ѡ��,1��˳ʱ��,0����ʱ��
			speed���ٶ� 1-5
			angle���Ƕ�ѡ�� 0-360
			sta���������״̬��1 ������0 ֹͣ
*/
void Step_Motor_Run(u8 step,u8 dir,u8 speed,u16 angle,u8 sta)
{
	char i=0;
	u16 j=0;
	if(sta==1)
	{
		if(dir==0) //���Ϊ��ʱ����ת
			{
			for(j=0;j<64*angle/45;j++)
			{
				for(i=0;i<8;i+=(8/step))
				{
					switch(i)//8 �����Ŀ��ƣ�A->AB->B->BC->C->CD->D->DA
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
		else//���Ϊ˳ʱ����ת
		{
			for(j=0;j<64*angle/45;j++)
			{
				for(i=0;i<8;i+=(8/step))
				{
					switch(i)//8 �����Ŀ��ƣ�A->AB->B->BC->C->CD->D->DA
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