/**
 * \file usr_wireless.c
 *
 * Created: 3/3/2020 5:36:57 PM
 * Author: rohit
 *
 * \brief  User level API file of Wireless Project generated by Project Wizard
 *
 * Copyright (c) 2014 Atmel Corporation. All rights reserved.
 *
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * \page license License
 * Copyright(c) 2014, Atmel Corporation All rights reserved.
 *
 * Licensed under Atmel's Limited License Agreement --> EULA.txt
 */


#include "usr_wireless.h"
#include "wireless_config.h"
#include "adc.h"
#include "led.h"
#define ADC_INPUT      ADC_MUX_ADC0
#define ADC_VREF       ADC_VREF_AVCC

char Temperature[10];
char celsius;
int32_t light;
/**
* \brief This function needs to be edited by the user for adding application tasks
*/


void usr_wireless_app_task(void)
{
	
	static bool init_frame_trx = false ;
	
	
	if(!init_frame_trx)
	{   //Get the battery voltage and transmit it
	 
	    int bat_voltage;
	    bat_voltage = 2;
		 transmit_sample_frame((uint8_t *)&bat_voltage,sizeof(int));
		 init_frame_trx = true;
	}
	// TODO (Project Wizard) - Add application tasks here.
	// This function will be called repeatedly from main.c. (Refer to function app_task(), WirelessTask() in main.c)
	// The following code demonstrates transmission of a sample packet frame every 1 second.
/*adc_init(ADC_PRESCALER_DIV128);
	#ifdef TRANSMITTER_ENABLED	
	celsius = "1";//adc_read_8bit(ADC_INPUT, ADC_VREF);
	light =0xffff;

transmit_sample_frame((uint8_t*)&light, sizeof(light));	
	//	transmit_sample_frame((uint8_t *)&temp_sen,sizeof(float));
		delay_ms(1000);
	#endif
*/
	/* Examples : */

	/* Toggle an LED in when frame is received */
    /* led_toggle(); */

    /* Check for button press */
    /* if( button_pressed() )
    {
        // Add application specific code here
    } */
}

/**
* \brief This function needs to be edited by the user for adding  tasks when a frame is received
* \param frame pointer to the received frame
*/
void usr_frame_received_cb(frame_info_t *frame)
{
		//TODO (Project Wizard) - Add application task when the frame is received

		/* Toggle an LED in when frame is received */
		/* led_toggle(); */
}

/**
* \brief This function needs to be edited by the user for adding  tasks when a frame is transmitted
* \status Status of frame transmission i.e MAC_SUCCESS,MAC_NO_ACK,CHANNEL_ACCESS_FAILURE etc
* \param frame pointer to the transmitted frame
*/
void usr_frame_transmitted_cb(retval_t status, frame_info_t *frame)
{
	//TODO (Project Wizard) - Add application tasks when the frame is transmitted

	/* Toggle an LED in user-interface */
	led_toggle(); 
}
