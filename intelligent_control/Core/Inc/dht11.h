#ifndef __DHT11_H_
#define __DHT11_H_

#include "main.h"
#include "stdio.h"
#include "gpio.h"
#include "stm32f1xx.h"

#define DHT11_GPIO GPIOG
#define DHT11_PIN GPIO_PIN_1

#define DHT11_PIN_SET HAL_GPIO_WritePin(DHT11_GPIO,DHT11_PIN,GPIO_PIN_SET)
#define DHT11_PIN_RESET HAL_GPIO_WritePin(DHT11_GPIO,DHT11_PIN,GPIO_PIN_RESET)
#define DHT11_READ_IO HAL_GPIO_ReadPin(DHT11_GPIO,DHT11_PIN)

uint8_t DHT11_Read_Data(uint8_t* temp_h,uint8_t* temp_l,uint8_t* humi_h,uint8_t* humi_l);//读温湿度数据
void DHT11_Start(void);	
unsigned char DHT11_Read_Bit(void);								//读取1b数据
unsigned char DHT11_Read_Byte(void);							//读取1By数据
uint8_t DHT11_Check(void);									//检查响应信号
void DHT11_IN(void);
void DHT11_OUT(void);
void delay_us(uint32_t us);


#endif
