//*****************************************************************************
// LPC55S69_cm33_core0 startup code for use with MCUXpresso IDE
//
// Version : 220119
//*****************************************************************************
//
// Copyright 2016-2019 NXP
// All rights reserved.
//
// SPDX-License-Identifier: BSD-3-Clause
//*****************************************************************************

#if defined (DEBUG)
#pragma GCC push_options
#pragma GCC optimize ("Og")
#endif // (DEBUG)

#if defined (__cplusplus)
#ifdef __REDLIB__
#error Redlib does not support C++
#else
//*****************************************************************************
//
// The entry point for the C++ library startup
//
//*****************************************************************************
extern "C" {
    extern void __libc_init_array(void);
}
#endif
#endif

#define WEAK __attribute__ ((weak))
#define WEAK_AV __attribute__ ((weak, section(".after_vectors")))
#define ALIAS(f) __attribute__ ((weak, alias (#f)))

//*****************************************************************************
#if defined (__cplusplus)
extern "C" {
#endif

//*****************************************************************************
// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
//*****************************************************************************
//*****************************************************************************
// Declaration of external SystemInit function
//*****************************************************************************
#if defined (__USE_CMSIS)
extern void SystemInit(void);
#endif // (__USE_CMSIS)

//*****************************************************************************
// Forward declaration of the core exception handlers.
// When the application defines a handler (with the same name), this will
// automatically take precedence over these weak definitions.
// If your application is a C++ one, then any interrupt handlers defined
// in C++ files within in your main application will need to have C linkage
// rather than C++ linkage. To do this, make sure that you are using extern "C"
// { .... } around the interrupt handler within your main application code.
//*****************************************************************************
     void ResetISR(void);
WEAK void NMI_Handler(void);
WEAK void HardFault_Handler(void);
WEAK void MemManage_Handler(void);
WEAK void BusFault_Handler(void);
WEAK void UsageFault_Handler(void);
WEAK void SVC_Handler(void);
WEAK void DebugMon_Handler(void);
WEAK void PendSV_Handler(void);
WEAK void SysTick_Handler(void);
WEAK void IntDefaultHandler(void);

//*****************************************************************************
// Forward declaration of the application IRQ handlers. When the application
// defines a handler (with the same name), this will automatically take
// precedence over weak definitions below
//*****************************************************************************
WEAK void SPU_IRQHandler(void);
WEAK void CLOCK_POWER_IRQHandler(void);
WEAK void UARTE0_SPIM0_SPIS0_TWIM0_TWIS0_IRQHandler(void);
WEAK void UARTE1_SPIM1_SPIS1_TWIM1_TWIS1_IRQHandler(void);
WEAK void UARTE2_SPIM2_SPIS2_TWIM2_TWIS2_IRQHandler(void);
WEAK void UARTE3_SPIM3_SPIS3_TWIM3_TWIS3_IRQHandler(void);
WEAK void GPIOTE0_IRQHandler(void);
WEAK void SAADC_IRQHandler(void);
WEAK void TIMER0_IRQHandler(void);
WEAK void TIMER1_IRQHandler(void);
WEAK void TIMER2_IRQHandler(void);
WEAK void RTC0_IRQHandler(void);
WEAK void RTC1_IRQHandler(void);
WEAK void WDT_IRQHandler(void);
WEAK void EGU0_IRQHandler(void);
WEAK void EGU1_IRQHandler(void);
WEAK void EGU2_IRQHandler(void);
WEAK void EGU3_IRQHandler(void);
WEAK void EGU4_IRQHandler(void);
WEAK void EGU5_IRQHandler(void);
WEAK void PWM0_IRQHandler(void);
WEAK void PWM1_IRQHandler(void);
WEAK void PWM2_IRQHandler(void);
WEAK void PWM3_IRQHandler(void);
WEAK void PDM_IRQHandler(void);
WEAK void I2S_IRQHandler(void);
WEAK void IPC_IRQHandler(void);
WEAK void FPU_IRQHandler(void);
WEAK void GPIOTE1_IRQHandler(void);
WEAK void KMU_IRQHandler(void);
WEAK void CRYPTOCELL_IRQHandler(void);

//*****************************************************************************
// Forward declaration of the driver IRQ handlers. These are aliased
// to the IntDefaultHandler, which is a 'forever' loop. When the driver
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//*****************************************************************************
void SPU_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CLOCK_POWER_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void UARTE0_SPIM0_SPIS0_TWIM0_TWIS0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void UARTE1_SPIM1_SPIS1_TWIM1_TWIS1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void UARTE2_SPIM2_SPIS2_TWIM2_TWIS2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void UARTE3_SPIM3_SPIS3_TWIM3_TWIS3_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void GPIOTE0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SAADC_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void TIMER0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void TIMER1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void TIMER2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void WDT_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void EGU0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void EGU1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void EGU2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void EGU3_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void EGU4_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void EGU5_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PWM0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PWM1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PWM2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PWM3_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PDM_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void I2S_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void IPC_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void FPU_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void GPIOTE1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void KMU_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CRYPTOCELL_DriverIRQHandler(void) ALIAS(IntDefaultHandler);

//*****************************************************************************
// The entry point for the application.
// __main() is the entry point for Redlib based applications
// main() is the entry point for Newlib based applications
//*****************************************************************************
#if defined (__REDLIB__)
extern void __main(void);
#endif
extern int main(void);

//*****************************************************************************
// External declaration for the pointer to the stack top from the Linker Script
//*****************************************************************************
extern void _vStackTop(void);
//*****************************************************************************
// External declaration for LPC MCU vector table checksum from  Linker Script
//*****************************************************************************
WEAK extern void __valid_user_code_checksum();

//*****************************************************************************
//*****************************************************************************
#if defined (__cplusplus)
} // extern "C"
#endif
//*****************************************************************************
// The vector table.
// This relies on the linker script to place at correct location in memory.
//*****************************************************************************
extern void (* const g_pfnVectors[])(void);
extern void * __Vectors __attribute__ ((alias ("g_pfnVectors")));

__attribute__ ((used, section(".isr_vector")))
void (* const g_pfnVectors[])(void) = {
    // Core Level - CM33
    &_vStackTop,                       // The initial stack pointer
    ResetISR,                          // The reset handler
    NMI_Handler,                       // The NMI handler
    HardFault_Handler,                 // The hard fault handler
    MemManage_Handler,                 // The MPU fault handler
    BusFault_Handler,                  // The bus fault handler
    UsageFault_Handler,                // The usage fault handler
    __valid_user_code_checksum,        // LPC MCU checksum
    0,                                 // ECRP
    0,                                 // Reserved
    0,                                 // Reserved
    SVC_Handler,                       // SVCall handler
    DebugMon_Handler,                  // Debug monitor handler
    0,                                 // Reserved
    PendSV_Handler,                    // The PendSV handler
    SysTick_Handler,                   // The SysTick handler

    // Chip Level - nRF9160 - core0
	0,                            //Reserved
	0,                            //Reserved
	0,                            //Reserved
	SPU_IRQHandler,
	0,                           //Reserved
	CLOCK_POWER_IRQHandler,
	0,                           //Reserved
	0,                           //Reserved
	UARTE0_SPIM0_SPIS0_TWIM0_TWIS0_IRQHandler,
	UARTE1_SPIM1_SPIS1_TWIM1_TWIS1_IRQHandler,
	UARTE2_SPIM2_SPIS2_TWIM2_TWIS2_IRQHandler,
	UARTE3_SPIM3_SPIS3_TWIM3_TWIS3_IRQHandler,
	0,                          //Reserved
	GPIOTE0_IRQHandler,
	SAADC_IRQHandler,
	TIMER0_IRQHandler,
	TIMER1_IRQHandler,
	TIMER2_IRQHandler,
	0,                           //Reserved
	0,                           //Reserved
	RTC0_IRQHandler,
	RTC1_IRQHandler,
	0,                           //Reserved
	0,                           //Reserved
	WDT_IRQHandler,
	0,                           //Reserved
	0,                           //Reserved
	EGU0_IRQHandler,
	EGU1_IRQHandler,
	EGU2_IRQHandler,
	EGU3_IRQHandler,
	EGU4_IRQHandler,
	EGU5_IRQHandler,
	PWM0_IRQHandler,
	PWM1_IRQHandler,
	PWM2_IRQHandler,
	PWM3_IRQHandler,
	0,                           //Reserved
	PDM_IRQHandler,
	0,                         //Reserved
	I2S_IRQHandler,
	0,                           //Reserved
	IPC_IRQHandler,
	0,                           //Reserved
	FPU_IRQHandler,
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	GPIOTE1_IRQHandler,
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	KMU_IRQHandler,
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	CRYPTOCELL_IRQHandler,
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved
	0,                           //Reserved

}; /* End of g_pfnVectors */

//*****************************************************************************
// Functions to carry out the initialization of RW and BSS data sections. These
// are written as separate functions rather than being inlined within the
// ResetISR() function in order to cope with MCUs with multiple banks of
// memory.
//*****************************************************************************
__attribute__ ((section(".after_vectors.init_data")))
void data_init(unsigned int romstart, unsigned int start, unsigned int len) {
    unsigned int *pulDest = (unsigned int*) start;
    unsigned int *pulSrc = (unsigned int*) romstart;
    unsigned int loop;
    for (loop = 0; loop < len; loop = loop + 4)
        *pulDest++ = *pulSrc++;
}

__attribute__ ((section(".after_vectors.init_bss")))
void bss_init(unsigned int start, unsigned int len) {
    unsigned int *pulDest = (unsigned int*) start;
    unsigned int loop;
    for (loop = 0; loop < len; loop = loop + 4)
        *pulDest++ = 0;
}

//*****************************************************************************
// The following symbols are constructs generated by the linker, indicating
// the location of various points in the "Global Section Table". This table is
// created by the linker via the Code Red managed linker script mechanism. It
// contains the load address, execution address and length of each RW data
// section and the execution and length of each BSS (zero initialized) section.
//*****************************************************************************
extern unsigned int __data_section_table;
extern unsigned int __data_section_table_end;
extern unsigned int __bss_section_table;
extern unsigned int __bss_section_table_end;

//*****************************************************************************
// Reset entry point for your code.
// Sets up a simple runtime environment and initializes the C/C++
// library.
//*****************************************************************************
__attribute__ ((section(".after_vectors.reset")))
void ResetISR(void) {

    // Disable interrupts
    __asm volatile ("cpsid i");

#if defined (__USE_CMSIS)
// If __USE_CMSIS defined, then call CMSIS SystemInit code
    SystemInit();

#endif // (__USE_CMSIS)

    //
    // Copy the data sections from flash to SRAM.
    //
    unsigned int LoadAddr, ExeAddr, SectionLen;
    unsigned int *SectionTableAddr;

    // Load base address of Global Section Table
    SectionTableAddr = &__data_section_table;

    // Copy the data sections from flash to SRAM.
    while (SectionTableAddr < &__data_section_table_end) {
        LoadAddr = *SectionTableAddr++;
        ExeAddr = *SectionTableAddr++;
        SectionLen = *SectionTableAddr++;
        data_init(LoadAddr, ExeAddr, SectionLen);
    }

    // At this point, SectionTableAddr = &__bss_section_table;
    // Zero fill the bss segment
    while (SectionTableAddr < &__bss_section_table_end) {
        ExeAddr = *SectionTableAddr++;
        SectionLen = *SectionTableAddr++;
        bss_init(ExeAddr, SectionLen);
    }


#if !defined (__USE_CMSIS)
// Assume that if __USE_CMSIS defined, then CMSIS SystemInit code
// will setup the VTOR register

    // Check to see if we are running the code from a non-zero
    // address (eg RAM, external flash), in which case we need
    // to modify the VTOR register to tell the CPU that the
    // vector table is located at a non-0x0 address.
    unsigned int * pSCB_VTOR = (unsigned int *) 0xE000ED08;
    if ((unsigned int *)g_pfnVectors!=(unsigned int *) 0x00000000) {
        *pSCB_VTOR = (unsigned int)g_pfnVectors;
    }
#endif // (__USE_CMSIS)
#if defined (__cplusplus)
    //
    // Call C++ library initialisation
    //
    __libc_init_array();
#endif

    // Reenable interrupts
    __asm volatile ("cpsie i");

#if defined (__REDLIB__)
    // Call the Redlib library, which in turn calls main()
    __main();
#else
    main();
#endif

    //
    // main() shouldn't return, but if it does, we'll just enter an infinite loop
    //
    while (1) {
        ;
    }
}

//*****************************************************************************
// Default core exception handlers. Override the ones here by defining your own
// handler routines in your application code.
//*****************************************************************************
WEAK_AV void NMI_Handler(void)
{ while(1) {}
}

WEAK_AV void HardFault_Handler(void)
{ while(1) {}
}

WEAK_AV void MemManage_Handler(void)
{ while(1) {}
}

WEAK_AV void BusFault_Handler(void)
{ while(1) {}
}

WEAK_AV void UsageFault_Handler(void)
{ while(1) {}
}

WEAK_AV void SVC_Handler(void)
{ while(1) {}
}

WEAK_AV void DebugMon_Handler(void)
{ while(1) {}
}

WEAK_AV void PendSV_Handler(void)
{ while(1) {}
}

WEAK_AV void SysTick_Handler(void)
{ while(1) {}
}

//*****************************************************************************
// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.
//*****************************************************************************
WEAK_AV void IntDefaultHandler(void)
{ while(1) {}
}

//*****************************************************************************
// Default application exception handlers. Override the ones here by defining
// your own handler routines in your application code. These routines call
// driver exception handlers or IntDefaultHandler() if no driver exception
// handler is included.
//*****************************************************************************
WEAK void SPU_IRQHandler(void)
{   SPU_DriverIRQHandler();
}

WEAK void CLOCK_POWER_IRQHandler(void)
{   CLOCK_POWER_DriverIRQHandler();
}

WEAK void UARTE0_SPIM0_SPIS0_TWIM0_TWIS0_IRQHandler(void)
{   UARTE0_SPIM0_SPIS0_TWIM0_TWIS0_DriverIRQHandler();
}

WEAK void UARTE1_SPIM1_SPIS1_TWIM1_TWIS1_IRQHandler(void)
{   UARTE1_SPIM1_SPIS1_TWIM1_TWIS1_DriverIRQHandler();
}

WEAK void UARTE2_SPIM2_SPIS2_TWIM2_TWIS2_IRQHandler(void)
{   UARTE2_SPIM2_SPIS2_TWIM2_TWIS2_DriverIRQHandler();
}

WEAK void UARTE3_SPIM3_SPIS3_TWIM3_TWIS3_IRQHandler(void)
{   UARTE3_SPIM3_SPIS3_TWIM3_TWIS3_DriverIRQHandler();
}

WEAK void GPIOTE0_IRQHandler(void)
{   GPIOTE0_DriverIRQHandler();
}

WEAK void SAADC_IRQHandler(void)
{   SAADC_DriverIRQHandler();
}

WEAK void TIMER0_IRQHandler(void)
{   TIMER0_DriverIRQHandler();
}

WEAK void TIMER1_IRQHandler(void)
{   TIMER1_DriverIRQHandler();
}

WEAK void TIMER2_IRQHandler(void)
{   TIMER2_DriverIRQHandler();
}

WEAK void RTC0_IRQHandler(void)
{   RTC0_DriverIRQHandler();
}

WEAK void RTC1_IRQHandler(void)
{   RTC1_DriverIRQHandler();
}

WEAK void WDT_IRQHandler(void)
{   WDT_DriverIRQHandler();
}

WEAK void EGU0_IRQHandler(void)
{   EGU0_DriverIRQHandler();
}

WEAK void EGU1_IRQHandler(void)
{   EGU1_DriverIRQHandler();
}

WEAK void EGU2_IRQHandler(void)
{   EGU2_DriverIRQHandler();
}

WEAK void EGU3_IRQHandler(void)
{   EGU3_DriverIRQHandler();
}

WEAK void EGU4_IRQHandler(void)
{   EGU4_DriverIRQHandler();
}

WEAK void EGU5_IRQHandler(void)
{   EGU5_DriverIRQHandler();
}

WEAK void PWM0_IRQHandler(void)
{   PWM0_DriverIRQHandler();
}

WEAK void PWM1_IRQHandler(void)
{   PWM1_DriverIRQHandler();
}

WEAK void PWM2_IRQHandler(void)
{   PWM2_DriverIRQHandler();
}

WEAK void PWM3_IRQHandler(void)
{   PWM3_DriverIRQHandler();
}

WEAK void PDM_IRQHandler(void)
{   PDM_DriverIRQHandler();
}

WEAK void I2S_IRQHandler(void)
{   I2S_DriverIRQHandler();
}

WEAK void IPC_IRQHandler(void)
{   IPC_DriverIRQHandler();
}

WEAK void FPU_IRQHandler(void)
{   FPU_DriverIRQHandler();
}

WEAK void GPIOTE1_IRQHandler(void)
{   GPIOTE1_DriverIRQHandler();
}

WEAK void KMU_IRQHandler(void)
{   KMU_DriverIRQHandler();
}

WEAK void CRYPTOCELL_IRQHandler(void)
{   CRYPTOCELL_DriverIRQHandler();
}
//*****************************************************************************

#if defined (DEBUG)
#pragma GCC pop_options
#endif // (DEBUG)
