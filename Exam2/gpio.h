#ifndef GPIO_H
#define GPIO_H

#include "stm32g0xx.h"
#include <stdint.h>

/* GPIO configuration functions */
void GPIO_InitOutput(GPIO_TypeDef *port, uint8_t pin);
void GPIO_InitInput(GPIO_TypeDef *port, uint8_t pin);
void GPIO_InitAlternateF(GPIO_TypeDef *port, uint8_t pin, uint8_t af);

/* GPIO control functions */
void GPIO_Set(GPIO_TypeDef *port, uint8_t pin);
void GPIO_Clear(GPIO_TypeDef *port, uint8_t pin);
void GPIO_Toggle(GPIO_TypeDef *port, uint8_t pin);
uint8_t GPIO_Read(GPIO_TypeDef *port, uint8_t pin);

#endif
