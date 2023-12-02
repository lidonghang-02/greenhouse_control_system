#ifndef __KEY_H_
#define __KEY_H_
#include "gpio.h"

#define KEY0 HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_4)
#define KEY1 HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_3)
#define WK_UP HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)

#define KEY0_PRES 0
#define KEY1_PRES 1
#define WKUP_PRES 2


uint8_t KEY_Scan(uint8_t mode);

#endif
