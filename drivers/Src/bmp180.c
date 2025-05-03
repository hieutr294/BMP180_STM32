/*
 * bmp180.c
 *
 *  Created on: May 3, 2025
 *      Author: minhh
 */
#include "bmp180.h"
#include "stdint.h"
#include "i2c.h"

void bmp180GetCalibData(I2C_Handle_t* i2c, uint16_t* calibData){
	uint16_t ac1Reg[1] = {0xaa};
	uint16_t ac2Reg[1] = {0xac};
	uint16_t ac3Reg[1] = {0xae};
	uint16_t ac4Reg[1] = {0xb0};
	uint16_t ac5Reg[1] = {0xb2};
	uint16_t ac6Reg[1] = {0xb4};

	uint16_t b1Reg[1] = {0xb6};
	uint16_t b2Reg[1] = {0xb8};

	uint16_t mbReg[1] = {0xba};
	uint16_t mcReg[1] = {0xbc};
	uint16_t mdReg[1] = {0xbe};

	uint16_t AC1[2];
	uint16_t AC2[2];
	uint16_t AC3[2];
	uint16_t AC4[2];
	uint16_t AC5[2];
	uint16_t AC6[2];
	uint16_t B1[2];
	uint16_t B2[2];
	uint16_t MD[2];
	uint16_t MC[2];
	uint16_t MB[2];

	I2C_MasterSendPolling(i2c, ac1Reg, 1, 0x77);
	I2C_MasterRecivePolling(i2c, AC1, 2, 0x77);
	I2C_MasterSendPolling(i2c, ac2Reg, 1, 0x77);
	I2C_MasterRecivePolling(i2c, AC2, 2, 0x77);
	I2C_MasterSendPolling(i2c, ac3Reg, 1, 0x77);
	I2C_MasterRecivePolling(i2c, AC3, 2, 0x77);
	I2C_MasterSendPolling(i2c, ac4Reg, 1, 0x77);
	I2C_MasterRecivePolling(i2c, AC4, 2, 0x77);
	I2C_MasterSendPolling(i2c, ac5Reg, 1, 0x77);
	I2C_MasterRecivePolling(i2c, AC5, 2, 0x77);
	I2C_MasterSendPolling(i2c, ac6Reg, 1, 0x77);
	I2C_MasterRecivePolling(i2c, AC6, 2, 0x77);


	I2C_MasterSendPolling(i2c, b1Reg, 1, 0x77);
	I2C_MasterRecivePolling(i2c, B1, 2, 0x77);
	I2C_MasterSendPolling(i2c, b2Reg, 1, 0x77);
	I2C_MasterRecivePolling(i2c, B2, 2, 0x77);


	I2C_MasterSendPolling(i2c, mbReg, 1, 0x77);
	I2C_MasterRecivePolling(i2c, MB, 2, 0x77);
	I2C_MasterSendPolling(i2c, mcReg, 1, 0x77);
	I2C_MasterRecivePolling(i2c, MC, 2, 0x77);
	I2C_MasterSendPolling(i2c, mdReg, 1, 0x77);
	I2C_MasterRecivePolling(i2c, MD, 2, 0x77);

	*calibData = AC1[0]<<8|AC1[1];
	calibData++;
	*calibData = AC2[0]<<8|AC2[1];
	calibData++;
	*calibData = AC3[0]<<8|AC3[1];
	calibData++;
	*calibData = AC4[0]<<8|AC4[1];
	calibData++;
	*calibData = AC5[0]<<8|AC5[1];
	calibData++;
	*calibData = AC6[0]<<8|AC6[1];
	calibData++;
	*calibData = B1[0]<<8|B1[1];
	calibData++;
	*calibData = B2[0]<<8|B2[1];
	calibData++;
	*calibData = MB[0]<<8|MB[1];
	calibData++;
	*calibData = MC[0]<<8|MC[1];
	calibData++;
	*calibData = MD[0]<<8|MD[1];


}
