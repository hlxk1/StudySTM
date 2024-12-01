# STM32待机模式

很多单片机具有低功耗模式，比如 MSP430、STM8L 等，我们的 STM32 也不例外。默认情况下，系统复位或上电复位后，微控制器进入运行模式。在运行模式下，HCLK 为 CPU 提供时钟，并执行程序代码。当 CPU 不需继续运行（例如等待外部事件）时，可以利用多种低功耗模式来节省功耗。用户需要根据最低电源消耗、最快速启动时间和可用的唤醒源等条件，选定一个最佳的低功耗模式。

当然在运行模式下，也可以通过如下方式降低功耗：

①降低系统时钟速度

②不使用 APBx 和 AHB 外设时，将对应的外设时钟关闭

STM32 提供了 3 种低功耗模式，以达到不同层次的降低功耗的目的，这三种模式如下：

①睡眠模式（CM3 内核停止工作，外设仍在运行）

②停止模式（所有时钟都停止）

③待机模式（1.8V 内核电源关闭）

这三种模式所需的功耗是逐级递减，也就是说待机模式功耗是最低的。三种低功耗模式汇总表如下图所示：

![image-20241201212528532](.\img\image-20241201212528532.png)

**（1）待机模式**

在**睡眠模式**中，仅关闭了内核时钟，内核停止运行，但其片上外设， CM3 核心的外设全都照常运行。在**停止模式**中，进一步关闭了其它所有的时钟，于是所有的外设都停止了工作，但由于其 1.8V 区域的部分电源没有关闭，还保留了内核的寄存器、内存的信息，所以从停止模式唤醒，并重新开启时钟后，还可以从上次停止处继续执行代码。在**待机模式**中，它除了关闭所有的时钟，还把 1.8V 区域的电源也完全关闭了，也就是说，从待机模式唤醒后，由于没有之前代码的运行记录，只能对芯片复位，重新检测 BOOT 条件，从头开始执行程序

![image-20241201213325619](.\img\image-20241201213325619.png)

退出待机模式的操作，当检测到外部复位（NRST 引脚）、 IWDG复位、 WKUP 引脚上升沿、 RTC 闹钟事件的上升沿时，微控制器退出待机模式。本章我们是**通过 WKUP 引脚（PA0）上升沿来退出待机模式**，当然也可以直接通过芯片复位管脚 NRST 退出。

**从待机模式唤醒后**，除了电源控制/状态寄存器(PWR_CSR)，所有的寄存器豆被复位，程序将按照复位（启动引脚采样、复位向量已获取等）后的方式重新执行。电源控制/状态寄存器(PWR_CSR)将会指示内核由待机状态退出。

**在进入待机模式后**，除了复位引脚以及被设置为防侵入或校准输出时的TAMPER （PC13）引脚和被使能的唤醒引脚（ WK_UP 脚（PA0）），其他的 IO 引脚都将处于高阻态。

## Ⅰ、**待机模式配置步骤**

电源管理相关库函数在 stm32f10x_pwr.c和 stm32f10x_pwr.h 文件中

#### **（1）使能电源时钟**

```
RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);//使能 PWR 外设时钟
```

#### **（2）设置 WK_UP 引脚为唤醒源**

待机唤醒方式有很多种，我们选择 WK_UP 引脚（PA0）上升沿来退出待机

```
PWR_WakeUpPinCmd(ENABLE);
```

可以使用一根导线将 PA0 引脚和电源 3.3V 来退出待机模式。

#### **（3）进入待机模式**

进入待机模式，首先要设置 SLEEPDEEP 位详见《 Cortex M3 权威指南(中文)》，chpt13 Cortex-M3 的其它特性--电源管理章节接着我们通过 PWR_CR设置 PDDS 位，使得 CPU 进入深度睡眠时进入待机模式，最后执行 WFI 指令开始进入待机模式，并等待 WK_UP 中断的到来。整个操作可以通过一个库函数完成，如下：

```
PWR_EnterSTANDBYMode();//进入待机模式
```

通常在进入待机模式前，我们会清除唤醒标志，以等待下次进入。

```
PWR_ClearFlag(PWR_FLAG_WU);//清除 Wake-up 标志
```

#### **特别提醒下**

**如果学到 RTC 实时时钟实验的时候，需要进入待机模式，如果使能了 RTC 闹钟中断的时候，进入待机模式前，必须按如下操作处理：**

**1.禁止 RTC 中断（ ALRAIE、 ALRBIE、 WUTIE、 TAMPIE 和 TSIE 等）。**

**2.清零对应中断标志位。**

**3.清除 PWR 唤醒(WUF)标志（通过设置 PWR_CR 的 CWUF 位实现）。**

**4.重新使能 RTC 对应中断。**

**5.进入低功耗模式。**

## Ⅱ、**硬件设计**

（1）LED 指示灯

（2）串口 1

LED 指示灯、串口 1 电路在前面章节都介绍过，这里不多说。LED 指示灯用来提示系统正常运行，使用一根导线将 PA0 引脚和电源 3.3V 触碰一下用来唤醒待机模式，串口 1 用来输出提示信息。

## Ⅲ、**软件设计**

### wakeup.c

```
#include "wakeup.h"

void Enter_Standby_Mode()
{
	RCC_APB1PeriphResetCmd(RCC_APB1Periph_PWR, ENABLE);
	
	PWR_ClearFlag(PWR_FLAG_WU);//清除 Wake-up 标志
	
	PWR_WakeUpPinCmd(ENABLE);
	
	PWR_EnterSTANDBYMode();//进入待机模式
}

```

### main.c

```c
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
#include "wakeup.h"

int main(){
	u8 i=0;
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	USART1_Init(115200);
	LED_Init();
	KEY_Init();
	LED1=0;
	while(1){
		if(KEY_Scan()==KEY1_Press)
		{
			Enter_Standby_Mode();
		}	
		i++;
		if(i%10==0)
			LED0=!LED0;
		delay_ms(10);
		
	}
	
}

```

### wakeup.h

```
#ifndef _WAKEUP_H
#define _WAKEUP_H

#include "system.h"

void Enter_Standby_Mode(void);

#endif

```

