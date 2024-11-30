# PWM 脉冲宽度调制

它是利用微处理器的数字输出来对模拟电路进行控制的一种非常有效的技术，其控制简单、灵活和动态响应好等优点而成为电力电子技术最广泛应用的控制方式，其应用领域包括测量，通信，功率控制与变换，电动机控制、伺服控制、调光、开关电源，甚至某些音频放大器

![image-20241130204507919](.\img\image-20241130204507919.png)

从图中可以看到，上图 a 是一个正弦波即模拟信号，b 是一个数字脉冲波形即数字信号。我们知道在计算机系统中只能识别是 1 和 0，对于 STM32F1 芯片，要么输出高电平（3.3V），要么输出低电平（0），假如要输出 1.5V 的电压，那么就必须通过相应的处理，比如本章所要讲解的 PWM 输出，其实从上图也可以看到，只要保证数字信号脉宽足够就可以使用 PWM 进行编码，从而输出 1.5V 的电压。

**高电平所占比例**

STM32F1 除了基本定时器 TIM6 和 TIM7，其他定时器都可以产生 PWM 输出。其中高级定时器 TIM1 和 TIM8 可以同时产生多达 7 路的 PWM 输出。而通用定时器也能同时产生多达 4 路的 PWM 输出

PWM 的输出其实就是对外输出脉宽可调（即占空比调节）的方波信号，信号频率是由自动重装寄存器 ARR 的值决定，占空比由比较寄存器 CCR 的值决定。其示意图如下图所示：

![image-20241130205341067](.\img\image-20241130205341067.png)

从图中可以看到，PWM 输出频率是不变的，改变的是 CCR 寄存器内的值，此值的改变将导致 PWM 输出信号**占空比**的改变。**占空比其实就是一个周期内高电平时间与周期的比值。**

PWM 输出比较模式总共有 8 种，具体由寄存器 CCMRx 的位 OCxM[2:0]配置。我们这里只讲解最常用的两种 PWM 输出模式：PWM1 和 PWM2，其他几种模式可以参考《STM32F10x 中文参考手册》13、14 定时器章节。

PWM1 和 PWM2 这两种模式用法差不多，区别之处就是输出电平的极性不同。

![PWM 输出比较模式](.\img\image-20241130205519273.png)

PWM 模式根据计数器 CNT 计数方式，可分为边沿对齐模式和中心对齐模式。

##### **（1）PWM 边沿对齐模式**

当 TIMx_CR1 寄存器中的 DIR 位为低时执行递增计数，计数器 CNT 从 0 计数到自动重载值（TIMx_ARR 寄存器的内容），然后重新从 0 开始计数并生成计数器上溢事件。

以 PWM 模式 1 为例。只要 **TIMx_CNT < TIMx_CCRx， PWM 参考信号 OCxREF便为有效的高电平，否则为无效的低电平**。如果 TIMx_CCRx 中的比较值大于自动重载值（TIMx_ARR 中），则 OCxREF 保持为“ 1”。如果比较值为 0，则 OCxREF保持为“ 0”。如下图所示：

![image-20241130205641102](.\img\image-20241130205641102.png)

当 TIMx_CR1 寄存器中的 DIR 位为高时执行递减计数，计数器 CNT 从自动重载值（TIMx_ARR 寄存器的内容）递减计数到 0，然后重新从 TIMx_ARR 值开始计数并生成计数器下溢事件。以 PWM 模式 1 为例。只要 TIMx_CNT >TIMx_CCRx， PWM 参考信号 OCxREF便为无效的低电平，否则为有效的高电平。如果 TIMx_CCRx 中的比较值大于自动重载值（TIMx_ARR 中），则 OCxREF 保持为“ 1”。此模式下不能产生 0%的PWM 波形。

##### **（2）PWM 中心对齐模式**

在中心对齐模式下，计数器 CNT 是工作在递增/递减模式下。开始的时候，计数器 CNT 从 0 开始计数到自动重载值减 1(ARR-1)，生成计数器上溢事件；然后从自动重载值开始向下计数到 1 并生成计数器下溢事件。之后从 0 开始重新计数。如下图所示：

![image-20241130205659111](.\img\image-20241130205659111.png)

我们以 ARR=8，CCRx=4 为例进行介绍。

第一阶段计数器 CNT 工作在递增计数方式，从 0 开始计数，当 **TIMx_CNT < TIMx_CCRx 时，PWM 参考信号 OCxREF 为有效的高电平，当 TIMx_CNT >= TIMx_CCRx 时，PWM 参考信号 OCxREF 为无效的低电平。**

第二阶段计数器 CNT 工作在递减计数方式，从 ARR 开始递减计数，当TIMx_CNT > TIMx_CCRx 时，PWM 参考信号 OCxREF 为无效的低电平，当 TIMx_CNT<= TIMx_CCRx 时，PWM 参考信号 OCxREF 为有效的高电平。

中心对齐模式又分为中心对齐模式 1/2/3 三种，具体由寄存器 CR1 位CMS[1:0]配置。具体的区别就是比较中断标志位 CCxIF 在何时置 1：中心模式 1在 CNT 递减计数的时候置 1，中心对齐模式 2 在 CNT 递增计数时置 1，中心模式 3 在 CNT 递增和递减计数时都置 1。

### 一、定时器PWM输出配置

#### （1）使能定时器及端口时钟，并设置引脚复用器映射

```
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//使能 TIM3 时钟
```

而 TIM3 的 CH2 通道对应的管脚是 PA7，正好对应底板 LED 模块的 D8 指示灯。假如 LED 灯并没有接在 PA7 引脚上，如果要让这个通道映射到 LED 所接的 IO 口上，则需要使用 GPIO 的复用功能重映射，

![image-20241130214201541](.\img\image-20241130214201541.png)

LED 模块的 D8 就是连接在 PA7 口的，所以可以无需重映射即可在 PA7 输出PWM。如果使用到重映射功能，需要开启 AFIO 时钟，所以开启 AFIO 时钟函数如

```
RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
```

最后还要记得将 PA7 管脚模式配置为复用推挽输出

```
GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//复用推挽输出
```

#### **（2）初始化定时器参数,包含自动重装值，分频系数，计数方式等**

```
voidTIM_TimeBaseInit(TIM_TypeDef*TIMx,TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
```

#### **（3）初始化 PWM 输出参数，包含 PWM 模式、输出极性、使能等**

```
void TIM_OCxInit(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
```

这里我们就讲解下比较常用的 PWM 模式所需的成员变量：**TIM_OCMode：**比较输出模式选择，总共有 8 种，最常用的是 PWM1 和 PWM2。

**TIM_OutputState：**比较输出使能，用来使能 PWM 输出到 IO 口。

**TIM_OCPolarity：**输出极性，用来设定输出通道电平的极性，是高电平还是低电平。

结构体内其他的成员变量 **TIM_OutputNState**，**TIM_OCNPolarity**，**TIM_OCIdleState** 和 **TIM_OCNIdleState** 是高级定时器才用到的。如大家使用到高级定时器，可以查看中文参考手册高级定时器章节。

#### **（4）开启定时器**一般再配置完最后放置

```
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);
```

#### **（5）修改 TIMx_CCRx 的值控制占空比**

```
void TIM_SetCompare2(TIM_TypeDef* TIMx, uint32_t Compare1);
```

#### **（6）使能 TIMx 在 CCRx 上的预装载寄存器**

```
void TIM_OCxPreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
```

**影子寄存器使能**，需要中途修改其预装载值时再配置

#### **（7）使能 TIMx 在 ARR 上的预装载寄存器允许位**

```
void TIM_ARRPreloadConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
```

虽然高级定时器和通用定时器类似，但是高级定时器要想输出 PWM 波形，必须要设置一个 MOE 位(TIMx_BDTR 的第 15 位)，以使能主输出，否则不会输出 PWM。库函数设置的函数为：

```
void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);
```

### 二、硬件设计

```
只使用到开发板上的 LED（D8），因为 D8 指示灯正好接在 PA7 管脚，而此管脚具有 TIM3_CH2 复用功能。所以可以通过 TIM3 的 CH2输出 PWM 信号，实现呼吸灯效果。
```

### 三、软件设计

#### mian.c

TIM3_CH2_PWM_Init(500,72-1);调用配置好的PWM函数，计数器500次，1MHz,即没1us计数一次，计数500us

TIM_SetCompare2使用了设置通道2占空比的函数，通过变量j递增来改变占空比到某值时递减，要小于500

```
#include "system.h"
#include "led.h"
#include "systick.h"
#include "pwm.h"

int main(){
	u8 i=0;
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	LED_Init();
	TIM3_CH2_PWM_Init(500,72-1);
	u16 j=0;
	u8 fx=0;
	while(1){
		if(fx==0){
			j++;
			if(j>=300)fx=1;
		}else{
			j--;
			if(j==0)fx=0;
		}
		TIM_SetCompare2(TIM3,j);//设置频道2的占空比值
		i++;
		if(i%10==0)
			LED0=!LED0;
		delay_ms(10);
	}
}

```

#### PWM.c

```
#include "pwm.h"

void TIM3_CH2_PWM_Init(uint16_t per,uint16_t psc)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_OCInitTypeDef TIM_OCInitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period=per;
	TIM_TimeBaseInitStruct.TIM_Prescaler=psc;
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;//不分频
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	
	TIM_OCInitStruct.TIM_OCMode=TIM_OCMode_PWM1; // 输出模式
	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable; 
	TIM_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_Low;// 低极性
	TIM_OC2Init(TIM3,&TIM_OCInitStruct);
	
	TIM_ARRPreloadConfig(TIM3,ENABLE);
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
	
	TIM_Cmd(TIM3,ENABLE);
	
}

```

#### PWM.h

```
#ifndef _PWM_H
#define _PWM_H

#include "system.h"
#include "led.h"

void TIM3_CH2_PWM_Init(uint16_t per,uint16_t psc);

#endif

```

