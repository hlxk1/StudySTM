# 数码管SMG

![image-20241124164806729](.\img\image-20241124164806729.png)

```
数码管是一种半导体发光器件，其基本单元是发光二极管。数码管也称 LED数码管数码管按段数可分为七段数码管和八段数码管，八段数码管比七段数码管多一个发光二极管单元，也就是多一个小数点（DP）这个小数点可以更精确的表示数码管想要显示的内容；按能显示多少个（8）可分为 1 位、 2 位、 3 位、 4 位、 5 位、6 位、7 位等数码管。
```

###### a.共阳数码管

```
共阳数码管是指将所有发光二极管的阳极接到一起形成公共阳极(COM)的数码管，共阳数码管在应用时应将公共极 COM 接到电源正极，当某一字段发光二极管的阴极为低电平时，相应字段就点亮，当某一字段的阴极为高电平时，相应字段就不亮。
```

###### b.共阴数码管

```
共阴数码管是指将所有发光二极管的阴极接到一起形成公共阴极(COM)的数码管，共阴数码管在应用时应将公共极 COM 接到地线 GND 上，当某一字段发光二极管的阳极为高电平时，相应字段就点亮，当某一字段的阳极为低电平时，相应字段就不亮。
```

### 一、数码管显示原理

![image-20241124171603445](.\img\image-20241124171603445.png)

```
从上图可看出，一位数码管的引脚是 10 个，显示一个 8 字需要 7 个小段，另外还有一个小数点，所以其内部一共有 8 个小的发光二极管，最后还有一个公共端，多数生产商为了封装统一，单位数码管都封装 10 个引脚，其中第 3 和第 8 引脚是连接在一起的。而它们的公共端又可分为共阳极和共阴极，图中间为共阳极内部原理图，右图为共阴极内部原理图。	
```

​	对**共阴极数码**来说，其 8 个发光二极管的阴极在数码管内部全部连接在一起，所以称“共阴”，而它们的阳极是独立的，通常在设计电路时一般把阴极接地。当我们给数码管的任意一个阳极加一个高电平时，对应的这个发光二极管就点亮了。如果想要显示出一个 8 字，并且把右下角的小数点也点亮的话，可以给 8个阳极全部送高电平，如果想让它显示出一个 0 字，那么我们可以除了第“g,dp” 这两位送低电平外，其余引脚全部都送高电平，这样它就显示出 0 字了。如果使用共阴数码管，需要**注意增加单片机 IO 口驱动电流**，因为**共阴数码管是要靠单片机 IO 口输出电流来点亮的**，但单片机 I/O 口难以输出稳定的、如此大的电流，所以数码管与单片机连接时需要加驱动电路，可以用上拉电阻的方法或使用专门的数码管驱动芯片，比如 74HC573、74HC245 等，其输出电流较大，电路接口简单。

​	**共阳极数码**管其内部 8 个发光二极管的所有阳极全部连接在一起，电路连接时，公共端接高电平，因此我们要点亮哪个发光管二极管就需要给阴极送低电平，此时显示数字的编码与共阴极编码是相反的关系，数码管内部发光二极管点亮时，也需要 5mA 以上的电流，而且电流不可过大，否则会烧坏发光二极管。因此不仅要防止数码管电流过大，同时要防止流经数码管的电流集中到单片机时电流不能过大，否则会损坏主芯片。**一般共阳极数码管更为常用**，为什么呢？ 这是因为数码管的非公共端往往接在 IC 芯片的 I/O 上，而 IC 芯片的驱动能力往往是比较小的，**如果采用共阴极数码管，它的驱动端在非公共端， 就有可能受限于 IC 芯片输出电流不够而显示昏暗**，要外加上拉电阻或者是增加三极管加大驱动能力。但是 IC 芯片的灌电流，即输入电流范围比较大。所以使用共阳极数码管的好处是：**将驱动数码管的工作交到公共端（一般接驱动电源），加大驱动电源的功率自然要比加大 IC 芯片 I/O口的驱动电流简单许多**。另一方面，这样也能减轻主芯片的负担。

##### 数码管LED图

##### ![image-20241124173608480](.\img\image-20241124173608480.png)

从**右往左是由高到低**，所以

##### a.共阴极数码管表

![image-20241124173340433](.\img\image-20241124173340433.png)

###### b.共阳极数码管表

![image-20241124173505019](.\img\image-20241124173505019.png)

```
从上述共阳和共阴码表中不难发现，它们的数据正好是相互取反的值。比如共阴数码管数字 0 段码：0x3f，其二进制是：0011 1111，取反后为：1100 0000，转换成 16 进制即为 0XC0。
```

### 二、74HC245和74HC138芯片

#### 1. 74HC245芯片

![image-20241124191648380](.\img\image-20241124191648380.png)

![image-20241124191709905](.\img\image-20241124191709905.png)

```

```

![image-20241124191724007](.\img\image-20241124191724007.png)

```
真值表中：L表示低电平，H表示高电平，X是无论为什么电平

```

①采用 CMOS 工艺
②宽电压工作范围：3.0V-5.0V
③双向三态输出(高电平，低电平，高阻态)
④八线双向收发器
⑤封装形式：SOP20、SOP20-2、TSSOP20、DIP20

```
	从上面的管脚功能定义说明及真值表可以知道该芯片使用方法很简单，给 OE使能管脚低电平，DIR 管脚为高电平传输方向是 A->B 输出，DIR 为低电平传输方向是 B->A，至于输出高电平还是输出低电平取决于输入端的状态，如果输入为低电平，输出即为低；输入为高电平，输出即为高。如果 OE 使能管脚为高电平，不论 DIR 管脚是高还是低，输出是高组态。
	通常我们使用 74HC245 芯片用作驱动只会让其在一个方向输出，即 DIR 管脚为高电平，传输方向是 A->B。
```



#### 2. 74HC138芯片

又叫38译码器

![image-20241124192542972](.\img\image-20241124192542972.png)

![image-20241124192557878](.\img\image-20241124192557878.png)

![image-20241124192632636](.\img\image-20241124192632636.png)

①采用 CMOS 工艺

②低功耗

③工作电压：3.0V-5.0V

④封装形式：SOP16

```
从上面的管脚功能定义说明及真值表可以知道该芯片使用方法很简单，给E1、E2 使能管脚低电平，E3 管脚为高电平，至于哪个管脚输出有效电平（低电平），要看 A0，A1，A2 输入管脚的电平状态。如果 A0，A1，A2 都为低电平，则Y0 输出有效电平（低电平），其他管脚均输出高电平。如果 A0 为高电平，A1，A2 都为低电平，则 Y1 输出有效电平（低电平），其他管脚均输出高电平。其他几种输出大家可以对照真值表查看。如果 E1、E2 使能管脚任意一个为高电平或者 E3 为低电平，不论输入是什么，输出都为高电平。
```

**这里给大家总结一个方法：A0、A1、A2 输入就相当于 3 位 2 进制数，A0 是低位，A1 是次高位，A2 是高位。而 Y0-Y7 具体哪一个输出有效电平，就看输入二进制对应的十进制数值。比如输入是 101（A2，A1，A0），其对应的十进制数是 5，所以 Y5 输出有效电平（低电平）。**

### 三、硬件设计

![image-20241124195432746](.\img\image-20241124195432746.png)

上图电路使用的是 2 个四位一体的共阴数码管组成，即 8 位数码管的段选数据 a-dp 全部并联一起引出，每位数码管的位选即公共端引出。数码管的段选 a-dp连接在 74HC245 驱动芯片输出口，由 PA0-PA7 引脚控制。由 PB5、PB4、PB3 管脚控制 74HC138 译码器输入从而控制数码管位选。

```
通74HC245芯片的引脚来控制数码管输出的高低电平，来显示不同数字
```

```
通过控制38译码器的输入引脚ABC即LSA，LSB,LSC,来控制对应当数码管COM的选择其Y输出口输出有效低电平
如：38译码器三个引脚A B C都输入高电平时，使Y7输出低电平有效，使数码管COM8有效，单个数码管都无效
```

```
通过间隔一段肉眼不感知的时间，让COM7也有效，使第二个数码管也亮，接着同理，使所有管都有效一回
```

注意：每显示完一个数码管，都要使74HC245芯片输入端至全0，把数据都清掉，防止出现余晖现象，就是残影类似的东西

### 四、软件设计

![image-20241124204641457](.\img\image-20241124204641457.png)

SMG_Init 函数为数码管初始化功能，主要实现对数码管使用的 IO 时钟进行配置，由于位选控制管脚在 PB3 和 PB4，而这两个引脚初始为 JTAG 功能，要使其作为 IO 口使用，需要关闭 JTAG 功能，因此使能 AFIO 端口时钟，调用GPIO_PinRemapConfig 函数关闭 JTAG 功能。

这样就能作为普通io口作用了

#### smg.h

```
#ifndef _SMG_H
#define _SMG_H

#include "system.h"
#include "systick.h"

#define LSA_PORT GPIOB
#define LSA_PIN GPIO_Pin_5
#define LSA_PORT_RCC RCC_APB2Periph_GPIOB

#define LSB_PORT GPIOB
#define LSB_PIN GPIO_Pin_4
#define LSB_PORT_RCC RCC_APB2Periph_GPIOB

#define LSC_PORT GPIOB
#define LSC_PIN GPIO_Pin_3
#define LSC_PORT_RCC RCC_APB2Periph_GPIOB

#define SMG_A_DP_PORT GPIOA
#define SMG_A_DP_PIN GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
#define SMG_A_DP_PORT_RCC RCC_APB2Periph_GPIOB

#define LSA PBout(5)
#define LSB PBout(4)
#define LSC PBout(3)

extern uint8_t gsmg_code[17];

void Smg_Init(void);
void SMG_Dispaly(u8 dat[],u8 pos);
void SMG_Write_Data(u16 GPIO_Pin,u8 data);
	
#endif

```



#### smg.c

```
#include "smg.h"

//共阴极数码管显示 0~F 的段码数据 0-9 A-F
uint8_t gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void Smg_Init()
{
		// 结构体定义
	GPIO_InitTypeDef GPIO_InitStruct;
	// 开启时钟GPIO挂接的时钟
	RCC_APB2PeriphClockCmd(LSA_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(LSB_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(LSC_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(SMG_A_DP_PORT_RCC, ENABLE);
	// 开启复用，才能配置重映射关闭两个功能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	// 重映射
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=LSA_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LSA_PORT, &GPIO_InitStruct);


	GPIO_InitStruct.GPIO_Pin=LSB_PIN;
	GPIO_Init(LSB_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=LSC_PIN;
	GPIO_Init(LSC_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin=SMG_A_DP_PIN;
	GPIO_Init(SMG_A_DP_PORT, &GPIO_InitStruct);
	
	
}


```

```
void SMG_Write_Data(u16 GPIO_Pin,u8 data)
{
    u8 i,j=GPIO_Pin;
    for(i=0;i<8;i++)
    {
        if(data&0x01)
        	GPIO_WriteBit(SMG_A_DP_PORT, j<<i ,Bit_SET);
        else
        	GPIO_WriteBit(SMG_A_DP_PORT, j<<i ,Bit_RESET);
        data = data >> 1 ;
    }
}
/* 
这个函数和LED跑马灯的函数除了名字不一样可能还有端口不一样，其他都一样，
传入引脚从第GPIO_Pin_0开始,dat[0-7],
*/
```

```
void SMG_Dispaly(u8 dat[],u8 pos)
{
	uint8_t i=0;
	// pos从第几个数码管开始，比如只显示最后两个的数码管就是6
	uint8_t pos_temp=pos;
	for(i=pos_temp;i<8;i++)
	{
		switch(i)
		{
			case 0:LSA=1;LSB=1;LSC=1;break;
			case 1:LSA=0;LSB=1;LSC=1;break;
			case 2:LSA=1;LSB=0;LSC=1;break;
			case 3:LSA=0;LSB=0;LSC=1;break;
			case 4:LSA=1;LSB=1;LSC=0;break;
			case 5:LSA=0;LSB=1;LSC=0;break;
			case 6:LSA=1;LSB=0;LSC=0;break;
			case 7:LSA=0;LSB=0;LSC=0;break;
		}
		SMG_Write_Data(GPIO_Pin_0,dat[i-pos_temp]);
		delay_ms(1);//保证肉眼察觉不到
		SMG_Write_Data(GPIO_Pin_0,0x00);// 消隐
	}
}
/* 
比如传入的是索引是数码管显示0-7的地址的数组，位置是从第0个数码管开始显示
i:用来得知是轮到哪个数码管
switch作用是轮流开启对应COMx的显示，从第一个数码管开始显示
dat[i-pos_temp]：pos_temp=0,则在循环中传入dat[0-7]


*/
```



#### main.c

```
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

```

首先目的是让数码管模块从左往右显示0-7，所以传入的是数组gsmg_code的只有0-7的索引的值，并且是从第一个即0数码管开始**SMG_Dispaly(smgbuf,0);**