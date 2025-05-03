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

void bmp180GetCalibData(I2C_Handle_t* i2c, uint16_t* calibData);


#endif /* DRIVERS_INC_BMP180_H_ */
