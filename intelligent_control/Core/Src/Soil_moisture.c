#include "adc.h"
#include "stdio.h"
#include "stm32f1xx.h"
#include "Soil_moisture.h"
/*2080---4095*/

double Soil_Get_Data(void)
{
	uint32_t value;
	HAL_ADC_Start(&Soli_ADC);
	if(HAL_ADC_PollForConversion(&Soli_ADC,Soil_ADC_GPIO) == HAL_OK)
	{
		value = HAL_ADC_GetValue(&Soli_ADC);
	}
	return value;
}

double Soil_Get_Average(uint8_t time)
{
	int i;
	double data;
	for(i = 0;i< time;i++)
	{
		data += Soil_Get_Data();
		HAL_Delay(10);
	}
	data = data / time;
	return data;
}
