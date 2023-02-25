#ifndef _BSP_USART_H
#define _BSP_USART_H

#include "gd32f4xx.h"
#include "systick.h"

#define BSP_USART_TX_RCU				RCU_GPIOA
#define BSP_USART_RX_RCU				RCU_GPIOA
#define BSP_USART_RCU 					RCU_USART0
			
#define BSP_USART_TX_PORT 			GPIOA
#define BSP_USART_RX_PORT 			GPIOA
#define BSP_USART_AF						GPIO_AF_7
#define BSP_USART_TX_PIN  			GPIO_PIN_9
#define BSP_USART_RX_PIN  			GPIO_PIN_10
			
#define BSP_USART 							USART0
#define BSP_USART_IRQ						USART0_IRQn

// 蓝牙连接接口
#define BSP_UART6_TX_RCU  			RCU_GPIOF        // 串口6TX的端口时钟
#define BSP_UART6_RX_RCU 				RCU_GPIOF        // 串口6RX的端口时钟
#define BSP_UART6_RCU     			RCU_UART6        // 串口6的时钟
		
#define BSP_UART6_TX_PORT 			GPIOF		  			 // 串口TX的端口
#define BSP_UART6_RX_PORT 			GPIOF			 			 // 串口RX的端口
#define BSP_UART6_AF 						GPIO_AF_8  			 // 串口6的复用功能
#define BSP_UART6_TX_PIN  			GPIO_PIN_7   		 // 串口6TX的引脚
#define BSP_UART6_RX_PIN  			GPIO_PIN_6 	 		 // 串口6RX的引脚
		
#define BSP_UART6 							UART6      	 			// 串口6
#define BSP_UART6_IRQ						UART6_IRQn 		 		// 串口6中断
#define BSP_UART6_IRQHandler  	UART6_IRQHandler 	// 串口6中断服务函数

#define USART_RECV_LEN	  4096

extern uint8_t g_recv_buff[USART_RECV_LEN];
extern uint16_t g_recv_len;
extern uint8_t g_recv_complete_flag;

void usart_gpio_config(uint32_t brand_rate);
void usart_send_data(uint8_t);
void usart_send_string(uint8_t *ucstr);

void uart6_gpio_config(uint32_t band_rate);	 // 配置串口6

#endif
