/*
 * perip_i2c.c
 *
 *  Created on: Feb 10, 2024
 *      Author: rbevi
 */

#include "periph_i2c.h"

// Max timeout in microseconfs
#define I2C_MAX_TIMEOUT 100u

#define I2C_MAX_DATA_SIZE 1u

static I2C_HandleTypeDef hi2c_s;
static bool module_init_s = false;


/*!
 * \brief     This function will initialize this module for use by the main code.
 * \param[in] hi2c - pointer to the I2C handle.
 * \return    module_init_s - True if the module was initialized okay, False if not.
 */
bool periph_i2c_init(const I2C_HandleTypeDef *hi2c)
{
	hi2c_s = *hi2c;
	module_init_s = true;
	return module_init_s;
}

/*!
 * \brief     This function will write the given data to a given regsiter address.
 * \param[in] device_add - Address of the register we want to write data to.
 * \param[in] data - Pointer to the data that we want to write over I2C.
 * \return    tx_okay - True if the transmit of the register data was okay, False if not.
 */
bool periph_i2c_tx(uint16_t device_add, uint8_t *data)
{
	bool tx_okay = false;
	if(module_init_s)
	{
		HAL_StatusTypeDef i2c_tx_okay = HAL_I2C_Master_Transmit(&hi2c_s, device_add, data, I2C_MAX_DATA_SIZE, I2C_MAX_TIMEOUT);
		if(i2c_tx_okay == HAL_OK)
		{
			tx_okay = true;
		}
	}
	return tx_okay;
}

/*!
 * \brief     This function will read data from a given register address.
 * \param[in] device_add - Address of the register we want to read data from.
 * \retval    rx_data - Data read from a register address given.
 */
bool periph_i2c_rx(uint16_t device_add, uint8_t reg_add, uint8_t *reg_val)
{
	bool rx_okay = false;
	if(module_init_s)
	{
		HAL_StatusTypeDef i2c_tx_okay = HAL_I2C_Master_Transmit(&hi2c_s, &device_add, &reg_add, I2C_MAX_DATA_SIZE, I2C_MAX_TIMEOUT);
		HAL_StatusTypeDef i2c_rx_okay = HAL_I2C_Master_Receive(&hi2c_s, &device_add, reg_val, I2C_MAX_DATA_SIZE, I2C_MAX_TIMEOUT);
		if((i2c_tx_okay == HAL_OK) && (i2c_rx_okay == HAL_OK))
		{
			rx_okay = true;
		}
	}
	return rx_okay;
}
