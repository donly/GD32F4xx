#ifndef _BSP_BEEP_H
#define _BSP_BEEP_H

#include "gd32f4xx.h"
#include "systick.h"

	
#define RCU_BEEP 	RCU_GPIOF
#define PORT_BEEP GPIOF
#define PIN_BEEP	GPIO_PIN_8

#define BEEP_ON 	gpio_bit_write(PORT_BEEP, PIN_BEEP, RESET)
#define BEEP_OFF 	gpio_bit_write(PORT_BEEP, PIN_BEEP, SET)

void beep_gpio_config(void);

#endif
