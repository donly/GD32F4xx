#include "bsp_basic_timer.h"
#include "bsp_led.h"
#include <stdio.h>

void basic_timer_config(uint16_t pre, uint16_t per)
{
	timer_parameter_struct timer_init_param;
	
	rcu_periph_clock_enable(BSP_TIMER_RCU);
	
	// 配置时钟
	rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);
	timer_deinit(BSP_TIMER);
	
	timer_struct_para_init(&timer_init_param);
	timer_init_param.prescaler = pre - 1;
	timer_init_param.period = per - 1;
	timer_init(BSP_TIMER, &timer_init_param);
	
	nvic_irq_enable(BSP_TIMER_IRQ, 3, 2);
	timer_interrupt_enable(BSP_TIMER, TIMER_INT_UP);
	timer_enable(BSP_TIMER);
}

void BSP_TIMER_IRQHANDLER(void)
{
//	if (timer_interrupt_flag_get(BSP_TIMER, TIMER_INT_FLAG_UP) == SET)
//	{
//		gpio_bit_toggle(PORT_LED1, PIN_LED_L);
//		printf("BSP_TIMER_IRQHANDLER!\r\n");
//	}
//	
//	timer_interrupt_flag_clear(BSP_TIMER, TIMER_INT_FLAG_UP);
}
