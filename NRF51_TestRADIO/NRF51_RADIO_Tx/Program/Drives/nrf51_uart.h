/* #include "nrf51_uart.h" */

#ifndef __NRF51_UART_H
#define __NRF51_UART_H

#include "nrf51_system.h"
/*====================================================================================================*/
/*====================================================================================================*/
typedef struct {
  uint8_t  UART_PinTXD;
  uint8_t  UART_PinRXD;
  uint8_t  UART_PinRTS;
  uint8_t  UART_PinCTS;
  uint32_t UART_Parity;
  // UART_CONFIG_PARITY_Excluded - Parity bit excluded.
  // UART_CONFIG_PARITY_Included - Parity bit included.
  uint32_t UART_HardwareFlowControl;
  // UART_CONFIG_HWFC_Disabled - Hardware flow control disabled.
  // UART_CONFIG_HWFC_Enabled  - Hardware flow control enabled.
  uint32_t UART_BaudRate;
  // UART_BAUDRATE_BAUDRATE_Baud1200   -   1200 baud.
  // UART_BAUDRATE_BAUDRATE_Baud2400   -   2400 baud.
  // UART_BAUDRATE_BAUDRATE_Baud4800   -   4800 baud.
  // UART_BAUDRATE_BAUDRATE_Baud9600   -   9600 baud.
  // UART_BAUDRATE_BAUDRATE_Baud14400  -  14400 baud.
  // UART_BAUDRATE_BAUDRATE_Baud19200  -  19200 baud.
  // UART_BAUDRATE_BAUDRATE_Baud28800  -  28800 baud.
  // UART_BAUDRATE_BAUDRATE_Baud38400  -  38400 baud.
  // UART_BAUDRATE_BAUDRATE_Baud57600  -  57600 baud.
  // UART_BAUDRATE_BAUDRATE_Baud76800  -  76800 baud.
  // UART_BAUDRATE_BAUDRATE_Baud115200 - 115200 baud.
  // UART_BAUDRATE_BAUDRATE_Baud230400 - 230400 baud.
  // UART_BAUDRATE_BAUDRATE_Baud250000 - 250000 baud.
  // UART_BAUDRATE_BAUDRATE_Baud460800 - 460800 baud.
  // UART_BAUDRATE_BAUDRATE_Baud921600 - 921600 baud.
  // UART_BAUDRATE_BAUDRATE_Baud1M     -     1M baud.
} UART_InitTypeDef;
/*====================================================================================================*/
/*====================================================================================================*/
void UART_Init( UART_InitTypeDef *UART_InitStruct );
void UART_InterruptCmd( FunctionalState NewState );

void    UART_SendByte( uint8_t SendData );
uint8_t UART_RecvByte( void );
uint8_t UART_RecvByteWTO( uint8_t *RecvData, int32_t Timeout_ms );
void    UART_SendData( uint8_t *SendData, uint16_t DataLen );
void    UART_RecvData( uint8_t *RecvData, uint16_t DataLen );
uint8_t UART_RecvDataWTO( uint8_t *RecvData, uint16_t DataLen, int32_t Timeout_ms );
/*====================================================================================================*/
/*====================================================================================================*/
#endif	 
