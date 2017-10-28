/**************************************************************************
 * @file    led.c
 * @author  Clément Ailloud
 * @version V1.0
 * @date    07-October-2017
 * @brief   Default main function.
 **************************************************************************/

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

int main(void){
/* __HAL_RCC_GPIOx_CLK_ENABLE();
 *
 * x is port to choose (A, B, C, D...)
 *
 * Enable the GPIO AHB clock on PORTD */
	__HAL_RCC_GPIOD_CLK_ENABLE();

/* Structure permitting to initialized GPIO's pins */
	GPIO_InitTypeDef GPIO_Init;

/* Initialization using GPIO_Init structure's pointer of GPIO_InitTypeDef */

/* Configuring Pin with four Led's pin */
	GPIO_Init.Pin = LED4_PIN;
/* Configuring Mode with Mode Output Push Pull */
	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
/* Configuring Pull with No Pull */
	GPIO_Init.Pull = GPIO_NOPULL;
/* Configuring Speed with LOW */
	GPIO_Init.Speed = GPIO_SPEED_FREQ_LOW;

/* Initializing GPIO with previous configuration */
	HAL_GPIO_Init(GPIOD, &GPIO_Init);

/* Set/reset the level of a pin configured in output mode */
	HAL_GPIO_WritePin(GPIOD, LED4_PIN, GPIO_PIN_SET);

	for(;;);
}
