/*
 * bmp180.h
 *
 *  Created on: May 3, 2025
 *      Author: minhh
 */

#ifndef DRIVERS_INC_BMP180_H_
#define DRIVERS_INC_BMP180_H_

#include "stdint.h"
#include "i2c.h"

typedef union{
	uint16_t full[11];
	struct{
		uint16_t AC1;
		uint16_t AC2;
		uint16_t AC3;
		uint16_t AC4;
		uint16_t AC5;
		uint16_t AC6;
		uint16_t B1;
		uint16_t B2;
		uint16_t MB;
		uint16_t MC;
		uint16_t MD;
	}get;
}BMP180_CALIBDATA;

void bmp180GetCalibData(I2C_Handle_t* i2c, BMP180_CALIBDATA* calibData);
uint32_t bmp180GetRawTemperature(I2C_Handle_t* i2c);
float bmp180GetTemperature(I2C_Handle_t* i2c, BMP180_CALIBDATA* calibData);

#endif /* DRIVERS_INC_BMP180_H_ */
