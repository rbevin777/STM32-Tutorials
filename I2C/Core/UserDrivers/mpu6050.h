/*
 * mpu6050.h
 *
 *  Created on: Feb 10, 2024
 *      Author: rbevi
 */

#ifndef USERDRIVERS_MPU6050_H_
#define USERDRIVERS_MPU6050_H_

#include <stdint.h>

#define MPU6050_DEV_ADD_AD0_LOW 0xD0u // Device address of the MPU6050 when pin AD0 is pulled low
#define MPU6050_DEV_ADD_AD0_HIGH 0xE0u // Device address of the MPU6050 when pin AD0 is pulled high


bool mpu6050_init(void);
int16_t mpu6050_get_x_axis_data(void);
int16_t mpu6050_get_y_axis_data(void);
int16_t mpu6050_get_z_axis_data(void);


#endif /* USERDRIVERS_MPU6050_H_ */
