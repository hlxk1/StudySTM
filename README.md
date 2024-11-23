# StudySTM
Study knowledge about STM32

## STM32与ARM的关系

![image-20241109184337399](.\img\image-20241109184337399.png)

ARM公司负责芯片方案设计

ST负责制造芯片

![image-20241109185228634](.\img\image-20241109185228634.png)

STM32f103就属于Cortex—M3

![image-20241109185429564](.\img\image-20241109185429564.png)

STM32拿到ARM设计的内核，STM32基于这个内核添加了自己公司的外设进行打包，封装，生产

![image-20241109185701632](.\img\image-20241109185701632.png)

L:代表低功耗

F1和F4比较主流性价比高

## STM32F103C8T6介绍

![image-20241109185935538](.\img\image-20241109185935538.png)

https://www.stmcu.com.cn/

logo:ST表示由ST公司生产，通常芯片表面还会有一个ARM（内核基于ARM公司设计）

一般芯片上还会有个**圆点针对芯片管脚的顺序（按逆时针）**

------

![image-20241109191021165](.\img\image-20241109191021165.png)

通过这张图（在STM32选型表中）可以看到不同芯片的外设资源数目

------

![image-20241109191250443](.\img\image-20241109191250443.png)

![image-20241109191254519](.\img\image-20241109191254519.png)

这就是STM32F103C8T6的外设资源

------

![image-20241109191523534](.\img\image-20241109191523534.png)

**芯片上型号的规则**

------

## 芯片管脚

![image-20241109192743952](.\img\image-20241109192743952.png)

芯片引脚的功能

![image-20241109192933633](.\img\image-20241109192933633.png)

## STM32能做什么

![image-20241109193015834](.\img\image-20241109193015834.png)

## STM32学习方法

### 1 基本外设

GPIO 输入输出，外部中断，定时器，串口。

### 2 基本外设接口

SPI，IIC，WDG，FSMC，ADC/DAC,SDIO等

### 3 高级功能

RTOS，LWIP，FATFS，GUI，USB等

### 4 提升C语言，多编程，多查找

## STM32最小系统

### STM32 最小系统构成

#### 1 晶振电路

![image-20241109194640166](.\img\image-20241109194640166.png)

下方为主晶振

D2为发光二极管，便于调试提示我们连接到了PC13的管脚

#### 2 复位电路

![image-20241109194650673](.\img\image-20241109194650673.png)

NRST引脚及低电平复位

RST是加上按键

#### 3 电源电路

![image-20241109194813060](.\img\image-20241109194813060.png)

![image-20241109195202471](F:\StudySTM\img\image-20241109195202471.png)

![image-20241109195309819](.\img\image-20241109195309819.png)

稳压芯片将5V电压变为3.3V

#### 4 下载电路

![image-20241109194928506](.\img\image-20241109194928506.png)

只需要两个引脚SWDIO，SWCLK，通过添加供电引脚方便仿真器供电

------

![image-20241109195559799](.\img\image-20241109195559799.png)

![image-20241109195608775](.\img\image-20241109195608775.png)

VDD是电源正极，VSS是电源负极

### STM32启动模式

![image-20241109195830986](.\img\image-20241109195830986.png)

![image-20241109200005470](.\img\image-20241109200005470.png)

类似图中的 BOOT0 标识的叫做**网络标号**

## Keil5软件安装及配置

### 1 Keil5获取

官网：https://www.keil.com/download/product/

![image-20241109203354502](.\img\image-20241109203354502.png)

STM32是基于MDK-Arm下载

下载过程提示你安装一些jlink驱动，可以安装或不安装

### 2 添加STM32的芯片包

![image-20241109203715429](.\img\image-20241109203715429.png)

#### 点击新建项目新建文件验证是否有芯片包

![image-20241109203936522](.\img\image-20241109203936522.png)

![image-20241109204058623](.\img\image-20241109204058623.png)

### 3 破解Keil5

![image-20241109204148719](.\img\image-20241109204148719.png)

破解的注册及软件

![image-20241109204251497](.\img\image-20241109204251497.png)

点击License Management管理

------

![image-20241109204333043](.\img\image-20241109204333043.png)

复制CID

![image-20241109204419133](.\img\image-20241109204419133.png)

将注册机打开选择Target为ARM（如果是51单片机才选择C51）,并把复制好的CID填入

点击Generate，生成的码复制写入 License ID Code

![image-20241109204649868](.\img\image-20241109204649868.png)

### 修改编码风格

![image-20241109205315760](.\img\image-20241109205315760.png)

 

## STM32固件库介绍

### 1 CMSIS标准 

CMSIS是Cortex Microcontroller Software Interface Standard英文首字母缩写，是ARM Cortex微控制器软件接口标准

![image-20241110000504395](.\img\image-20241110000504395.png)







### 2 库目录文件

![image-20241110001628161](.\img\image-20241110001628161.png)

![image-20241110001646512](.\img\image-20241110001646512.png)

![image-20241110001703803](.\img\image-20241110001703803.png)

#### 文件介绍

![image-20241110002011496](.\img\image-20241110002011496.png)

##### 启动文件startup

![image-20241110002049450](.\img\image-20241110002049450.png)

![image-20241110002111752](.\img\image-20241110002111752.png)

根据这个表选择对应的型号的启动文件（看缩写）

### 3 库帮组文档使用

![image-20241119211258746](.\img\image-20241119211258746.png)

对函数功能的了解

## keil5库函数模板创建

### 获取固件库

![image-20241119212021778](.\img\image-20241119212021778.png)

### 工程模板拷贝

![image-20241119212554123](.\img\image-20241119212554123.png)

![image-20241119212858391](.\img\image-20241119212858391.png)

------

CMSIS中的文件有**内核支持文件**core_cm3.c .h,**启动文件**startup_stm32f10x_md.s,**系统时钟文件**

![image-20241119213218147](.\img\image-20241119213218147.png)

![image-20241119213535907](.\img\image-20241119213535907.png)

![image-20241119213909187](.\img\image-20241119213909187.png)

------

user文件夹下

![image-20241119214433707](.\img\image-20241119214433707.png)

![image-20241119214655916](.\img\image-20241119214655916.png)

### 创建工程添加文件

![image-20241119215254608](.\img\image-20241119215254608.png)

![image-20241119215308725](.\img\image-20241119215308725.png)

![image-20241119215322907](.\img\image-20241119215322907.png)

![image-20241119215344260](.\img\image-20241119215344260.png)

在ok后弹出的运行管理（manege run...enviroment）窗口关掉就好了

![image-20241119220034108](.\img\image-20241119220034108.png)

![image-20241119220309679](.\img\image-20241119220309679.png)

------

![image-20241119221007931](.\img\image-20241119221007931.png)

![image-20241119221016446](.\img\image-20241119221016446.png)

在CMSIS肯看不到.s后缀的文件，需要在下面通配符选择所有文件可见

![image-20241119221104379](.\img\image-20241119221104379.png)

这是添加源文件，头文件链接就好不需要添加进来对于外设接口

![image-20241119221143387](.\img\image-20241119221143387.png)

![image-20241119221432708](.\img\image-20241119221432708.png)

#### 最终模板

![image-20241119221631325](.\img\image-20241119221631325.png)

### 工程中参数设置

![image-20241119223443868](.\img\image-20241119223443868.png)

![image-20241119223456616](.\img\image-20241119223456616.png)

![image-20241119223508617](.\img\image-20241119223508617.png)

![image-20241119223518240](F:\StudySTM\img\image-20241119223518240.png)

![image-20241119223529505](.\img\image-20241119223529505.png)

每一步配置好参数点击OK才能应用，然后把复制过来的main.c模板文件清空写自己的文件，一般一个程序都有一个死循环，目的就是能完成一个功能它能一直展现。游戏也是如此

![image-20241119224726350](.\img\image-20241119224726350.png)

------

#### 二、解决编译报错

![image-20241119225238010](.\img\image-20241119225238010.png)

在添加下面这个宏，为的是当使用不是芯片自带的外设不属于它时，需要这个宏才不会报错

![image-20241119230520873](.\img\image-20241119230520873.png)

要在宏里添加个英文分号;来添加第二个宏

![image-20241119230646754](.\img\image-20241119230646754.png)

这样编译器就打开了这些外设

#### 三、关于编译

![image-20241119231133778](.\img\image-20241119231133778.png)

### 启动文件

从复位道开始执行main函数的工作

**开发攻略-库函数模板介绍**中有详解

1.初始化堆栈指针sp

![image-20241119233138508](.\img\image-20241119233138508.png)



2.初始化pc指针，执行对应

3.初始化中断向量表

4.配置系统时钟

## GPIO

是通用输入输出端口简称，通过软件来控制其输入输出

![image-20241119233429651](.\img\image-20241119233429651.png)

这个学习板F103有48个引脚

**1.电源引脚**

带有VSSA，VDDA，VDD，VSS的网络标识符为电源引脚**VSS(电源负极)**，**VDD(电源正极)**

**2.晶振引脚**

OSC32

**3.复位引脚**

NRST,N表示要低电平，RST表示复位

**4.下载引脚**

 SWD

**5.BOOT引脚**



**6.GPIO引脚**

PA，PB,PC,PD

通过芯片手册来查看不同管脚功能

### 一、GPIO结构框图

![image-20241119234510456](.\img\image-20241119234510456.png)

 

------

#### 保护二极管电路

![image-20241119235745429](.\img\image-20241119235745429.png)

保护二极管电路，目的是防止外部过高或过低的电压引入。

**若外部电压过高**，大于VDD_FT或Vdd的时候，上方二极管起到保护作用吸收该高电压

**若外部电压低于Vss时**，下部二极管起到保护作用吸收这个低电压。

防止外部电压不正常导致芯片烧坏。

**但是若连接的是一些大功率器件**的话，比如电机是会烧坏器件的，要在电机和IO引脚之间增加一个驱动电路

------

#### 1.上下拉电路

![image-20241120000420990](.\img\image-20241120000420990.png)

这些开关可通过程序来断开和闭合。

上面闭合，下面断开：**上拉模式**，io引脚为高电平，*其驱动能力较弱，可在外部增加一个上拉电阻*

下面闭合，上面断开：**下拉模式**，io引脚为低电平

都断开：**浮空模式**，引脚电压不确定

------

#### 2.输出驱动

![image-20241120000919005](.\img\image-20241120000919005.png)

##### **推挽输出**：

当输出驱动电路输出高电平1时，P-MOS导通，M-MOS截止，对外输出的是高电平

当输出驱动电路输出低电平0时，P-MOS截止，M-MOS导通，对外输出的是低电平

当切换输出高低电平，那就轮流导通两个MOS，有助于管脚驱动能力提高

##### **开漏输出**：

P-MOS管都是断开的，只有M-MOS有用，

输出低电平M-MOS导通。

输出高电平时M-MOS是不通的，

要输出高电平要在io引脚做一个上拉才能。

**案例：**

要让管脚输出大于3.3V的电平如5V，选择开漏模式，依靠外部上拉电阻接入5V电压。

------

#### 3.寄存器

##### 输出数据寄存器

通过输出数据寄存器中的值改变管脚高低电平的输出

##### 位设置/清楚寄存器

来改变输出数据寄存器的值来到大引脚输出电平改变

##### 片上外设数据寄存器

通过其它外设来改变复用功能输出来改变输出驱动电路的高低电平让管脚电平发生改变

对于复用功能也是一样，对片上外设复用功能输入传到片上外设寄存器

##### 输入数据寄存器

通过io口经过上下拉电阻，经过TTL施密特触发器（将信号转化为0或1）存入到输入数据寄存器，从而读取到管脚接收的电平状态，

------

#### 4.模拟输入

没有经过TTL施密特触发器,得到的使原始信号，通常应用于ADC数据采集。模拟信号转为数字信号

也有DAC功能：是输出模式，输出数字信号

### 二、硬件设计

![image-20241120004035360](.\img\image-20241120004035360.png)

如上图LED灯特性可知，需要一个引脚输出低电平就能实现点亮，所以控制引脚高低电平就能实现开关灯

### 三、点亮第一个LED灯-软件设计

(1)初始化系统时钟，默认配置为72MHz

(2)初始化LED对应的GPIO相关参数，并使能端口时钟

(3)点亮LED灯，操作相应管脚

#### 项目管理

新建一个APP文件夹并在其中创建APP/led/文件夹，为了更好的管理文件项目

![image-20241119220034108](.\img\image-20241119220034108.png)

在这里将APP文件放入工程管理组

![image-20241120230506263](.\img\image-20241120230506263.png)

并通过魔术棒将头文件路径保护在C/C++的include中

#### 通过GPIO库文件来配置GPIO

![image-20241120230733247](.\img\image-20241120230733247.png)

该文件下都是相关GPIO函数，并包含初始化函数

![image-20241120230751802](.\img\image-20241120230751802.png)

初始化函数的参数

![image-20241120230929645](.\img\image-20241120230929645.png)

跳转到每个参数的信息找到对应的进行配置

![image-20241120231129542](.\img\image-20241120231129542.png)

通过全局搜索找到每个结构体成员的值，找到对应进行配置

GPIO_Pin：即引脚，找到对应led引脚

![image-20241120231437661](.\img\image-20241120231437661.png)

GPIO_Speed:输出速度

![image-20241120231523416](.\img\image-20241120231523416.png)

一般选择50MHz

GPIO_Mode:模式

![image-20241120231835929](.\img\image-20241120231835929.png)

控制LED灯用推挽输出即可

------

#### 代码编写



##### 头文件

*存放管脚定义以及函数声明*

宏定义是为了更好的移植和管理

包含宏：端口(GPIOx)，引脚(GPIO_Pin_n)，时钟（）

端口和引脚在gpio.h找，时钟在rcc.h找在文件末尾一般这里的GPIO挂接在APB2总线，

通过RCC_APB2PeriphClockCmd函数对应参数找到要是能的GPIO端口

```c
#ifndef _LED_H
#define _LED_H

#include "stm32f10x.h"

#define LED0_PORT GPIOC // 端口
#define LED0_PIN GPIO_Pin_13 // 引脚
#define LED0_PORT_RCC RCC_APB2Periph_GPIOC //时钟

void LED_Init(void);

#endif

```



##### 源文件.c

*存放驱动函数*

```c
#include "led.h"

void LED_Init(){
	// 结构体定义
	GPIO_InitTypeDef GPIO_InitStruct;
	// 开启时钟GPIO挂接的时钟
	RCC_APB2PeriphClockCmd(LED0_PORT_RCC, ENABLE);
	// GPIO结构体配置
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=LED0_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED0_PORT, &GPIO_InitStruct);
	// 设置高点电平保证灯灭
	GPIO_SetBits(LED0_PORT,LED0_PIN);
	
}

```



##### main.cc

![image-20241121230314827](F:\StudySTM\img\image-20241121230314827.png)

最后从魔术棒设置Debug，Use为CMSIS-DAP Debugger即为仿真器下载

![image-20241121231550561](.\img\image-20241121231550561.png)

![image-20241121232015242](.\img\image-20241121232015242.png)

![image-20241121232112605](.\img\image-20241121232112605.png)

## STM32时钟系统

### 时钟树

![image-20241121231012231](.\img\image-20241121231012231.png)

图中有5种时钟源

H代表高速，L代表低速，E代表外部时钟源，I表示内部时钟源

高速时钟源：HSI,HSE,PLL

低速时钟源：LSE,LSI

#### HSI

8MHz

二分频流入到PLL,也可流入到作为系统时钟输入

#### HSE

4-16MHz,外部高速时钟，通过OSC_OUT和OSC_IN两引脚连接外部晶振，通常连接8MHz

可作为系统时钟，作为PLL输入，或二分频作为PLL时钟输入，或128分频作为作为RTC时钟源

#### LSE

外部低速时钟，连接外部低速晶振32.768KHz

可作为RTC的时钟源

#### LSI

低速内部，

可作为独立看门狗和RTC的时钟源

#### PLL

PLL锁相环，通过PLLMUL锁相环

![image-20241121233214576](.\img\image-20241121233214576.png)

通过PLLSRC选项器选择通过哪个时钟源，再通过倍频器获得增倍的频率，

------

![image-20241121233421665](.\img\image-20241121233421665.png)

通过选项器得到系统时钟，目前最大是72MHz

------

![image-20241121234500451](.\img\image-20241121234500451.png)

MCO为时钟输出引脚，通过选择器选择一个时钟信号输出，给外部外设提供时钟频率来源

------

![image-20241121234713307](.\img\image-20241121234713307.png)

通过PLLCLK提供USB接口时钟来源

------

#### SYSCLK

为系统时钟，通常选择PLLCLK得到高速时钟源作为系统时钟

------

#### AHB分频器

![image-20241121234948020](.\img\image-20241121234948020.png)

通过AHB分频器提供时钟源给各个部分提供时钟

------

若不依靠外部时钟，依靠内部HSI用于PLL时钟的输入时，系统能得到的最大频率时64MHz

用户可通过多个预分频器配置AHB、高速APB(APB2)和低速APB(APB1)域的频率。AHB和APB2域的最大频率是72MHz。APB1域的最大允许频率是36MHz。SDIO接口的时钟频率固定为HCLK/2。RCC通过AHB时钟(HCLK)8分频后作为Cortex系统定时器(SysTick)的外部时钟。通过对SysTick控制与状态寄存器的设置，可选择上述时钟或Cortex(HCLK)时钟作为SysTick时钟。ADC时钟由高速APB2时钟经2、4、6或8分频后获得。

------

### 时钟配置函数

#### 1、时钟初始化配置函数

```
void SystemInit(void)
```

![image-20241121235747580](.\img\image-20241121235747580.png)

#### 2、外设时钟使能配置函数

```
void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState)
void RCC_APB2PeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState)
void RCC_APB1PeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState)
```

![image-20241122000359091](.\img\image-20241122000359091.png)

#### 3、时钟源使能函数

```
void RCC_HSICmd (FunctionalState NewState);
void RCC_LSICmd(FunctionalState NewState);
void RCC_PLLCmd(FunctionalState NewState);
void RCC_RTCCLKCmd(FunctionalState NewState);
```

![image-20241122000256584](.\img\image-20241122000256584.png)

#### 4、时钟源和倍频因子配置函数

就是时钟树中的选择器

```
RCC_HSEConfig (RCC_HSE_ON) ;
RCC_SYSCLKConfig (RCC_SYSCLKSource_HSE) ;
RCC_HCLKConfig (RCC_SYSCLK_Div1) ;
RCC_PCLK1Config(RCC_HCLK_Div2);
RCC_PCLK2Config (RCC_HCLK_Div1) ;
```

![image-20241122000556220]( .\img\image-20241122000556220.png)

#### 5、外设时钟复位函数

```
void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph,FunctionalState NewState)
void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph,FunctionalState NewState)
```

![image-20241122000715698](.\img\image-20241122000715698.png)

------

### 自定义系统时钟

通过软件自定义系统时钟,格式时固定的

第一个参数是设置**时钟来源**，第二个参数是**倍频系数**

```
void RCC_HSE_Config(u32 div,u32 pllm)//自定义系统时间（可以修改时钟)
{
	RCC_DeInit();//将外设RCC寄存器重设为缺省值
	RCC_HSEConfig(RCC_HSE_ON);//设置外部高速晶振（HSE)
	if(RCC_WaitForHSEStartUp()==SUCCESS) //等待HSE起振
	{
		RCC_HCLKConfig(RCC_SYSCLK_Div1);//设置AHB时钟（HCLK)
		RCC_PCLK1Config(RCC_HCLK_Div2);//设置低速AHB时钟（PCLK1）
		RCC_PCLK2Config(RCC_HCLK_Div1);//设置高速AHB时钟（PCLK2）
		RCC_PLLConfig(div,pllm);//设置PLL时钟源及倍频系数
		RCC_PLLCmd(ENABLE);//使能或者失能PLL
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);//检查指定的RCC标志位设置与否,PLL就绪
		RCC_SYSCLKConfig (RCC_SYSCLKSource_PLLCLK);//设置系统时钟 (SYSCLK)
		while(RCC_GetSYSCLKSource()!=0x08);//返回用作系统时钟的时钟源,0x08：PLL作为系统时钟
	}
}
```

#### RCC_PLLConfig(div,pllm);//设置PLL时钟源及倍频系数

![image-20241122221912716](.\img\image-20241122221912716.png)

点击函数跳转到定义

##### div参数设置时钟源

![image-20241122222001827](.\img\image-20241122222001827.png)

找到时钟源函数跳转到定义

通过参数选择分频系数,包含HSI 二分频，HSE一分频，HSE二分频

![image-20241122222105499](.\img\image-20241122222105499.png)

pllm参数设置倍频系数,

![image-20241122222349758](.\img\image-20241122222349758.png)

跳转函数选择倍频系数

![image-20241122222608151](.\img\image-20241122222608151.png)

#### main.c函数

对该函数配置参数，通过改变函数参数即改变系统时钟源的配品系数和时钟来源，延时(通过循环递减延时)LED亮灭闪烁的快慢，可以知道这个函数对系统时钟的有效性

![image-20241122223659916](.\img\image-20241122223659916.png)

## STM32位带操作

为什么要用位带，位带操作允许对单个比特（bit）进行读写，而不是只能对整个字节（Byte）进行操作。在常规的内存访问中，通常是按字节、字（多个字节，如 32 位系统中的 4 字节）等来访问内存。但在支持位带操作的 SRAM 区域中，可以直接对内存中的某一位进行读写。

![image-20241122225115611](.\img\image-20241122225115611.png)

### 位带操作

支持位带操作的区域SRAM**（静态随机存取存储器）**,Peripheral**（外设）**，通过操作**位带别名区**去访问位带区

#### 一、位带区于位带别名区地址转换

上图有地址

1.外设位带别名区地址

```
AliasAddr=0x42000000+（A-0x40000000)*8*4 +n*4
A:位带区的某个地址
0x40000000：位带区起始地址
*4:四个字节
*8:每个字节八位
即放大32倍
n:某一个管脚，代表在A地址的序列号
*4:膨胀四个字节
```

![image-20241122230133911](.\img\image-20241122230133911.png)

2.SRAM位带别名区地址

```
AliasAddr=0x22000000+（A-0x20000000)*8*4 +n*4
同上
```

![image-20241122230242143](.\img\image-20241122230242143.png)

将以上别名区统一为一个公式

```
#define BITBAND(addr,bitnum) (addr &0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
addr:所求的位带区地址
(addr&0xF0000000)+0x2000000:为了区分是外设还是SRAM,因为它们主要是起始4和2区别
(addr &0xFFFFF)<<5):因为最大不会超过0x43FFFFF或0x23FFFFF，向左移动五个位，即2^5=32倍
bitnum:序列，2^2等同于n*4
```

![image-20241122231149723](.\img\image-20241122231149723.png)

通过宏定义方式获得存储器地址

```
#define MEM_ADDR(addr)   *((volatile unsigned long *) (addr))
通过指针类型访问这个地址，通过调用这个宏，将addr这个地址传递进来

```

![image-20241122232634362](.\img\image-20241122232634362.png)

```
#define BIT_ADDR(addr, bitnum)  MEM_ADDR (BITBAND(addr, bitnum))
对实际位操作的定义，通过这个宏得到位带区地址，和地址序列
```

#### 二、位带操作的有优点

1.控制GPIO口输入输出非常简单

```
比如通过以上封装宏，重新访问位重新命名led1，led1对应的是ODR寄存器输出，即led=1,即为输出高电平，led=!led作为切换
```



2.操作串行接口芯片非常方便（DS1302，74HC595等）



3.代码简洁，阅读方便

#### 三、软件设计

创建Public文件夹，放入位带操作的相关代码，这个文件称之为系统文件

##### system.h

```c
#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "stm32f10x.h"

//IO 口操作宏定义
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr&0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr) *((volatile unsigned long *)(addr))
#define BIT_ADDR(addr, bitnum) MEM_ADDR(BITBAND(addr, bitnum))
//IO 口地址映射
#define GPIOA_ODR_Addr (GPIOA_BASE+12) //0x4001080C
#define GPIOB_ODR_Addr (GPIOB_BASE+12) //0x40010C0C
#define GPIOC_ODR_Addr (GPIOC_BASE+12) //0x4001100C
#define GPIOD_ODR_Addr (GPIOD_BASE+12) //0x4001140C
#define GPIOE_ODR_Addr (GPIOE_BASE+12) //0x4001180C
#define GPIOF_ODR_Addr (GPIOF_BASE+12) //0x40011A0C
#define GPIOG_ODR_Addr (GPIOG_BASE+12) //0x40011E0C

#define GPIOA_IDR_Addr (GPIOA_BASE+8) //0x40010808
#define GPIOB_IDR_Addr (GPIOB_BASE+8) //0x40010C08
#define GPIOC_IDR_Addr (GPIOC_BASE+8) //0x40011008
#define GPIOD_IDR_Addr (GPIOD_BASE+8) //0x40011408
#define GPIOE_IDR_Addr (GPIOE_BASE+8) //0x40011808
#define GPIOF_IDR_Addr (GPIOF_BASE+8) //0x40011A08
#define GPIOG_IDR_Addr (GPIOG_BASE+8) //0x40011E08

//IO 口操作,只对单一的 IO 口!
//确保 n 的值小于 16!
#define PAout(n) BIT_ADDR(GPIOA_ODR_Addr,n) //输出
#define PAin(n) BIT_ADDR(GPIOA_IDR_Addr,n) //输入

#define PBout(n) BIT_ADDR(GPIOB_ODR_Addr,n) //输出
#define PBin(n) BIT_ADDR(GPIOB_IDR_Addr,n) //输入

#define PCout(n) BIT_ADDR(GPIOC_ODR_Addr,n) //输出
#define PCin(n) BIT_ADDR(GPIOC_IDR_Addr,n) //输入

#define PDout(n) BIT_ADDR(GPIOD_ODR_Addr,n) //输出
#define PDin(n) BIT_ADDR(GPIOD_IDR_Addr,n) //输入

#define PEout(n) BIT_ADDR(GPIOE_ODR_Addr,n) //输出
#define PEin(n) BIT_ADDR(GPIOE_IDR_Addr,n) //输入

#define PFout(n) BIT_ADDR(GPIOF_ODR_Addr,n) //输出
#define PFin(n) BIT_ADDR(GPIOF_IDR_Addr,n) //输入

#define PGout(n) BIT_ADDR(GPIOG_ODR_Addr,n) //输出
#define PGin(n) BIT_ADDR(GPIOG_IDR_Addr,n) //输入

void RCC_HSE_Config(u32 div,u32 pllm);

#endif

```

##### system.c

将时钟函数放入

```
#include "system.h"

void RCC_HSE_Config(u32 div,u32 pllm)//自定义系统时间（可以修改时钟)
{
	RCC_DeInit();//将外设RCC寄存器重设为缺省值
	RCC_HSEConfig(RCC_HSE_ON);//设置外部高速晶振（HSE)
	if(RCC_WaitForHSEStartUp()==SUCCESS) //等待HSE起振
	{
		RCC_HCLKConfig(RCC_SYSCLK_Div1);//设置AHB时钟（HCLK)
		RCC_PCLK1Config(RCC_HCLK_Div2);//设置低速AHB时钟（PCLK1）
		RCC_PCLK2Config(RCC_HCLK_Div1);//设置高速AHB时钟（PCLK2）
		RCC_PLLConfig(div,pllm);//设置PLL时钟源及倍频系数
		RCC_PLLCmd(ENABLE);//使能或者失能PLL
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);//检查指定的RCC标志位设置与否,PLL就绪
		RCC_SYSCLKConfig (RCC_SYSCLKSource_PLLCLK);//设置系统时钟 (SYSCLK)
		while(RCC_GetSYSCLKSource()!=0x08);//返回用作系统时钟的时钟源,0x08：PLL作为系统时钟
	}
}

```

## SysTick系统定时器

通过循环延时是不精确的，通过SysTick系统定时器是精确的

![image-20241123000304426](.\img\image-20241123000304426.png)

1/72MHz/8 = 9M,即1us计数9次

它也能够使用中断事件，配置中断的话，它就是当计数到0会触发中断事件

### 一、SysTick定时器操作

#### SysTick定时器寄存器

通常使用3个寄存器

##### 1.CTRL寄存器

控制状态寄存器

![image-20241123000827602](.\img\image-20241123000827602.png)

```
最低为0：可读写，使能位
第二位1：R/W，中断使能位
第三位2：时钟源选择位
第十七位16：只有读，当SysTick已经数到了0，该位标记为1
```

##### 2.LOAD寄存器

重装载寄存器

![image-20241123001356389](.\img\image-20241123001356389.png)

24位寄存器0xFFFFFF为最大值

##### 3.VAL寄存器

当前数值寄存器

![image-20241123001409897](.\img\image-20241123001409897.png)

```
它读取CTRL寄存器中16位段清楚器其标志
```

##### 4.CALIB寄存器

CALIB是SysTick定时器的校准数值寄存器

![image-20241123001931275](.\img\image-20241123001931275.png)

目前没用到

### 二、SysTick定时器操作

#### 操作步骤

##### 1 设置SysTick定时器的时钟源



##### 2.设置SysTick定时器的重装初始值(如果要使用中断的话，就将中断使能打开)



##### 3.清零SysTick定时器当前计数的值。



##### 4.打开SysTick定时器



### 三、软件设计

通过SysTick实现延时函数

时钟源库文件misc.c,没添加一个库文件都要编译（阶段性编译）

![image-20241123151138180](.\img\image-20241123151138180.png)

![image-20241123151646446](.\img\image-20241123151646446.png)

![image-20241123152510141](.\img\image-20241123152510141.png)

在core_cm可以找到SysTick结构体成员寄存器来配置

![image-20241123152900258](.\img\image-20241123152900258.png)

可以看到SysTick内存映射地址通过宏定义SysTick指针指向

#### main.c

```
#include "system.h"
#include "led.h"
#include "systick.h"


int main(){
	SysTick_Init(72);
	LED_Init();
	
	while(1){
		LED0=!LED0;
		delay_ms(1000);
	}
}
```

#### SysTick.h

```
#ifndef _SYSTICK_H
#define _SYSTICK_H

#include "system.h"


void SysTick_Init(u8 SYSCLK);// SYSCLK 表示系统时钟频率如72MHz
void delay_us(u32 nus);
void delay_ms(u32 nms);
#endif

```



#### SysTick.c

![image-20241123153733004](.\img\image-20241123153733004.png)



```
#include "systick.h"

u8 fac_us=0;
u16 fac_ms=0;

void SysTick_Init(u8 SYSCLK) // SYSCLK 表示系统时钟频率如72MHz
{ 
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);// 配置Systick时钟源72MHz/8div八分频
	fac_us=SYSCLK/8;   // 如：72/8 = 9 即1us就此
	fac_ms=fac_us*1000;
}

void delay_us(u32 nus)
{
	u32 temp; // 用来获取CTRL寄存器的值
	SysTick->LOAD=nus*fac_us; // 重装载值，即为计数值
	SysTick->VAL=0; // 将当前计数值清零
	SysTick->CTRL|=0x01; // 为了不影响其他位通过|运算符，让最低为为1使能定时器
	do
	{
		temp=SysTick->CTRL;
		//temp&(1<<16)即为第十七位，相与结果为1就说明计数结束，就要跳出循环即要！非运算至0
	}while((temp&0x01)&&!(temp&(1<<16)));
	SysTick->CTRL&=~(0x1); // 最低位设置为0，关闭使能
	SysTick->VAL=0; // 将当前计数值清零
}
void delay_ms(u32 nms)
{
	u32 temp; // 用来获取CTRL寄存器的值
	SysTick->LOAD=nms*fac_ms; // 重装载值，即为计数值
	SysTick->VAL=0; // 将当前计数值清零
	SysTick->CTRL|=0x01; // 为了不影响其他位通过|运算符，让最低为为1使能定时器
	do
	{
		temp=SysTick->CTRL;
		//temp&(1<<16)即为第十七位，相与结果为1就说明计数结束，就要跳出循环即要！非运算至0
	}while((temp&0x01)&&!(temp&(1<<16)));
	SysTick->CTRL&=~(0x1); // 最低位设置为0，关闭使能
	SysTick->VAL=0; // 将当前计数值清零
}

```



```
void SysTick_Init(u8 SYSCLK) // SYSCLK 表示系统时钟频率如72MHz
{ 
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);// 配置Systick时钟源72MHz/8div八分频
	fac_us=SYSCLK/8;   // 如：72/8 = 9 即1us就此
	fac_ms=fac_us*1000;
}
该函数中fac_us=SYSCLK/8是为了得到基数值，就是在对应时钟频率(SYSCLK)下1us计数器计数9次
所以LOAD->的值为nus*fac_us，就是说计时器计数9次才是1us
```

##### 微秒和毫秒延时

微秒延时可以传递值是16位

毫秒延时传递的值就限制更小了，LOAD最大范围0xFFFFFF，LOAD_max(0XFFFFFF) / fac_ms(9000)= 1864，最大到1.8s

##### 关于重装载值



![image-20241123160403616](.\img\image-20241123160403616.png)

### 跑马灯实验

有了SysTick定时器，我们就可以通过时间来做流水灯了

![image-20241123162828147](.\img\image-20241123162828147.png)

##### **首先找到网络标号**

![image-20241123163154009](.\img\image-20241123163154009.png)

J11端子通过黄色跳线帽让VCC3.3_LED与VCC3.3相连，使LED模块获得3.3V电压从而能亮

为什么要有跳线帽，因为PA端口引脚不只是连接了LED,还有**数码管SMG**

#### 软件设计

#### led.h

```
#ifndef _LED_H
#define _LED_H

#include "stm32f10x.h"

#define LED0_PORT GPIOC
#define LED0_PIN GPIO_Pin_13
#define LED0_PORT_RCC RCC_APB2Periph_GPIOC

#define LED0 PCout(13)
/* LED模块 */
#define LED1_PORT GPIOA
#define LED1_PIN GPIO_Pin_0
#define LED1_PORT_RCC RCC_APB2Periph_GPIOA

#define LED2_PORT GPIOA
#define LED2_PIN GPIO_Pin_1
#define LED2_PORT_RCC RCC_APB2Periph_GPIOA

#define LED3_PORT GPIOA
#define LED3_PIN GPIO_Pin_2
#define LED3_PORT_RCC RCC_APB2Periph_GPIOA

#define LED4_PORT GPIOA
#define LED4_PIN GPIO_Pin_3
#define LED4_PORT_RCC RCC_APB2Periph_GPIOA

#define LED5_PORT GPIOA
#define LED5_PIN GPIO_Pin_4
#define LED5_PORT_RCC RCC_APB2Periph_GPIOA

#define LED6_PORT GPIOA
#define LED6_PIN GPIO_Pin_5
#define LED6_PORT_RCC RCC_APB2Periph_GPIOA

#define LED7_PORT GPIOA
#define LED7_PIN GPIO_Pin_6
#define LED7_PORT_RCC RCC_APB2Periph_GPIOA

#define LED8_PORT GPIOA
#define LED8_PIN GPIO_Pin_7
#define LED8_PORT_RCC RCC_APB2Periph_GPIOA
//位带定义
#define LED1 PAout(0)
#define LED2 PAout(1)
#define LED3 PAout(2)
#define LED4 PAout(3)
#define LED5 PAout(4)
#define LED6 PAout(5)
#define LED7 PAout(6)
#define LED8 PAout(7)

// 函数声明
void LED_Init(void);

#endif

```



##### 1初始化LED相关GPIO

###### 第一种配置方式，因为都是一个端口下

```
void LED_Init(){
	// 结构体定义
	GPIO_InitTypeDef GPIO_InitStruct;
	// 开启时钟GPIO挂接的时钟
	RCC_APB2PeriphClockCmd(LED0_PORT_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// GPIO结构体配置
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=LED0_PIN|LED1_PIN|LED2_PIN|LED3_PIN|LED4_PIN|LED5_PIN|LED6_PIN|LED7_PIN|LED8_PIN;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED0_PORT, &GPIO_InitStruct);
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	// 设置高点电平保证灯灭
	GPIO_SetBits(LED0_PORT,LED0_PIN|LED1_PIN|LED2_PIN|LED3_PIN|LED4_PIN|LED5_PIN|LED6_PIN|LED7_PIN|LED8_PIN);
	
}
```

###### 这是另一种，为了方便移植

```
#include "led.h"
/*******************************************************************************
* 函 数 名 : LED_Init
* 函数功能 : LED 初始化函数
* 输 入 : 无
* 输 出 : 无
*******************************************************************************/
void LED_Init(void)
{
GPIO_InitTypeDef GPIO_InitStructure;//定义结构体变量
RCC_APB2PeriphClockCmd(LED0_PORT_RCC,ENABLE);
RCC_APB2PeriphClockCmd(LED1_PORT_RCC,ENABLE);
RCC_APB2PeriphClockCmd(LED2_PORT_RCC,ENABLE);
RCC_APB2PeriphClockCmd(LED3_PORT_RCC,ENABLE);
RCC_APB2PeriphClockCmd(LED4_PORT_RCC,ENABLE);
RCC_APB2PeriphClockCmd(LED5_PORT_RCC,ENABLE);
RCC_APB2PeriphClockCmd(LED6_PORT_RCC,ENABLE);
RCC_APB2PeriphClockCmd(LED7_PORT_RCC,ENABLE);
RCC_APB2PeriphClockCmd(LED8_PORT_RCC,ENABLE);
GPIO_InitStructure.GPIO_Pin=LED0_PIN; //选择你要设置的 IO 口
GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //设置推挽输出模式
GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //设置传输速率
GPIO_Init(LED0_PORT,&GPIO_InitStructure); /* 初始化 GPIO */
GPIO_SetBits(LED0_PORT,LED0_PIN); //将 LED 端口拉高，熄灭所有 LED
GPIO_InitStructure.GPIO_Pin=LED1_PIN;
GPIO_Init(LED1_PORT,&GPIO_InitStructure);
GPIO_SetBits(LED1_PORT,LED1_PIN);
GPIO_InitStructure.GPIO_Pin=LED2_PIN;
GPIO_Init(LED2_PORT,&GPIO_InitStructure);
GPIO_SetBits(LED2_PORT,LED2_PIN);
GPIO_InitStructure.GPIO_Pin=LED3_PIN;
GPIO_Init(LED3_PORT,&GPIO_InitStructure);
GPIO_SetBits(LED3_PORT,LED3_PIN);
GPIO_InitStructure.GPIO_Pin=LED4_PIN;
GPIO_Init(LED4_PORT,&GPIO_InitStructure);
GPIO_SetBits(LED4_PORT,LED4_PIN);
GPIO_InitStructure.GPIO_Pin=LED5_PIN;
GPIO_Init(LED5_PORT,&GPIO_InitStructure);
GPIO_SetBits(LED5_PORT,LED5_PIN);
GPIO_InitStructure.GPIO_Pin=LED6_PIN;
GPIO_Init(LED6_PORT,&GPIO_InitStructure);
GPIO_SetBits(LED6_PORT,LED6_PIN);
GPIO_InitStructure.GPIO_Pin=LED7_PIN;
GPIO_Init(LED7_PORT,&GPIO_InitStructure);
GPIO_SetBits(LED7_PORT,LED7_PIN);
GPIO_InitStructure.GPIO_Pin=LED8_PIN;
GPIO_Init(LED8_PORT,&GPIO_InitStructure);
GPIO_SetBits(LED8_PORT,LED8_PIN);
}
//LED 端口 8 位数据同时操作，不影响高位
//写入数据到 8 位端口，数据低位对应端口低引脚
//GPIO_Pin：8 位端口低位引脚
//data：写入数据
void LED_Write_Data(u16 GPIO_Pin,u8 data)
{
u8 i,j=GPIO_Pin;
for(i=0;i<8;i++)
{
if(data&0x01)
GPIO_WriteBit(GPIOA, j<<i ,Bit_SET);
else
GPIO_WriteBit(GPIOA, j<<i ,Bit_RESET);
data = data >> 1 ;
}
}
```



##### 2 实现跑马灯函数

GPIO_WriteBit(GPIOA, j<<i ,Bit_SET);

第一位为端口，第二位为引脚，第三位为设置为高低电平

![](.\img\image-20241124012019869.png)

```
//LED 端口 8 位数据同时操作，不影响高位
//写入数据到 8 位端口，数据低位对应端口低引脚
//GPIO_Pin：8 位端口低位引脚
//data：写入数据
void LED_Write_Data(u16 GPIO_Pin,u8 data)
{
    u8 i,j=GPIO_Pin;
    for(i=0;i<8;i++)
    {
        if(data&0x01)
        	GPIO_WriteBit(GPIOA, j<<i ,Bit_SET);
        else
        	GPIO_WriteBit(GPIOA, j<<i ,Bit_RESET);
        data = data >> 1 ;
    }
}
```

通过data：来决定输出高电平还是低电平，比较其最低为多少

GPIO_Pin：传入的管脚

![image-20241124012532593](.\img\image-20241124012532593.png)

每个管脚地址就是移动一位的距离所以**通过 j << i 就能切换引脚**，i来控制移到等于哪个管脚的

##### 3 主函数main.c

```
#include "system.h"
#include "SysTick.h"
#include "led.h"
int main()
{
    u8 dat=0x01;
    u8 i=0;
    SysTick_Init(72);
    LED_Init();
    while(1)
    {
        LED_Write_Data(GPIO_Pin_0,~(dat<<i));
        i++;
        if(i>=8)i=0;
        delay_ms(200);
    }
}
```

dat=0x01传入~(dat<<i)取反，如~11111110=00000001，i=0,i++,即八个管脚谁位至1谁熄灭

```c
void LED_Write_Data(u16 GPIO_Pin,u8 data)
{
    u8 i,j=GPIO_Pin;
    for(i=0;i<8;i++)
    {
        if(data&0x01)
        	GPIO_WriteBit(GPIOA, j<<i ,Bit_SET);
        else
        	GPIO_WriteBit(GPIOA, j<<i ,Bit_RESET);
        data = data >> 1 ;//00000001
    }
}
```

