#include "window.h"
#include "lcd.h"
#include "stdio.h"
#include "get_data.h"

void window_main_menu(struct Status *sta,int mode)
{
	uint8_t str_buff[100];
	char *status = "OFF";
	uint8_t temp=0,humi=0;
	double soil=0;
	uint32_t light=0;
	
	LCD_ShowString(20,10,220,12,12, "---------------------------------");
	LCD_ShowString(20,30,220,12,12, "|  Vegetable Greenhouse Control |");
	LCD_ShowString(20,50,220,12,12, "---------------------------------");
	
	get_temp_humi(&temp,&humi);
	sprintf((char *)str_buff,       "|   Temperature: %2d             |",temp);
	LCD_ShowString(20,70,220,12,12, str_buff);
	
	sprintf((char *)str_buff,       "|   Humidity: %2d%%               |",humi);
	LCD_ShowString(20,90,220,12,12, str_buff);
	get_soil(&soil);
	sprintf((char *)str_buff,       "|   Soil Moisture: %3.2lf%%        |",soil);
	LCD_ShowString(20,110,220,12,12,str_buff);
	get_light(&light);
	sprintf((char *)str_buff,       "|   Light Intensity: %4d lx    |",light);
	LCD_ShowString(20,130,220,12,12,str_buff);

	LCD_ShowString(20,150,220,12,12,"---------------------------------");
	LCD_ShowString(20,170,220,12,12,"| Control Status:               |");
	
	if((sta->Light_status)%2 == 0)
	{
		status = "OFF";
		led1_off;
	}
	else
	{
		status ="ON";
		led1_on;
	}
	sprintf((char *)str_buff,       "| 1.Light: %3s                  |",status);
	LCD_ShowString(20,190,220,12,12,str_buff);
	if((sta->Water_status)%2 == 0)
	{
		status = "OFF";
		led2_off;
	}
	else
	{
		status ="ON";
		led2_on;
	}
	sprintf((char *)str_buff,       "| 2.Watering: %3s               |",status);
	LCD_ShowString(20,210,220,12,12,str_buff);
	if((sta->Ven_status)%2 == 0)
	{
		status = "OFF";
		led3_off;
	}
	else
	{
		status ="ON";
		led3_on;
	}
	sprintf((char *)str_buff,       "| 3.Ventilation: %3s            |",status);
	LCD_ShowString(20,230,220,12,12,str_buff);
	
	LCD_ShowString(20,250,220,12,12,"---------------------------------");
	
	if(mode == 0) 
		LCD_ShowString(20,270,220,12,12,"| Mode:Automatic                |");
	else 
		LCD_ShowString(20,270,220,12,12,"| Mode:Manual                   |");
	
	LCD_ShowString(20,290,220,12,12,"---------------------------------");
	
}
	
void window_update_menu(struct threshold *value)
{
	uint8_t str_buff[100];
	LCD_ShowString(20,10,220,12,12, "---------------------------------");
	LCD_ShowString(20,25,220,12,12, "|                               |");
	LCD_ShowString(20,40,220,12,12, "|     Threshold Adjustment      |");
	LCD_ShowString(20,55,220,12,12, "|                               |");
	LCD_ShowString(20,70,220,12,12, "---------------------------------");
	LCD_ShowString(20,85,220,12,12, "|                               |");
	

	sprintf((char *)str_buff,       "|1.Temperature MIN:%2d           |",value->temp_l);
	LCD_ShowString(20,100,220,12,12,str_buff); 
	
	sprintf((char *)str_buff,       "|2.Temperature MAX:%2d           |",value->temp_h);
	LCD_ShowString(20,115,220,12,12,str_buff);

	sprintf((char *)str_buff,       "|3.Humidity MIN      :%3d%%      |",value->humi_l);
	LCD_ShowString(20,130,220,12,12,str_buff);

	sprintf((char *)str_buff,       "|4.Humidity MAX      :%3d%%      |",value->humi_h);
	LCD_ShowString(20,145,220,12,12,str_buff);
	
	sprintf((char *)str_buff,       "|5.Soil Moisture MIN:%2d%%        |",value->soil_l);
	LCD_ShowString(20,160,220,12,12,str_buff);

	sprintf((char *)str_buff,       "|6.Soil Moisture MAX:%2d%%        |",value->soil_h);
	LCD_ShowString(20,175,220,12,12,str_buff);
	
	sprintf((char *)str_buff,       "|7.Light MIN: %3dlx             |",value->light_l);
	LCD_ShowString(20,190,220,12,12,str_buff);
	
	sprintf((char *)str_buff,       "|8.Light MAX: %3dlx             |",value->light_h);	
	LCD_ShowString(20,205,220,12,12,str_buff);
	
	LCD_ShowString(20,220,220,12,12,"---------------------------------");
	LCD_ShowString(20,230,220,12,12,"|                               |");
	LCD_ShowString(20,240,220,12,12,"|9. Save and Return             |");
	LCD_ShowString(20,255,220,12,12,"|                               |");
	LCD_ShowString(20,270,220,12,12,"|10. Discard Changes and Return |");
	LCD_ShowString(20,285,220,12,12,"|                               |");
	LCD_ShowString(20,300,220,12,12,"---------------------------------");
}

