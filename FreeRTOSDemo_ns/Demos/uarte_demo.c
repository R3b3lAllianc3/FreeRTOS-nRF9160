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

#include "boards.h"

/* UARTE includes. */
#include "nrf_drv_uart.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"

//TaskHandle_t  m_uarte_task_handle;   /**< Reference to UARTE FreeRTOS task. */


void vStartUARTEDemo( void );

static void uart_event_handler(nrf_drv_uart_event_t * p_event, void * p_context)
{
    //nrf_cli_uart_internal_t * p_internal = (nrf_cli_uart_internal_t *)p_context;
    //ret_code_t err_code = NRF_SUCCESS;
    //UNUSED_VARIABLE(err_code);
    //uint8_t * p_data;
    //size_t len = 255;
    switch (p_event->type)
    {
        case NRF_DRV_UART_EVT_ERROR:
            /*
        	NRF_LOG_WARNING("id:%d, evt: ERROR:%d",
                            p_internal->p_uart->inst_idx,
                            p_event->data.error.error_mask);
            err_code = nrf_ringbuf_put(p_internal->p_rx_ringbuf, p_event->data.error.rxtx.bytes);
            ASSERT((err_code == NRF_SUCCESS) || (err_code == NRF_ERROR_NO_MEM));
            err_code = rx_try(p_internal);
            ASSERT(err_code == NRF_SUCCESS);
*/
            break;

        case NRF_DRV_UART_EVT_RX_DONE:
/*
            err_code = nrf_ringbuf_put(p_internal->p_rx_ringbuf, p_event->data.rxtx.bytes);
            ASSERT((err_code == NRF_SUCCESS) || (err_code == NRF_ERROR_NO_MEM));

            if (p_event->data.rxtx.bytes)
            {
                NRF_LOG_INFO("id:%d, evt: RXRDY len:%d",
                             p_internal->p_uart->inst_idx,
                             p_event->data.rxtx.bytes);
                NRF_LOG_HEXDUMP_DEBUG(p_event->data.rxtx.p_data, p_event->data.rxtx.bytes);
                p_internal->p_cb->handler(NRF_CLI_TRANSPORT_EVT_RX_RDY,
                                          p_internal->p_cb->p_context);
            }
            err_code = rx_try(p_internal);
            ASSERT(err_code == NRF_SUCCESS);
*/
            break;

        case NRF_DRV_UART_EVT_TX_DONE:
/*
        	err_code = nrf_ringbuf_free(p_internal->p_tx_ringbuf, p_event->data.rxtx.bytes);
            ASSERT(err_code == NRF_SUCCESS);
            len = 255;
            err_code = nrf_ringbuf_get(p_internal->p_tx_ringbuf, &p_data, &len, true);
            ASSERT(err_code == NRF_SUCCESS);
            if (len)
            {
                NRF_LOG_INFO("id:%d, evt uart_tx, len:%d", p_internal->p_uart->inst_idx, len);
                err_code = nrf_drv_uart_tx(p_internal->p_uart, p_data, len);
            ASSERT(err_code == NRF_SUCCESS);
            }
            p_internal->p_cb->handler(NRF_CLI_TRANSPORT_EVT_TX_RDY, p_internal->p_cb->p_context);
            NRF_LOG_INFO("id:%d, evt: TXRDY, len:%d",
                         p_internal->p_uart->inst_idx,
                         p_event->data.rxtx.bytes);
*/
            break;

        default:
/*
        	NRF_LOG_ERROR("Unknown event");
            ASSERT(false);
*/
        	break;
    }
}

#if 1
/**@brief UARTE task entry function.
 *
 * @param[in] pvParameter   Pointer that will be used as the parameter for the task.
 */
static void uarte_task_function (void * pvParameter)
{
	uint8_t tx_string[] = {72, 69, 108, 108, 79, 32, 119, 79, 82, 76, 68, 10, 13};
	nrf_drv_uart_t m_uarte = NRF_DRV_UART_INSTANCE(1);
	nrf_drv_uart_config_t m_uarte_config =  NRF_DRV_UART_DEFAULT_CONFIG;

	m_uarte_config.pseltxd = TX_PIN_NUMBER_UARTE1;
	m_uarte_config.pselrxd = RX_PIN_NUMBER_UARTE1;
	m_uarte_config.pselrts = RTS_PIN_NUMBER_UARTE1;
	m_uarte_config.pselcts = CTS_PIN_NUMBER_UARTE1;
	m_uarte_config.hwfc    = NRF_UART_HWFC_DISABLED;

	UNUSED_VARIABLE(nrf_drv_uart_init(&m_uarte,	&m_uarte_config, uart_event_handler));

    UNUSED_PARAMETER(pvParameter);
    while (1)
    {
        if (!nrf_drv_uart_tx_in_progress(&m_uarte))
        {
        	UNUSED_VARIABLE(nrf_drv_uart_tx(&m_uarte, tx_string, sizeof(tx_string)));
        	vTaskDelay(pdMS_TO_TICKS(500));
        }

        /* Delay a task for a given number of ticks */
        //vTaskDelay(pdMS_TO_TICKS(TASK_DELAY));

        /* Tasks must be implemented to never return... */
    }
}
#else
static void uarte_task_function (void * pvParameter)
{
	uint32_t counter = 0;

    UNUSED_PARAMETER(pvParameter);
    while (1)
    {
    	UNUSED_RETURN_VALUE(NRF_LOG_PROCESS());
    	counter++;
        NRF_LOG_INFO("Test %i", counter);
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}
#endif

void vStartUARTEDemo( void )
{
#define UARTE_TASK_STACK_SIZE (configMINIMAL_STACK_SIZE << 2)
	static StackType_t x_uarte_task_stack[ (UARTE_TASK_STACK_SIZE) ] __attribute__( ( aligned( 32 ) ) );
	TaskParameters_t x_uarte_task_parameters =
	{
		.pvTaskCode		= uarte_task_function,
		.pcName			= "UARTE",
		.usStackDepth	= (UARTE_TASK_STACK_SIZE),
		.pvParameters	= NULL,
		.uxPriority		= (tskIDLE_PRIORITY | portPRIVILEGE_BIT),
		.puxStackBuffer	= x_uarte_task_stack,
		.xRegions		=	{
								{ 0,					0,		0 							},
								{ NRF_P0,				64,		tskMPU_REGION_DEVICE_MEMORY	},
								{ NRF_UARTE0,			1408,	tskMPU_REGION_DEVICE_MEMORY },
							}
	};

	/* Create task for UARTE TX. */
	UNUSED_VARIABLE(xTaskCreateRestricted( &( x_uarte_task_parameters ), NULL ));
}
