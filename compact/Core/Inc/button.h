/*
 * button.h
 *
 *  Created on: Oct 19, 2022
 *      Author: tamqu
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button1_flag;

void getKeyInput();
//int isButtonPress();
void subKeyProcess();


#endif /* INC_BUTTON_H_ */
