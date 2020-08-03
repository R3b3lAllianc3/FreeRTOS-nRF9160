/*
 * Copyright 2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

//#include "fsl_common.h"
#include "tzm_config.h"
#include "nrf9160.h"
#include "arm_cmse.h"
#include "spm_internal.h"
#include "secure_port_macros.h"
#include<assert.h>

#ifndef __cplusplus
#define bool   _Bool
#define true   1
#define false  0
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define CODE_FLASH_START_NS         0x00010000  
#define CODE_FLASH_SIZE_NS          0x00030000
#define CODE_FLASH_START_NSC        0x1000FE00
#define CODE_FLASH_SIZE_NSC         0x200
#define DATA_RAM_START_NS           0x20008000
#define DATA_RAM_SIZE_NS            0x0002B000
#define PERIPH_START_NS             0x40000000
#define PERIPH_SIZE_NS              0x00100000

/*******************************************************************************
 * Variables
 ******************************************************************************/
#if defined(__MCUXPRESSO)
extern unsigned char _start_sg[];
//extern long __sg_size;
#endif

#define FIRST_NONSECURE_ADDRESS (CODE_FLASH_START_NS)
#define LAST_SECURE_REGION_INDEX \
	((FIRST_NONSECURE_ADDRESS / FLASH_SECURE_ATTRIBUTION_REGION_SIZE) - 1)


/* Local convenience macro to extract the peripheral
 * ID from the base address.
 */
#define NRFX_PERIPHERAL_ID_GET(base_addr) \
	(uint8_t)((uint32_t)(base_addr) >> 12)

#define PERIPH(name, reg, is_secure)                          \
	{                                                         \
		name, .id = NRFX_PERIPHERAL_ID_GET(reg), is_secure    \
	}

/**************** MQ Lifted from ncs\zephyr\include\sys\util.h */
/* Evaluates to 0 if array is an array; compile error if not array (e.g.
 * pointer)
 */
/* Evaluates to 0 if cond is true-ish; compile error otherwise */
#define ZERO_OR_COMPILE_ERROR(cond) ((int) sizeof(char[1 - 2 * !(cond)]) - 1)

#define IS_ARRAY(array) \
	ZERO_OR_COMPILE_ERROR( \
		!__builtin_types_compatible_p(__typeof__(array), \
					      __typeof__(&(array)[0])))

#define ARRAY_SIZE(array) \
	((long) (IS_ARRAY(array) + (sizeof(array) / sizeof((array)[0]))))
/**************** MQ End lifted from ncs\zephyr\include\sys\util.h */

//assert(LAST_SECURE_REGION_INDEX != -1);

extern void irq_target_state_set(unsigned int irq, int secure_state);

static void spm_config_nsc_flash(void)
{
	/* Configure a single region in Secure Flash as Non-Secure Callable
	 * (NSC) area.
	 *
	 * Area to configure is dynamically decided with help from linker code.
	 *
	 * Note: Any Secure Entry functions, exposing secure services to the
	 * Non-Secure firmware, shall be located inside this NSC area.
	 *
	 * If the start address of the NSC area is hard-coded, it must follow
	 * the HW restrictions: The size must be a power of 2 between 32 and
	 * 4096, and the end address must fall on a SPU region boundary.
	 */
	//uint32_t nsc_size = FLASH_NSC_SIZE_FROM_ADDR(_start_sg);

	//assert((uint32_t)__sg_size <= nsc_size);
	//assert((u32_t)__sg_size <= nsc_size,
	//	"The Non-Secure Callable region is overflowed by %d byte(s).\n",
	//	(u32_t)__sg_size - nsc_size);

	NRF_SPU_S->FLASHNSC[0].REGION = FLASH_NSC_REGION_FROM_ADDR(_start_sg);
	//NRF_SPU_S->FLASHNSC[0].SIZE = FLASH_NSC_SIZE_REG(nsc_size);
	NRF_SPU_S->FLASHNSC[0].SIZE = SPU_FLASHNSC_SIZE_SIZE_512;  /* MQ Hardcoded this value because FLASH_NSC_SIZE_REG(nsc_size) is incorrect */

//	PRINT("Non-secure callable region 0 placed in flash region %d with size %d.\n",
//		NRF_SPU->FLASHNSC[0].REGION, NRF_SPU->FLASHNSC[0].SIZE << 5);
//	PRINT("\n");
}

static void spm_config_flash(void)
{
	/* Regions of flash up to and including SPM are configured as Secure.
	 * The rest of flash is configured as Non-Secure.
	 */
	static const uint32_t flash_perm[] = {
		/* Configuration for Secure Regions */
		[0 ... LAST_SECURE_REGION_INDEX] =
			FLASH_READ | FLASH_WRITE | FLASH_EXEC |
			FLASH_LOCK | FLASH_SECURE,
		/* Configuration for Non Secure Regions */
		[(LAST_SECURE_REGION_INDEX + 1) ... 31] =
			FLASH_READ | FLASH_WRITE | FLASH_EXEC |
			FLASH_LOCK | FLASH_NONSEC,
	};

	//PRINT("Flash region\t\tDomain\t\tPermissions\n");

	/* Assign permissions */
	for (size_t i = 0; i < ARRAY_SIZE(flash_perm); i++) {

		NRF_SPU_S->FLASHREGION[i].PERM = flash_perm[i];

		//PRINT("%02u 0x%05x 0x%05x \t", i, 32 * KB(i), 32 * KB(i + 1));
		//PRINT("%s", flash_perm[i] & FLASH_SECURE ? "Secure\t\t" :
		//					   "Non-Secure\t");

		//PRINT("%c", flash_perm[i] & FLASH_READ  ? 'r' : '-');
		//PRINT("%c", flash_perm[i] & FLASH_WRITE ? 'w' : '-');
		//PRINT("%c", flash_perm[i] & FLASH_EXEC  ? 'x' : '-');
		//PRINT("%c", flash_perm[i] & FLASH_LOCK  ? 'l' : '-');
		//PRINT("\n");
	}

	spm_config_nsc_flash();
//#if defined(CONFIG_ARM_FIRMWARE_HAS_SECURE_ENTRY_FUNCS)
//	spm_config_nsc_flash();

//#if defined(CONFIG_SPM_SECURE_SERVICES)
//	int err = spm_secure_services_init();

//	if (err != 0) {
//		//PRINT("Could not initialize secure services (err %d).\n", err);
//	}
//#endif
//#endif /* CONFIG_ARM_FIRMWARE_HAS_SECURE_ENTRY_FUNCS */

	//PRINT("\n");
}


static void spm_config_sram(void)
{
	/* Lower 32 kB of SRAM is allocated to the Secure firmware image.
	 * The rest of SRAM is allocated to Non-Secure firmware image.
	 */
	static const uint32_t sram_perm[] = {
		/* Configuration for Regions 0 - 7 (0 - 32 kB) */
		[0 ... 3] = SRAM_READ | SRAM_WRITE | SRAM_EXEC |
			    SRAM_LOCK | SRAM_SECURE,
		/* Configuration for Regions 4 - 31 (32 - 256 kB) */
		[4 ... 31] = SRAM_READ | SRAM_WRITE | SRAM_EXEC |
			     SRAM_LOCK | SRAM_NONSEC,
	};

//	PRINT("SRAM region\t\tDomain\t\tPermissions\n");

	/* Assign permissions */
	for (size_t i = 0; i < ARRAY_SIZE(sram_perm); i++) {

		NRF_SPU_S->RAMREGION[i].PERM = sram_perm[i];

//		PRINT("%02u 0x%05x 0x%05x\t", i, 8 * KB(i), 8 * KB(i + 1));
//		PRINT("%s", sram_perm[i] & SRAM_SECURE ? "Secure\t\t" :
//							 "Non-Secure\t");

//		PRINT("%c", sram_perm[i] & SRAM_READ  ? 'r' : '-');
//		PRINT("%c", sram_perm[i] & SRAM_WRITE ? 'w' : '-');
//		PRINT("%c", sram_perm[i] & SRAM_EXEC  ? 'x' : '-');
//		PRINT("%c", sram_perm[i] & SRAM_LOCK  ? 'l' : '-');
//		PRINT("\n");
	}
//	PRINT("\n");
}

static bool usel_or_split(uint8_t id)
{
	const uint32_t perm = NRF_SPU_S->PERIPHID[id].PERM;

	/* NRF_GPIOTE1_NS needs special handling as its
	 * peripheral ID for non-secure han incorrect properties
	 * in the NRF_SPM->PERIPHID[id].perm register.
	 */
	if (id == NRFX_PERIPHERAL_ID_GET(NRF_GPIOTE1_NS)) {
		return true;
	}

	bool present = (perm & SPU_PERIPHID_PERM_PRESENT_Msk) ==
		       SPU_PERIPHID_PERM_PRESENT_Msk;

	/* User-selectable attribution */
	bool usel = (perm & SPU_PERIPHID_PERM_SECUREMAPPING_Msk) ==
		    SPU_PERIPHID_PERM_SECUREMAPPING_UserSelectable;

	/* Split attribution */
	bool split = (perm & SPU_PERIPHID_PERM_SECUREMAPPING_Msk) ==
		     SPU_PERIPHID_PERM_SECUREMAPPING_Split;

	return present && (usel || split);
}

static int spm_config_peripheral(uint8_t id, bool dma_present)
{
	/* Set a peripheral to Non-Secure state, if
	 * - it is present
	 * - has UserSelectable/Split attribution.
	 *
	 * Assign DMA capabilities and lock down the attribution.
	 *
	 * Note: the function assumes that the peripheral ID matches
	 * the IRQ line.
	 */
	NVIC_DisableIRQ(id);

	if (usel_or_split(id)) {
		NRF_SPU_S->PERIPHID[id].PERM = PERIPH_PRESENT | PERIPH_NONSEC |
			(dma_present ? PERIPH_DMA_NOSEP : 0) |
			PERIPH_LOCK;
	}

	/* Even for non-present peripherals we force IRQs to be routed
	 * to Non-Secure state.
	 */
	irq_target_state_set(id, 0);
	return 0;
}

static void spm_dppi_configure(uint32_t mask)
{
	NRF_SPU_S->DPPI[0].PERM = mask;
}


static void spm_config_peripherals(void)
{
	struct periph_cfg {
		char *name;
		uint8_t id;
		uint8_t nonsecure;
	};

	/* - All user peripherals are allocated to the Non-Secure domain.
	 * - All GPIOs are allocated to the Non-Secure domain.
	 */
	static const struct periph_cfg periph[] = {
		PERIPH("NRF_P0", NRF_P0_NS, 1),
		PERIPH("NRF_UARTE0", NRF_UARTE0_NS, 1),
		PERIPH("NRF_CLOCK", NRF_CLOCK_NS, 1),
		PERIPH("NRF_RTC0", NRF_RTC0_NS, 1),
		PERIPH("NRF_RTC1", NRF_RTC1_NS, 1),
		PERIPH("NRF_NVMC", NRF_NVMC_NS, 1),
		PERIPH("NRF_UARTE1", NRF_UARTE1_NS, 1),
		PERIPH("NRF_UARTE2", NRF_UARTE2_NS, 1),
		PERIPH("NRF_TWIM2", NRF_TWIM2_NS, 1),
		PERIPH("NRF_SPIM3", NRF_SPIM3_NS, 1),
		PERIPH("NRF_TIMER0", NRF_TIMER0_NS, 1),
		PERIPH("NRF_TIMER1", NRF_TIMER1_NS, 1),
		PERIPH("NRF_TIMER2", NRF_TIMER2_NS, 1),
		PERIPH("NRF_SAADC", NRF_SAADC_NS, 1),
		PERIPH("NRF_PWM0", NRF_PWM0_NS, 1),
		PERIPH("NRF_PWM1", NRF_PWM1_NS, 1),
		PERIPH("NRF_PWM2", NRF_PWM2_NS, 1),
		PERIPH("NRF_PWM3", NRF_PWM3_NS, 1),
		PERIPH("NRF_WDT", NRF_WDT_NS, 1),

		PERIPH("NRF_IPC", NRF_IPC_S, 1),
		PERIPH("NRF_VMC", NRF_VMC_S, 1),
		PERIPH("NRF_FPU", NRF_FPU_S, 1),
		PERIPH("NRF_EGU1", NRF_EGU1_S, 1),
		PERIPH("NRF_EGU2", NRF_EGU2_S, 1),
		PERIPH("NRF_DPPIC", NRF_DPPIC_S, 1),

		PERIPH("NRF_GPIOTE1", NRF_GPIOTE1_NS,
						      1),
		PERIPH("NRF_REGULATORS", NRF_REGULATORS_S,
						      1),
	};

	spm_dppi_configure(0x00000000); //MQ Make all channels non-secure

	/* Configure GPIO pins to be Non-Secure */
	NRF_SPU_S->GPIOPORT[0].PERM = 0;

	for (size_t i = 0; i < ARRAY_SIZE(periph); i++) {
		int err;

		if (!periph[i].nonsecure) {
					//PRINT("\tSKIP\n");
			continue;
		}

		err = spm_config_peripheral(periph[i].id, false);
		if (err) {
			assert(0);
		}
	}
}


/*!
 * @brief TrustZone initialization
 *
 * SAU Configuration
 * This function configures 3 regions:
 * 0x00010000 - 0x00081FFF - non-secure for code execution
 * 0x1000FE00 - 0x1000FFFF - secure, non-secure callable for veneer table
 * 0x20000000 - 0x20032FFF - non-secure for data
 *
 * AHB secure controller settings
 * After RESET all memories and peripherals are set to user:non-secure access
 * This function configures following memories and peripherals as secure:
 * 0x00000000 - 0x0000FFFF - for secure code execution (this is physical FLASH address)
 * 0x00008000 - 0x20032FFF - for secure data (this is physical RAM address)
 *
 * Secure peripherals: SYSCON, IOCON, FLEXCOMM0
 * NOTE: This example configures necessary peripherals for this example. 
 *       User should configure all peripherals, which shouldn't be accessible
 *       from normal world.
*/
void BOARD_InitTrustZone()
{
#if NRF9160_XXAA
	spm_config_flash();
	spm_config_sram();
	spm_config_peripherals();


#else  /* MQ  No SAU implemented in nRF9160; see SPU instead. */
	/* Disable SAU */
    SAU->CTRL = 0U;
    
    /* Configure SAU region 0 - Non-secure RAM for CODE execution*/
    /* Set SAU region number */
    SAU->RNR = 0;

    /* Region base address */   
    SAU->RBAR = (CODE_FLASH_START_NS & SAU_RBAR_BADDR_Msk);
    /* Region end address */
    SAU->RLAR = ((CODE_FLASH_START_NS + CODE_FLASH_SIZE_NS-1) & SAU_RLAR_LADDR_Msk) | 
                 /* Region memory attribute index */
                 ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                 /* Enable region */
                 ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk); 
    
    /* Configure SAU region 1 - Non-secure RAM for DATA */
    /* Set SAU region number */
    SAU->RNR = 1;
    /* Region base address */   
    SAU->RBAR = (DATA_RAM_START_NS & SAU_RBAR_BADDR_Msk);
    /* Region end address */
    SAU->RLAR = ((DATA_RAM_START_NS + DATA_RAM_SIZE_NS-1) & SAU_RLAR_LADDR_Msk) | 
                 /* Region memory attribute index */
                 ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                 /* Enable region */
                 ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk); 
    
    /* Configure SAU region 2 - Non-secure callable FLASH for CODE veneer table*/
    /* Set SAU region number */
    SAU->RNR = 2;
    /* Region base address */   
#if defined(__MCUXPRESSO)
    SAU->RBAR = ((uint32_t)&_start_sg & SAU_RBAR_BADDR_Msk);
#else
    SAU->RBAR = (CODE_FLASH_START_NSC & SAU_RBAR_BADDR_Msk);
#endif
    /* Region end address */
#if defined(__MCUXPRESSO)
    SAU->RLAR = (((uint32_t)&_start_sg + CODE_FLASH_SIZE_NSC-1) & SAU_RLAR_LADDR_Msk) |
                 /* Region memory attribute index */
                 ((1U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                 /* Enable region */
                 ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk);
#else
    SAU->RLAR = ((CODE_FLASH_START_NSC + CODE_FLASH_SIZE_NSC-1) & SAU_RLAR_LADDR_Msk) | 
                 /* Region memory attribute index */
                 ((1U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                 /* Enable region */
                 ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk); 
#endif

    /* Configure SAU region 3 - Non-secure peripherals address space */
    /* Set SAU region number */
    SAU->RNR = 3;
    /* Region base address */
    SAU->RBAR = (PERIPH_START_NS & SAU_RBAR_BADDR_Msk);
    /* Region end address */
    SAU->RLAR = ((PERIPH_START_NS + PERIPH_SIZE_NS-1) & SAU_RLAR_LADDR_Msk) |
                 /* Region memory attribute index */
                 ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                 /* Enable region */
                 ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk);

    /* Force memory writes before continuing */
    __DSB();
    /* Flush and refill pipeline with updated permissions */
    __ISB();     
    /* Enable SAU */
    SAU->CTRL = 1U;  

 /* MQ  No AHB Secure Controller in the nRF9160. */
    /*Configuration of AHB Secure Controller 
     * Possible values for every memory sector or peripheral rule: 
     *  0b00    Non-secure and Non-priviledge user access allowed.
     *  0b01    Non-secure and Privilege access allowed.
     *  0b10    Secure and Non-priviledge user access allowed.
     *  0b11    Secure and Priviledge user access allowed. */

    /* FLASH memory configuration from 0x00000000 to 0x0000FFFF, sector size is 32kB */
    AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[0] = 0x00000033U;
    AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[1] = 0x00000000U;
    AHB_SECURE_CTRL->SEC_CTRL_FLASH_ROM[0].SEC_CTRL_FLASH_MEM_RULE[2] = 0x00000000U;
    /* RAM memory configuration from 0x20000000 to 0x20007FFF, sector size is 4kB */
    /* Memory settings for user non-secure access (0x0U) is mentioned for completness only. It is default RESET value. */    
    AHB_SECURE_CTRL->SEC_CTRL_RAM0[0].MEM_RULE[0] = 0x33333333U;
    AHB_SECURE_CTRL->SEC_CTRL_RAM0[0].MEM_RULE[1] = 0x00000000U;
    AHB_SECURE_CTRL->SEC_CTRL_RAM1[0].MEM_RULE[0] = 0x00000000U;
    AHB_SECURE_CTRL->SEC_CTRL_RAM1[0].MEM_RULE[1] = 0x00000000U;
    AHB_SECURE_CTRL->SEC_CTRL_RAM2[0].MEM_RULE[0] = 0x00000000U;
    AHB_SECURE_CTRL->SEC_CTRL_RAM2[0].MEM_RULE[1] = 0x00000000U;
    AHB_SECURE_CTRL->SEC_CTRL_RAM3[0].MEM_RULE[0] = 0x00000000U;
    AHB_SECURE_CTRL->SEC_CTRL_RAM3[0].MEM_RULE[1] = 0x00000000U;
    AHB_SECURE_CTRL->SEC_CTRL_RAM4[0].MEM_RULE[0] = 0x00000000U;
    
    /* Set SYSCON and IOCON as secure */
    AHB_SECURE_CTRL->SEC_CTRL_APB_BRIDGE[0].SEC_CTRL_APB_BRIDGE0_MEM_CTRL0 = AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE_SEC_CTRL_APB_BRIDGE0_MEM_CTRL0_SYSCON_RULE(0x3U) |
                                                                             AHB_SECURE_CTRL_SEC_CTRL_APB_BRIDGE_SEC_CTRL_APB_BRIDGE0_MEM_CTRL0_IOCON_RULE(0x3U);

    /* Set FLEXCOMM0 as secure */
    AHB_SECURE_CTRL->SEC_CTRL_AHB0_0_SLAVE_RULE = AHB_SECURE_CTRL_SEC_CTRL_AHB0_0_SLAVE_RULE_FLEXCOMM0_RULE(0x3U);

    /* Enable AHB secure controller check and lock all rule registers */
    AHB_SECURE_CTRL->MISC_CTRL_DP_REG = (AHB_SECURE_CTRL->MISC_CTRL_DP_REG & ~(AHB_SECURE_CTRL_MISC_CTRL_DP_REG_WRITE_LOCK_MASK | 
                                                                               AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK)) |
                                        AHB_SECURE_CTRL_MISC_CTRL_DP_REG_WRITE_LOCK(0x1U) |
                                        AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING(0x1U);
#endif

    /* Force memory writes before continuing */
    __DSB();
    /* Flush and refill pipeline with updated permissions */
    __ISB();
}
