/*
 * i2c.h
 *
 *  Created on: May 3, 2025
 *      Author: minhh
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_


#include <stdint.h>
#include "stm32f103xx.h"

#define I2C_SCL_SPEED_SM			100000 // Standard mode
#define I2C_SCL_SPEED_FM			400000 // Fast mode

#define I2C_ACK_ENABLE				1
#define I2C_ACK_DISABLE 			0

#define I2C_FM_DUTY_2				0
#define I2C_FM_DUTY_16_9			1

#define CCR_FS						15
#define CCR_CCR						0
#define CCR_DUTY					14

#define CR1_ACK						10
#define CR1_PE						0
#define CR1_SWRST					15
#define CR1_POS						11

#define CCR1_START					8
#define CCR1_STOP					9

#define CR2_FREQ					0
#define CR2_ITEVTEN					9
#define CR2_ITBUFEN					10
#define OAR1_ADD					1

#define SR1_SB						0
#define SR1_TXE						7
#define SR1_RXE						6
#define SR1_BTF						2
#define SR1_ADDR					1
#define SR2_MSL						0
#define TRISE_POS					0

#define I2C_FLAG_SB				(uint8_t)(1<<SR1_SB)
#define I2C_FLAG_TXE			(uint8_t)(1<<SR1_TXE)
#define I2C_FLAG_RXE			(uint8_t)(1<<SR1_RXE)
#define I2C_FLAG_BTF			(uint8_t)(1<<SR1_BTF)
#define I2C_FLAG_ADDR			(uint8_t)(1<<SR1_ADDR)
#define I2C_FLAG_ITEVFEN		(uint8_t)(1<<CR2_ITEVTEN)
#define I2C_FLAG_ITBUFEN		(uint8_t)(1<<CR2_ITBUFEN)
#define I2C_FLAG_MSL			(uint8_t)(1<<SR2_MSL)

typedef struct{
	uint32_t I2C_SCLSpeed;
	uint8_t I2C_DeviceAddress;
	uint8_t I2C_ACKControl;
	uint8_t I2C_FMDutyCycle;
	uint16_t* I2C_SendData;
	uint16_t* I2C_ReciveData;
	uint8_t I2C_ByteRecive;
	uint8_t I2C_Index;
	uint8_t I2C_SlaveAddress;
	uint8_t I2C_DataLength;
	uint8_t I2C_RxTxState;
	void (*I2C_CallBack)(uint8_t state);
}I2C_Config_t;

typedef enum{
	I2C_READY,
	I2C_BUSY_TX,
	I2C_BUSY_RX,
	I2C_TX_DONE,
	I2C_RX_DONE
}I2C_State_t;

typedef struct{
	I2C_Config_t pI2CConfig;
	I2C_RegDef_t* pI2Cx;
}I2C_Handle_t;

static void __I2C_ConfigPin();
void I2C_ClockControl(I2C_RegDef_t* pI2Cx, uint8_t condition);
void I2C_Init(I2C_Handle_t* pI2CHandle);
void I2C_MasterSendData(I2C_Handle_t* pI2CHandle,uint8_t* pBuffer, uint32_t len, uint8_t slaveAddress);
void I2C_MasterSendIT(I2C_Handle_t* pI2CHandle, uint16_t* data, uint8_t len, uint8_t address);
void I2C_MasterSendPolling(I2C_Handle_t* pI2CHandle, uint16_t* data, uint8_t len, uint8_t address);
void I2C_MasterReciveIT(I2C_Handle_t* pI2CHandle, uint16_t* reciveData, uint8_t byteRecive, uint8_t address);
void I2C_MasterRecivePolling(I2C_Handle_t* pI2CHandle, uint16_t* reciveData, uint8_t byteRecive, uint8_t address);
uint8_t I2C_CheckStatus(I2C_Handle_t* pI2CHandle);
void I2C_ACKManage(I2C_RegDef_t* pI2Cx, uint8_t condition);
void I2C_GenerateStartCondition(I2C_RegDef_t* pI2Cx);
void I2C_GenerateStopCondition(I2C_RegDef_t* pI2Cx);
void I2C_InteruptHandling(I2C_Handle_t* pI2CHandle);
static void I2C_AddressPhaseRead(I2C_RegDef_t* pI2Cx, uint8_t slaveAddress);
static void I2C_AddressPhaseWrite(I2C_RegDef_t* pI2Cx, uint8_t slaveAddress);
static void I2C_ClearAddrFlag(I2C_RegDef_t* pI2Cx);
//static void I2C_AddressPhase(I2C_RegDef_t* pI2Cx, uint8_t slaveAddress);
uint8_t I2C_GetFlagStatus(uint32_t reg, uint8_t flag);

#endif /* INC_I2C_H_ */
