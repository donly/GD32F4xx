#ifndef _BSP_KEH_H
#define _BSP_KEH_H

#include "gd32f4xx.h"
#include "systick.h"

#define RCU_KEY_MODE	 						RCU_GPIOB
#define PORT_KEY_MODE 						GPIOB
#define PIN_KEY_MODE 							GPIO_PIN_5

#define RCU_KEY_SPEED	 						RCU_GPIOE
#define PORT_KEY_SPEED 						GPIOE
#define PIN_KEY_SPEED 						GPIO_PIN_5

#define BSP_KEY_EXTI_IRQ_N 				EXTI5_9_IRQn
#define BSP_KEY_EXTI_PORT_SOURCE 	EXTI_SOURCE_GPIOB
#define BSP_KEY_EXTI_PIN_SOURCE 	EXTI_SOURCE_PIN7
#define BSP_KEY_EXTI_LINE 				EXTI_7
#define BSP_KEY_EXTI_IRQ_HANDLER  EXTI5_9_IRQHandler

//#define BSP_KEY_EXTI_IRQ_N 				EXTI3_IRQn
//#define BSP_KEY_EXTI_PORT_SOURCE 	EXTI_SOURCE_GPIOB
//#define BSP_KEY_EXTI_PIN_SOURCE 	EXTI_SOURCE_PIN3
//#define BSP_KEY_EXTI_LINE 				EXTI_3
//#define BSP_KEY_EXTI_IRQ_HANDLER  EXTI3_IRQHandler

#define KEY_MODE_PRESS_FLAG				1
#define KEY_SPEED_PRESS_FLAG			2

#define MOTION_MODE_BLE_FLAG			0
#define MOTION_MODE_AUTO_FLAG			1
#define MOTION_MODE_AVOID_FLAG		2  // 避障模式

#define MOTION_SPEED_NORMAL_FLAG	0
#define MOTION_SPEED_HIGH_FLAG		1

extern uint8_t 	motion_mode;
extern uint8_t 	motion_speed;

void key_gpio_config(void);
void key_scan(void);

#endif
