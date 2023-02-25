#ifndef _BSP_TRACK_H
#define _BSP_TRACK_H

#include "gd32f4xx.h"
#include "systick.h"

#define XJ01_RCU  		RCU_GPIOA   	// GPIOA的时钟
#define PORT_XJ01 		GPIOA					// GPIOA的端口
#define XJ01_PIN 			GPIO_PIN_15  	// GPIOA的引脚

#define XJ02_RCU  		RCU_GPIOC   	// GPIOC的时钟
#define PORT_XJ02 		GPIOC					// GPIOC的端口
#define XJ02_PIN 			GPIO_PIN_10  	// GPIOC的引脚

#define XJ03_RCU  		RCU_GPIOC   	// GPIOC的时钟
#define PORT_XJ03 		GPIOC					// GPIOC的端口
#define XJ03_PIN 			GPIO_PIN_12  	// GPIOC的引脚

#define XJ04_RCU  		RCU_GPIOB   	// GPIOB的时钟
#define PORT_XJ04 		GPIOB					// GPIOB的端口
#define XJ04_PIN 			GPIO_PIN_13  	// GPIOB的引脚

#define XJ05_RCU  		RCU_GPIOB   	// GPIOB的时钟
#define PORT_XJ05 		GPIOB					// GPIOB的端口
#define XJ05_PIN 			GPIO_PIN_15  	// GPIOB的引脚

#define No_Black_Line_Found   0			//没有检查到黑线
#define Black_Line_Found   	  1			//检查到黑线

extern FlagStatus XJ01;
extern FlagStatus XJ02;
extern FlagStatus XJ03;
extern FlagStatus XJ04;
extern FlagStatus XJ05;

void track_gpio_config(void); 	  	// 循迹gpio引脚配置
void Black_Line_Detection(void);    // 黑线检测函数

#endif /* _BSP_TRACK_H */
