/*
 * nvic.c
 *
 *  Created on: May 3, 2025
 *      Author: minhh
 */

#include "stm32f103xx.h"
#include <stdint.h>

void nvicEnable(uint8_t IRQNumber){
	NVIC_ISER_t* nvicISER = (NVIC_ISER_t*)(NVIC_ISER_BASE_ADDRESS);
	nvicISER->ISER[(uint8_t)IRQNumber/32] |= (1<<IRQNumber%32);
}

void nvicDisable(uint8_t IRQNumber){
	NVIC_ISER_t* nvicISER = (NVIC_ISER_t*)(NVIC_ISER_BASE_ADDRESS);
	nvicISER->ISER[(uint8_t)IRQNumber/32] &= ~(1<<IRQNumber%32);
}

void nvicSetPriority(uint8_t IRQNumber, uint8_t priority){
	NVIC_IPR_t* nvicIPR = (NVIC_IPR_t*)(NVIC_IPR_BASE_ADDRESS);
	uint8_t iprx = (IRQNumber)/4;
	uint8_t iprx_section = IRQNumber%4;
	uint8_t shift_amount = (8*iprx_section) + (8-4); // 8 - number of bit implement
	nvicIPR->IPR[iprx] |= (priority<<shift_amount);
}
