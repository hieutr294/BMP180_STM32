/*
 * systemtick.c
 *
 *  Created on: Dec 19, 2024
 *      Author: Hieu
 */

#include "stm32f103xx.h"
#include "systemtick.h"

void SystemTick_Start(SysTick_Handle_t *sysTick){
	sysTick->pSTK->STK_LOAD = sysTick->systemTickConfig.delayTime;

	if(sysTick->systemTickConfig.clockSource){
		sysTick->pSTK->STK_CTRL |= (1<<sysTick->systemTickConfig.clockSource);
	}else{
		sysTick->pSTK->STK_CTRL &= ~(1<<sysTick->systemTickConfig.clockSource);
	}

	if(sysTick->systemTickConfig.INTEN){
		sysTick->pSTK->STK_CTRL |= (1<<sysTick->systemTickConfig.INTEN);
	}else{
		sysTick->pSTK->STK_CTRL &= ~(1<<sysTick->systemTickConfig.INTEN);
	}

	sysTick->pSTK->STK_CTRL |= STK_CTRL_EN;
}

uint8_t getCountFlag(SysTick_Handle_t *sysTick){
	return sysTick->pSTK->STK_CTRL&(1<<18);
}
