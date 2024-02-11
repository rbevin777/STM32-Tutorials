/*
 * mpu6050.c
 *
 *  Created on: Feb 10, 2024
 *      Author: rbevi
 */

#include "periph_i2c.h"
#include "mpu6050_reg_map.h"
#include "mpu6050.h"
#include "periph_uart.h"

#include <string.h>


bool mpu6050_get_who_am_i(void)
{
	bool device_present = false;
	uint8_t reg_val = 0x00;

	(void)periph_i2c_rx(MPU6050_DEV_ADD_AD0_LOW, MPU6050_REG_WHO_AM_I, &reg_val);
	if(reg_val == WHO_AM_I_VALUE)
	{
		device_present = true;
	}
	return device_present;
}
