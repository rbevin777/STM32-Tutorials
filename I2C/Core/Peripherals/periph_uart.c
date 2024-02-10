/*
 * periph_uart.c
 *
 *  Created on: Feb 10, 2024
 *      Author: rbevi
 */

/**********************  INCLUDES **********************/
#include "periph_uart.h"

#include <string.h>


/******************  PRIVATE VARIABLES ******************/
static bool init_okay_s = false; // used to make sure public functions cannot be called unless module is initialized.
static uint8_t tx_buffer_s[MAX_BUFFER_LEN]; // rx_data buffer
static uint8_t rx_buffer_s[MAX_BUFFER_LEN]; // tx_data buffer
static uint8_t rx_data_s; // receive buffer
static uint32_t counter_s = 0; // count how many bytes are received


/****************** PUBLIC FUNCTIONS *******************/
/*!
 * \brief     Setup function to init uart with the correct data buffers
 * \param[in] huart - pointer to the uart handle we want to use.
 * \return    init_okay - True if setup was okay, false if not.
 */
bool periph_uart_init(UART_HandleTypeDef *huart)
{
	bool init_okay = false;
	HAL_StatusTypeDef tx_setup_ok = HAL_UART_Transmit_IT(huart, tx_buffer_s, MAX_BUFFER_LEN);
	HAL_StatusTypeDef rx_setup_ok = HAL_UART_Receive_IT(huart, &rx_data_s, 1);
	if(tx_setup_ok == HAL_OK && rx_setup_ok == HAL_OK)
	{
		init_okay = true;
		init_okay_s = init_okay;
	}
	return init_okay;
}

/*!
 * \brief     Setup function to init uart with the correct data buffers
 * \param[in] huart - pointer to the uart handle we want to use.
 */
void periph_uart_handle_tx_int_data(UART_HandleTypeDef *huart)
{
	if(init_okay_s)
	{
		memset(tx_buffer_s, '\0', (size_t)MAX_BUFFER_LEN); //empty the transmit data buffer to be ready for new data.
	}
}

/*!
 * \brief     Setup function to init uart with the correct data buffers
 * \param[in] huart - Pointer to the uart handle we want to use.
 */
void periph_uart_handle_rx_int_data(UART_HandleTypeDef *huart)
{
	if(init_okay_s)
	{
		 if(rx_data_s == '\r') // If we get the "Enter" character (carriage return ASCII) from the terminal.
		 {
			 char* hello_cmd = "hello"; // this is the command we want to look for from the sender.

			 if (strcmp(hello_cmd, rx_buffer_s) == 0) // string compare the command against what we received from the sender.
			 {
				 // if the comparison is okay, move the response into the transmit buffer.
				 const char *reponse = "Hello to you too!\n";
				 strcpy((char* )tx_buffer_s, reponse);
			 }
			 else
			 {
				 // if the comparison is not okay, move the error response into the transmit buffer.
				 const char *error = "Uh oh, something didn't work...\n";
				 strcpy((char* )tx_buffer_s, error);
			 }


			 HAL_UART_Transmit(huart, tx_buffer_s, (uint16_t)MAX_BUFFER_LEN, 100); // transmit the data buffer out the UART Tx pin.
			 memset(tx_buffer_s, '\0', (size_t)MAX_BUFFER_LEN); //empty the transmit data buffer to be ready for new data.
			 memset(rx_buffer_s, '\0', (size_t)MAX_BUFFER_LEN); //empty the receive data buffer to be ready for new data.
			 counter_s = 0; // reset the counter to be ready for new data.

		 }
		 else
		 {
			 // if there is data coming into the rx_data pointer that isn't the "Enter" character then add it to the buffer.
			 rx_buffer_s[counter_s++] = rx_data_s;
		 }

		 // Get ready for new data in rx_data_s pointer.
		 HAL_UART_Receive_IT(huart, &rx_data_s, 1);
	}
}

/*!
 * \brief    Setup function to init uart with the correct data buffers
 * \param[in] huart - Pointer to the uart handle we want to use.
 * \param[in] tx_buff - Buffer with the message we want to send.
 * \param[in] buffer_len - Maximum lenght of the buffer we want to send.
 */
void periph_uart_send_tx_data(UART_HandleTypeDef *huart, const char tx_buff[MAX_BUFFER_LEN], uint8_t buffer_len)
{
	if(init_okay_s)
	{
		strcpy((char* )tx_buffer_s, tx_buff);
		HAL_UART_Transmit(huart, tx_buffer_s, (uint16_t)MAX_BUFFER_LEN, buffer_len);
	}
}
