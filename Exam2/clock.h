#ifndef CLOCK_H
#define CLOCK_H

#include "stm32g0b1xx.h"

/* PLL Config (only what you need) */
#define PLL_40MHZ  (RCC_PLLCFGR_PLLREN | (20 << RCC_PLLCFGR_PLLN_Pos))

/* MCO options */
#define MCO_Sel_SYSCLK (1U << 24)
#define MCO_Div1       (0U << 28)

/* Function Prototypes */
void Clock_InitPll(uint32_t pll_config);
void Clock_SelectPLL(void);
void Clock_EnableOutput(uint32_t source, uint32_t div);

#endif