#include "bsp_pwm.h"


void pwm1_config(uint16_t pre, uint16_t per)
{
	// 定义定时器结构体
	timer_parameter_struct timer_init_param;
	timer_oc_parameter_struct timer_oc_int_param;
	
	
	// 配置时钟
	rcu_periph_clock_enable(BSP_PWM1_TIMER_RCU);
	rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);
	timer_deinit(BSP_PWM1_TIMER);
	timer_struct_para_init(&timer_init_param);
	timer_init_param.prescaler = pre - 1;
	timer_init_param.period = per - 1;
	timer_init(BSP_PWM1_TIMER, &timer_init_param);
	
	// 输出结构体
	timer_channel_output_struct_para_init(&timer_oc_int_param);
	timer_oc_int_param.outputstate = TIMER_CCX_ENABLE;
	timer_channel_output_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_0, &timer_oc_int_param);
	timer_channel_output_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_1, &timer_oc_int_param);
	timer_channel_output_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_2, &timer_oc_int_param);
	timer_channel_output_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_3, &timer_oc_int_param);
	
	timer_channel_output_pulse_value_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_0, 0);
	timer_channel_output_mode_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_0, TIMER_OC_MODE_PWM0);
	timer_channel_output_shadow_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_0, TIMER_OC_SHADOW_DISABLE);
	
	timer_channel_output_pulse_value_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_1, 0);
	timer_channel_output_mode_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_1, TIMER_OC_MODE_PWM0);
	timer_channel_output_shadow_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_1, TIMER_OC_SHADOW_DISABLE);
	
	timer_channel_output_pulse_value_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_2, 0);
	timer_channel_output_mode_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_2, TIMER_OC_MODE_PWM0);
	timer_channel_output_shadow_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_2, TIMER_OC_SHADOW_DISABLE);
	
	timer_channel_output_pulse_value_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_3, 0);
	timer_channel_output_mode_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_3, TIMER_OC_MODE_PWM0);
	timer_channel_output_shadow_config(BSP_PWM1_TIMER, BSP_PWM1_CHANNEL_3, TIMER_OC_SHADOW_DISABLE);
	
	timer_auto_reload_shadow_enable(BSP_PWM1_TIMER);
	
	timer_enable(BSP_PWM1_TIMER);
}

void pwm2_config(uint16_t pre, uint16_t per)
{
	// 定义定时器结构体
	timer_parameter_struct timer_init_param;
	timer_oc_parameter_struct timer_oc_int_param;
	
	
	// 配置时钟
	rcu_periph_clock_enable(BSP_PWM2_TIMER_RCU);
	rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);
	timer_deinit(BSP_PWM2_TIMER);
	timer_struct_para_init(&timer_init_param);
	timer_init_param.prescaler = pre - 1;
	timer_init_param.period = per - 1;
	timer_init(BSP_PWM2_TIMER, &timer_init_param);
	
	// 输出结构体
	timer_channel_output_struct_para_init(&timer_oc_int_param);
	timer_oc_int_param.outputstate = TIMER_CCX_ENABLE;
	timer_channel_output_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_0, &timer_oc_int_param);
	timer_channel_output_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_1, &timer_oc_int_param);
	timer_channel_output_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_2, &timer_oc_int_param);
	timer_channel_output_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_3, &timer_oc_int_param);
	
	timer_channel_output_pulse_value_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_0, 0);
	timer_channel_output_mode_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_0, TIMER_OC_MODE_PWM0);
	timer_channel_output_shadow_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_0, TIMER_OC_SHADOW_DISABLE);
	
	timer_channel_output_pulse_value_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_1, 0);
	timer_channel_output_mode_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_1, TIMER_OC_MODE_PWM0);
	timer_channel_output_shadow_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_1, TIMER_OC_SHADOW_DISABLE);
	
	timer_channel_output_pulse_value_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_2, 0);
	timer_channel_output_mode_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_2, TIMER_OC_MODE_PWM0);
	timer_channel_output_shadow_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_2, TIMER_OC_SHADOW_DISABLE);
	
	timer_channel_output_pulse_value_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_3, 0);
	timer_channel_output_mode_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_3, TIMER_OC_MODE_PWM0);
	timer_channel_output_shadow_config(BSP_PWM2_TIMER, BSP_PWM2_CHANNEL_3, TIMER_OC_SHADOW_DISABLE);

	timer_auto_reload_shadow_enable(BSP_PWM2_TIMER);
	
	timer_enable(BSP_PWM2_TIMER);
}
