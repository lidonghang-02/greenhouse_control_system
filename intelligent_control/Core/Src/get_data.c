#include "Soil_moisture.h"
#include "dht11.h"
#include "illumination.h"
#include "stdio.h"
#include "get_data.h"

void get_temp_humi(uint8_t *temp,uint8_t *humi)
{
	uint8_t temp_h,temp_l,humi_h,humi_l;
	DHT11_Read_Data(&temp_h,&temp_l,&humi_h,&humi_l);
	*temp =temp_h;
	*humi = humi_h;
}
void get_soil(double *soil)
{
	double data;
	data = Soil_Get_Data();
	*soil = (data - 1883)/2146;
	if(*soil < 0) *soil = 0;
	if(*soil > 1) *soil = 1;
	*soil= (1-(*soil)) * 100;
	
}
void get_light(uint32_t *light)
{
	uint32_t data;
	data= Illumination_Get_Date();
	(*light) = 30.303 * (3.3-data*(3.3/4095));
}
