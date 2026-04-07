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
    // Clear MCO bits and set new source
    RCC->CFGR = (RCC->CFGR & ~(0x7 << 24)) | (source & (0x7 << 24));

    // Clear MCO prescaler bits and set new divider
    RCC->CFGR = (RCC->CFGR & ~(0xF << 28)) | (div & (0xF << 28));
}