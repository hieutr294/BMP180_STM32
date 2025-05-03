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
