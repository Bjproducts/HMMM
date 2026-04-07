#include "uart.h"
#include <stdio.h>

/**
 * @brief Initializes the USART peripheral for STM32G0B1RE
 * @param USARTx: Pointer to USART peripheral (USART1, USART2, etc.)
 * @param BaudRate: Desired baud rate (e.g., 115200)
 * @param Interrupt: 1 to enable RX interrupt, 0 to disable
 */
void UART_Init(USART_TypeDef* USARTx, uint32_t BaudRate, char Interrupt) {
    
    // 1. Enable Clock for the specific USART peripheral
    // STM32G0B1RE maps USARTs across APBENR1 and APBENR2
    if (USARTx == USART1) {
        RCC->APBENR2 |= RCC_APBENR2_USART1EN;
    } else if (USARTx == USART2) {
        RCC->APBENR1 |= RCC_APBENR1_USART2EN;
    } else if (USARTx == USART3) {
        RCC->APBENR1 |= RCC_APBENR1_USART3EN;
    } else if (USARTx == USART4) {
        RCC->APBENR1 |= RCC_APBENR1_USART4EN;
    } 
    // Add USART5/6 if needed following the pattern above

    // 2. Configure Baud Rate
    // Standard oversampling by 16 (OVER8 = 0)
    // BRR = Frequency / BaudRate
    USARTx->BRR = (SystemCoreClock / BaudRate);

    // 3. Control Register 1 Configuration
    // Clear CR1 and set TE (Transmit Enable) and RE (Receive Enable)
    // Default is 8-bit, No parity, 1 stop bit
    USARTx->CR1 = USART_CR1_TE | USART_CR1_RE; 

    if (Interrupt) {
        USARTx->CR1 |= USART_CR1_RXNEIE_RXFNEIE; // ✅ G0 family name
        
        // Enable IRQ in NVIC
        if (USARTx == USART1) NVIC_EnableIRQ(USART1_IRQn);
        else if (USARTx == USART2) NVIC_EnableIRQ(USART2_LPUART2_IRQn); // G0B1 shared IRQ
        else if (USARTx == USART3 || USARTx == USART4) NVIC_EnableIRQ(USART3_4_5_6_LPUART1_IRQn);
    }

    // 4. Enable USART
    USARTx->CR1 |= USART_CR1_UE;
}

void UART_TxByte(USART_TypeDef* USARTx, uint8_t byte) {
    // Wait until Transmit Data Register is empty (TXE)
    while (!(USARTx->ISR & USART_ISR_TXE_TXFNF));
    USARTx->TDR = byte;
}

void UART_TxStr(USART_TypeDef* USARTx, const char* pStr) {
    while (*pStr) {
        UART_TxByte(USARTx, (uint8_t)*pStr++);
    }
}

void UART_TxBuffer(USART_TypeDef* USARTx, uint8_t* buffer, uint16_t size) {
    for (uint16_t i = 0; i < size; i++) {
        UART_TxByte(USARTx, buffer[i]);
    }
}

uint8_t UART_RxByte(USART_TypeDef* USARTx, uint8_t* pByte) {
    // Check if Read Data Register is NOT empty (RXNE)
    if (USARTx->ISR & USART_ISR_RXNE_RXFNE) {
        *pByte = (uint8_t)(USARTx->RDR);
        return 1;
    }
    return 0;
}

// --- Terminal Control Functions (VT100) ---

void TERM_ClearScreen(USART_TypeDef * pUSART) {
    // ESC [ 2 J (Clear) ESC [ H (Home)
    UART_TxStr(pUSART, "\033[2J\033[H");
}

void TERM_GotoXY(USART_TypeDef * pUSART, int iCol, int iRow) {
    char buf[24];
    // Sequence: ESC [ row ; col H
    sprintf(buf, "\033[%d;%dH", iRow, iCol);
    UART_TxStr(pUSART, buf);
}

void TERM_TxStringXY(USART_TypeDef * pUSART, int iCol, int iRow, char * pStr) {
    TERM_GotoXY(pUSART, iCol, iRow);
    UART_TxStr(pUSART, pStr);
}