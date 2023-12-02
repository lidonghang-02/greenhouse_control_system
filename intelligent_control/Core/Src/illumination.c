#include "main.h"
#include "adc.h"
#include "stm32f1xx.h"
#include "illumination.h"
uint32_t Illumination_Get_Date(void)
{
	uint32_t value;
	HAL_ADC_Start(&ill_ADC);
	if(HAL_ADC_PollForConversion(&ill_ADC,ill_ADC_GPIO) == HAL_OK)
	{
		value = HAL_ADC_GetValue(&ill_ADC);
	}
	return value;
}
