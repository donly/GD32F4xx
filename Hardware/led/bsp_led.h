#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "gd32f4xx.h"
#include "systick.h"
	
#define RCU_LED_L 	RCU_GPIOA
#define RCU_LED_R 	RCU_GPIOG
#define RCU_LED_M 	RCU_GPIOB
#define RCU_LED_S 	RCU_GPIOE

#define PORT_LED_L	GPIOA
#define PORT_LED_R	GPIOG
#define PORT_LED_M	GPIOB
#define PORT_LED_S  GPIOE

#define PIN_LED_L 	GPIO_PIN_12
#define PIN_LED_R 	GPIO_PIN_7
#define PIN_LED_M 	GPIO_PIN_3
#define PIN_LED_S 	GPIO_PIN_2

#define LED_L_ON gpio_bit_write(PORT_LED_L, PIN_LED_L, SET)
#define LED_L_OFF gpio_bit_write(PORT_LED_L, PIN_LED_L, RESET)
#define LED_R_ON gpio_bit_write(PORT_LED_R, PIN_LED_R, SET)
#define LED_R_OFF gpio_bit_write(PORT_LED_R, PIN_LED_R, RESET)

#define LED_MODE 	PBout(3)
#define LED_SPEED PEout(2)

void led_gpio_config(void);

#endif
