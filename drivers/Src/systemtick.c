/*
 * systemtick.c
 *
 *  Created on: Dec 19, 2024
 *      Author: Hieu
 */

#include "stm32f103xx.h"
#include "systemtick.h"

SysTick_Handle_t sysTick;

/**
 * @brief Initialize system tick with interupt not assert and clock source divide by 8
 *
 * @note The sysTick handle declare as global variable for convenience of use delay function in other funtion
 *
 * @param[in] None
 *
 * @return None
 *
 */

void SystemTickInit(){

	sysTick.pSTK = STK;
	sysTick.systemTickConfig.INTEN = STK_CTRL_TICK_INT_NOTASSERT;
	sysTick.systemTickConfig.clockSource = STK_CTRL_CLKSOURCE_AHBDIV8;

	sysTick.pSTK->STK_LOAD = 1;

	if(sysTick.systemTickConfig.clockSource){
		sysTick.pSTK->STK_CTRL |= (1<<sysTick.systemTickConfig.clockSource);
	}else{
		sysTick.pSTK->STK_CTRL &= ~(1<<sysTick.systemTickConfig.clockSource);
	}

	if(sysTick.systemTickConfig.INTEN){
		sysTick.pSTK->STK_CTRL |= (1<<sysTick.systemTickConfig.INTEN);
	}else{
		sysTick.pSTK->STK_CTRL &= ~(1<<sysTick.systemTickConfig.INTEN);
	}

	sysTick.pSTK->STK_CTRL |= STK_CTRL_EN;
}

/**
 * @brief Get current value of systick
 *
 * @param[in] pointer of systick handle struct
 *
 * @return Systick current value
 *
 */


uint32_t getCurrentValue(){
	return sysTick.pSTK->STK_VAL;
}

/**
 * @brief Delay in microsecond
 *
 * @param[in] number of delay time in milisecond, pointer of systick handle struct
 *
 * @return None
 *
 */

void delay_us(uint16_t delayTime){
	if(sysTick.pSTK->STK_LOAD!=(delayTime)){
		sysTick.pSTK->STK_LOAD = delayTime; // Only load new value
	}else{
		while(!(sysTick.pSTK->STK_CTRL&STK_COUNTFLAG)){
			; //Wait until count flag set
		}
		sysTick.pSTK->STK_VAL = 1; // Reset count flag by wirte to value register
	}
}

/**
 * @brief Delay in milisecond
 *
 * @param[in] number of delay time in milisecond, pointer of systick handle struct
 *
 * @return None
 *
 */
void delay_ms(uint16_t delayTime){
	if(sysTick.pSTK->STK_LOAD!=(delayTime*1000)){
		sysTick.pSTK->STK_LOAD = delayTime*1000; // Only load new value
	}else{
		while(!(sysTick.pSTK->STK_CTRL&(1<<16))){
			; //Wait until count flag set
		}
		sysTick.pSTK->STK_VAL = 1; // Reset count flag by wirte to value register
	}
}
