/*
 * periph_i2c.h
 *
 *  Created on: Feb 10, 2024
 *      Author: rbevi
 */

#ifndef PERIPHERALS_PERIPH_I2C_H_
#define PERIPHERALS_PERIPH_I2C_H_

#include "stm32f3xx_hal.h"

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>


#define I2C_MAX_DATA_SIZE 1u


bool periph_i2c_init(const I2C_HandleTypeDef *hi2c);
bool periph_i2c_tx(uint16_t device_add, uint8_t reg_add, uint8_t *data, uint16_t data_len);
bool periph_i2c_rx(uint16_t device_add, uint8_t reg_add, uint8_t *rx_data);

#endif /* PERIPHERALS_PERIPH_I2C_H_ */
