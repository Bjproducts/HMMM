//******************
// GPIO Library Implementation
//
// CREATED: 10/27/2023, updated for STM32G0B1
//
// FILE: gpio.c
//

#include "gpio.h"

/***************************************************************
 * Configure GPIO pin as output
 ***************************************************************/
void GPIO_InitOutput(GPIO_TypeDef *port, uint16_t pin)
{
    // Set mode to output (01)
    port->MODER &= ~(3U << (pin * 2));  // Clear bits
    port->MODER |=  (1U << (pin * 2));  // Output mode
}

/***************************************************************
 * Configure GPIO pin as input
 ***************************************************************/
void GPIO_InitInput(GPIO_TypeDef *port, uint16_t pin)
{
    // Set mode to input (00)
    port->MODER &= ~(3U << (pin * 2));
}

/***************************************************************
 * Configure GPIO alternate function
 ***************************************************************/
void GPIO_InitAlternateF(GPIO_TypeDef *port, uint16_t pin, uint16_t af)
{
    // Set mode to alternate function (10)
    port->MODER &= ~(3U << (pin * 2));
    port->MODER |=  (2U << (pin * 2));

    // Set AF register
    if (pin < 8)
    {
        port->AFR[0] &= ~(0xFU << (pin * 4));
        port->AFR[0] |=  ((af & 0xF) << (pin * 4));
    }
    else
    {
        port->AFR[1] &= ~(0xFU << ((pin - 8) * 4));
        port->AFR[1] |=  ((af & 0xF) << ((pin - 8) * 4));
    }
}

/***************************************************************
 * Set GPIO pin type (Push-Pull / Open-Drain)
 ***************************************************************/
void GPIO_SetType(GPIO_TypeDef *port, uint16_t pin, IO_Type type)
{
    port->OTYPER &= ~(1U << pin);
    port->OTYPER |= ((type & 0x1) << pin);
}

/***************************************************************
 * Set GPIO pin speed
 ***************************************************************/
void GPIO_SetSpeed(GPIO_TypeDef *port, uint16_t pin, IO_Speed speed)
{
    port->OSPEEDR &= ~(3U << (pin * 2));
    port->OSPEEDR |= ((speed & 0x3) << (pin * 2));
}

/***************************************************************
 * Set GPIO pull-up/pull-down
 ***************************************************************/
void GPIO_SetPullMode(GPIO_TypeDef *port, uint16_t pin, IO_PullMode mode)
{
    port->PUPDR &= ~(3U << (pin * 2));
    port->PUPDR |= ((mode & 0x3) << (pin * 2));
}

/***************************************************************
 * Set GPIO pin
 ***************************************************************/
void GPIO_Set(GPIO_TypeDef *port, uint16_t pin)
{
    port->BSRR = (1U << pin);
}

/***************************************************************
 * Clear GPIO pin
 ***************************************************************/
void GPIO_Clear(GPIO_TypeDef *port, uint16_t pin)
{
    port->BSRR = (1U << (pin + 16));
}

/***************************************************************
 * Toggle GPIO pin
 ***************************************************************/
void GPIO_Toggle(GPIO_TypeDef *port, uint16_t pin)
{
    if (port->ODR & (1U << pin))
        port->BSRR = (1U << (pin + 16));  // Clear
    else
        port->BSRR = (1U << pin);         // Set
}

/***************************************************************
 * Read GPIO pin
 ***************************************************************/
int GPIO_Read(GPIO_TypeDef *port, uint16_t pin)
{
    return (port->IDR & (1U << pin)) ? 1 : 0;
}

/***************************************************************
 * Configure GPIO for I2C (Open-Drain, Pull-Up, AF)
 ***************************************************************/
void GPIO_I2C_Config(GPIO_TypeDef *port, uint16_t pin)
{
    GPIO_InitAlternateF(port, pin, 1);  // AF1 = I2C
    GPIO_SetType(port, pin, Type_OpenDrain);
    GPIO_SetPullMode(port, pin, PullMode_PullUp);
    GPIO_SetSpeed(port, pin, Speed_High);
}