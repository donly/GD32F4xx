#include "bsp_hcsr.h"

// 超声波模块gpio引脚配置
void hcsr04_gpio_config(void)
{
	// 使能时钟
	rcu_periph_clock_enable(HCSR04_RCU);
	// 配置为输出模式 浮空模式
	gpio_mode_set(PORT_HCSR04,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,HCSR04_Trig_PIN);
	// 配置为推挽输出 50MHZ
	gpio_output_options_set(PORT_HCSR04,GPIO_OTYPE_PP,GPIO_OSPEED_50MHZ,HCSR04_Trig_PIN);
	// 配置为输入模式 下拉模式
	gpio_mode_set(PORT_HCSR04,GPIO_MODE_INPUT,GPIO_PUPD_PULLDOWN,HCSR04_Echo_PIN);
	// Trig初始状态为低电平，看时序图
	gpio_bit_write(PORT_HCSR04,HCSR04_Trig_PIN,RESET); 
}

// 读取HCSR04模块测量的距离(取声音在空气传播的速度为340m/s)
// 返 回 值为int32_t类型的距离d（单位：mm）
int32_t hcsr04_get_distance(void)
{
	uint32_t t=0; // Echo高电平时间
	int32_t d=0;
	
	Trig=1;
	delay_1us(20);
	Trig=0;
	
	t=0;
	while(Echo==0)
	{
		delay_1us(1);
		t++;
		
		if(t >= 1000000)
			return -1; // 设备响应超时处理
	}
	
	t=0;
	while(Echo)
	{
		
		delay_1us(9); 
		t++;
		
		if(t >= 10000) // 超出测量范围处理
			return -2;	
	}
	
	d =  t*3/2;
	return  d;
}
