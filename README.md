# StudySTM
Study knowledge about STM32

## STM32与ARM的关系

![image-20241109184337399](.\img\image-20241109184337399.png)

ARM公司负责芯片方案设计

ST负责制造芯片

![image-20241109185228634](F:\StudySTM\img\image-20241109185228634.png)

STM32f103就属于Cortex—M3

![image-20241109185429564](F:\StudySTM\img\image-20241109185429564.png)

STM32拿到ARM设计的内核，STM32基于这个内核添加了自己公司的外设进行打包，封装，生产

![image-20241109185701632](F:\StudySTM\img\image-20241109185701632.png)

L:代表低功耗

F1和F4比较主流性价比高

## STM32F103C8T6介绍

![image-20241109185935538](F:\StudySTM\img\image-20241109185935538.png)

https://www.stmcu.com.cn/

logo:ST表示由ST公司生产，通常芯片表面还会有一个ARM（内核基于ARM公司设计）

一般芯片上还会有个**圆点针对芯片管脚的顺序（按逆时针）**

------

![image-20241109191021165](F:\StudySTM\img\image-20241109191021165.png)

通过这张图（在STM32选型表中）可以看到不同芯片的外设资源数目

------

![image-20241109191250443](F:\StudySTM\img\image-20241109191250443.png)

![image-20241109191254519](C:\Users\火乐\AppData\Roaming\Typora\typora-user-images\image-20241109191254519.png)

这就是STM32F103C8T6的外设资源

------

![image-20241109191523534](F:\StudySTM\img\image-20241109191523534.png)

**芯片上型号的规则**

------

## 芯片管脚

![image-20241109192743952](F:\StudySTM\img\image-20241109192743952.png)

芯片引脚的功能

![image-20241109192933633](F:\StudySTM\img\image-20241109192933633.png)

## STM32能做什么

![image-20241109193015834](F:\StudySTM\img\image-20241109193015834.png)

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

![image-20241109194640166](F:\StudySTM\img\image-20241109194640166.png)

下方为主晶振

D2为发光二极管，便于调试提示我们连接到了PC13的管脚

#### 2 复位电路

![image-20241109194650673](F:\StudySTM\img\image-20241109194650673.png)

NRST引脚及低电平复位

RST是加上按键

#### 3 电源电路

![image-20241109194813060](F:\StudySTM\img\image-20241109194813060.png)

![image-20241109195202471](F:\StudySTM\img\image-20241109195202471.png)

![image-20241109195309819](C:\Users\火乐\AppData\Roaming\Typora\typora-user-images\image-20241109195309819.png)

稳压芯片将5V电压变为3.3V

#### 4 下载电路

![image-20241109194928506](F:\StudySTM\img\image-20241109194928506.png)

只需要两个引脚SWDIO，SWCLK，通过添加供电引脚方便仿真器供电

------

![image-20241109195559799](F:\StudySTM\img\image-20241109195559799.png)

![image-20241109195608775](F:\StudySTM\img\image-20241109195608775.png)

VDD是电源正极，VSS是电源负极

### STM32启动模式

![image-20241109195830986](F:\StudySTM\img\image-20241109195830986.png)

![image-20241109200005470](F:\StudySTM\img\image-20241109200005470.png)

类似图中的 BOOT0 标识的叫做**网络标号**

## Keil5软件安装及配置

### 1 Keil5获取

官网：https://www.keil.com/download/product/

![image-20241109203354502](F:\StudySTM\img\image-20241109203354502.png)

STM32是基于MDK-Arm下载

下载过程提示你安装一些jlink驱动，可以安装或不安装

### 2 添加STM32的芯片包

![image-20241109203715429](F:\StudySTM\img\image-20241109203715429.png)

#### 点击新建项目新建文件验证是否有芯片包

![image-20241109203936522](F:\StudySTM\img\image-20241109203936522.png)

![image-20241109204058623](F:\StudySTM\img\image-20241109204058623.png)

### 3 破解Keil5

![image-20241109204148719](F:\StudySTM\img\image-20241109204148719.png)

破解的注册及软件

![image-20241109204251497](F:\StudySTM\img\image-20241109204251497.png)

点击License Management管理

------

![image-20241109204333043](F:\StudySTM\img\image-20241109204333043.png)

复制CID

![image-20241109204419133](F:\StudySTM\img\image-20241109204419133.png)

将注册机打开选择Target为ARM（如果是51单片机才选择C51）,并把复制好的CID填入

点击Generate，生成的码复制写入 License ID Code

![image-20241109204649868](F:\StudySTM\img\image-20241109204649868.png)

### 修改编码风格

![image-20241109205315760](F:\StudySTM\img\image-20241109205315760.png)

 

## STM32固件库介绍

### 1 CMSIS标准 

CMSIS是Cortex Microcontroller Software Interface Standard英文首字母缩写，是ARM Cortex微控制器软件接口标准

![image-20241110000504395](F:\StudySTM\img\image-20241110000504395.png)







### 2 库目录文件

![image-20241110001628161](F:\StudySTM\img\image-20241110001628161.png)

![image-20241110001646512](F:\StudySTM\img\image-20241110001646512.png)

![image-20241110001703803](F:\StudySTM\img\image-20241110001703803.png)

#### 文件介绍

![image-20241110002011496](F:\StudySTM\img\image-20241110002011496.png)

##### 启动文件startup

![image-20241110002049450](F:\StudySTM\img\image-20241110002049450.png)

![image-20241110002111752](F:\StudySTM\img\image-20241110002111752.png)

根据这个表选择对应的型号的启动文件（看缩写）

### 3 库帮组文档使用

5.3
