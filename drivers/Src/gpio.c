/*
 * gpio.c
 *
 *  Created on: May 3, 2025
 *      Author: minhh
 */


#include "stm32f103xx.h"
#include "gpio.h"

void GPIO_ClockControl(GPIO_RegDef_t *pGPIOX, uint8_t condition){
	if(condition==ENABLE){
		if(pGPIOX==GPIOA){
			GPIOA_PCLK_EN();
		}else if(pGPIOX==GPIOB){
			GPIOB_PCLK_EN();
		}else if(pGPIOX==GPIOC){
			GPIOC_PCLK_EN();
		}else if(pGPIOX==GPIOD){
			GPIOD_PCLK_EN();
		}else if(pGPIOX==GPIOE){
			GPIOE_PCLK_EN();
		}else if(pGPIOX==GPIOF){
			GPIOF_PCLK_EN();
		}else if(pGPIOX==GPIOG){
			GPIOG_PCLK_EN();
		}
	}else{
		if(pGPIOX==GPIOA){
			GPIOA_PCLK_DI();
		}else if(pGPIOX==GPIOB){
			GPIOB_PCLK_DI();
		}else if(pGPIOX==GPIOC){
			GPIOC_PCLK_DI();
		}else if(pGPIOX==GPIOD){
			GPIOD_PCLK_DI();
		}else if(pGPIOX==GPIOE){
			GPIOE_PCLK_DI();
		}else if(pGPIOX==GPIOF){
			GPIOF_PCLK_DI();
		}else if(pGPIOX==GPIOG){
			GPIOG_PCLK_DI();
		}
	}
}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){

	if(pGPIOHandle->GPIO_PinConfig.pinMode < INTERRUPT_RT){
		if(pGPIOHandle->GPIO_PinConfig.pinNumber < 8){
			pGPIOHandle->pGPIOX->CRL &= ~(15 << (4 * pGPIOHandle->GPIO_PinConfig.pinNumber) );
			pGPIOHandle->pGPIOX->CRL |= (pGPIOHandle->GPIO_PinConfig.pinMode << (4 * pGPIOHandle->GPIO_PinConfig.pinNumber) );
		}else{
			pGPIOHandle->pGPIOX->CRH &= ~(15 << (4 * (pGPIOHandle->GPIO_PinConfig.pinNumber-8)) );
			pGPIOHandle->pGPIOX->CRH |= (pGPIOHandle->GPIO_PinConfig.pinMode << (4 * (pGPIOHandle->GPIO_PinConfig.pinNumber-8)) );
		}
	}else{

		EXTI->IMR |= (1<<pGPIOHandle->GPIO_PinConfig.pinNumber);

		if(pGPIOHandle->GPIO_PinConfig.pinMode == INTERRUPT_RT){
			EXTI->RTSR |= (1<<pGPIOHandle->GPIO_PinConfig.pinNumber);
			EXTI->FTSR &= ~(1<<pGPIOHandle->GPIO_PinConfig.pinNumber);
		}else if(pGPIOHandle->GPIO_PinConfig.pinMode == INTERRUPT_FT){
			EXTI->FTSR |= (1<<pGPIOHandle->GPIO_PinConfig.pinNumber);
			EXTI->RTSR &= ~(1<<pGPIOHandle->GPIO_PinConfig.pinNumber);
		}else if(pGPIOHandle->GPIO_PinConfig.pinMode == INTERRUPT_RFT){
			EXTI->RTSR |= (1<<pGPIOHandle->GPIO_PinConfig.pinNumber);
			EXTI->FTSR |= (1<<pGPIOHandle->GPIO_PinConfig.pinNumber);
		}

	}

}

void GPIO_DeInit(GPIO_Handle_t *pGPIOHandle){
	uint16_t temp = 0;
	temp = (1 << pGPIOHandle->GPIO_PinConfig.pinNumber);
	pGPIOHandle->pGPIOX->BRR = temp;
	temp = 0;
}

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOX, uint8_t pin){
	uint16_t temp = 0;

	if(pin == 0){
		temp = pGPIOX->IDR & 1;
	}else{
		temp = (pGPIOX->IDR>>pin) & 1;
	}

	return temp;
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOX, uint8_t pin, uint8_t value){
	if(value==GPIO_PIN_SET){
		pGPIOX->ODR |= (1<<pin);
	}else{
		pGPIOX->ODR &= ~(1<<pin);
	}

}

void GPIO_TogglePin(GPIO_RegDef_t *pGPIOX, uint8_t pin){
	pGPIOX->ODR ^= (1 << pin);
}

void GPIO_IRQ_Config(uint8_t IRQNumber, uint8_t port, uint32_t pin, uint8_t state){
	if(state==1){
		AFIO_PCLK_EN();

		uint8_t exticrX = pin/4;
		uint8_t exticrXSection = pin%4;

		AFIO->EXTICR[exticrX] |= (port<<4*exticrXSection);

		if(IRQNumber<=EXTI9_5_INTERRUPT){
			NVIC_ISER->ISER[0] |= (1<<IRQNumber);
		}else{
			NVIC_ISER->ISER[1] |= (1<<IRQNumber);
		}
	}else{
		if(IRQNumber<=EXTI9_5_INTERRUPT){
			NVIC_ICER->ICER[0] |= (1<<IRQNumber);
		}else{
			NVIC_ICER->ICER[1] |= (1<<IRQNumber);
		}
		AFIO_PCLK_DI();
	}

}

void GPIO_IRQ_Priority(uint8_t IRQNumber, uint8_t IRQPriority){
	uint8_t ipReg = IRQNumber/4;
	uint8_t ipSection = IRQNumber%4;
	uint8_t shift = (8*ipSection)+(8-4);
	NVIC_IPR->IPR[ipReg] |= (IRQPriority<<shift);
}

void GPIO_IRQ_Handling(uint8_t pinNumber){
	if(EXTI->PR & (1 << pinNumber)){
		EXTI->PR |= (1<<pinNumber);
	}
}
