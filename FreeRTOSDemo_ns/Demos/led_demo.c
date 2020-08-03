/*
 * FreeRTOS Kernel V10.2.1
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* MQ  LED includes */
#include "boards.h"

#define TASK_DELAY        200           /**< Task delay. Delays a LED0 task for 200 ms */

TaskHandle_t  led_toggle_task_handle;   /**< Reference to LED0 toggling FreeRTOS task. */

void vStartLEDDemo( void );

/**@brief LED0 task entry function.
 *
 * @param[in] pvParameter   Pointer that will be used as the parameter for the task.
 */
static void led_toggle_task_function (void * pvParameter)
{
    UNUSED_PARAMETER(pvParameter);
    while (1)
    {
        bsp_board_led_invert(BSP_BOARD_LED_0);

        /* Delay a task for a given number of ticks */
        vTaskDelay(pdMS_TO_TICKS(TASK_DELAY));

        /* Tasks must be implemented to never return... */
    }
}

void vStartLEDDemo( void )
{
#define LED_TASK_STACK_SIZE (configMINIMAL_STACK_SIZE << 2)
	static StackType_t x_led_toggle_task_stack[ LED_TASK_STACK_SIZE ] __attribute__( ( aligned( 32 ) ) );
	TaskParameters_t x_led_toggle_task_parameters =
	{
		.pvTaskCode		= led_toggle_task_function,
		.pcName			= "LED_toggle",
		.usStackDepth	= LED_TASK_STACK_SIZE,
		.pvParameters	= NULL,
		.uxPriority		= 1,
		.puxStackBuffer	= x_led_toggle_task_stack,
		.xRegions		=	{
								{ NRF_P0,				64,	tskMPU_REGION_DEVICE_MEMORY	},
								{ 0,					0,	0														},
								{ 0,					0,	0														},
							}
	};

	/* Configure LED-pins as outputs */
	bsp_board_init(BSP_INIT_LEDS);

	/* Create task for LED0 blinking. */
	UNUSED_VARIABLE(xTaskCreateRestricted( &( x_led_toggle_task_parameters ), NULL ));
}
