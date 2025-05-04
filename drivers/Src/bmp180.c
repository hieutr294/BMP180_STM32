/*
 * bmp180.c
 *
 *  Created on: May 3, 2025
 *      Author: minhh
 */
#include "bmp180.h"
#include "stdint.h"
#include "i2c.h"

void bmp180GetCalibData(I2C_Handle_t* i2c, BMP180_CALIBDATA* calibData){

	uint16_t calibReg[11] = {0xaa,0xac,0xae,0xb0,0xb2,0xb4,0xb6,0xb8,0xba,0xbc,0xbe};
	uint16_t temp[2];

	for(int i = 0; i < 11; i++){
		I2C_MasterSendPolling(i2c, &calibReg[i], 1, 0x77);
		I2C_MasterRecivePolling(i2c, temp, 2, 0x77);
		calibData->full[i] = temp[0]<<8|temp[1];
	}

}

uint32_t bmp180GetRawTemperature(I2C_Handle_t* i2c){
	uint16_t rawTemperature[2];
	uint16_t temperatureControllReg[2] = {0xf4,0x2e};
	I2C_MasterSendPolling(i2c, temperatureControllReg, 2, 0x77);
	delay_ms(10000);
	I2C_MasterRecivePolling(i2c, rawTemperature, 2, 0x77);
	return rawTemperature[0]<<8 | rawTemperature[1];
}

float bmp180GetTemperature(I2C_Handle_t* i2c, BMP180_CALIBDATA* calibData){
	float X1 = (bmp180GetRawTemperature(i2c) - calibData->get.AC6) * calibData->get.AC5 / (1<<15);
	float X2 = (calibData->get.MC * (1<<11))/(X1+calibData->get.MD);
	float B5 = X1+X2;
	float T = (B5+8)/(1<<4);
	return T;
}

