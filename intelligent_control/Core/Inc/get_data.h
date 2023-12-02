#ifndef __GET_DATA_H_
#define __GET_DATA_H_

#include "stdint.h"

void get_temp_humi(uint8_t *temp,uint8_t *humi);
void get_soil(double *soil);
void get_light(uint32_t *light);

#endif
