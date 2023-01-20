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

/*!
    \brief    main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
//	uint16_t i = 0;
//	float f = 0.0;
	// 设置优先级分组
	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
	systick_config();
	led_gpio_config();
	key_gpio_config();
	usart_gpio_config(9600);
	//basic_timer_config(20000, 10000);
	pwm_config(200, 10000);
	
	//BSP_GPIOD_OCTL |= 0x08;
	//BSP_GPIOD_OCTL |= 0x01 << 7;
	//BSP_GPIOD_BOP |= (0x01 << (7 + 16));
	//BSP_GPIOD_BOP |= (0x01 << (7));
	//BSP_GPIOE_BOP |= (0x01 << (7));
//    gpio_bit_set(GPIOD, GPIO_PIN_7);
//		gpio_bit_reset(GPIOD, GPIO_PIN_7);
	//gpio_bit_write(GPIOD, GPIO_PIN_7, SET);
	
	//printf("Start counting...\r\n");
	
	while(1) {
		//gpio_bit_write(PORT_LED1, PIN_LED1, SET);
//		PDout(7) = 1;
//		delay_1ms(1000);
//		//gpio_bit_write(PORT_LED1, PIN_LED1, RESET);
//		PDout(7) = 0;
//		delay_1ms(1000);
//		i++;
//		f += 0.11;
//		printf("i=%d, f=%0.2f\r\n", i, f);
		
//		key_scan();
		pwm_breathing_led();
  }
}
