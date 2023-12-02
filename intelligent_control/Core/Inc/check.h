#ifndef __CHECK_H_
#define __CHECK_H_
#include "gpio.h"
#include "window.h"

#define BEEP_ON HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_SET)
#define BEEP_OFF HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_RESET)

void check_BEEP(struct threshold defa,struct Status status);



#endif
