/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Practical Assessment #2
Device  : STM32G0B1RE
Term    : Winter 2026  
Name    : BuoapuA
*/

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32g0b1xx.h"
#include "gpio.h"
#include "uart.h"
#include "clock.h"
#include "timer.h"




/*********************************************************************
*
*       main()
*
*  Function description
*   Application entry point.
*/

void UpdateDisplay(uint32_t leftCount, uint32_t rightCount);
int main(void)
{
    //Part c STATE VAIBALES
    uint32_t leftCount  = 0;
    uint32_t rightCount = 0;
    int leftArmed  = 1;
    int rightArmed = 1;

    //PART D STATE VARIABLE
    int buttonReady = 1;

    //CLOCK CONFIG
    Clock_InitPll(PLL_50MHZ);

    //Enable GPIO CLOCKS
    RCC->IOPENR  |= RCC_IOPENR_GPIOAEN;         //Enable GPIOA
    RCC->IOPENR  |= RCC_IOPENR_GPIOCEN;         //Enable GPIOC

    //Enable CLocks
    RCC->APBENR1 |= RCC_APBENR1_USART2EN;       //Enable USART2
    RCC->APBENR1 |= RCC_APBENR1_TIM6EN;         //Enable TIM6
    RCC->APBENR1 |= RCC_APBENR1_TIM7EN;         //Enable TIM7


    GPIO_InitAlternateF(GPIOA, 9, 0);
    Clock_EnableOutput(MCO_Sel_SYSCLK, MCO_Div4);

    //UART2 CONFIG
    GPIO_InitAlternateF(GPIOA, 2, 1);
    GPIO_InitAlternateF(GPIOA, 3, 1);

    //CONFIG PA5
    GPIO_InitOutput(GPIOA, 5);

   //LED AS OUTPUT
    GPIO_InitOutput(GPIOA, 6);

  
    GPIO_InitInput(GPIOC, 4);
    GPIO_SetPullMode(GPIOC, 4, PullMode_PullDown);
    GPIO_InitInput(GPIOC, 5);
    GPIO_SetPullMode(GPIOC, 5, PullMode_PullDown);

    //PC13 CONFIG
    GPIO_InitInput(GPIOC, 13);
    GPIO_SetPullMode(GPIOC, 13, PullMode_PullUp);

//UART 115200 BAUD RATE
    UART_Init(USART2, 115200, 0);
    TERM_ClearScreen(USART2);
    UpdateDisplay(leftCount, rightCount);

    //TIMER TO 7.7ms
    Timer_SetusTick(TIM6);
    TIM6->ARR = 7700 - 1;
    Timer_SetEnable(TIM6, 1);

    //Nonblocking delay
    Timer_SetmsTick(TIM7);

    while (1)
    {
       
        if (Timer_PollUIF(TIM6))
            GPIO_Toggle(GPIOA, 6);

      //Read left and right 
        int leftPressed  = GPIO_Read(GPIOC, 4);
        int rightPressed = GPIO_Read(GPIOC, 5);

        if (leftPressed && leftArmed)
        {//Left pressed
            leftCount++;
            leftArmed = 0;
            UpdateDisplay(leftCount, rightCount);
        }
        else if (!leftPressed)
        {//Left released
            leftArmed = 1;
        }

        if (rightPressed && rightArmed)
        {//Right pressed
            rightCount++;
            rightArmed = 0;
            UpdateDisplay(leftCount, rightCount);
        }
        else if (!rightPressed)
        {//Right released
            rightArmed = 1;
        }

        //Part D: PC13 press -> PA5 high for 75 ms
        int pressed = (GPIO_Read(GPIOC, 13) == 0);

        if (pressed && buttonReady)
        {//Button pressed
            buttonReady = 0;
            GPIO_Set(GPIOA, 5);
            Timer_DelayTicks(TIM7, 75);
            GPIO_Clear(GPIOA, 5);
        }
        else if (!pressed)
        {//Button released
            buttonReady = 1;
        }
    }
}
void UpdateDisplay(uint32_t leftCount, uint32_t rightCount)
{
    char buf[20];

    TERM_TxStringXY(USART2, 1,  10, "LEFT SW:");
    TERM_TxStringXY(USART2, 1,  11, "RIGHT SW:");

    sprintf(buf, "%02lu", (unsigned long)leftCount);
    TERM_TxStringXY(USART2, 15, 10, buf);

    sprintf(buf, "%02lu", (unsigned long)rightCount);
    TERM_TxStringXY(USART2, 15, 11, buf);
}

/*************************** End of file ****************************/