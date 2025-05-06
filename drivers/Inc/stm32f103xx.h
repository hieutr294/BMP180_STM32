/*
 * stm32f103xx.h
 *
 *  Created on: May 3, 2025
 *      Author: minhh
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_


#include <stdint.h>
#define __weak __attribute__((weak))
/*------------------------------------------ Peripheral Base Address ---------------------------------------*/
/*---- Core Base Address ----*/

#define NVIC_BASE_ADDRESS				0xE000E100U
#define STK_BASE_ADDRESS				0xE000E010U

#define NVIC_ISER_BASE_ADDRESS 			(NVIC_BASE_ADDRESS+0x000)
#define NVIC_ICER_BASE_ADDRESS 			(NVIC_BASE_ADDRESS+0x080)
#define NVIC_ISPR_BASE_ADDRESS			(NVIC_BASE_ADDRESS+0x100)
#define NVIC_ICPR_BASE_ADDRESS			(NVIC_BASE_ADDRESS+0x180)
#define NVIC_IABR_BASE_ADDRESS			(NVIC_BASE_ADDRESS+0x200)
#define NVIC_IPR_BASE_ADDRESS			(NVIC_BASE_ADDRESS+0x300)

#define STK_CTRL_BASE_ADDRESS			(STK_BASE_ADDRESS+0x00)
#define STK_LOAD_BASE_ADDRESS			(STK_BASE_ADDRESS+0x04)
#define STK_VAL_BASE_ADDRESS			(STK_BASE_ADDRESS+0x08)
#define STK_CALID_BASE_ADDRESS			(STK_BASE_ADDRESS+0x0C)

/*---- End ----*/

#define APB1_BASE_ADDRESS 				0x40000000U
#define APB2_BASE_ADDRESS 				0x40010000U
#define AHB_BASE_ADDRESS 				0x40020000U

#define DMA1_BASE_ADDRESS 				(AHB_BASE_ADDRESS+0x0000)
#define DMA2_BASE_ADDRESS 				(AHB_BASE_ADDRESS+0x0400)
#define RCC_BASE_ADDRESS 				(AHB_BASE_ADDRESS+0x1000)
#define FLASH_BASE_ADDRESS 				(AHB_BASE_ADDRESS+0x2000)
#define CRC_BASE_ADDRESS 				(AHB_BASE_ADDRESS+0x3000)
#define ETHERNET_BASE_ADDRESS 			(AHB_BASE_ADDRESS+0x8000)

#define TIM2_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x0000)
#define TIM3_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x0400)
#define TIM4_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x0800)
#define TIM5_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x0c00)
#define TIM6_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x1000)
#define TIM7_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x1400)
#define TIM12_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x1800)
#define TIM13_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x1c00)
#define TIM14_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x2000)
#define RTC_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x2800)
#define WWDG_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x2c00)
#define IWDG_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x3000)
#define SPI2_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x3800)
#define SPI3_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x3c00)
#define USART2_BASE_ADDRESS 			(APB1_BASE_ADDRESS+0x4400)
#define USART3_BASE_ADDRESS 			(APB1_BASE_ADDRESS+0x4800)
#define UART4_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x4c00)
#define UART5_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x5000)
#define I2C1_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x5400)
#define I2C2_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x5800)
#define USB_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x5c00)
#define CAN2_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x6800)
#define CAN1_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x5400)
#define BKP_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x6c00)
#define PWR_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x7000)
#define DAC_BASE_ADDRESS 				(APB1_BASE_ADDRESS+0x7400)

#define AFIO_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x0000)
#define EXTI_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x0400)
#define GPIOA_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x0800)
#define GPIOB_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x0C00)
#define GPIOC_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x1000)
#define GPIOD_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x1400)
#define GPIOE_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x1800)
#define GPIOF_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x1C00)
#define GPIOG_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x2000)
#define ADC1_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x2400)
#define ADC2_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x2800)
#define TIM1_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x2c00)
#define SPI1_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x3000)
#define TIM8_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x2c00)
#define USART1_BASE_ADDRESS 			(APB2_BASE_ADDRESS+0x3800)
#define ADC3_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x3c00)
#define TIM9_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x4c00)
#define TIM10_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x5000)
#define TIM11_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x5400)
#define SDIO_BASE_ADDRESS 				(APB2_BASE_ADDRESS+0x8000)

/*------------------------------------------ Register Struct ---------------------------------------*/
typedef struct{
	uint32_t ISER[3];
}NVIC_ISER_t;

typedef struct{
	uint32_t ICER[3];
}NVIC_ICER_t;

typedef struct{
	uint32_t ISPR[3];
}NVIC_ISPR_t;

typedef struct{
	uint32_t ICPR[3];
}NVIC_ICPR_t;

typedef struct{
	uint32_t IABR[3];
}NVIC_IABR_t;

typedef struct{
	uint32_t IPR[21];
}NVIC_IPR_t;

typedef struct{
	uint32_t IMR;
	uint32_t EMR;
	uint32_t RTSR;
	uint32_t FTSR;
	uint32_t SWIER;
	uint32_t PR;
}EXTI_Config_t;

typedef struct{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint16_t BRR;
	uint32_t LCKR;
}GPIO_RegDef_t;

typedef struct{
	uint32_t EVCR;
	uint32_t MAPR;
	uint32_t EXTICR[4];
	uint32_t MAPR2;
}AFIO_Config_t;

typedef struct{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;
	uint32_t APB1ENR;
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t AHBSTR;
	uint32_t CFGR2;
}RCC_config_t;

typedef struct{
	uint32_t CR1;
	uint32_t CR2;
	uint32_t SR;
	uint32_t DR;
	uint32_t CRCPR;
	uint32_t RXCRCR;
	uint32_t TXCRCR;
	uint32_t I2SCFGR;
	uint32_t I2SPR;
}SPI_RegDef_t;

typedef struct{
	uint32_t SR;
	uint32_t CR1;
	uint32_t CR2;
	uint32_t SMPR1;
	uint32_t SMPR2;
	uint32_t JOFR1;
	uint32_t JOFR2;
	uint32_t JOFR3;
	uint32_t JOFR4;
	uint32_t HTR;
	uint32_t LTR;
	uint32_t SQR1;
	uint32_t SQR2;
	uint32_t SQR3;
	uint32_t JSQR;
	uint32_t JDR1;
	uint32_t JDR2;
	uint32_t JDR3;
	uint32_t JDR4;
	uint32_t DR;
}ADC_RegDef_t;

typedef struct{
	uint32_t ISR;
	uint32_t IFCR;
	uint32_t CCR;
	uint32_t CNDTR;
	uint32_t CPAR;
	uint32_t CMAR;
}DMA_RegDef_t;

//typedef struct{
//	uint32_t CR1;
//	uint32_t CR2;
//	uint32_t SMCR;
//	uint32_t DIER;
//	uint32_t SR;
//	uint32_t EGR;
//	uint32_t CCMR1;
//	uint32_t CCMR2;
//	uint32_t CCER;
//	uint32_t CNT;
//	uint32_t PSC;
//	uint32_t ARR;
//	uint32_t RCR;
//	uint32_t CCR1;
//	uint32_t CCR2;
//	uint32_t CCR3;
//	uint32_t CCR4;
//	uint32_t BDTR;
//	uint32_t DCR;
//	uint32_t DMAR;
//}TIMER_RegDef_t;

typedef struct{
	uint32_t CR1;
	uint32_t CR2;
	uint32_t SMCR;
	uint32_t DIER;
	uint32_t SR;
	uint32_t EGR;
	uint32_t CCMR1;
	uint32_t CCMR2;
	uint32_t CCER;
	uint32_t CNT;
	uint32_t PSC;
	uint32_t ARR;
	uint32_t RCR;
	uint32_t CCR[4];
	uint32_t BDTR;
	uint32_t DCR;
	uint32_t DMAR;
}TIMER_RegDef_t;

typedef struct{
	uint32_t CR1;
	uint32_t CR2;
	uint32_t OAR1;
	uint32_t OAR2;
	uint32_t DR;
	uint32_t SR1;
	uint32_t SR2;
	uint32_t CCR;
	uint32_t TRISE;

}I2C_RegDef_t;

typedef struct{
	uint32_t SR;
	uint32_t DR;
	uint32_t BRR;
	uint32_t CR1;
	uint32_t CR2;
	uint32_t CR3;
	uint32_t GTPR;
}USART_RegDef_t;

typedef struct{
	uint32_t STK_CTRL;
	uint32_t STK_LOAD;
	uint32_t STK_VAL;
	uint32_t STK_CALIB;
}SysTick_RegDef_t;

/*--------------------------Peripheral Define----------------------------*/

#define GPIOA 				((GPIO_RegDef_t*)(GPIOA_BASE_ADDRESS))
#define GPIOB 				((GPIO_RegDef_t*)(GPIOB_BASE_ADDRESS))
#define GPIOC 				((GPIO_RegDef_t*)(GPIOC_BASE_ADDRESS))
#define GPIOD 				((GPIO_RegDef_t*)(GPIOD_BASE_ADDRESS))
#define GPIOE 				((GPIO_RegDef_t*)(GPIOE_BASE_ADDRESS))
#define GPIOF 				((GPIO_RegDef_t*)(GPIOF_BASE_ADDRESS))
#define GPIOG 				((GPIO_RegDef_t*)(GPIOG_BASE_ADDRESS))
#define AFIO				((AFIO_Config_t*)(AFIO_BASE_ADDRESS))
#define NVIC_ISER			((NVIC_ISER_t*)(NVIC_ISER_BASE_ADDRESS))
#define NVIC_ICER			((NVIC_ICER_t*)(NVIC_ICER_BASE_ADDRESS))
#define NVIC_ISPR			((NVIC_ISPR_t*)(NVIC_ISPR_BASE_ADDRESS))
#define NVIC_ICPR			((NVIC_ICPR_t*)(NVIC_ICPR_BASE_ADDRESS))
#define NVIC_IABR			((NVIC_IABR_t*)(NVIC_IABR_BASE_ADDRESS))
#define NVIC_IPR			((NVIC_IPR_t*)(NVIC_IPR_BASE_ADDRESS))
#define STK					((SysTick_RegDef_t*)(STK_BASE_ADDRESS))
#define EXTI				((EXTI_Config_t*)(EXTI_BASE_ADDRESS))
#define RCC 				((RCC_config_t*)(RCC_BASE_ADDRESS))
#define SPI1				((SPI_RegDef_t*)(SPI1_BASE_ADDRESS))
#define SPI2				((SPI_RegDef_t*)(SPI2_BASE_ADDRESS))
#define SPI3				((SPI_RegDef_t*)(SPI3_BASE_ADDRESS))
#define ADC1				((ADC_RegDef_t*)(ADC1_BASE_ADDRESS))
#define ADC2				((ADC_RegDef_t*)(ADC2_BASE_ADDRESS))
#define ADC3				((ADC_RegDef_t*)(ADC3_BASE_ADDRESS))
#define DMA1				((DMA_RegDef_t*)(DMA1_BASE_ADDRESS))
#define DMA2				((DMA_RegDef_t*)(DMA2_BASE_ADDRESS))
#define I2C1				((I2C_RegDef_t*)(I2C1_BASE_ADDRESS))
#define I2C2				((I2C_RegDef_t*)(I2C2_BASE_ADDRESS))
#define USART1				((USART_RegDef_t*)(USART1_BASE_ADDRESS))
#define USART2				((USART_RegDef_t*)(USART2_BASE_ADDRESS))
#define USART3				((USART_RegDef_t*)(USART3_BASE_ADDRESS))

#define TIM1				((TIMER_RegDef_t*)(TIM1_BASE_ADDRESS))
#define TIM8				((TIMER_RegDef_t*)(TIM8_BASE_ADDRESS))
#define TIM2				((TIMER_RegDef_t*)(TIM2_BASE_ADDRESS))
/*-------------------------- Peripheral Enable ----------------------------*/
#define AFIO_PCLK_EN() 		(RCC->APB2ENR |= (1<<0))
#define GPIOA_PCLK_EN() 	(RCC->APB2ENR |= (1<<2))
#define GPIOB_PCLK_EN()		(RCC->APB2ENR |= (1<<3))
#define GPIOC_PCLK_EN()		(RCC->APB2ENR |= (1<<4))
#define GPIOD_PCLK_EN()		(RCC->APB2ENR |= (1<<5))
#define GPIOE_PCLK_EN()		(RCC->APB2ENR |= (1<<6))
#define GPIOF_PCLK_EN()		(RCC->APB2ENR |= (1<<7))
#define GPIOG_PCLK_EN()		(RCC->APB2ENR |= (1<<8))

#define ADC1_PCLK_EN() 		(RCC->APB2ENR |= (1<<9))
#define ADC2_PCLK_EN() 		(RCC->APB2ENR |= (1<<10))
#define TIM1_PCLK_EN() 		(RCC->APB2ENR |= (1<<11))
#define SPI1_PCLK_EN() 		(RCC->APB2ENR |= (1<<12))
#define TIM8_PCLK_EN() 		(RCC->APB2ENR |= (1<<13))
#define USART1_PCLK_EN() 	(RCC->APB2ENR |= (1<<14))
#define ADC3_PCLK_EN() 		(RCC->APB2ENR |= (1<<15))
#define TIM9_PCLK_EN() 		(RCC->APB2ENR |= (1<<19))
#define TIM10_PCLK_EN() 	(RCC->APB2ENR |= (1<<20))
#define TIM11_PCLK_EN() 	(RCC->APB2ENR |= (1<<21))

#define TIM2_PCLK_EN() 		(RCC->APB1ENR |= (1<<0))
#define TIM3_PCLK_EN() 		(RCC->APB1ENR |= (1<<1))
#define TIM4_PCLK_EN() 		(RCC->APB1ENR |= (1<<2))
#define TIM5_PCLK_EN() 		(RCC->APB1ENR |= (1<<3))
#define TIM6_PCLK_EN() 		(RCC->APB1ENR |= (1<<4))
#define TIM7_PCLK_EN() 		(RCC->APB1ENR |= (1<<5))
#define TIM12_PCLK_EN() 	(RCC->APB1ENR |= (1<<6))
#define TIM13_PCLK_EN() 	(RCC->APB1ENR |= (1<<7))
#define TIM14_PCLK_EN() 	(RCC->APB1ENR |= (1<<8))
#define WWDG_PCLK_EN() 		(RCC->APB1ENR |= (1<<11))
#define SPI2_PCLK_EN() 		(RCC->APB1ENR |= (1<<14))
#define SPI3_PCLK_EN() 		(RCC->APB1ENR |= (1<<15))
#define USART2_PCLK_EN() 	(RCC->APB1ENR |= (1<<17))
#define USART3_PCLK_EN() 	(RCC->APB1ENR |= (1<<18))
#define USART4_PCLK_EN() 	(RCC->APB1ENR |= (1<<19))
#define USART5_PCLK_EN() 	(RCC->APB1ENR |= (1<<20))
#define I2C1_PCLK_EN() 		(RCC->APB1ENR |= (1<<21))
#define I2C2_PCLK_EN() 		(RCC->APB1ENR |= (1<<22))
#define USB_PCLK_EN() 		(RCC->APB1ENR |= (1<<23))
#define CAN_PCLK_EN() 		(RCC->APB1ENR |= (1<<25))
#define BKP_PCLK_EN() 		(RCC->APB1ENR |= (1<<27))
#define PWR_PCLK_EN() 		(RCC->APB1ENR |= (1<<28))
#define DAC_PCLK_EN() 		(RCC->APB1ENR |= (1<<29))

#define DMA1_PCLK_EN()		(RCC->AHBENR |= (1<<0))
#define DMA2_PCLK_EN()		(RCC->AHBENR |= (1<<1))
#define SRAM_PCLK_EN()		(RCC->AHBENR |= (1<<2))
#define FLITFEN_PCLK_EN()	(RCC->AHBENR |= (1<<4))
#define CRCEN_PCLK_EN()		(RCC->AHBENR |= (1<<6))
#define OTGFS_PCLK_EN()		(RCC->AHBENR |= (1<<12))
#define ETHMAC_PCLK_EN()	(RCC->AHBENR |= (1<<14))
#define ETHMACTX_PCLK_EN()	(RCC->AHBENR |= (1<<15))
#define ETHMACRX_PCLK_EN()	(RCC->AHBENR |= (1<<16))

/*--------------------------Peripheral Disable----------------------------*/
#define AFIO_PCLK_DI() 		(RCC->APB2ENR &= ~(1<<0))
#define GPIOA_PCLK_DI() 	(RCC->APB2ENR &= ~(1<<2))
#define GPIOB_PCLK_DI()		(RCC->APB2ENR &= ~(1<<3))
#define GPIOC_PCLK_DI()		(RCC->APB2ENR &= ~(1<<4))
#define GPIOD_PCLK_DI()		(RCC->APB2ENR &= ~(1<<5))
#define GPIOE_PCLK_DI()		(RCC->APB2ENR &= ~(1<<6))
#define GPIOF_PCLK_DI()		(RCC->APB2ENR &= ~(1<<7))
#define GPIOG_PCLK_DI()		(RCC->APB2ENR &= ~(1<<8))

#define ADC1_PCLK_DI() 		(RCC->APB2ENR &= ~(1<<9))
#define ADC2_PCLK_DI() 		(RCC->APB2ENR &= ~(1<<10))
#define TIM1_PCLK_DI() 		(RCC->APB2ENR &= ~(1<<11))
#define SPI1_PCLK_DI() 		(RCC->APB2ENR &= ~(1<<12))
#define TIM8_PCLK_DI() 		(RCC->APB2ENR &= ~(1<<13))
#define USART1_PCLK_DI() 	(RCC->APB2ENR &= ~(1<<14))
#define ADC3_PCLK_DI() 		(RCC->APB2ENR &= ~(1<<15))
#define TIM9_PCLK_DI() 		(RCC->APB2ENR &= ~(1<<19))
#define TIM10_PCLK_DI() 	(RCC->APB2ENR &= ~(1<<20))
#define TIM11_PCLK_DI() 	(RCC->APB2ENR &= ~(1<<21))

#define TIM2_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<0))
#define TIM3_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<1))
#define TIM4_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<2))
#define TIM5_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<3))
#define TIM6_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<4))
#define TIM7_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<5))
#define TIM12_PCLK_DI() 	(RCC->APB1ENR &= ~(1<<6))
#define TIM13_PCLK_DI() 	(RCC->APB1ENR &= ~(1<<7))
#define TIM14_PCLK_DI() 	(RCC->APB1ENR &= ~(1<<8))
#define WWDG_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<11))
#define SPI2_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<14))
#define SPI3_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<15))
#define USART2_PCLK_DI() 	(RCC->APB1ENR &= ~(1<<17))
#define USART3_PCLK_DI() 	(RCC->APB1ENR &= ~(1<<18))
#define USART4_PCLK_DI() 	(RCC->APB1ENR &= ~(1<<19))
#define USART5_PCLK_DI() 	(RCC->APB1ENR &= ~(1<<20))
#define I2C1_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<21))
#define I2C2_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<22))
#define USB_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<23))
#define CAN_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<25))
#define BKP_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<27))
#define PWR_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<28))
#define DAC_PCLK_DI() 		(RCC->APB1ENR &= ~(1<<29))

#define DMA1_PCLK_DI()		(RCC->AHBENR &= ~(1<<0))
#define DMA2_PCLK_DI()		(RCC->AHBENR &= ~(1<<1))
#define SRAM_PCLK_DI()		(RCC->AHBENR &= ~(1<<2))
#define FLITFEN_PCLK_DI()	(RCC->AHBENR &= ~(1<<4))
#define CRCEN_PCLK_DI()		(RCC->AHBENR &= ~(1<<6))
#define OTGFS_PCLK_DI()		(RCC->AHBENR &= ~(1<<12))
#define ETHMAC_PCLK_DI()	(RCC->AHBENR &= ~(1<<14))
#define ETHMACTX_PCLK_DI()	(RCC->AHBENR &= ~(1<<15))
#define ETHMACRX_PCLK_DI()	(RCC->AHBENR &= ~(1<<16))

#define ENABLE 					1
#define DISABLE 				0
#define FLAG_SET				1
#define FLAG_RESET				0
/*-------------------------- Port Code ----------------------------*/
#define PORTA 					0
#define PORTB 					1
#define PORTC 					2
#define PORTD 					3
#define PORTE 					4
#define PORTF 					5
#define PORTG 					6

/*-------------------------- Interrupt Define ----------------------------*/
#define EXTI0_INTERRUPT 		6
#define EXTI1_INTERRUPT 		7
#define EXTI2_INTERRUPT 		8
#define EXTI3_INTERRUPT 		9
#define EXTI4_INTERRUPT 		10
#define EXTI9_5_INTERRUPT 		23
#define EXTI15_10_INTERRUPT 	40

/*-------------------------- IQRNUMBER ---------------------------------*/
#define SPI1_GLOBAL_INTERRUPT 	32

#endif /* INC_STM32F103XX_H_ */
