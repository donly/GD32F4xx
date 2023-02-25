#include "bsp_usart.h"
#include <stdio.h>
#include "bsp_dma.h"

uint8_t g_recv_buff[USART_RECV_LEN];
uint16_t g_recv_len = 0;
uint8_t g_recv_complete_flag = 0;

void usart_gpio_config(uint32_t brand_rate)
{
	// 开启时钟
	rcu_periph_clock_enable(BSP_USART_RCU);
	rcu_periph_clock_enable(BSP_USART_RX_RCU);
	rcu_periph_clock_enable(BSP_USART_TX_RCU);
	
	// 配置GPIO的复用功能，把 PA9,PA10 设置为串口功能
	gpio_af_set(BSP_USART_TX_PORT, BSP_USART_AF, BSP_USART_TX_PIN); 	// TX
	gpio_af_set(BSP_USART_RX_PORT, BSP_USART_AF, BSP_USART_RX_PIN);   // RX
	
	// 配置GPIO的模式
	gpio_mode_set(BSP_USART_TX_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, BSP_USART_TX_PIN); // 配置TX为复用上拉模式
	gpio_mode_set(BSP_USART_RX_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, BSP_USART_RX_PIN); // 配置RX为复用上拉模式
	
	// 配置GPIO的输出
	gpio_output_options_set(BSP_USART_TX_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_USART_TX_PIN); // 配置 TX 为推挽输出 50MHZ
	gpio_output_options_set(BSP_USART_RX_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_USART_RX_PIN); // 配置 RX 为推挽输出 50MHZ
	
	// 配置串口
	usart_deinit(BSP_USART);
	usart_baudrate_set(BSP_USART, brand_rate);
	usart_parity_config(BSP_USART, USART_PM_NONE);
	usart_word_length_set(BSP_USART, USART_WL_8BIT);
	usart_stop_bit_set(BSP_USART, USART_STB_1BIT);
	
	// 使能串口
	usart_enable(BSP_USART);
	usart_transmit_config(BSP_USART, USART_TRANSMIT_ENABLE);
	usart_receive_config(BSP_USART, USART_RECEIVE_ENABLE);
	
	// 配置中断优先级
	nvic_irq_enable(BSP_USART_IRQ, 2, 2);
	
	// 使能中断
	//usart_interrupt_enable(BSP_USART, USART_INT_RBNE); // 接收缓冲区不为空中断和溢出错误中断
	usart_interrupt_enable(BSP_USART, USART_INT_IDLE); // 空闲检测中断
}

void uart6_gpio_config(uint32_t band_rate)
{
	/* 开启时钟 */
	rcu_periph_clock_enable(BSP_UART6_TX_RCU);   // 开启串口时钟
	rcu_periph_clock_enable(BSP_UART6_RX_RCU);   // 开启端口时钟
	rcu_periph_clock_enable(BSP_UART6_RCU);      // 开启端口时钟
	
	/* 配置GPIO复用功能 */
	gpio_af_set(BSP_UART6_TX_PORT,BSP_UART6_AF,BSP_UART6_TX_PIN);	
	gpio_af_set(BSP_UART6_RX_PORT,BSP_UART6_AF,BSP_UART6_RX_PIN);	
	
	/* 配置GPIO的模式 */
	/* 配置TX为复用模式 上拉模式 */
	gpio_mode_set(BSP_UART6_TX_PORT,GPIO_MODE_AF,GPIO_PUPD_PULLUP,BSP_UART6_TX_PIN);
	/* 配置RX为复用模式 上拉模式 */
	gpio_mode_set(BSP_UART6_RX_PORT, GPIO_MODE_AF,GPIO_PUPD_PULLUP,BSP_UART6_RX_PIN);
	
	/* 配置TX为推挽输出 50MHZ */
	gpio_output_options_set(BSP_UART6_TX_PORT,GPIO_OTYPE_PP,GPIO_OSPEED_50MHZ,BSP_UART6_TX_PIN);
	/* 配置RX为推挽输出 50MHZ */
	gpio_output_options_set(BSP_UART6_RX_PORT,GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_UART6_RX_PIN);

	/* 配置串口的参数 */
	usart_deinit(BSP_UART6);                                 // 复位串口
	usart_baudrate_set(BSP_UART6,band_rate);                 // 设置波特率
	usart_parity_config(BSP_UART6,USART_PM_NONE);            // 没有校验位
	usart_word_length_set(BSP_UART6,USART_WL_8BIT);          // 8位数据位
	usart_stop_bit_set(BSP_UART6,USART_STB_1BIT);     		 // 1位停止位

	/* 使能串口 */
	usart_enable(BSP_UART6);                          		 // 使能串口
	usart_transmit_config(BSP_UART6,USART_TRANSMIT_ENABLE);  // 使能串口发送
	usart_receive_config(BSP_UART6,USART_RECEIVE_ENABLE);    // 使能串口接收
	
	/* 中断配置 */
	nvic_irq_enable(BSP_UART6_IRQ, 2, 2); 					 // 配置中断优先级
	usart_interrupt_enable(BSP_UART6,USART_INT_RBNE);		 // 读数据缓冲区非空中断和溢出错误中断
	usart_interrupt_enable(BSP_UART6,USART_INT_IDLE);		 // 空闲检测中断
}

// 串口发送数据
void usart_send_data(uint8_t ucch)
{
	usart_data_transmit(BSP_USART, (uint8_t)ucch);
	while (RESET == usart_flag_get(BSP_USART, USART_FLAG_TBE)); // 等待发送数据缓冲区 标志置位
	
}

// 串口发送字符串
void usart_send_string(uint8_t *ucstr)
{
	while (ucstr && *ucstr) // 地址为空或者值为空结束
	{
		usart_send_data(*ucstr++);
	}
}

int fputc(int ch, FILE *f)
{
	usart_send_data(ch);
	return ch;
}

// 串口中断函数
void USART0_IRQHandler(void)
{
//	if (usart_interrupt_flag_get(BSP_USART, USART_INT_FLAG_RBNE) == SET)
//	{
//		g_recv_buff[g_recv_len++] = usart_data_receive(BSP_USART);
//	}
	
	if (usart_interrupt_flag_get(BSP_USART, USART_INT_FLAG_IDLE) == SET)
	{
		usart_data_receive(BSP_USART);
		g_recv_len = USART_RECV_LEN - dma_transfer_number_get(BSP_DMA, BSP_DMA_CH);
		
		g_recv_buff[g_recv_len] = '\0';
		g_recv_complete_flag = 1;
		
		dma_channel_disable(BSP_DMA, BSP_DMA_CH);
		dma_config();
	}
}

void BSP_UART6_IRQHandler(void)
{
	if(usart_interrupt_flag_get(BSP_UART6,USART_INT_FLAG_RBNE) == SET)     // 接收缓冲区不为空
	{
		g_recv_buff[g_recv_len++] = usart_data_receive(BSP_UART6);      // 把接收到的数据放到缓冲区中
	}
	
	if(usart_interrupt_flag_get(BSP_UART6,USART_INT_FLAG_IDLE) == SET)     // 检测到帧中断
	{
		usart_data_receive(BSP_UART6);                                     // 必须要读，读出来的值不能要
		g_recv_buff[g_recv_len] = '\0';								 		  						   // 数据接收完毕，数组结束标志
		g_recv_complete_flag = 1;                                          // 接收完成 
	}
}
