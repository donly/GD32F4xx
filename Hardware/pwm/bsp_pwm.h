#ifndef _BSP_PWM_H
#define _BSP_PWM_H

#include "gd32f4xx.h"
#include "systick.h"

#define BSP_PWM1_TIMER_RCU 		RCU_TIMER1			// 定时器1时钟
#define BSP_PWM1_TIMER 				TIMER1 					// 定时器1
#define BSP_PWM1_CHANNEL_0 		TIMER_CH_0			// 定时器通道0
#define BSP_PWM1_CHANNEL_1 		TIMER_CH_1			// 定时器通道1
#define BSP_PWM1_CHANNEL_2 		TIMER_CH_2			// 定时器通道2
#define BSP_PWM1_CHANNEL_3 		TIMER_CH_3			// 定时器通道3

#define BSP_PWM2_TIMER_RCU 		RCU_TIMER2			// 定时器2时钟
#define BSP_PWM2_TIMER 				TIMER2 					// 定时器2
#define BSP_PWM2_CHANNEL_0 		TIMER_CH_0			// 定时器通道0
#define BSP_PWM2_CHANNEL_1 		TIMER_CH_1			// 定时器通道1
#define BSP_PWM2_CHANNEL_2 		TIMER_CH_2			// 定时器通道2
#define BSP_PWM2_CHANNEL_3 		TIMER_CH_3			// 定时器通道3

void pwm1_config(uint16_t pre, uint16_t per);
void pwm2_config(uint16_t pre, uint16_t per);

#endif
