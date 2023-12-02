#ifndef __SoilMoisture_H_
#define __SoilMoisture_H_

#include "stdint.h"

#define Soli_ADC hadc2
#define Soil_ADC_GPIO 4

double Soil_Get_Data(void);
double Soil_Get_Average(uint8_t tim);

#endif
