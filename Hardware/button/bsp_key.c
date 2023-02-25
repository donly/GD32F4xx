#include "bsp_key.h"
#include "sys.h"
#include <stdio.h>
#include "bsp_led.h"

uint8_t uckey 				= 0;
uint8_t motion_mode 	= MOTION_MODE_BLE_FLAG;
uint8_t motion_speed	= MOTION_SPEED_NORMAL_FLAG;

void key_gpio_config(void)
{
	// 开启 GPIO 的端口时钟
	rcu_periph_clock_enable(RCU_KEY_MODE);
	rcu_periph_clock_enable(RCU_KEY_SPEED);
	
	// 系统配置时钟
	//rcu_periph_clock_enable(RCU_SYSCFG);
	// 配置 GPIO 模式 ，按键默认状态是低电平，配置为上拉
	gpio_mode_set(PORT_KEY_MODE, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, PIN_KEY_MODE);
	gpio_mode_set(PORT_KEY_SPEED, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, PIN_KEY_SPEED);
	
//	// 设置中断优先级
//	nvic_irq_enable(BSP_KEY_EXTI_IRQ_N, 3U, 3U);
//	// 连接中断线到 GPIO
//	syscfg_exti_line_config(BSP_KEY_EXTI_PORT_SOURCE, BSP_KEY_EXTI_PIN_SOURCE);
//	
//	// 对中断进行初始化
//	exti_init(BSP_KEY_EXTI_LINE, EXTI_INTERRUPT, EXTI_TRIG_BOTH);
//	
//	// 使能中断
//	exti_interrupt_enable(BSP_KEY_EXTI_LINE);
//	
//	// 清除中断标志位
//	exti_interrupt_flag_clear(BSP_KEY_EXTI_LINE);
}

uint8_t key_read(void)
{
	uint8_t key_val = 0;
	/* 先读取按键引脚的电平 如果低电平，按键按下 */
	if(gpio_input_bit_get(PORT_KEY_MODE, PIN_KEY_MODE) == RESET)         // 按键按下
	{
		delay_1ms(20);  // 延迟消抖 
		if(gpio_input_bit_get(PORT_KEY_MODE, PIN_KEY_MODE) == RESET)       // 再次检测按键是否按下 
			 key_val = KEY_MODE_PRESS_FLAG;
	}
	
	/* 先读取按键引脚的电平 如果低电平，按键按下 */
	if(gpio_input_bit_get(PORT_KEY_SPEED, PIN_KEY_SPEED) == RESET)         // 按键按下
	{
		delay_1ms(20);  // 延迟消抖 
		if(gpio_input_bit_get(PORT_KEY_SPEED, PIN_KEY_SPEED) == RESET)       // 再次检测按键是否按下 
			 key_val = KEY_SPEED_PRESS_FLAG;
	}
	
	return key_val;
}


void key_scan(void)
{
	uint8_t key_val=0;
	key_val = key_read();
	if(key_val != uckey)
	uckey=key_val;
	else
	key_val = 0;
	
	switch(key_val)
	{
	case KEY_MODE_PRESS_FLAG:
			LED_MODE ^= 1;
		break;
	case KEY_SPEED_PRESS_FLAG:
			LED_SPEED ^= 1;
		break;
	default:
		break;
	}
}

// 中断服务函数
void BSP_KEY_EXTI_IRQ_HANDLER(void)
{
	// 中断标志位为 1，按键按下
	if (exti_interrupt_flag_get(BSP_KEY_EXTI_LINE) == RESET)
	{
		if (gpio_input_bit_get(PORT_KEY_MODE, PIN_KEY_MODE) == RESET)
		{
			printf("key press!\r\n");
			gpio_bit_toggle(PORT_LED_R, PIN_LED_R);
		}
		else {
			printf("key release!\r\n");
			//gpio_bit_toggle(PORT_LED_R, PIN_LED_R);
		}
		
		// 清中断标志位
		exti_interrupt_flag_clear(BSP_KEY_EXTI_LINE);
	}
}
