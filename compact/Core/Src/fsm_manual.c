/*
 * fsm_manual.c
 *
 *  Created on: Oct 19, 2022
 *      Author: tamqu
 */
#include "fsm_manual.h"

void fsm_manual_run() {
	switch(status) {
		case MAN_RED:
			//todo
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin|LED_YELLOW_Pin, 1);
			if (timer1_flag == 1) {
				status = AUTO_RED;
				setTimer1(3000);
			}
			if (button1_flag == 1) {
				button1_flag = 0; //!important
				status = MAN_GREEN;
				setTimer1(10000);
			}
			break;
		case MAN_GREEN:
//			HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin|LED_GREEN_Pin);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin, 1);
			if (timer1_flag == 1) {
				status = AUTO_GREEN;
				setTimer1(2000);
			}
			if (button1_flag == 1) {
				button1_flag = 0; //!important
				status = MAN_YELLOW;
				setTimer1(10000);
			}
			break;
		case MAN_YELLOW:
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_GREEN_Pin, 1);
//			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_Pin|LED_GREEN_Pin);
			if (timer1_flag == 1) {
				status = AUTO_YELLOW;
				setTimer1(5000);
			}
			if (button1_flag == 1) {
				button1_flag = 0; //!important
				status = MAN_RED;
				setTimer1(10000);
			}
			break;
		default:
			break;
	}
}

