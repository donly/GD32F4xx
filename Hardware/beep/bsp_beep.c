#include "bsp_beep.h"

void beep_gpio_config(void)
{
	// 使能时钟
	rcu_periph_clock_enable(RCU_BEEP);
	// 配置GPIO的模式
	gpio_mode_set(PORT_BEEP, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_BEEP);
	// 配置GPIO的输出
	gpio_output_options_set(PORT_BEEP, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_BEEP);
}
