/*
 * mpu6050.h
 *
 *  Created on: Feb 10, 2024
 *      Author: rbevi
 */

#ifndef USERDRIVERS_MPU6050_H_
#define USERDRIVERS_MPU6050_H_

#include <stdint.h>

#define MPU6050_DEV_ADD_AD0_LOW 0xD0 // Device address of the MPU6050.
#define MPU6050_DEV_ADD_AD0_HIGH 0xE0 // Device address of the MPU6050.

#define WHO_AM_I_VALUE 0x68u  // This is the value of the data in the WHO_AM_I register.


bool mpu6050_get_who_am_i(void);
#endif /* USERDRIVERS_MPU6050_H_ */
