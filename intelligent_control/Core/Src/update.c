#include "update.h"
#include "lcd.h"
#include "stdio.h"

uint8_t update_light_status(void);
uint8_t update_water_status(void);
uint8_t update_ven_status(void);

void update_threshold(int flag)
{
	if(flag == 1){
		LCD_Fill(25,100,30,111,YELLOW);
	}
	else if(flag == 2)
	{
		LCD_Fill(25,115,30,126,YELLOW);
	}
	else if(flag == 3)
	{
		LCD_Fill(25,130,30,141,YELLOW);
	}
	else if(flag == 4)
	{
		LCD_Fill(25,145,30,156,YELLOW);
	}
	else if(flag == 5)
	{
		LCD_Fill(25,160,30,171,YELLOW);
	}
	else if(flag == 6)
	{
		LCD_Fill(25,175,30,186,YELLOW);
		
	}
	else if(flag == 7)
	{
		LCD_Fill(25,190,30,201,YELLOW);
		
	}
	else if(flag == 8)
	{
		LCD_Fill(25,205,30,216,YELLOW);
		
	}
	else if(flag == 9)
	{
		LCD_Fill(25,240,30,251,YELLOW);
		
	}
	else if(flag == 10)
	{
		LCD_Fill(25,270,35,281,YELLOW);
		
	}
}
void update_status(int flag)
{
	if(flag == 1)
	{
		LCD_Fill(30,190,35,201,YELLOW);
	}
	else if(flag == 2)
	{
		LCD_Fill(30,210,35,221,YELLOW);
	}
	else if(flag == 3)
	{
		LCD_Fill(30,230,35,241,YELLOW);
	}
}

void update_data_threshold(struct threshold *value,int flag,int *save)
{
	switch(flag)
	{
		case 1:
			(value->temp_l)++;
			if((value->temp_l) > (value->temp_h)) (value->temp_l) = 0;
			break;
		case 2:
			(value->temp_h)++;
			if((value->temp_h) > 60) (value->temp_h) = value->temp_l;
			break;
		case 3:
			(value->humi_l)++;
			if((value->humi_l) > (value->humi_h)) (value->humi_l) = 0;
			break;
		case 4:
			(value->humi_h)++;
			if((value->humi_l) > 99) (value->temp_h) = value->humi_l;
			break;
		case 5:
			(value->soil_l)++;
			if((value->soil_l) > (value->soil_h)) (value->soil_l) = 0;
			break;
		case 6:
			(value->soil_h)++;
			if((value->soil_h) > 99) (value->soil_h) = value->soil_l;
			break;
		case 7:
			(value->light_l)++;
			if((value->light_l) > (value->light_h)) (value->light_l) = 0;
			break;
		case 8:
			(value->light_h)++;
			if((value->light_h) > 99) (value->temp_h) = value->light_l;
			break;
		case 9:
			(*save) = 1;
			break;
		case 10:
			(*save) = 2;
			break;
	}
}

void update_data_status(uint8_t *Light_status,uint8_t *Water_status,uint8_t *Ven_status,int flag)
{
	switch(flag)
	{
		case 1:
			(*Light_status)++;
			break;
		case 2:
			(*Water_status)++;
			break;
		case 3:
			(*Ven_status)++;
			break;
	}
}

