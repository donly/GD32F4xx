/*!
    \file    main.c
    \brief   led

    \version 2023-01-09, V1.0.0, firmware for GD32F4xx
*/

/*
    Copyright (c) 2023, PROPGM.COM

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/


#include <stdio.h>
#include "main.h"
#include "bsp_led.h"
#include "sys.h"
#include "bsp_usart.h"
#include "bsp_key.h"
#include "bsp_basic_timer.h"
#include "bsp_pwm.h"
#include "string.h"
#include "bsp_dma.h"
#include "bsp_beep.h"
#include "bsp_motor.h"
#include "bsp_hcsr.h"
#include "bsp_track.h"

#define SPEED_L 40
#define SPEED_M 50
#define SPEED_H 80
uint16_t speed = SPEED_M;

int32_t distance = 0;												//测量距离
uint16_t No_Black_Line_TimeCount = 0 ;			// 没有发现黑线时间
uint8_t  LongTime_No_Black_Line_Flag = 0 ;	// 长时间没发现黑线标志位

/*!
    \brief    main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
	// 设置优先级分组
	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
	systick_config();
	motor_gpio_config();
	pwm1_config(200, 100); // 10000Hz
	pwm2_config(200, 100); // 10000Hz
	track_gpio_config();			// 循迹gpio引脚配置
	led_gpio_config();
	beep_gpio_config();
	key_gpio_config();
	usart_gpio_config(9600U);
	uart6_gpio_config(9600U);	// 蓝牙接口，串口6初始化
	//basic_timer_config(20000, 10000);
	hcsr04_gpio_config();
	
	//BSP_GPIOD_OCTL |= 0x08;
	//BSP_GPIOD_OCTL |= 0x01 << 7;
	//BSP_GPIOD_BOP |= (0x01 << (7 + 16));
	//BSP_GPIOD_BOP |= (0x01 << (7));
	//BSP_GPIOE_BOP |= (0x01 << (7));
//    gpio_bit_set(GPIOD, GPIO_PIN_7);
//		gpio_bit_reset(GPIOD, GPIO_PIN_7);
	//gpio_bit_write(GPIOD, GPIO_PIN_7, SET);
	BEEP_OFF;
	//熄火停止
	car_stop(FLAMEOUT_STOP);
	printf("ready");
#if 0
	printf("-------This is bluetooth AT test-------\r\n");
	HC05_Bluetooth2_0_config();//直接使用串口调试助手发送AT指令也行，需要借助USB转TTL模块
#endif
//	dma_config();
	
//	PBout(4) = 1;
//	PAout(7) = 1;
//	
//	PAout(3) = 1;
//	PAout(2) = 1;
//	
//	PBout(1) = 1;
//	PBout(0) = 1;
//	
//	PAout(1) = 1;
//	PAout(0) = 1;
	
	while(1) {
		key_scan();
		
		switch (motion_mode) {
			case MOTION_MODE_AUTO_FLAG:
				LED_MODE = 1;	//模式灯亮
				Black_Line_Detection();//黑线检测函数

				if(XJ01==No_Black_Line_Found && XJ02==No_Black_Line_Found && XJ03==Black_Line_Found && XJ04==No_Black_Line_Found && XJ05==No_Black_Line_Found)//3中间检测到黑线00100
				{
					car_forward(speed);	//前进
					printf("car_forward");
		//			delay_1ms(2);
				}
				if(XJ01==No_Black_Line_Found && XJ02==Black_Line_Found && XJ03==Black_Line_Found && XJ04==Black_Line_Found && XJ05==No_Black_Line_Found)//2 3 4中间检测到黑线00100
				{
					car_forward(speed);	//前进
					printf("car_forward");
		//			delay_1ms(2);
				}
				if(XJ01==No_Black_Line_Found && XJ02==Black_Line_Found && XJ03==Black_Line_Found && XJ04==No_Black_Line_Found && XJ05==No_Black_Line_Found)//2 3检测到黑线(右偏小)01100
				{
					motor_lq_forward(40);
					motor_lh_forward(40);
					motor_rq_forward(SPEED_H);
					motor_rh_forward(SPEED_H);
		//			delay_1ms(2);
				}
				if(XJ01==No_Black_Line_Found && XJ02==Black_Line_Found && XJ03==No_Black_Line_Found && XJ04==No_Black_Line_Found && XJ05==No_Black_Line_Found)//2检测到黑线(右偏大)01000
				{
					motor_lq_forward(30);
					motor_lh_forward(30);
					motor_rq_forward(SPEED_H);
					motor_rh_forward(SPEED_H);
		//			delay_1ms(2);
				}
				if(XJ01==No_Black_Line_Found && XJ02==No_Black_Line_Found && XJ03==Black_Line_Found && XJ04==Black_Line_Found && XJ05==No_Black_Line_Found)//4 3检测到黑线(左偏小)00110
				{
					motor_lq_forward(SPEED_H);
					motor_lh_forward(SPEED_H);
					motor_rq_forward(40);
					motor_rh_forward(40);
		//			delay_1ms(2);
				}
				if(XJ01==No_Black_Line_Found && XJ02==No_Black_Line_Found && XJ03==No_Black_Line_Found && XJ04==Black_Line_Found && XJ05==No_Black_Line_Found)//4检测到黑线(左偏大)
				{
					motor_lq_forward(SPEED_H);
					motor_lh_forward(SPEED_H);
					motor_rq_forward(30);
					motor_rh_forward(30);
		//			delay_1ms(2);
				}
				if(XJ01==Black_Line_Found && XJ02==Black_Line_Found && XJ03==No_Black_Line_Found && XJ04==No_Black_Line_Found && XJ05==No_Black_Line_Found)//1 2检测到黑线(左转)
				{
					motor_lq_backward(55);
					motor_lh_backward(55);
					motor_rq_forward(SPEED_H);
					motor_rh_forward(SPEED_H);
		//			delay_1ms(2);
				}
				if(XJ01==Black_Line_Found && XJ02==No_Black_Line_Found && XJ03==No_Black_Line_Found && XJ04==No_Black_Line_Found && XJ05==No_Black_Line_Found)//1 检测到黑线(左转)
				{
					motor_lq_backward(45);
					motor_lh_backward(45);
					motor_rq_forward(SPEED_H);
					motor_rh_forward(SPEED_H);
		//			delay_1ms(2);
				}
				if(XJ01==Black_Line_Found && XJ02==Black_Line_Found && XJ03==Black_Line_Found && XJ04==No_Black_Line_Found && XJ05==No_Black_Line_Found)//1 2 3检测到黑线(左转)
				{
					motor_lq_backward(35);
					motor_lh_backward(35);
					motor_rq_forward(SPEED_H);
					motor_rh_forward(SPEED_H);
		//			delay_1ms(2);
				}
				
				if(XJ01==No_Black_Line_Found && XJ02==No_Black_Line_Found && XJ03==No_Black_Line_Found && XJ04==Black_Line_Found && XJ05==Black_Line_Found)//4 5检测到黑线(右转)
				{
					motor_lq_forward(SPEED_H);
					motor_lh_forward(SPEED_H);
					motor_rq_backward(55);
					motor_rh_backward(55); 
		//			delay_1ms(2);
				}
				if(XJ01==No_Black_Line_Found && XJ02==No_Black_Line_Found && XJ03==No_Black_Line_Found && XJ04==No_Black_Line_Found && XJ05==Black_Line_Found)//5 检测到黑线(右转)
				{
					motor_lq_forward(SPEED_H);
					motor_lh_forward(SPEED_H);
					motor_rq_backward(45);
					motor_rh_backward(45);
		//			delay_1ms(2);
				}
				if(XJ01==No_Black_Line_Found && XJ02==No_Black_Line_Found && XJ03==Black_Line_Found && XJ04==Black_Line_Found && XJ05==Black_Line_Found)//3 4 5检测到黑线(右转)
				{
					motor_lq_forward(SPEED_H);
					motor_lh_forward(SPEED_H);
					motor_rq_backward(35);
					motor_rh_backward(35);
		//			delay_1ms(2); 
				}
				if(XJ01==Black_Line_Found && XJ02==Black_Line_Found && XJ03==Black_Line_Found && XJ04==Black_Line_Found && XJ05==Black_Line_Found)
				{
					car_stop(BREAK_STOP);//刹车停止
					delay_1ms(4000);
					car_forward(SPEED_H);	//前进
					delay_1ms(200);
				}
				if(XJ01==Black_Line_Found || XJ02==Black_Line_Found || XJ03==Black_Line_Found || XJ04==Black_Line_Found || XJ05==Black_Line_Found)
				{
					No_Black_Line_TimeCount=0;
					LongTime_No_Black_Line_Flag=0;
				}
				if(XJ01==No_Black_Line_Found && XJ02==No_Black_Line_Found && XJ03==No_Black_Line_Found && XJ04==No_Black_Line_Found && XJ05==No_Black_Line_Found)//未检测到黑线(停止)
				{
					if(LongTime_No_Black_Line_Flag == 1)//长时间
						car_stop(BREAK_STOP);	//刹车停止
					else
						car_forward(SPEED_H);	//前进
				}
				break;
			case MOTION_MODE_AVOID_FLAG:
				LED_MODE = 0;
				distance=hcsr04_get_distance();
				printf("distance is :%d mm\r\n",distance);
				delay_1us(1000000);/*注意：因为超声波驱动需要用到微秒延时，所以这
									里是直接修改了滴答定时器的中断时长，后面可以采用定时器中断的方式重新写超声波的驱动*/
				break;
			case MOTION_MODE_BLE_FLAG:
				LED_MODE = 0;
				break;
		}
		
		if (g_recv_complete_flag) {
			g_recv_complete_flag = 0;
			printf("len=%d", g_recv_len);
			printf("buff=%s\r\n", g_recv_buff);

			switch(g_recv_buff[0]){
					case 1:
						car_forward(speed);//前进
						break;
					case 4:
						car_right(speed);//右转
						break;
					case 2:
						car_left(speed);//左转
						break;
					case 0:
						car_stop(1);//停止
						break;
					case 3:
						car_backward(speed);//后退
						break;
					case 5:
						BEEP_ON;
						break;
					case 6:
						BEEP_OFF;
						break;
					case 7:
						LED_L_ON; //开灯
						LED_R_ON;
						break;
					case 8:
						LED_L_OFF;//关灯
						LED_R_OFF;
						break;
					case 9:
						speed=SPEED_L;//慢速
						break;
					case 0xa:
						speed=SPEED_M;//中速
						break;
					case 0xb:
						speed=SPEED_H;//快速
						break;
					case 0xc:
						motion_mode = MOTION_MODE_AUTO_FLAG;
						break;
					case 0xd:
						motion_mode = MOTION_MODE_AVOID_FLAG;
						break;
					case 0xe:
						motion_mode = MOTION_MODE_BLE_FLAG;
						break;
					default:
//						printf("指令错误！！！\r\n");
						break;
				}
			
			memset(g_recv_buff, 0, g_recv_len);
			g_recv_len = 0;
		}
  }
}
