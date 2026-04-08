#include "clock.h"

void Clock_InitPll(uint32_t pll_config)
{
    RCC->CR &= ~RCC_CR_PLLON;        // Turn off PLL
    while(RCC->CR & RCC_CR_PLLRDY);  // Wait for PLL to stop

    RCC->PLLCFGR = pll_config;       // Load configuration

    RCC->CR |= RCC_CR_PLLON;         // Turn on PLL
    while(!(RCC->CR & RCC_CR_PLLRDY)); // Wait for PLL ready
}
void Clock_EnableOutput(uint32_t source, uint32_t div)
{
    // Set MCO source safely
    RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_MCOSEL_Msk) | (source & RCC_CFGR_MCOSEL_Msk);

    // Set MCO prescaler safely
    RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_MCOPRE_Msk) | (div & RCC_CFGR_MCOPRE_Msk);
}