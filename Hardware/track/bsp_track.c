#include "bsp_track.h"

FlagStatus XJ01  = RESET;
FlagStatus XJ02  = RESET;
FlagStatus XJ03  = RESET;
FlagStatus XJ04  = RESET;
FlagStatus XJ05  = RESET;


// 循迹gpio引脚配置
void track_gpio_config(void) 	 
{
	/* 使能时钟 */
	rcu_periph_clock_enable(XJ01_RCU);
	/* 配置为输入模式 上拉模式 */
	gpio_mode_set(PORT_XJ01,GPIO_MODE_INPUT,GPIO_PUPD_PULLUP,XJ01_PIN);
	
	/* 使能时钟 */
	rcu_periph_clock_enable(XJ02_RCU);
	/* 配置为输入模式 上拉模式 */
	gpio_mode_set(PORT_XJ02,GPIO_MODE_INPUT,GPIO_PUPD_PULLUP,XJ02_PIN);
	
	/* 使能时钟 */
	rcu_periph_clock_enable(XJ03_RCU);
	/* 配置为输入模式 上拉模式 */
	gpio_mode_set(PORT_XJ03,GPIO_MODE_INPUT,GPIO_PUPD_PULLUP,XJ03_PIN);
	
	/* 使能时钟 */
	rcu_periph_clock_enable(XJ04_RCU);
	/* 配置为输入模式 上拉模式 */
	gpio_mode_set(PORT_XJ04,GPIO_MODE_INPUT,GPIO_PUPD_PULLUP,XJ04_PIN);
	
	/* 使能时钟 */
	rcu_periph_clock_enable(XJ05_RCU);
	/* 配置为输入模式 上拉模式 */
	gpio_mode_set(PORT_XJ05,GPIO_MODE_INPUT,GPIO_PUPD_PULLUP,XJ05_PIN);
}

// 黑线检测函数
void Black_Line_Detection(void)
{
	XJ01  = gpio_input_bit_get(PORT_XJ01,XJ01_PIN);
	XJ02  = gpio_input_bit_get(PORT_XJ02,XJ02_PIN);
	XJ03  = gpio_input_bit_get(PORT_XJ03,XJ03_PIN);
	XJ04  = gpio_input_bit_get(PORT_XJ04,XJ04_PIN);
	XJ05  = gpio_input_bit_get(PORT_XJ05,XJ05_PIN);
}
