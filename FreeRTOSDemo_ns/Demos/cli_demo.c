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

#include "nrf_drv_uart.h"

#define CLI_OVER_UART 1
/* MQ  LED includes */
#include "boards.h"

/* MQ  CLI includes */
#include "nrf_drv_clock.h"
#include "app_error.h"
#include "nrf_delay.h"

#include "app_timer.h"
#include "fds.h"
#include "app_error.h"
#include "app_util.h"

#include "nrf_cli.h"
#include "nrf_cli_uart.h"
#include "nrf_cli_types.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_log_backend_flash.h"
#include "nrf_fstorage_nvmc.h"

/**
 * @brief Command line interface instance
 * */
#define CLI_EXAMPLE_LOG_QUEUE_SIZE  (4)

#if CLI_OVER_USB_CDC_ACM
NRF_CLI_CDC_ACM_DEF(m_cli_cdc_acm_transport);
NRF_CLI_DEF(m_cli_cdc_acm,
            "usb_cli:~$ ",
            &m_cli_cdc_acm_transport.transport,
            '\r',
            CLI_EXAMPLE_LOG_QUEUE_SIZE);
#endif //CLI_OVER_USB_CDC_ACM

#if CLI_OVER_UART
NRF_CLI_UART_DEF(m_cli_uart_transport, 1, 64, 16);
NRF_CLI_DEF(m_cli_uart,
            "uart_cli:~$ ",
            &m_cli_uart_transport.transport,
            '\r\n',
            CLI_EXAMPLE_LOG_QUEUE_SIZE);
#endif

/*
NRF_CLI_RTT_DEF(m_cli_rtt_transport);
NRF_CLI_DEF(m_cli_rtt,
            "rtt_cli:~$ ",
            &m_cli_rtt_transport.transport,
            '\n',
            CLI_EXAMPLE_LOG_QUEUE_SIZE);
*/

#if NRF_LOG_BACKEND_FLASHLOG_ENABLED
NRF_LOG_BACKEND_FLASHLOG_DEF(m_flash_log_backend);
#endif

#if NRF_LOG_BACKEND_CRASHLOG_ENABLED
NRF_LOG_BACKEND_CRASHLOG_DEF(m_crash_log_backend);
#endif

/* Counter timer. */
APP_TIMER_DEF(m_timer_0);

TaskHandle_t  CLI_task_handle;   /**< Reference to CLI toggling FreeRTOS task. */

void vStartCLIDemo( void );

static void cli_process(void)
{
#if CLI_OVER_USB_CDC_ACM
    nrf_cli_process(&m_cli_cdc_acm);
#endif

#if CLI_OVER_UART
    nrf_cli_process(&m_cli_uart);
#endif

    //nrf_cli_process(&m_cli_rtt);
}



/**@brief LED0 task entry function.
 *
 * @param[in] pvParameter   Pointer that will be used as the parameter for the task.
 */
static void cli_task_function (void * pvParameter)
{
    UNUSED_PARAMETER(pvParameter);
    while (1)
    {
    	//UNUSED_RETURN_VALUE(NRF_LOG_PROCESS());
    	cli_process();

        /* Tasks must be implemented to never return... */
    }
}

static void cli_init(void)
{
    ret_code_t ret;

#if CLI_OVER_USB_CDC_ACM
    ret = nrf_cli_init(&m_cli_cdc_acm, NULL, true, true, NRF_LOG_SEVERITY_INFO);
    APP_ERROR_CHECK(ret);
#endif

#if CLI_OVER_UART
    nrf_drv_uart_config_t uart_config = NRF_DRV_UART_DEFAULT_CONFIG;
    uart_config.pseltxd = TX_PIN_NUMBER_UARTE1;
    uart_config.pselrxd = RX_PIN_NUMBER_UARTE1;
    uart_config.pselrts = RTS_PIN_NUMBER_UARTE1;
    uart_config.pselcts = CTS_PIN_NUMBER_UARTE1;
    uart_config.hwfc    = NRF_UART_HWFC_ENABLED;
    ret = nrf_cli_init(&m_cli_uart, &uart_config, true, true, NRF_LOG_SEVERITY_INFO);
    APP_ERROR_CHECK(ret);
#endif

    //ret = nrf_cli_init(&m_cli_rtt, NULL, true, true, NRF_LOG_SEVERITY_INFO);
    APP_ERROR_CHECK(ret);
}

static void cli_start(void)
{
    ret_code_t ret;

#if CLI_OVER_USB_CDC_ACM
    ret = nrf_cli_start(&m_cli_cdc_acm);
    APP_ERROR_CHECK(ret);
#endif

#if CLI_OVER_UART
    ret = nrf_cli_start(&m_cli_uart);
    APP_ERROR_CHECK(ret);
#endif

    //ret = nrf_cli_start(&m_cli_rtt);
    //APP_ERROR_CHECK(ret);
}

static void flashlog_init(void)
{
    ret_code_t ret;
    int32_t backend_id;

    ret = nrf_log_backend_flash_init(&nrf_fstorage_nvmc);
    APP_ERROR_CHECK(ret);
#if NRF_LOG_BACKEND_FLASHLOG_ENABLED
    backend_id = nrf_log_backend_add(&m_flash_log_backend, NRF_LOG_SEVERITY_WARNING);
    APP_ERROR_CHECK_BOOL(backend_id >= 0);

    nrf_log_backend_enable(&m_flash_log_backend);
#endif

#if NRF_LOG_BACKEND_CRASHLOG_ENABLED
    backend_id = nrf_log_backend_add(&m_crash_log_backend, NRF_LOG_SEVERITY_INFO);
    APP_ERROR_CHECK_BOOL(backend_id >= 0);

    nrf_log_backend_enable(&m_crash_log_backend);
#endif
}

static	uint32_t m_counter;
static	bool m_counter_active;

static void timer_handle(void * p_context)
{
    UNUSED_PARAMETER(p_context);

    if (m_counter_active)
    {
        m_counter++;
        NRF_LOG_RAW_INFO("counter = %d\n", m_counter);
    }
}

void vStartCLIDemo( void )
{
#define CLI_TASK_STACK_SIZE (configMINIMAL_STACK_SIZE << 2)
	static StackType_t x_cli_task_stack[ CLI_TASK_STACK_SIZE ] __attribute__( ( aligned( 32 ) ) );

	TaskParameters_t x_cli_task_parameters =
	{
		.pvTaskCode		= cli_task_function,
		.pcName			= "CLI",
		.usStackDepth	= CLI_TASK_STACK_SIZE,
		.pvParameters	= NULL,
		.uxPriority		= (tskIDLE_PRIORITY | portPRIVILEGE_BIT),
		.puxStackBuffer	= x_cli_task_stack,
		.xRegions		=	{
								{ 0,					0,	0		},
								{ 0,					0,	0		},
								{ 0,					0,	0		},
							}
	};

	ret_code_t ret;

	ret = nrf_drv_clock_init();
	APP_ERROR_CHECK(ret);
	nrf_drv_clock_lfclk_request(NULL);

	ret = app_timer_init();
	APP_ERROR_CHECK(ret);

	ret = app_timer_create(&m_timer_0, APP_TIMER_MODE_REPEATED, timer_handle);
	APP_ERROR_CHECK(ret);

	ret = app_timer_start(m_timer_0, APP_TIMER_TICKS(1000), NULL);
	APP_ERROR_CHECK(ret);

	cli_init();

	ret = fds_init();
	APP_ERROR_CHECK(ret);


	UNUSED_RETURN_VALUE(nrf_log_config_load());

	cli_start();
	flashlog_init();

	/* Create task for CLI. */
	UNUSED_VARIABLE(xTaskCreateRestricted( &( x_cli_task_parameters ), NULL ));
}

