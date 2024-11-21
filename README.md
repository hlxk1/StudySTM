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
void RCC_HSE_Config(u32 div,u32 pllm）//自定义系统时间（可以修改时钟)
{
	RCC_DeInit();//将外设RCC寄存器重设为缺省值
	RCC_HSEConfig(RCC_HSE_ON);//设置外部高速晶振（HSE)
	if(RCC_WaitForHSEStartUp()==SUCCESS）//等待HSE起振
	{
		RCC_HCLKConfig(RCC_SYSCLK_Div1);//设置AHB时钟（HCLK)
		RCC_PCLK1Config(RCC_HCLK_Div2);//设置低速AHB时钟（PCLK1）
		RCC_PCLK2Config(RCC_HCLK_Div1);//设置高速AHB时钟（PCLK2）
		RCC_PLLConfig(div,pllm);//设置PLL时钟源及倍频系数
		RCC_PLLCmd(ENABLE)；//使能或者失能PLL
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);//检查指定的RCC标志位设置与否,PLL就绪
		RCC_SYSCLKConfig (RCC_SYSCLKSource_PLLCLK);//设置系统时钟 (SYSCLK)
		while(RCC_GetSYSCLKSource()!=Ox08);//返回用作系统时钟的时钟源,Ox08：PLL作为系统时钟
	}
}
```

