/*
 * nvic.h
 *
 *  Created on: May 3, 2025
 *      Author: minhh
 */

#ifndef DRIVERS_INC_NVIC_H_
#define DRIVERS_INC_NVIC_H_

#define I2C1_EV_IRQ_NUMBER			31

void nvicEnable(int IRQNumber);
void nvicDisable(uint8_t IRQNumber);
void nvicSetPriority(uint8_t IRQNumber, uint8_t priority);


#endif /* DRIVERS_INC_NVIC_H_ */
