/*
 * mpu6050.c
 *
 *  Created on: Feb 10, 2024
 *      Author: rbevi
 */
/**********************  INCLUDES **********************/

#include "periph_i2c.h"
#include "mpu6050_reg_map.h"
#include "mpu6050.h"

#include <string.h>

/******************  PRIVATE VARIABLES ******************/
#define MPU6050_ADDRESS MPU6050_DEV_ADD_AD0_LOW
#define WHO_AM_I_VALUE 0x68u  // This is the value of the data in the WHO_AM_I register.

static bool device_init_complete_s = false;

/************* PRIVATE FUNCTION PROTOTYPES **************/
bool get_who_am_i(void);
bool write_accel_config(void);
uint8_t read_regsiter(uint8_t reg_add);
void write_regsiter(uint8_t reg_add, uint8_t reg_val);

/******************* PUBLIC FUNCTIONS *******************/
/*!
 * \brief     Init function used to setup this module and the accelerometer for sampling.
 * \return    device_init_complete_s - True is the device is initialized okay, false if not.
 */
bool mpu6050_init(void)
{
	// This is a ternary operator. It's a more condensed if statement.
	device_init_complete_s = (get_who_am_i() == true) ? true : false;

	// Need to take the accelerometer out of sleep mode.
	uint8_t data = 0x00;
	(void)write_regsiter(MPU6050_REG_PWR_MGMT_1, data);

    // Set data rate to 1KHz by writing MPU6050_REG_SMPRT_DIV register.
	data = 0x07;
	(void)write_regsiter(MPU6050_REG_SMPRT_DIV, data);

	// Set accelerometer configuration to +-4g.
	data = 0x10;
	(void)write_regsiter(MPU6050_REG_ACCEL_CONFIG, data);

	return device_init_complete_s;
}

/*!
 * \brief     Reads and formats the X Axis data from the MPU6050.
 * \return    x_axis - X axis value.
 */
int16_t mpu6050_get_x_axis_data(void)
{
	uint16_t x_axis = 0u;
	if(device_init_complete_s)
	{
		uint8_t x_axis_l = read_regsiter(MPU6050_REG_ACCEL_XOUT_L);
		uint8_t x_axis_h = read_regsiter(MPU6050_REG_ACCEL_XOUT_H);
		x_axis = ((int16_t)x_axis_h << 8) | x_axis_l;
	}
	return x_axis;
}

/*!
 * \brief     Reads and formats the Y Axis data from the MPU6050.
 * \return    y_axis - Y axis value.
 */
int16_t mpu6050_get_y_axis_data(void)
{
	uint16_t y_axis = 0u;
	if(device_init_complete_s)
	{
		uint8_t y_axis_l = read_regsiter(MPU6050_REG_ACCEL_YOUT_L);
		uint8_t y_axis_h = read_regsiter(MPU6050_REG_ACCEL_YOUT_H);
		y_axis = ((int16_t)y_axis_h << 8) | y_axis_l;
	}
	return y_axis;
}

/*!
 * \brief     Reads and formats the Z Axis data from the MPU6050.
 * \return    z_axis - Z axis value.
 */
int16_t mpu6050_get_z_axis_data(void)
{
	uint16_t z_axis = 0u;
	if(device_init_complete_s)
	{
		uint8_t z_axis_l = read_regsiter(MPU6050_REG_ACCEL_ZOUT_L);
		uint8_t z_axis_h = read_regsiter(MPU6050_REG_ACCEL_ZOUT_H);
		z_axis = ((int16_t)z_axis_h << 8) | z_axis_l;
	}
	return z_axis;
}

/****************** PRIVATE FUNCTIONS *******************/

/*!
 * \brief     Reads the WHO_AM_I register of the MPU6050.
 * \return    device_present - True is the register value was read correctly, false if not.
 */
bool get_who_am_i(void)
{
	bool device_present = false;
	uint8_t reg_val = 0x00;

	reg_val = read_regsiter(MPU6050_REG_WHO_AM_I);
	if(reg_val == WHO_AM_I_VALUE)
	{
		device_present = true;
	}
	return device_present;
}

/*!
 * \brief     Reads from a register address passed into the function.
 * \param[in] reg_add - Address of the register we want to read.
 * \return    reg_val - Value of the register we read from.
 */
uint8_t read_regsiter(uint8_t reg_add)
{
	uint8_t reg_val = 0x00;
	(void)periph_i2c_rx(MPU6050_ADDRESS, reg_add, &reg_val);
	return reg_val;
}

/*!
 * \brief     Writes a register value to a given register address.
 * \param[in] reg_add - Address of the register we want to write to.
 * \param[in] reg_val - Value of the register we want to write.
 * \return    reg_write_okay - True is the register write was successful, false if not.
 *
 */
bool write_regsiter(uint8_t reg_add, uint8_t reg_val)
{
	bool reg_write_okay = periph_i2c_rx(MPU6050_ADDRESS, reg_add, &reg_val);
	return reg_write_okay;
}
