/*
 * periph_uart.h
 *
 *  Created on: Feb 10, 2024
 *      Author: rbevi
 */

#ifndef PERIPHERALS_PERIPH_UART_H_
#define PERIPHERALS_PERIPH_UART_H_

#include "stm32f3xx_hal.h"

#include <stdbool.h>


#define MAX_BUFFER_LEN 200u
#define MAX_UART_TIMEOUT 100u

bool periph_uart_init(UART_HandleTypeDef *huart);
void periph_uart_handle_tx_int_data(UART_HandleTypeDef *huart);
void periph_uart_handle_rx_int_data(UART_HandleTypeDef *huart);
void periph_uart_send_tx_data(const char *tx_buff, uint16_t buffer_len);

#endif /* PERIPHERALS_PERIPH_UART_H_ */
