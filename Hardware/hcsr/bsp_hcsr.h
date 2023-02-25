#ifndef _BSP_HCSR_H
#define _BSP_HCSR_H

#include "gd32f4xx.h"
#include "systick.h"
#include "sys.h"

#define HCSR04_RCU  			RCU_GPIOB   	// GPIOB的时钟
#define PORT_HCSR04 			GPIOB					// GPIOB的端口
#define HCSR04_Trig_PIN 	GPIO_PIN_12  	// GPIOB的引脚
#define HCSR04_Echo_PIN 	GPIO_PIN_10  	// GPIOB的引脚

#define Trig PBout(12)
#define Echo PBin(10)

void hcsr04_gpio_config(void);
int32_t hcsr04_get_distance(void);

#endif /* BSP_HCSR_H */

