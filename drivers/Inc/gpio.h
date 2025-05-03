/*
 * gpio.h
 *
 *  Created on: May 3, 2025
 *      Author: minhh
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_


#include <stdint.h>

#include "stm32f103xx.h"

#define ANALOG_INPUT 0
#define FLOATING_INPUT 1
#define INPUT_PUPD 8

#define GPIO_MODE_PUSH_PULL_10MHZ 1
#define GPIO_MODE_OPEN_DRAIN_10MHZ 5
#define GPIO_MODE_AF_PUSH_PULL_10MHZ 9
#define GPIO_MODE_AF_OPEN_DRAIN_10MHZ 13

#define GPIO_MODE_PUSH_PULL_2MHZ 2
#define GPIO_MODE_OPEN_DRAIN_2MHZ 6
#define GPIO_MODE_AF_PUSH_PULL_2MHZ 10
#define GPIO_MODE_AF_OPEN_DRAIN_2MHZ 14

#define GPIO_MODE_PUSH_PULL_50MHZ 3
#define GPIO_MODE_OPEN_DRAIN_50MHZ 7
#define GPIO_MODE_AF_PUSH_PULL_50MHZ 11
#define GPIO_MODE_AF_OPEN_DRAIN_50MHZ 15

#define INTERRUPT_RT 19
#define INTERRUPT_FT 20
#define INTERRUPT_RFT 21

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
#define PIN_8 8
#define PIN_9 9
#define PIN_10 10
#define PIN_11 11
#define PIN_12 12
#define PIN_13 13
#define PIN_14 14
#define PIN_15 15

#define GPIO_PIN_SET 1
#define GPIO_PIN_RESET 0

typedef struct{
	uint8_t pinNumber;
	uint8_t pinMode;
}GPIO_PinConfig_t;

typedef struct{
	GPIO_RegDef_t *pGPIOX;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_Handle_t *pGPIOHandle);

void GPIO_ClockControl(GPIO_RegDef_t *pGPIOX, uint8_t condition);

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOX, uint8_t pin);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOX, uint8_t pin, uint8_t value);
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOX, uint8_t pin);

void GPIO_IRQ_Config(uint8_t IRQNumber, uint8_t port, uint32_t pin, uint8_t state);
void GPIO_IRQ_Priority(uint8_t IRQNumber, uint8_t IRQPriority);
void GPIO_IRQ_Handling(uint8_t pinNumber);


#endif /* INC_GPIO_H_ */
