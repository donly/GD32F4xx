#ifndef _BSP_MOTOR_H
#define _BSP_MOTOR_H

#include "gd32f4xx.h"
#include "systick.h"
#include "sys.h"
#include "bsp_pwm.h"

// 左前轮LQ+ FI PB4
#define BSP_LQ_FI_RCU 		RCU_GPIOB			// GPIOB的时钟
#define BSP_LQ_FI_PORT 		GPIOB					// GPIOB的端口
#define BSP_LQ_FI_PIN 		GPIO_PIN_4		// GPIOB的引脚
#define BSP_TIMER2_CH0 		GPIO_AF_2			// PWM引脚利用
#define BSP_LQ_FI 				PBout(4)
// 左前轮LQ- BI PA7
#define BSP_LQ_BI_RCU 		RCU_GPIOA			// GPIOA的时钟
#define BSP_LQ_BI_PORT 		GPIOA					// GPIOA的端口
#define BSP_LQ_BI_PIN 		GPIO_PIN_7		// GPIOA的引脚
#define BSP_TIMER2_CH1 		GPIO_AF_2			// PWM引脚利用
#define BSP_LQ_BI 				PAout(7)

// 左后轮LH+ FI PB0
#define BSP_LH_FI_RCU 		RCU_GPIOB			// GPIOB的时钟
#define BSP_LH_FI_PORT 		GPIOB					// GPIOB的端口
#define BSP_LH_FI_PIN 		GPIO_PIN_0		// GPIOB的引脚
#define BSP_TIMER2_CH2 		GPIO_AF_2			// PWM引脚利用
#define BSP_LH_FI 				PBout(0)
// 左后轮LH- BI PB1
#define BSP_LH_BI_RCU 		RCU_GPIOB			// GPIOB的时钟
#define BSP_LH_BI_PORT 		GPIOB					// GPIOB的端口
#define BSP_LH_BI_PIN 		GPIO_PIN_1		// GPIOB的引脚
#define BSP_TIMER2_CH3 		GPIO_AF_2			// PWM引脚利用
#define BSP_LH_BI 				PBout(1)

// 右前轮RQ- BI PA2
#define BSP_RQ_BI_RCU 		RCU_GPIOA			// GPIOA的时钟
#define BSP_RQ_BI_PORT 		GPIOA					// GPIOA的端口
#define BSP_RQ_BI_PIN 		GPIO_PIN_2		// GPIOA的引脚
#define BSP_TIMER1_CH2 		GPIO_AF_1			// PWM引脚利用
#define BSP_RQ_BI 				PAout(2)
// 右前轮RQ+ FI PA3
#define BSP_RQ_FI_RCU 		RCU_GPIOA			// GPIOA的时钟
#define BSP_RQ_FI_PORT 		GPIOA					// GPIOA的端口
#define BSP_RQ_FI_PIN 		GPIO_PIN_3		// GPIOA的引脚
#define BSP_TIMER1_CH3 		GPIO_AF_1			// PWM引脚利用
#define BSP_RQ_FI 				PAout(3)

// 右后轮RH- BI PA1
#define BSP_RH_BI_RCU 		RCU_GPIOA			// GPIOA的时钟
#define BSP_RH_BI_PORT 		GPIOA					// GPIOA的端口
#define BSP_RH_BI_PIN 		GPIO_PIN_1		// GPIOA的引脚
#define BSP_TIMER1_CH1 		GPIO_AF_1			// PWM引脚利用
#define BSP_RH_BI 				PAout(1)
// 右后轮RH+ FI PA0
#define BSP_RH_FI_RCU 		RCU_GPIOA			// GPIOA的时钟
#define BSP_RH_FI_PORT 		GPIOA					// GPIOA的端口
#define BSP_RH_FI_PIN 		GPIO_PIN_0		// GPIOA的引脚
#define BSP_TIMER1_CH0 		GPIO_AF_1			// PWM引脚利用
#define BSP_RH_FI 				PAout(0)

#define FLAMEOUT_STOP 0									// 熄火
#define BREAK_STOP 		1									// 急刹车

void motor_gpio_config(void);
void car_forward(uint16_t speed);
void car_backward(uint16_t speed);
void car_left(uint16_t speed);
void car_right(uint16_t speed);
void car_stop(uint16_t mode);

void motor_lq_forward(uint16_t speed);
void motor_lq_backward(uint16_t speed);
void motor_lh_forward(uint16_t speed);
void motor_lh_backward(uint16_t speed);
void motor_rq_forward(uint16_t speed);
void motor_rq_backward(uint16_t speed);
void motor_rh_forward(uint16_t speed);
void motor_rh_backward(uint16_t speed);

#endif
