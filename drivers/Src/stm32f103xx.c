/*
 * stm32f103xx.c
 *
 *  Created on: May 3, 2025
 *      Author: minhh
 */


#include "stm32f103xx.h"

void delay_us(uint32_t us) {
    for (uint32_t i = 0; i < us * 8; i++) {
        __asm("NOP");  // Lệnh NOP giúp tối ưu thời gian trễ
    }
}

void delay_ms(uint32_t ms) {
    while (ms--) {
        delay_us(1000);  // Gọi delay_us() 1000 lần để tạo 1ms
    }
}
