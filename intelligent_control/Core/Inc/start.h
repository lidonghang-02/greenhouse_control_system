#ifndef __START_H_
#define __START_H_

#include "gpio.h"
#define BEEP_ON HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_SET)
#define BEEP_OFF HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_RESET)


void check_BEEP(void);
void start(void);
void init(void);

#endif


