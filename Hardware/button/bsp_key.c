#include "bsp_key.h"
#include "sys.h"
#include <stdio.h>
#include "bsp_led.h"

void key_gpio_config(void)
{
	// 开启 GPIO 的端口时钟
	rcu_periph_clock_enable(BSP_KEY_RCU);
	
	// 配置 GPIO 模式为浮空模式
	gpio_mode_set(BSP_KEY_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, BSP_KEY_PIN);
}

void key_scan(void)
{
	// 获取按键引脚的电平状态
	if (gpio_input_bit_get(BSP_KEY_PORT, BSP_KEY_PIN) == SET)
	{
		// 延迟消抖
		delay_1ms(20);
		if (gpio_input_bit_get(BSP_KEY_PORT, BSP_KEY_PIN) == SET)
		{
			// 执行功能
//			PDout(7) = 1;
			gpio_bit_toggle(PORT_LED1, PIN_LED1);
			printf("key pressed.\n\r");
			// 等待按键松开
			while(gpio_input_bit_get(BSP_KEY_PORT, BSP_KEY_PIN) == SET);
			printf("key released.\n\r");
		}
	}
	
	
}
