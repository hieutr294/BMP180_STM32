/*
 * systemtick.h
 *
 *  Created on: Dec 19, 2024
 *      Author: Hieu
 */

#ifndef INC_SYSTEMTICK_H_
#define INC_SYSTEMTICK_H_

#include "stm32f103xx.h"
#include <stdint.h>

#define STK_CTRL_EN (1<<0)
#define STK_CTRL_DI ~(1<<0) // Tat bit thu 0

#define STK_CTRL_TICK_INT_NOTASSERT ~(1<<1)
#define STK_CTRL_TICK_INT_ASSERT (1<<1)

#define STK_CTRL_CLKSOURCE_AHBDIV8 ~(1<<2)
#define STK_CTRL_CLKSOURCE_AHB (1<<2)

/*
 * Config system tick clock source with STK_CTRL_CLKSOURCE_AHBDIV8 or STK_CTRL_CLKSOURCE_AHB flag
 * If using with STK_CTRL_CLKSOURCE_AHBDIV8 flag mean AHB bus divide by 8
 * Then AHBBUS/8 equal to 8Mhz(HSI clock) / 8 = 1Mhz
 * Mean 1 Cycle = 1us
 * Config INTEN = STK_CTRL_TICK_INT_ASSERT or STK_CTRL_TICK_INT_NOTASSERT to active or inactive interupt (SysTick_Handler)
 * Config clockSource with STK_CTRL_CLKSOURCE_AHBDIV8 (AHB divide by 8) or STK_CTRL_CLKSOURCE_AHB (AHB divide by 1)
 * Assign load value to system tick load register through delayTime variable of SysTick_Config_t struct
 * If choose clockSource with STK_CTRL_CLKSOURCE_AHBDIV8 (AHB divide by 8) mean 1 cycle = 1us => 1s = 1000000 us
 * Need to assign 1000000 to delayTime variable of SysTick_Config_t struct
 *
 * reloadValue = delayTime (s) / (1/(feq_systick))
 * */

typedef struct{
	uint32_t delayTime;
	uint8_t clockSource;
	uint8_t INTEN;
}SysTick_Config_t;

typedef struct{
	SysTick_RegDef_t* pSTK;
	SysTick_Config_t systemTickConfig;
}SysTick_Handle_t;
#endif /* INC_SYSTEMTICK_H_ */
