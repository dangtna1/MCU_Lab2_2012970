/*
 * fsm_automatic.c
 *
 *  Created on: Oct 19, 2022
 *      Author: tamqu
 */
#include "fsm_automatic.h"

void fsm_automatic_run() {
	switch(status) {
	case INIT:
		HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin|LED_YELLOW_Pin, 1);
		setTimer1(5000);
		status = AUTO_RED;
		break;
	case AUTO_RED:
		if (timer1_flag == 1) {
			HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin|LED_GREEN_Pin);
			setTimer1(3000);
			status = AUTO_GREEN;
		}
		break;
	case AUTO_GREEN:
		if (timer1_flag == 1) {
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_Pin|LED_GREEN_Pin);
			setTimer1(2000);
			status = AUTO_YELLOW;
		}
		break;
	case AUTO_YELLOW:
		if (timer1_flag == 1) {
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_Pin|LED_RED_Pin);
			setTimer1(5000);
			status = AUTO_RED;
		}
		break;
	default:
		break;
	}
}

