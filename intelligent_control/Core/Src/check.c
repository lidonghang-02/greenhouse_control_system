#include "get_data.c"
#include "check.h"


void check_BEEP(struct threshold defa,struct Status status)
{
	uint8_t temp,humi;
	double soil;
	uint32_t light;
	
	get_temp_humi(&temp,&humi);
	get_soil(&soil);
	get_light(&light);
	if(temp > defa.temp_h)
	{
		BEEP_ON;
		status.Ven_status = 1;
	}
	else if(temp < defa.temp_l)
	{
		BEEP_ON;
		status.Light_status = 1;
		status.Ven_status = 0;
	}
	
	if(humi > defa.humi_h)
	{
		BEEP_ON;
		status.Ven_status = 1;
	}
	else if(humi < defa.humi_l)
	{
		BEEP_ON;
		status.Ven_status = 1;
	}
	
	if(soil > defa.soil_h)
	{
		BEEP_ON;
		status.Water_status = 0;
	}
	else if(soil < defa.soil_l)
	{
		BEEP_ON;
		status.Water_status = 1;
	}
	
	if(light > defa.light_h)
	{
		BEEP_ON;
		status.Light_status = 0;
	}
	else if(light < defa.light_l)
	{
		BEEP_ON;
		status.Light_status = 1;
	}
	
	if(!(temp > defa.temp_h || humi > defa.humi_h || soil > defa.soil_h || light > defa.light_h ||
		 temp < defa.temp_l || humi < defa.humi_l || soil < defa.soil_l || light < defa.light_l))
	{
		BEEP_OFF;
	}
}