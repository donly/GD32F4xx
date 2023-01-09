#include "bsp_led.h"

void led_gpio_config(void)
{
	
	// 1.开启GPIO的端口时钟
	//BSP_RCU_AHB1EN |= 0x00000008
	BSP_RCU_AHB1EN |= (1 << 3);
	
	// 2.配置GPIO的模式
	BSP_GPIOD_CTL &= ~(0x03 << (2*7));
	BSP_GPIOD_CTL |= (0x01 << (2*7));
	
	BSP_GPIOD_PUD &= ~(0x03 << (2*7));
	//BSP_GPIOD_PUD |= (0x00 << (2*7));
	
	// 3.配置GPIO的输出
	BSP_GPIOD_OMODE &= (0x1 << 7);  // 配置为推挽输出
	
	// 配置为速度为50MHZ
	BSP_GPIOD_OSPD &= ~(0x03 << (2*7));
	BSP_GPIOD_OSPD |= (0x2 << (2*7));
}
