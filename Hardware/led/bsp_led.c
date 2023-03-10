#include "bsp_led.h"

void led_gpio_config(void)
{
	
	// 1.开启GPIO的端口时钟
//	BSP_RCU_AHB1EN |= 0x00000008
//	BSP_RCU_AHB1EN |= (1 << 3);
//	rcu_periph_clock_enable(RCU_GPIOD);
	
	// 2.配置GPIO的模式
//	BSP_GPIOD_CTL &= ~(0x03 << (2*7));
//	BSP_GPIOD_CTL |= (0x01 << (2*7));
//	BSP_GPIOE_CTL &= ~(0x03 << (2*3));
//	BSP_GPIOE_CTL |= (0x01 << (2*3));
	
//	BSP_GPIOD_PUD &= ~(0x03 << (2*7));
//	BSP_GPIOD_PUD |= (0x00 << (2*7));
//	BSP_GPIOE_PUD &= ~(0x03 << (2*3));
	
//	gpio_mode_set(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_7);
	
	// 3.配置GPIO的输出
//	BSP_GPIOD_OMODE &= (0x1 << 7);  // 配置为推挽输出
//	BSP_GPIOE_OMODE &= (0x1 << 3);
	
	// 配置为速度为50MHZ
//	BSP_GPIOD_OSPD &= ~(0x03 << (2*7));
//	BSP_GPIOD_OSPD |= (0x2 << (2*7));
//	BSP_GPIOE_OSPD &= ~(0x03 << (2*3));
//	BSP_GPIOE_OSPD |= (0x2 << (2*3));
//	gpio_output_options_set(GPIOD, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_7);

	// 使能时钟
	rcu_periph_clock_enable(RCU_LED_L);
	rcu_periph_clock_enable(RCU_LED_R);
	rcu_periph_clock_enable(RCU_LED_M);
	rcu_periph_clock_enable(RCU_LED_S);
	
	// 配置GPIO的模式
	gpio_mode_set(PORT_LED_L, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_LED_L);
	gpio_mode_set(PORT_LED_R, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_LED_R);
	gpio_mode_set(PORT_LED_M, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_LED_M);
	gpio_mode_set(PORT_LED_S, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_LED_S);
	// 配置GPIO的输出
	gpio_output_options_set(PORT_LED_L, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_LED_L);
	gpio_output_options_set(PORT_LED_R, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_LED_R);
	gpio_output_options_set(PORT_LED_M, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_LED_M);
	gpio_output_options_set(PORT_LED_S, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_LED_S);
}
