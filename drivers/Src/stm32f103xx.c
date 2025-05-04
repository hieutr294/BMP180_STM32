/*
 * stm32f103xx.c
 *
 *  Created on: May 3, 2025
 *      Author: minhh
 */


#include "stm32f103xx.h"

void delay_us(uint32_t us) {
	while(us--){
		__asm("NOP");  // Lệnh NOP giúp tối ưu thời gian trễ
	}
}

void delay_ms(uint32_t ms) {
    while (ms--) {
    	__asm("NOP");  // Lệnh NOP giúp tối ưu thời gian trễ
    }
}
