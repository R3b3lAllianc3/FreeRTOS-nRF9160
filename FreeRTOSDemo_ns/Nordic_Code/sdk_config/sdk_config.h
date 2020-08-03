/**
 * Copyright (c) 2017 - 2019, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */



#ifndef SDK_CONFIG_H
#define SDK_CONFIG_H
// <e> NRF_CLOCK_ENABLED - nrf_drv_clock - CLOCK peripheral driver - legacy layer
//==========================================================
#ifndef NRF_CLOCK_ENABLED
#define NRF_CLOCK_ENABLED 1
#endif
// <o> CLOCK_CONFIG_LF_SRC  - LF Clock Source
 
// <0=> RC 
// <1=> XTAL 
// <2=> Synth 
// <131073=> External Low Swing 
// <196609=> External Full Swing 

#ifndef CLOCK_CONFIG_LF_SRC
#define CLOCK_CONFIG_LF_SRC 1
#endif

// <q> CLOCK_CONFIG_LF_CAL_ENABLED  - Calibration enable for LF Clock Source
 

#ifndef CLOCK_CONFIG_LF_CAL_ENABLED
#define CLOCK_CONFIG_LF_CAL_ENABLED 0
#endif

// <o> CLOCK_CONFIG_IRQ_PRIORITY  - Interrupt priority
 

// <i> Priorities 0,2 (nRF51) and 0,1,4,5 (nRF52) are reserved for SoftDevice
// <0=> 0 (highest) 
// <1=> 1 
// <2=> 2 
// <3=> 3 
// <4=> 4 
// <5=> 5 
// <6=> 6 
// <7=> 7 

#ifndef CLOCK_CONFIG_IRQ_PRIORITY
#define CLOCK_CONFIG_IRQ_PRIORITY 6
#endif

// </e>


// <e> NRF_LOG_BACKEND_UART_ENABLED - nrf_log_backend_uart - Log UART backend
//==========================================================
#ifndef NRF_LOG_BACKEND_UART_ENABLED
#define NRF_LOG_BACKEND_UART_ENABLED 1
#endif
// <o> NRF_LOG_BACKEND_UART_TX_PIN - UART TX pin
#ifndef NRF_LOG_BACKEND_UART_TX_PIN
#define NRF_LOG_BACKEND_UART_TX_PIN 29
#endif

// <o> NRF_LOG_BACKEND_UART_BAUDRATE  - Default Baudrate

// <323584=> 1200 baud
// <643072=> 2400 baud
// <1290240=> 4800 baud
// <2576384=> 9600 baud
// <3862528=> 14400 baud
// <5152768=> 19200 baud
// <7716864=> 28800 baud
// <10289152=> 38400 baud
// <15400960=> 57600 baud
// <20615168=> 76800 baud
// <30801920=> 115200 baud
// <61865984=> 230400 baud
// <67108864=> 250000 baud
// <121634816=> 460800 baud
// <251658240=> 921600 baud
// <268435456=> 1000000 baud

#ifndef NRF_LOG_BACKEND_UART_BAUDRATE
#define NRF_LOG_BACKEND_UART_BAUDRATE 30801920
#endif

// <o> NRF_LOG_BACKEND_UART_TEMP_BUFFER_SIZE - Size of buffer for partially processed strings.
// <i> Size of the buffer is a trade-off between RAM usage and processing.
// <i> if buffer is smaller then strings will often be fragmented.
// <i> It is recommended to use size which will fit typical log and only the
// <i> longer one will be fragmented.

#ifndef NRF_LOG_BACKEND_UART_TEMP_BUFFER_SIZE
#define NRF_LOG_BACKEND_UART_TEMP_BUFFER_SIZE 64
#endif

// </e>



#define NRF_FPRINTF_ENABLED 1

// <e> NRF_LOG_ENABLED - nrf_log - Logger
//==========================================================
#ifndef NRF_LOG_ENABLED
#define NRF_LOG_ENABLED 1
#endif
// <h> Log message pool - Configuration of log message pool

//==========================================================
// <o> NRF_LOG_MSGPOOL_ELEMENT_SIZE - Size of a single element in the pool of memory objects. 
// <i> If a small value is set, then performance of logs processing
// <i> is degraded because data is fragmented. Bigger value impacts
// <i> RAM memory utilization. The size is set to fit a message with
// <i> a timestamp and up to 2 arguments in a single memory object.

#ifndef NRF_LOG_MSGPOOL_ELEMENT_SIZE
#define NRF_LOG_MSGPOOL_ELEMENT_SIZE 20
#endif

// <o> NRF_LOG_MSGPOOL_ELEMENT_COUNT - Number of elements in the pool of memory objects 
// <i> If a small value is set, then it may lead to a deadlock
// <i> in certain cases if backend has high latency and holds
// <i> multiple messages for long time. Bigger value impacts
// <i> RAM memory usage.

#ifndef NRF_LOG_MSGPOOL_ELEMENT_COUNT
#define NRF_LOG_MSGPOOL_ELEMENT_COUNT 8
#endif

// </h> 
//==========================================================

// <q> NRF_LOG_ALLOW_OVERFLOW  - Configures behavior when circular buffer is full.
 

// <i> If set then oldest logs are overwritten. Otherwise a 
// <i> marker is injected informing about overflow.

#ifndef NRF_LOG_ALLOW_OVERFLOW
#define NRF_LOG_ALLOW_OVERFLOW 1
#endif

// <o> NRF_LOG_BUFSIZE  - Size of the buffer for storing logs (in bytes).
 

// <i> Must be power of 2 and multiple of 4.
// <i> If NRF_LOG_DEFERRED = 0 then buffer size can be reduced to minimum.
// <128=> 128 
// <256=> 256 
// <512=> 512 
// <1024=> 1024 
// <2048=> 2048 
// <4096=> 4096 
// <8192=> 8192 
// <16384=> 16384 

#ifndef NRF_LOG_BUFSIZE
#define NRF_LOG_BUFSIZE 1024
#endif

// <q> NRF_LOG_CLI_CMDS  - Enable CLI commands for the module.
 

#ifndef NRF_LOG_CLI_CMDS
#define NRF_LOG_CLI_CMDS 1
#endif

// <o> NRF_LOG_DEFAULT_LEVEL  - Default Severity level
 
// <0=> Off 
// <1=> Error 
// <2=> Warning 
// <3=> Info 
// <4=> Debug 

#ifndef NRF_LOG_DEFAULT_LEVEL
#define NRF_LOG_DEFAULT_LEVEL 4
#endif

// <q> NRF_LOG_DEFERRED  - Enable deffered logger.
 

// <i> Log data is buffered and can be processed in idle.

#ifndef NRF_LOG_DEFERRED
#define NRF_LOG_DEFERRED 0
#endif

// <q> NRF_LOG_FILTERS_ENABLED  - Enable dynamic filtering of logs.
 

#ifndef NRF_LOG_FILTERS_ENABLED
#define NRF_LOG_FILTERS_ENABLED 1
#endif

// <q> NRF_LOG_NON_DEFFERED_CRITICAL_REGION_ENABLED  - Enable use of critical region for non deffered mode when flushing logs.
 

// <i> When enabled NRF_LOG_FLUSH is called from critical section when non deffered mode is used.
// <i> Log output will never be corrupted as access to the log backend is exclusive
// <i> but system will spend significant amount of time in critical section

#ifndef NRF_LOG_NON_DEFFERED_CRITICAL_REGION_ENABLED
#define NRF_LOG_NON_DEFFERED_CRITICAL_REGION_ENABLED 0
#endif

// <o> NRF_LOG_STR_PUSH_BUFFER_SIZE  - Size of the buffer dedicated for strings stored using @ref NRF_LOG_PUSH.
 
// <16=> 16 
// <32=> 32 
// <64=> 64 
// <128=> 128 
// <256=> 256 
// <512=> 512 
// <1024=> 1024 

#ifndef NRF_LOG_STR_PUSH_BUFFER_SIZE
#define NRF_LOG_STR_PUSH_BUFFER_SIZE 128
#endif

// <o> NRF_LOG_STR_PUSH_BUFFER_SIZE  - Size of the buffer dedicated for strings stored using @ref NRF_LOG_PUSH.
 
// <16=> 16 
// <32=> 32 
// <64=> 64 
// <128=> 128 
// <256=> 256 
// <512=> 512 
// <1024=> 1024 

#ifndef NRF_LOG_STR_PUSH_BUFFER_SIZE
#define NRF_LOG_STR_PUSH_BUFFER_SIZE 128
#endif

// <e> NRF_LOG_USES_COLORS - If enabled then ANSI escape code for colors is prefixed to every string
//==========================================================
#ifndef NRF_LOG_USES_COLORS
#define NRF_LOG_USES_COLORS 0
#endif
// <o> NRF_LOG_COLOR_DEFAULT  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef NRF_LOG_COLOR_DEFAULT
#define NRF_LOG_COLOR_DEFAULT 0
#endif

// <o> NRF_LOG_ERROR_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef NRF_LOG_ERROR_COLOR
#define NRF_LOG_ERROR_COLOR 2
#endif

// <o> NRF_LOG_WARNING_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef NRF_LOG_WARNING_COLOR
#define NRF_LOG_WARNING_COLOR 4
#endif

// </e>

// <e> NRF_LOG_USES_TIMESTAMP - Enable timestamping

// <i> Function for getting the timestamp is provided by the user
//==========================================================
#ifndef NRF_LOG_USES_TIMESTAMP
#define NRF_LOG_USES_TIMESTAMP 0
#endif
// <o> NRF_LOG_TIMESTAMP_DEFAULT_FREQUENCY - Default frequency of the timestamp (in Hz) or 0 to use app_timer frequency. 
#ifndef NRF_LOG_TIMESTAMP_DEFAULT_FREQUENCY
#define NRF_LOG_TIMESTAMP_DEFAULT_FREQUENCY 0
#endif

// <q> NRF_LOG_STR_FORMATTER_TIMESTAMP_FORMAT_ENABLED  - nrf_log_str_formatter - Log string formatter
 

#ifndef NRF_LOG_STR_FORMATTER_TIMESTAMP_FORMAT_ENABLED
#define NRF_LOG_STR_FORMATTER_TIMESTAMP_FORMAT_ENABLED 1
#endif
// </e>

// <h> nrf_log module configuration 
// <e> NRF_BALLOC_ENABLED - nrf_balloc - Block allocator module
//==========================================================
#ifndef NRF_BALLOC_ENABLED
#define NRF_BALLOC_ENABLED 1
#endif

// <e> NRF_BALLOC_CONFIG_LOG_ENABLED - Enables logging in the module.
//==========================================================
#ifndef NRF_BALLOC_CONFIG_LOG_ENABLED
#define NRF_BALLOC_CONFIG_LOG_ENABLED 0
#endif
// <o> NRF_BALLOC_CONFIG_LOG_LEVEL  - Default Severity level
 
// <0=> Off 
// <1=> Error 
// <2=> Warning 
// <3=> Info 
// <4=> Debug 

#ifndef NRF_BALLOC_CONFIG_LOG_LEVEL
#define NRF_BALLOC_CONFIG_LOG_LEVEL 3
#endif

// <o> NRF_BALLOC_CONFIG_INITIAL_LOG_LEVEL  - Initial severity level if dynamic filtering is enabled.
 

// <i> If module generates a lot of logs, initial log level can
// <i> be decreased to prevent flooding. Severity level can be
// <i> increased on instance basis.
// <0=> Off 
// <1=> Error 
// <2=> Warning 
// <3=> Info 
// <4=> Debug 

#ifndef NRF_BALLOC_CONFIG_INITIAL_LOG_LEVEL
#define NRF_BALLOC_CONFIG_INITIAL_LOG_LEVEL 3
#endif

// <o> NRF_BALLOC_CONFIG_INFO_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef NRF_BALLOC_CONFIG_INFO_COLOR
#define NRF_BALLOC_CONFIG_INFO_COLOR 0
#endif

// <o> NRF_BALLOC_CONFIG_DEBUG_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef NRF_BALLOC_CONFIG_DEBUG_COLOR
#define NRF_BALLOC_CONFIG_DEBUG_COLOR 0
#endif

// <q> NRF_MEMOBJ_ENABLED  - nrf_memobj - Linked memory allocator module


#ifndef NRF_MEMOBJ_ENABLED
#define NRF_MEMOBJ_ENABLED 1
#endif

// <q> NRF_STRERROR_ENABLED  - nrf_strerror - Library for converting error code to string.


#ifndef NRF_STRERROR_ENABLED
#define NRF_STRERROR_ENABLED 1
#endif

// <e> APP_TIMER_ENABLED - app_timer - Application timer functionality
//==========================================================
#ifndef APP_TIMER_ENABLED
#define APP_TIMER_ENABLED 1
#endif
// <o> APP_TIMER_CONFIG_RTC_FREQUENCY  - Configure RTC prescaler.
 
// <0=> 32768 Hz 
// <1=> 16384 Hz 
// <3=> 8192 Hz 
// <7=> 4096 Hz 
// <15=> 2048 Hz 
// <31=> 1024 Hz 

#ifndef APP_TIMER_CONFIG_RTC_FREQUENCY
#define APP_TIMER_CONFIG_RTC_FREQUENCY 1
#endif

// <o> APP_TIMER_CONFIG_IRQ_PRIORITY  - Interrupt priority
 

// <i> Priorities 0,2 (nRF51) and 0,1,4,5 (nRF52) are reserved for SoftDevice
// <0=> 0 (highest) 
// <1=> 1 
// <2=> 2 
// <3=> 3 
// <4=> 4 
// <5=> 5 
// <6=> 6 
// <7=> 7 

#ifndef APP_TIMER_CONFIG_IRQ_PRIORITY
#define APP_TIMER_CONFIG_IRQ_PRIORITY 6
#endif

// <o> APP_TIMER_CONFIG_OP_QUEUE_SIZE - Capacity of timer requests queue. 
// <i> Size of the queue depends on how many timers are used
// <i> in the system, how often timers are started and overall
// <i> system latency. If queue size is too small app_timer calls
// <i> will fail.

#ifndef APP_TIMER_CONFIG_OP_QUEUE_SIZE
#define APP_TIMER_CONFIG_OP_QUEUE_SIZE 10
#endif

// <q> APP_TIMER_CONFIG_USE_SCHEDULER  - Enable scheduling app_timer events to app_scheduler
 

#ifndef APP_TIMER_CONFIG_USE_SCHEDULER
#define APP_TIMER_CONFIG_USE_SCHEDULER 0
#endif

// <q> APP_TIMER_KEEPS_RTC_ACTIVE  - Enable RTC always on
 

// <i> If option is enabled RTC is kept running even if there is no active timers.
// <i> This option can be used when app_timer is used for timestamping.

#ifndef APP_TIMER_KEEPS_RTC_ACTIVE
#define APP_TIMER_KEEPS_RTC_ACTIVE 0
#endif

// <o> APP_TIMER_SAFE_WINDOW_MS - Maximum possible latency (in milliseconds) of handling app_timer event. 
// <i> Maximum possible timeout that can be set is reduced by safe window.
// <i> Example: RTC frequency 16384 Hz, maximum possible timeout 1024 seconds - APP_TIMER_SAFE_WINDOW_MS.
// <i> Since RTC is not stopped when processor is halted in debugging session, this value
// <i> must cover it if debugging is needed. It is possible to halt processor for APP_TIMER_SAFE_WINDOW_MS
// <i> without corrupting app_timer behavior.

#ifndef APP_TIMER_SAFE_WINDOW_MS
#define APP_TIMER_SAFE_WINDOW_MS 300000
#endif


// <e> NRF_ATFIFO_CONFIG_LOG_ENABLED - Enables logging in the module.
//==========================================================
#ifndef NRF_ATFIFO_CONFIG_LOG_ENABLED
#define NRF_ATFIFO_CONFIG_LOG_ENABLED 0
#endif
// <o> NRF_ATFIFO_CONFIG_LOG_LEVEL  - Default Severity level
 
// <0=> Off 
// <1=> Error 
// <2=> Warning 
// <3=> Info 
// <4=> Debug 

#ifndef NRF_ATFIFO_CONFIG_LOG_LEVEL
#define NRF_ATFIFO_CONFIG_LOG_LEVEL 3
#endif

// <o> NRF_ATFIFO_CONFIG_LOG_INIT_FILTER_LEVEL  - Initial severity level if dynamic filtering is enabled
 
// <0=> Off 
// <1=> Error 
// <2=> Warning 
// <3=> Info 
// <4=> Debug 

#ifndef NRF_ATFIFO_CONFIG_LOG_INIT_FILTER_LEVEL
#define NRF_ATFIFO_CONFIG_LOG_INIT_FILTER_LEVEL 3
#endif

// <o> NRF_ATFIFO_CONFIG_INFO_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef NRF_ATFIFO_CONFIG_INFO_COLOR
#define NRF_ATFIFO_CONFIG_INFO_COLOR 0
#endif

// <o> NRF_ATFIFO_CONFIG_DEBUG_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef NRF_ATFIFO_CONFIG_DEBUG_COLOR
#define NRF_ATFIFO_CONFIG_DEBUG_COLOR 0
#endif

// <e> NRF_SORTLIST_CONFIG_LOG_ENABLED - Enables logging in the module.
//==========================================================
#ifndef NRF_SORTLIST_CONFIG_LOG_ENABLED
#define NRF_SORTLIST_CONFIG_LOG_ENABLED 0
#endif
// <o> NRF_SORTLIST_CONFIG_LOG_LEVEL  - Default Severity level
 
// <0=> Off 
// <1=> Error 
// <2=> Warning 
// <3=> Info 
// <4=> Debug 

#ifndef NRF_SORTLIST_CONFIG_LOG_LEVEL
#define NRF_SORTLIST_CONFIG_LOG_LEVEL 3
#endif

// <o> NRF_SORTLIST_CONFIG_INFO_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef NRF_SORTLIST_CONFIG_INFO_COLOR
#define NRF_SORTLIST_CONFIG_INFO_COLOR 0
#endif

// <o> NRF_SORTLIST_CONFIG_DEBUG_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef NRF_SORTLIST_CONFIG_DEBUG_COLOR
#define NRF_SORTLIST_CONFIG_DEBUG_COLOR 0
#endif

// </e>

// <e> NRF_QUEUE_ENABLED - nrf_queue - Queue module
//==========================================================
#ifndef NRF_QUEUE_ENABLED
#define NRF_QUEUE_ENABLED 1
#endif
// <q> NRF_QUEUE_CLI_CMDS  - Enable CLI commands specific to the module
 

#ifndef NRF_QUEUE_CLI_CMDS
#define NRF_QUEUE_CLI_CMDS 1
#endif

//==========================================================

// <h> nrf_cli - Command line interface

//==========================================================
// <q> NRF_CLI_ENABLED  - Enable/disable the CLI module.
 

#ifndef NRF_CLI_ENABLED
#define NRF_CLI_ENABLED 1
#endif

// <o> NRF_CLI_ARGC_MAX - Maximum number of parameters passed to the command handler. 
#ifndef NRF_CLI_ARGC_MAX
#define NRF_CLI_ARGC_MAX 12
#endif

// <q> NRF_CLI_BUILD_IN_CMDS_ENABLED  - CLI built-in commands.
 

#ifndef NRF_CLI_BUILD_IN_CMDS_ENABLED
#define NRF_CLI_BUILD_IN_CMDS_ENABLED 1
#endif

// <o> NRF_CLI_CMD_BUFF_SIZE - Maximum buffer size for a single command. 
#ifndef NRF_CLI_CMD_BUFF_SIZE
#define NRF_CLI_CMD_BUFF_SIZE 128
#endif

// <q> NRF_CLI_ECHO_STATUS  - CLI echo status. If set, echo is ON.
 

#ifndef NRF_CLI_ECHO_STATUS
#define NRF_CLI_ECHO_STATUS 1
#endif

// <q> NRF_CLI_WILDCARD_ENABLED  - Enable wildcard functionality for CLI commands.
 

#ifndef NRF_CLI_WILDCARD_ENABLED
#define NRF_CLI_WILDCARD_ENABLED 0
#endif

// <q> NRF_CLI_METAKEYS_ENABLED  - Enable additional control keys for CLI commands like ctrl+a, ctrl+e, ctrl+w, ctrl+u
 

#ifndef NRF_CLI_METAKEYS_ENABLED
#define NRF_CLI_METAKEYS_ENABLED 0
#endif

// <o> NRF_CLI_PRINTF_BUFF_SIZE - Maximum print buffer size. 
#ifndef NRF_CLI_PRINTF_BUFF_SIZE
#define NRF_CLI_PRINTF_BUFF_SIZE 23
#endif

// <e> NRF_CLI_HISTORY_ENABLED - Enable CLI history mode.
//==========================================================
#ifndef NRF_CLI_HISTORY_ENABLED
#define NRF_CLI_HISTORY_ENABLED 1
#endif
// <o> NRF_CLI_HISTORY_ELEMENT_SIZE - Size of one memory object reserved for CLI history. 
#ifndef NRF_CLI_HISTORY_ELEMENT_SIZE
#define NRF_CLI_HISTORY_ELEMENT_SIZE 32
#endif

// <o> NRF_CLI_HISTORY_ELEMENT_COUNT - Number of history memory objects. 
#ifndef NRF_CLI_HISTORY_ELEMENT_COUNT
#define NRF_CLI_HISTORY_ELEMENT_COUNT 8
#endif

// </e>

// <q> NRF_CLI_VT100_COLORS_ENABLED  - CLI VT100 colors.
 

#ifndef NRF_CLI_VT100_COLORS_ENABLED
#define NRF_CLI_VT100_COLORS_ENABLED 1
#endif

// <q> NRF_CLI_STATISTICS_ENABLED  - Enable CLI statistics.
 

#ifndef NRF_CLI_STATISTICS_ENABLED
#define NRF_CLI_STATISTICS_ENABLED 1
#endif

// <q> NRF_CLI_LOG_BACKEND  - Enable logger backend interface.
 

#ifndef NRF_CLI_LOG_BACKEND
#define NRF_CLI_LOG_BACKEND 1
#endif

// <q> NRF_CLI_USES_TASK_MANAGER_ENABLED  - Enable CLI to use task_manager
 

#ifndef NRF_CLI_USES_TASK_MANAGER_ENABLED
#define NRF_CLI_USES_TASK_MANAGER_ENABLED 0
#endif

// </h> 
//==========================================================
// <e> APP_TIMER_CONFIG_LOG_ENABLED - Enables logging in the module.
//==========================================================
#ifndef APP_TIMER_CONFIG_LOG_ENABLED
#define APP_TIMER_CONFIG_LOG_ENABLED 0
#endif
// <o> APP_TIMER_CONFIG_LOG_LEVEL  - Default Severity level
 
// <0=> Off 
// <1=> Error 
// <2=> Warning 
// <3=> Info 
// <4=> Debug 

#ifndef APP_TIMER_CONFIG_LOG_LEVEL
#define APP_TIMER_CONFIG_LOG_LEVEL 3
#endif

// <o> APP_TIMER_CONFIG_INITIAL_LOG_LEVEL  - Initial severity level if dynamic filtering is enabled.
 

// <i> If module generates a lot of logs, initial log level can
// <i> be decreased to prevent flooding. Severity level can be
// <i> increased on instance basis.
// <0=> Off 
// <1=> Error 
// <2=> Warning 
// <3=> Info 
// <4=> Debug 

#ifndef APP_TIMER_CONFIG_INITIAL_LOG_LEVEL
#define APP_TIMER_CONFIG_INITIAL_LOG_LEVEL 3
#endif

// <o> APP_TIMER_CONFIG_INFO_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef APP_TIMER_CONFIG_INFO_COLOR
#define APP_TIMER_CONFIG_INFO_COLOR 0
#endif

// <o> APP_TIMER_CONFIG_DEBUG_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef APP_TIMER_CONFIG_DEBUG_COLOR
#define APP_TIMER_CONFIG_DEBUG_COLOR 0
#endif

// </e>
// <e> NRF_QUEUE_CONFIG_LOG_ENABLED - Enables logging in the module.
//==========================================================
#ifndef NRF_QUEUE_CONFIG_LOG_ENABLED
#define NRF_QUEUE_CONFIG_LOG_ENABLED 0
#endif
// <o> NRF_QUEUE_CONFIG_LOG_LEVEL  - Default Severity level
 
// <0=> Off 
// <1=> Error 
// <2=> Warning 
// <3=> Info 
// <4=> Debug 

#ifndef NRF_QUEUE_CONFIG_LOG_LEVEL
#define NRF_QUEUE_CONFIG_LOG_LEVEL 3
#endif

// <o> NRF_QUEUE_CONFIG_LOG_INIT_FILTER_LEVEL  - Initial severity level if dynamic filtering is enabled
 
// <0=> Off 
// <1=> Error 
// <2=> Warning 
// <3=> Info 
// <4=> Debug 

#ifndef NRF_QUEUE_CONFIG_LOG_INIT_FILTER_LEVEL
#define NRF_QUEUE_CONFIG_LOG_INIT_FILTER_LEVEL 3
#endif

// <o> NRF_QUEUE_CONFIG_INFO_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef NRF_QUEUE_CONFIG_INFO_COLOR
#define NRF_QUEUE_CONFIG_INFO_COLOR 0
#endif

// <o> NRF_QUEUE_CONFIG_DEBUG_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef NRF_QUEUE_CONFIG_DEBUG_COLOR
#define NRF_QUEUE_CONFIG_DEBUG_COLOR 0
#endif

// </e>

// <q> NRF_SECTION_ITER_ENABLED  - nrf_section_iter - Section iterator
 

#ifndef NRF_SECTION_ITER_ENABLED
#define NRF_SECTION_ITER_ENABLED 1
#endif

// </e>
// <e> NRF_LOG_BACKEND_FLASHLOG_ENABLED - Enable flashlog backend.
//==========================================================
#ifndef NRF_LOG_BACKEND_FLASHLOG_ENABLED
#define NRF_LOG_BACKEND_FLASHLOG_ENABLED 1
#endif
// <o> NRF_LOG_BACKEND_FLASHLOG_QUEUE_SIZE - Logger messages queue size. 
// <i> Queue holds log messages pending to be written to flash.
// <i> Note that the queue holds logger messages and thus the queue size determines
// <i> increasing the pool of logger messages (see log message pool configuration).

#ifndef NRF_LOG_BACKEND_FLASHLOG_QUEUE_SIZE
#define NRF_LOG_BACKEND_FLASHLOG_QUEUE_SIZE 8
#endif

// </e>

// <e> NRF_LOG_BACKEND_CRASHLOG_ENABLED - Enable crashlog backend.
//==========================================================
#ifndef NRF_LOG_BACKEND_CRASHLOG_ENABLED
#define NRF_LOG_BACKEND_CRASHLOG_ENABLED 1
#endif
// <o> NRF_LOG_BACKEND_CRASHLOG_FIFO_SIZE - Number of log messages held to be flushed in panic. 
// <i> Crashlog FIFO always keeps a defined number of the most
// <i> recent logs (severity level is set on runtime).
// <i> Note that the FIFO holds logger messages and thus the FIFO size determines
// <i> increasing the pool of logger messages (see log message pool configuration).

#ifndef NRF_LOG_BACKEND_CRASHLOG_FIFO_SIZE
#define NRF_LOG_BACKEND_CRASHLOG_FIFO_SIZE 8
#endif

// </e>

// <o> NRF_LOG_BACKEND_FLASH_SER_BUFFER_SIZE - Size of the buffer used for serialize log message. 
// <i> Message is trimmed if it is longer. It may happen in case of 
// <i> hexdump message. Buffer size must be multiple of 4.

#ifndef NRF_LOG_BACKEND_FLASH_SER_BUFFER_SIZE
#define NRF_LOG_BACKEND_FLASH_SER_BUFFER_SIZE 64
#endif

// <h> Flash log location - Configuration of flash area used for storing the logs.

//==========================================================
// <o> NRF_LOG_BACKEND_FLASH_START_PAGE - Starting page.  
// <i> If 0, then pages directly after the application are used.

#ifndef NRF_LOG_BACKEND_FLASH_START_PAGE
#define NRF_LOG_BACKEND_FLASH_START_PAGE 0
#endif

// <o> NRF_LOG_BACKEND_PAGES - Number of pages. 
#ifndef NRF_LOG_BACKEND_PAGES
#define NRF_LOG_BACKEND_PAGES 1
#endif

// <e> FDS_ENABLED - fds - Flash data storage module
//==========================================================
#ifndef FDS_ENABLED
#define FDS_ENABLED 1
#endif
// <h> Pages - Virtual page settings

// <i> Configure the number of virtual pages to use and their size.
//==========================================================
// <o> FDS_VIRTUAL_PAGES - Number of virtual flash pages to use. 
// <i> One of the virtual pages is reserved by the system for garbage collection.
// <i> Therefore, the minimum is two virtual pages: one page to store data and one page to be used by the system for garbage collection.
// <i> The total amount of flash memory that is used by FDS amounts to @ref FDS_VIRTUAL_PAGES * @ref FDS_VIRTUAL_PAGE_SIZE * 4 bytes.

#ifndef FDS_VIRTUAL_PAGES
#define FDS_VIRTUAL_PAGES 3
#endif

// <o> FDS_VIRTUAL_PAGE_SIZE  - The size of a virtual flash page.
 

// <i> Expressed in number of 4-byte words.
// <i> By default, a virtual page is the same size as a physical page.
// <i> The size of a virtual page must be a multiple of the size of a physical page.
// <1024=> 1024 
// <2048=> 2048 

#ifndef FDS_VIRTUAL_PAGE_SIZE
#define FDS_VIRTUAL_PAGE_SIZE 1024
#endif

// <o> FDS_VIRTUAL_PAGES_RESERVED - The number of virtual flash pages that are used by other modules. 
// <i> FDS module stores its data in the last pages of the flash memory.
// <i> By setting this value, you can move flash end address used by the FDS.
// <i> As a result the reserved space can be used by other modules.

#ifndef FDS_VIRTUAL_PAGES_RESERVED
#define FDS_VIRTUAL_PAGES_RESERVED 0
#endif

// </h> 
//==========================================================

// <h> Backend - Backend configuration

// <i> Configure which nrf_fstorage backend is used by FDS to write to flash.
//==========================================================
// <o> FDS_BACKEND  - FDS flash backend.
 

// <i> NRF_FSTORAGE_SD uses the nrf_fstorage_sd backend implementation using the SoftDevice API. Use this if you have a SoftDevice present.
// <i> NRF_FSTORAGE_NVMC uses the nrf_fstorage_nvmc implementation. Use this setting if you don't use the SoftDevice.
// <1=> NRF_FSTORAGE_NVMC 
// <2=> NRF_FSTORAGE_SD 

#ifndef FDS_BACKEND
#define FDS_BACKEND 1
#endif

// </h> 
//==========================================================

// <h> Queue - Queue settings

//==========================================================
// <o> FDS_OP_QUEUE_SIZE - Size of the internal queue. 
// <i> Increase this value if you frequently get synchronous FDS_ERR_NO_SPACE_IN_QUEUES errors.

#ifndef FDS_OP_QUEUE_SIZE
#define FDS_OP_QUEUE_SIZE 4
#endif

// </h> 
//==========================================================

// <h> CRC - CRC functionality

//==========================================================
// <e> FDS_CRC_CHECK_ON_READ - Enable CRC checks.

// <i> Save a record's CRC when it is written to flash and check it when the record is opened.
// <i> Records with an incorrect CRC can still be 'seen' by the user using FDS functions, but they cannot be opened.
// <i> Additionally, they will not be garbage collected until they are deleted.
//==========================================================
#ifndef FDS_CRC_CHECK_ON_READ
#define FDS_CRC_CHECK_ON_READ 0
#endif
// <o> FDS_CRC_CHECK_ON_WRITE  - Perform a CRC check on newly written records.
 

// <i> Perform a CRC check on newly written records.
// <i> This setting can be used to make sure that the record data was not altered while being written to flash.
// <1=> Enabled 
// <0=> Disabled 

#ifndef FDS_CRC_CHECK_ON_WRITE
#define FDS_CRC_CHECK_ON_WRITE 0
#endif

// </e>

// </h> 
//==========================================================

// <h> Users - Number of users

//==========================================================
// <o> FDS_MAX_USERS - Maximum number of callbacks that can be registered. 
#ifndef FDS_MAX_USERS
#define FDS_MAX_USERS 4
#endif

// <e> NRF_FSTORAGE_ENABLED - nrf_fstorage - Flash abstraction library
//==========================================================
#ifndef NRF_FSTORAGE_ENABLED
#define NRF_FSTORAGE_ENABLED 1
#endif
// <h> nrf_fstorage - Common settings

// <i> Common settings to all fstorage implementations
//==========================================================
// <q> NRF_FSTORAGE_PARAM_CHECK_DISABLED  - Disable user input validation
 

// <i> If selected, use ASSERT to validate user input.
// <i> This effectively removes user input validation in production code.
// <i> Recommended setting: OFF, only enable this setting if size is a major concern.

#ifndef NRF_FSTORAGE_PARAM_CHECK_DISABLED
#define NRF_FSTORAGE_PARAM_CHECK_DISABLED 0
#endif

// </h> 
//==========================================================

// <h> nrf_fstorage_sd - Implementation using the SoftDevice

// <i> Configuration options for the fstorage implementation using the SoftDevice
//==========================================================
// <o> NRF_FSTORAGE_SD_QUEUE_SIZE - Size of the internal queue of operations 
// <i> Increase this value if API calls frequently return the error @ref NRF_ERROR_NO_MEM.

#ifndef NRF_FSTORAGE_SD_QUEUE_SIZE
#define NRF_FSTORAGE_SD_QUEUE_SIZE 4
#endif

// <o> NRF_FSTORAGE_SD_MAX_RETRIES - Maximum number of attempts at executing an operation when the SoftDevice is busy 
// <i> Increase this value if events frequently return the @ref NRF_ERROR_TIMEOUT error.
// <i> The SoftDevice might fail to schedule flash access due to high BLE activity.

#ifndef NRF_FSTORAGE_SD_MAX_RETRIES
#define NRF_FSTORAGE_SD_MAX_RETRIES 8
#endif

// <o> NRF_FSTORAGE_SD_MAX_WRITE_SIZE - Maximum number of bytes to be written to flash in a single operation 
// <i> This value must be a multiple of four.
// <i> Lowering this value can increase the chances of the SoftDevice being able to execute flash operations in between radio activity.
// <i> This value is bound by the maximum number of bytes that can be written to flash in a single call to @ref sd_flash_write.
// <i> That is 1024 bytes for nRF51 ICs and 4096 bytes for nRF52 ICs.

#ifndef NRF_FSTORAGE_SD_MAX_WRITE_SIZE
#define NRF_FSTORAGE_SD_MAX_WRITE_SIZE 4096
#endif

// <q> NRF_CLI_UART_ENABLED  - nrf_cli_uart - UART command line interface transport
 

#ifndef NRF_CLI_UART_ENABLED
#define NRF_CLI_UART_ENABLED 1

// <e> NRF_CLI_UART_CONFIG_LOG_ENABLED - Enables logging in the module.
//==========================================================
#ifndef NRF_CLI_UART_CONFIG_LOG_ENABLED
#define NRF_CLI_UART_CONFIG_LOG_ENABLED 0
#endif
// <o> NRF_CLI_UART_CONFIG_LOG_LEVEL  - Default Severity level
 
// <0=> Off 
// <1=> Error 
// <2=> Warning 
// <3=> Info 
// <4=> Debug 

#ifndef NRF_CLI_UART_CONFIG_LOG_LEVEL
#define NRF_CLI_UART_CONFIG_LOG_LEVEL 3
#endif

// <o> NRF_CLI_UART_CONFIG_INFO_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef NRF_CLI_UART_CONFIG_INFO_COLOR
#define NRF_CLI_UART_CONFIG_INFO_COLOR 0
#endif

// <o> NRF_CLI_UART_CONFIG_DEBUG_COLOR  - ANSI escape code prefix.
 
// <0=> Default 
// <1=> Black 
// <2=> Red 
// <3=> Green 
// <4=> Yellow 
// <5=> Blue 
// <6=> Magenta 
// <7=> Cyan 
// <8=> White 

#ifndef NRF_CLI_UART_CONFIG_DEBUG_COLOR
#define NRF_CLI_UART_CONFIG_DEBUG_COLOR 0
#endif

#endif

// </e>
//==========================================================
// <e> NRF_LOG_BACKEND_FLASH_ENABLED - nrf_log_backend_flash - Log flash backend
//==========================================================
#ifndef NRF_LOG_BACKEND_FLASH_ENABLED
#define NRF_LOG_BACKEND_FLASH_ENABLED 1
#endif
// <q> NRF_LOG_BACKEND_FLASH_CLI_CMDS  - Enable CLI commands for this module.
 

#ifndef NRF_LOG_BACKEND_FLASH_CLI_CMDS
#define NRF_LOG_BACKEND_FLASH_CLI_CMDS 1
#endif

// <e> NRF_LOG_BACKEND_FLASHLOG_ENABLED - Enable flashlog backend.
//==========================================================
#ifndef NRF_LOG_BACKEND_FLASHLOG_ENABLED
#define NRF_LOG_BACKEND_FLASHLOG_ENABLED 1
#endif
// <o> NRF_LOG_BACKEND_FLASHLOG_QUEUE_SIZE - Logger messages queue size. 
// <i> Queue holds log messages pending to be written to flash.
// <i> Note that the queue holds logger messages and thus the queue size determines
// <i> increasing the pool of logger messages (see log message pool configuration).

#ifndef NRF_LOG_BACKEND_FLASHLOG_QUEUE_SIZE
#define NRF_LOG_BACKEND_FLASHLOG_QUEUE_SIZE 8
#endif

// </e>

// <e> NRF_LOG_BACKEND_CRASHLOG_ENABLED - Enable crashlog backend.
//==========================================================
#ifndef NRF_LOG_BACKEND_CRASHLOG_ENABLED
#define NRF_LOG_BACKEND_CRASHLOG_ENABLED 1
#endif
// <o> NRF_LOG_BACKEND_CRASHLOG_FIFO_SIZE - Number of log messages held to be flushed in panic. 
// <i> Crashlog FIFO always keeps a defined number of the most
// <i> recent logs (severity level is set on runtime).
// <i> Note that the FIFO holds logger messages and thus the FIFO size determines
// <i> increasing the pool of logger messages (see log message pool configuration).

#ifndef NRF_LOG_BACKEND_CRASHLOG_FIFO_SIZE
#define NRF_LOG_BACKEND_CRASHLOG_FIFO_SIZE 8
#endif

// </e>

// <o> NRF_LOG_BACKEND_FLASH_SER_BUFFER_SIZE - Size of the buffer used for serialize log message. 
// <i> Message is trimmed if it is longer. It may happen in case of 
// <i> hexdump message. Buffer size must be multiple of 4.

#ifndef NRF_LOG_BACKEND_FLASH_SER_BUFFER_SIZE
#define NRF_LOG_BACKEND_FLASH_SER_BUFFER_SIZE 64
#endif

// <h> Flash log location - Configuration of flash area used for storing the logs.

//==========================================================
// <o> NRF_LOG_BACKEND_FLASH_START_PAGE - Starting page.  
// <i> If 0, then pages directly after the application are used.

#ifndef NRF_LOG_BACKEND_FLASH_START_PAGE
#define NRF_LOG_BACKEND_FLASH_START_PAGE 0
#endif

// <o> NRF_LOG_BACKEND_PAGES - Number of pages. 
#ifndef NRF_LOG_BACKEND_PAGES
#define NRF_LOG_BACKEND_PAGES 1
#endif

// <q> NRF_SORTLIST_ENABLED  - nrf_sortlist - Sorted list
 

#ifndef NRF_SORTLIST_ENABLED
#define NRF_SORTLIST_ENABLED 1
#endif

#endif