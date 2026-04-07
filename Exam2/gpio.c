#include "gpio.h"

void GPIO_InitOutput(GPIO_TypeDef *port, uint8_t pin)
{
    port->MODER &= ~(3U << (pin * 2));   // Clear mode bits
    port->MODER |=  (1U << (pin * 2));   // Output mode
}

void GPIO_InitInput(GPIO_TypeDef *port, uint8_t pin)
{
    port->MODER &= ~(3U << (pin * 2));   // Input mode (00)
}

void GPIO_InitAlternateF(GPIO_TypeDef *port, uint8_t pin, uint8_t af)
{
    port->MODER &= ~(3U << (pin * 2));
    port->MODER |=  (2U << (pin * 2));   // Alternate function

    if (pin < 8)
    {
        port->AFR[0] &= ~(0xF << (pin * 4));
        port->AFR[0] |=  (af  << (pin * 4));
    }
    else
    {
        port->AFR[1] &= ~(0xF << ((pin - 8) * 4));
        port->AFR[1] |=  (af  << ((pin - 8) * 4));
    }
}

void GPIO_Set(GPIO_TypeDef *port, uint8_t pin)
{
    port->BSRR = (1U << pin);
}

void GPIO_Clear(GPIO_TypeDef *port, uint8_t pin)
{
    port->BSRR = (1U << (pin + 16));
}

void GPIO_Toggle(GPIO_TypeDef *port, uint8_t pin)
{
    if (port->ODR & (1U << pin))
      port->BSRR = (1U << (pin + 16));  // Clear
    else
     port->BSRR = (1U << pin);  
}

uint8_t GPIO_Read(GPIO_TypeDef *port, uint8_t pin)
{
    return (port->IDR & (1U << pin)) ? 1 : 0;
}
