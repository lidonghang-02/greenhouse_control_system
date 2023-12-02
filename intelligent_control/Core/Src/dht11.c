#include "dht11.h"
#include "stm32f1xx.h"
#include "tim.h"

void delay_us(uint32_t us)
{
	__HAL_TIM_SetCounter(&htim3,0);
	HAL_TIM_Base_Start(&htim3);
	while(__HAL_TIM_GetCounter(&htim3) < us);
	HAL_TIM_Base_Stop(&htim3);
}

void DHT11_IN(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = DHT11_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(DHT11_GPIO,&GPIO_InitStruct);
}
void DHT11_OUT(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = DHT11_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(DHT11_GPIO,&GPIO_InitStruct);
}

void DHT11_Start(void)
{
	DHT11_OUT();
	DHT11_PIN_RESET;
	HAL_Delay(20);		//拉低至少18ms
	DHT11_PIN_SET;
	delay_us(30);		//拉高20~40us
	
}

//等待回应
uint8_t DHT11_Check(void)
{
	uint8_t retry = 0;
	DHT11_IN();
	while(DHT11_READ_IO && retry < 100)		//等待变为低电平
	{
		retry++;
		delay_us(1);
	}
	if(retry >= 100) return 0;		//响应失败
	retry = 0;
	while(DHT11_READ_IO == GPIO_PIN_RESET && retry < 100)		//等待便高电平
	{
		retry++;
		delay_us(1);
	}
	if(retry >= 100) return 0;		//无回应
	return 1;
}
  
unsigned char DHT11_Read_Bit(void)	//读取1b数据
{
	uint8_t retry = 0;
	while(DHT11_READ_IO == GPIO_PIN_SET && retry < 100)		//等待变为低电平
	{
		retry++;
		delay_us(1);
	}
	retry = 0;
	while(DHT11_READ_IO == GPIO_PIN_RESET && retry < 100)		//等待便高电平
	{
		retry++;
		delay_us(1);
	}
	delay_us(40);
	if(DHT11_READ_IO == GPIO_PIN_SET) return 1;							//此时如果还为高电平则数据为1
	return 0;
}
unsigned char DHT11_Read_Byte(void)								//读取1Byte数据
{
	uint8_t data = 0,i;
	for(i = 0;i < 8;i++)
	{
		data <<= 1;
		data |= DHT11_Read_Bit();
	}
	return data;
}

uint8_t DHT11_Read_Data(uint8_t* temp_h,uint8_t* temp_l,uint8_t* humi_h,uint8_t* humi_l)
{
	uint8_t data[5];
	uint8_t i;
	DHT11_Start();
	if(DHT11_Check() == 1)
	{
		for(i = 0;i < 5;i++)		//读数据
		{
			data[i] = DHT11_Read_Byte();
		}
		if(data[0] + data[1] + data[2] + data[3] == data[4])		//校验数据
		{
			*humi_h = data[0];
			*humi_l = data[1];
			*temp_h = data[2];
			*temp_l = data[3];
		}
	}
	else return 0;
	return 1;		//成功
}
