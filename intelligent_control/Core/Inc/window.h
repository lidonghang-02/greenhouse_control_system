#ifndef __WINDOW_H_
#define __WINDOW_H_

#include "stdint.h"
#include "gpio.h"

struct threshold{
	uint8_t temp_h,temp_l;
	uint8_t humi_h,humi_l;
	uint8_t soil_h,soil_l;
	uint32_t light_h,light_l;
};

struct Status{
	uint8_t Light_status,Water_status,Ven_status;
};

#define led1_on HAL_GPIO_WritePin(GPIOG,GPIO_PIN_3,GPIO_PIN_SET)
#define led1_off HAL_GPIO_WritePin(GPIOG,GPIO_PIN_3,GPIO_PIN_RESET)

#define led2_on HAL_GPIO_WritePin(GPIOG,GPIO_PIN_5,GPIO_PIN_SET)
#define led2_off HAL_GPIO_WritePin(GPIOG,GPIO_PIN_5,GPIO_PIN_RESET)

#define led3_on HAL_GPIO_WritePin(GPIOG,GPIO_PIN_7,GPIO_PIN_SET)
#define led3_off HAL_GPIO_WritePin(GPIOG,GPIO_PIN_7,GPIO_PIN_RESET)


void window_main_menu(struct Status *status,int mode);
void window_update_menu(struct threshold *value);

#endif
