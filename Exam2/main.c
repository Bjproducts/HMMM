/*********************************************************************
*                    CMPE1250: Embedded Systems FUndamentals         *
*                                          NAIT                      *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Practical Assessment #2
Device  : STM32G0B1RE
Term    : Winter 2026  
Name    : This is you
*/

#include <stdio.h>
#include <stdlib.h>
#include "stm32g0b1xx.h"

/*Include your libraries here*/

/*********************************************************************
*
*       main()
*
*  Function description
*   Application entry point.
*/

/*Local function prototypes*/


int main(void) 
{
  //Initialization
  //Enable power interface clock (RM 5.4.15)
  RCC->APBENR1 |= RCC_APBENR1_PWREN;

  /*Peripherals clock enable (RM 5.4.13)*/


  /*Other PIN configurations*/



  while(1)
  {

  }
}

/*Local functions Implementation*/




/*************************** End of file ****************************/