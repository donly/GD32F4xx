#include "bsp_motor.h"

// 电机驱动gpio引脚配置
void motor_gpio_config(void)
{
	// 左前轮
	/* 使能时钟 */
	rcu_periph_clock_enable(BSP_LQ_FI_RCU);
	/* 配置为输出模式 复用模式 */
	gpio_mode_set(BSP_LQ_FI_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, BSP_LQ_FI_PIN);
	/* 配置为推挽输出 50MHZ */
	gpio_output_options_set(BSP_LQ_FI_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_LQ_FI_PIN);
	gpio_af_set(BSP_LQ_FI_PORT, BSP_TIMER2_CH0, BSP_LQ_FI_PIN); // 配置GPIO的复用

	rcu_periph_clock_enable(BSP_LQ_BI_RCU);
	gpio_mode_set(BSP_LQ_BI_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, BSP_LQ_BI_PIN);
	gpio_output_options_set(BSP_LQ_BI_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_LQ_BI_PIN);
	gpio_af_set(BSP_LQ_BI_PORT, BSP_TIMER2_CH1, BSP_LQ_BI_PIN);
	
	// 左后轮
	rcu_periph_clock_enable(BSP_LH_FI_RCU);
	gpio_mode_set(BSP_LH_FI_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, BSP_LH_FI_PIN);
	gpio_output_options_set(BSP_LH_FI_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_LH_FI_PIN);
	gpio_af_set(BSP_LH_FI_PORT, BSP_TIMER2_CH2, BSP_LH_FI_PIN);
	rcu_periph_clock_enable(BSP_LH_BI_RCU);
	gpio_mode_set(BSP_LH_BI_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, BSP_LH_BI_PIN);
	gpio_output_options_set(BSP_LH_BI_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_LH_BI_PIN);
	gpio_af_set(BSP_LH_BI_PORT, BSP_TIMER2_CH3, BSP_LH_BI_PIN);
	
	// 右前轮
	rcu_periph_clock_enable(BSP_RQ_FI_RCU);
	gpio_mode_set(BSP_RQ_FI_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, BSP_RQ_FI_PIN);
	gpio_output_options_set(BSP_RQ_FI_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_RQ_FI_PIN);
	gpio_af_set(BSP_RQ_FI_PORT, BSP_TIMER1_CH3, BSP_RQ_FI_PIN);
	rcu_periph_clock_enable(BSP_RQ_BI_RCU);
	gpio_mode_set(BSP_RQ_BI_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, BSP_RQ_BI_PIN);
	gpio_output_options_set(BSP_RQ_BI_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_RQ_BI_PIN);
	gpio_af_set(BSP_RQ_BI_PORT, BSP_TIMER1_CH2, BSP_RQ_BI_PIN);
	
	// 右后轮
	rcu_periph_clock_enable(BSP_RH_FI_RCU);
	gpio_mode_set(BSP_RH_FI_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, BSP_RH_FI_PIN);
	gpio_output_options_set(BSP_RH_FI_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_RH_FI_PIN);
	gpio_af_set(BSP_RH_FI_PORT, BSP_TIMER1_CH0, BSP_RH_FI_PIN);
	rcu_periph_clock_enable(BSP_LH_BI_RCU);
	gpio_mode_set(BSP_RH_BI_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, BSP_RH_BI_PIN);
	gpio_output_options_set(BSP_RH_BI_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_RH_BI_PIN);
	gpio_af_set(BSP_RH_BI_PORT, BSP_TIMER1_CH1, BSP_RH_BI_PIN);
}

// 左前轮正转
void motor_lq_forward(uint16_t speed)
{
	gpio_mode_set(BSP_LQ_FI_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BSP_LQ_FI_PIN); // 通用推挽输出
	BSP_LQ_FI = 0;
	
	gpio_mode_set(BSP_LQ_BI_PORT,GPIO_MODE_AF,GPIO_PUPD_NONE, BSP_LQ_BI_PIN);	// 复用推挽输出
	timer_channel_output_pulse_value_config(BSP_PWM2_TIMER, TIMER_CH_1,speed); // 配置定时器通道输出脉冲值
}

// 左前轮后转
void motor_lq_backward(uint16_t speed)
{
	gpio_mode_set(BSP_LQ_FI_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BSP_LQ_FI_PIN); // 通用推挽输出
	BSP_LQ_FI = 1;
	
	gpio_mode_set(BSP_LQ_BI_PORT,GPIO_MODE_AF,GPIO_PUPD_NONE, BSP_LQ_BI_PIN);	// 复用推挽输出
	timer_channel_output_pulse_value_config(BSP_PWM2_TIMER, TIMER_CH_1,speed); // 配置定时器通道输出脉冲值
}

// 左后轮正转
void motor_lh_forward(uint16_t speed)
{
	gpio_mode_set(BSP_LH_FI_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BSP_LH_FI_PIN); // 通用推挽输出
	BSP_LH_FI = 0;
	
	gpio_mode_set(BSP_LH_BI_PORT,GPIO_MODE_AF,GPIO_PUPD_NONE, BSP_LH_BI_PIN);	// 复用推挽输出
	timer_channel_output_pulse_value_config(BSP_PWM2_TIMER, TIMER_CH_3,speed); // 配置定时器通道输出脉冲值
}

// 左后轮后转
void motor_lh_backward(uint16_t speed)
{
	gpio_mode_set(BSP_LH_FI_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BSP_LH_FI_PIN); // 通用推挽输出
	BSP_LH_FI = 1;
	
	gpio_mode_set(BSP_LH_BI_PORT,GPIO_MODE_AF,GPIO_PUPD_NONE, BSP_LH_BI_PIN);	// 复用推挽输出
	timer_channel_output_pulse_value_config(BSP_PWM2_TIMER, TIMER_CH_3,speed); // 配置定时器通道输出脉冲值
}

// 右前轮正转
void motor_rq_forward(uint16_t speed)
{
	gpio_mode_set(BSP_RQ_FI_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BSP_RQ_FI_PIN); // 通用推挽输出
	BSP_RQ_FI = 0;
	
	gpio_mode_set(BSP_RQ_BI_PORT,GPIO_MODE_AF,GPIO_PUPD_NONE, BSP_RQ_BI_PIN);	// 复用推挽输出
	timer_channel_output_pulse_value_config(BSP_PWM1_TIMER, TIMER_CH_2,speed); // 配置定时器通道输出脉冲值
}
// 右前轮后转
void motor_rq_backward(uint16_t speed)
{
	gpio_mode_set(BSP_RQ_FI_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BSP_RQ_FI_PIN); // 通用推挽输出
	BSP_RQ_FI = 1;
	
	gpio_mode_set(BSP_RQ_BI_PORT,GPIO_MODE_AF,GPIO_PUPD_NONE, BSP_RQ_BI_PIN);	// 复用推挽输出
	timer_channel_output_pulse_value_config(BSP_PWM1_TIMER, TIMER_CH_2,speed); // 配置定时器通道输出脉冲值
}

// 右后轮正转
void motor_rh_forward(uint16_t speed)
{
	gpio_mode_set(BSP_RH_FI_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BSP_RH_FI_PIN); // 通用推挽输出
	BSP_RH_FI = 0;
	
	gpio_mode_set(BSP_RH_BI_PORT,GPIO_MODE_AF,GPIO_PUPD_NONE, BSP_RH_BI_PIN);	// 复用推挽输出
	timer_channel_output_pulse_value_config(BSP_PWM1_TIMER, TIMER_CH_1,speed); // 配置定时器通道输出脉冲值
}
// 右后轮后转
void motor_rh_backward(uint16_t speed)
{
	gpio_mode_set(BSP_RH_FI_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BSP_RH_FI_PIN); // 通用推挽输出
	BSP_RH_FI = 1;
	
	gpio_mode_set(BSP_RH_BI_PORT,GPIO_MODE_AF,GPIO_PUPD_NONE, BSP_RH_BI_PIN);	// 复用推挽输出
	timer_channel_output_pulse_value_config(BSP_PWM1_TIMER, TIMER_CH_1,speed); // 配置定时器通道输出脉冲值
}


// 小车前进
void car_forward(uint16_t speed)
{
	motor_lq_forward(speed);
	motor_lh_forward(speed);
	motor_rq_forward(speed);
	motor_rh_forward(speed);
}

// 小车后退
void car_backward(uint16_t speed)
{
	motor_lq_backward(speed);
	motor_lh_backward(speed);
	motor_rq_backward(speed);
	motor_rh_backward(speed);
}

void car_left(uint16_t speed)
{
	motor_lq_backward(speed);
	motor_lh_backward(speed);
	motor_rq_forward(speed);
	motor_rh_forward(speed);
}

void car_right(uint16_t speed)
{
	motor_lq_forward(speed);
	motor_lh_forward(speed);
	motor_rq_backward(speed);
	motor_rh_backward(speed);
}

// 停止
void motor_lq_stop(uint16_t stopMode)
{
	if(stopMode)
	{
		gpio_mode_set(BSP_LQ_BI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_LQ_BI_PIN);//通用推挽输出
		BSP_LQ_BI=1;
		gpio_mode_set(BSP_LQ_FI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_LQ_FI_PIN);//通用推挽输出
		BSP_LQ_FI=1;
	}
	else
	{
		gpio_mode_set(BSP_LQ_BI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_LQ_BI_PIN);//通用推挽输出
		BSP_LQ_BI=0;
		gpio_mode_set(BSP_LQ_FI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_LQ_FI_PIN);//通用推挽输出
		BSP_LQ_FI=0;
	}
}
void motor_lh_stop(uint16_t stopMode)
{
	if(stopMode)
	{
		gpio_mode_set(BSP_LH_BI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_LH_BI_PIN);//通用推挽输出
		BSP_LH_BI=1;
		gpio_mode_set(BSP_LH_FI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_LH_FI_PIN);//通用推挽输出
		BSP_LH_FI=1;
	}
	else
	{
		gpio_mode_set(BSP_LH_BI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_LH_BI_PIN);//通用推挽输出
		BSP_LH_BI=0;
		gpio_mode_set(BSP_LH_FI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_LH_FI_PIN);//通用推挽输出
		BSP_LH_FI=0;
	}
}
void motor_rq_stop(uint16_t stopMode)
{
	if(stopMode)
	{
		gpio_mode_set(BSP_RQ_BI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_RQ_BI_PIN);//通用推挽输出
		BSP_RQ_BI=1;
		gpio_mode_set(BSP_RQ_FI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_RQ_FI_PIN);//通用推挽输出
		BSP_RQ_FI=1;
	}
	else
	{
		gpio_mode_set(BSP_RQ_BI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_RQ_BI_PIN);//通用推挽输出
		BSP_RQ_BI=0;
		gpio_mode_set(BSP_RQ_FI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_RQ_FI_PIN);//通用推挽输出
		BSP_RQ_FI=0;
	}
}
void motor_rh_stop(uint16_t stopMode)
{
	if(stopMode)
	{
		gpio_mode_set(BSP_RH_BI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_RH_BI_PIN);//通用推挽输出
		BSP_RH_BI=1;
		gpio_mode_set(BSP_RH_FI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_RH_FI_PIN);//通用推挽输出
		BSP_RH_FI=1;
	}
	else
	{
		gpio_mode_set(BSP_RH_BI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_RH_BI_PIN);//通用推挽输出
		BSP_RH_BI=0;
		gpio_mode_set(BSP_RH_FI_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,BSP_RH_FI_PIN);//通用推挽输出
		BSP_RH_FI=0;
	}
}

// stopMode=0：熄火停止；stopMode=1：刹车停止
void car_stop(uint16_t stopMode)
{
	if(stopMode)
	{
		motor_lq_stop(1);
		motor_lh_stop(1);
		motor_rq_stop(1);
		motor_rh_stop(1);
	}
	else
	{
		motor_lq_stop(0);
		motor_lh_stop(0);
		motor_rq_stop(0);
		motor_rh_stop(0);
	}
}

