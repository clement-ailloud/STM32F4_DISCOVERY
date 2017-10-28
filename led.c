/*
 * led.c
 *
 *  Created on: Oct 14, 2017
 *      Author: clement
 */

#include "led.h"

void GPIO_INIT(void){
	HAL_Init();

	__HAL_RCC_GPIOD_CLK_ENABLE();

/* Allow access to GPIO configuration */
	GPIO_InitTypeDef GPIO_init;

/* GPIO Configuration
 * 	+ Pins : LED3_PIN, LED4_PIN, LED5_PIN and LED6_PIN
 * 	+ Output mode implementing push-pull
 * 	+ No pull
 * 	+ Frequency: 2 Mhz (Low speed)
 */
	GPIO_init.Pin = LED3_PIN | LED4_PIN | LED5_PIN | LED6_PIN;
	GPIO_init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_init.Pull = GPIO_NOPULL;
	GPIO_init.Speed = GPIO_SPEED_FREQ_LOW;

/* Initializes the GPIOx peripheral according to the specified
 * parameters in the GPIO_InitTypeDef structure.
 */
	HAL_GPIO_Init(GPIOD, &GPIO_init);

/* Initializes GPIO by writing a zero in data bit of each led. */
	HAL_GPIO_WritePin(GPIOD, LED3_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, LED4_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, LED5_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, LED6_PIN, GPIO_PIN_RESET);
}

/* Toggle one by one led's GPIO every second
 *
 * Have to toggle GPIO attached to led for enabling the state switching of this one.
 * To do this, it necessary to shift the leds' bit in ODR (Output Data Register)
 * by incrementing his value. To facilitate viewing, a delay function is added between
 * each toggle.
 */

void TOGGLE_ONEBYONE(void){
	uint16_t ledPin = LED3_PIN;

	for(int i = 1; i < 5; i++){
		/* Toggle led's GPIO */
		HAL_GPIO_TogglePin(GPIOD, ledPin);
		HAL_Delay(1000);
		HAL_GPIO_TogglePin(GPIOD, ledPin);
		ledPin = LED3_PIN << i;
	}
	ledPin = LED3_PIN;

/* Lock pin configuration until next reset */
	//HAL_GPIO_LockPin();
}
