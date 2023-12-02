#include "gpio.h"
#include "stdio.h"
#include "key.h"
#include "lcd.h"
#include "update.h"
#include "get_data.h"
#include "window.h"
#include "start.h"

struct threshold defa, alter;

struct Status status;

int flag_threshold = 0, flag_status = 0, save_threshold = 0;
uint8_t key_1, key_2, key_3;
int flag_mode = 0;

void init(void)
{
	LCD_Init();

	defa.temp_h = 50, defa.humi_h = 50, defa.soil_h = 30, defa.light_h = 500;
	defa.temp_l = 0, defa.humi_l = 0, defa.soil_l = 0, defa.light_l = 0;
	status.Light_status = 0, status.Water_status = 0, status.Ven_status = 0;
}

void check_BEEP(void)
{
	uint8_t temp, humi;
	double soil;
	uint32_t light;

	get_temp_humi(&temp, &humi);
	get_soil(&soil);
	get_light(&light);
	if (temp > defa.temp_h)
	{
		BEEP_ON;
		if (flag_mode == 0)
			status.Ven_status = 1;
	}
	else if (temp < defa.temp_l)
	{
		BEEP_ON;
		if (flag_mode == 0)
		{
			status.Light_status = 1;
			status.Ven_status = 0;
		}
	}

	if (humi > defa.humi_h)
	{
		BEEP_ON;
		if (flag_mode == 0)
			status.Ven_status = 1;
	}
	else if (humi < defa.humi_l)
	{
		BEEP_ON;
		if (flag_mode == 0)
			status.Ven_status = 1;
	}

	if (soil > defa.soil_h)
	{
		BEEP_ON;
		if (flag_mode == 0)
			status.Water_status = 0;
	}
	else if (soil < defa.soil_l)
	{
		BEEP_ON;
		if (flag_mode == 0)
			status.Water_status = 1;
	}

	if (light > defa.light_h)
	{
		BEEP_ON;
		if (flag_mode == 0)
			status.Light_status = 0;
	}
	else if (light < defa.light_l)
	{
		BEEP_ON;
		if (flag_mode == 0)
			status.Light_status = 1;
	}

	if (!(temp > defa.temp_h || humi > defa.humi_h || soil > defa.soil_h || light > defa.light_h ||
		  temp < defa.temp_l || humi < defa.humi_l || soil < defa.soil_l || light < defa.light_l))
	{
		BEEP_OFF;
		if (flag_mode == 0)
			status.Light_status = 0, status.Water_status = 0, status.Ven_status = 0;
	}
}

void start(void)
{
	check_BEEP();
	window_main_menu(&status, flag_mode);
	key_1 = KEY_Scan(0);
	if (key_1 == KEY1_PRES)
	{
		flag_mode++;
		flag_mode = flag_mode % 2;
	}
	else if (key_1 == KEY0_PRES)
	{
		flag_status = 0;
		while (1)
		{
			update_status(flag_status % 3 + 1);
			window_main_menu(&status, flag_mode);
			key_2 = KEY_Scan(0);
			if (key_2 == KEY0_PRES)
				flag_status++;
			else if (key_2 == KEY1_PRES)
			{
				update_data_status(&status.Light_status, &status.Water_status, &status.Ven_status, flag_status % 3 + 1);
			}
			else if (key_2 == WKUP_PRES)
				break;
		}
	}
	else if (key_1 == WKUP_PRES)
	{
		BEEP_OFF;
		LCD_Clear(WHITE);
		window_update_menu(&defa);
		while (1)
		{
			key_2 = KEY_Scan(0);
			if (key_2 == WKUP_PRES)
			{
				LCD_Clear(WHITE);
				window_main_menu(&status, flag_mode);
				break;
			}
			else if (key_2 == KEY0_PRES)
			{
				flag_threshold = 0;
				save_threshold = 0;
				LCD_Clear(WHITE);
				alter = defa;
				while (1)
				{
					update_threshold(flag_threshold % 10 + 1);
					window_update_menu(&alter);
					key_3 = KEY_Scan(1);
					switch (key_3)
					{
					case KEY0_PRES:
						flag_threshold++;
						break;
					case KEY1_PRES:
						update_data_threshold(&alter, flag_threshold % 10 + 1, &save_threshold);
						break;
					}
					if (save_threshold == 1)
					{
						defa = alter;
						break;
					}
					else if (save_threshold == 2)
					{
						window_update_menu(&defa);
						break;
					}
				}
			}
		}
	}
}
