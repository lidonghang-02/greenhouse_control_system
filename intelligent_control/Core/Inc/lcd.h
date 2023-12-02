#ifndef __LCD_H
#define __LCD_H
//#include "sys.h"
#include "stdlib.h"
#include "main.h"

extern SRAM_HandleTypeDef TFTSRAM_Handler;    //SRAM??(????LCD)
 
//LCD?????
typedef struct
{
    uint16_t width;      //LCD ??
    uint16_t height;     //LCD ??
    uint16_t id;         //LCD ID
    uint8_t  dir;        //????????:0,??;1,???
    uint16_t wramcmd;    //???gram??
    uint16_t setxcmd;    //??x????
    uint16_t  setycmd;   //??y????
} _lcd_dev;
 
//LCD??
extern _lcd_dev lcddev; //??LCD????
//LCD?????????
extern uint32_t  POINT_COLOR;//????
extern uint32_t  BACK_COLOR; //????.?????
 
 
//
//-----------------MCU? LCD????----------------
//#define	LCD_LED PBout(0)    //LCD?? PB0
 
//LCD?????
typedef struct
{
    uint16_t LCD_REG;
    uint16_t LCD_RAM;
} LCD_TypeDef;
 
//??NOR/SRAM? Bank1.sector4,???HADDR[27,26]=11 A10?????????
//?????STM32?????????!
#define LCD_BASE        ((uint32_t)(0x6C000000 | 0x000007FE))
#define LCD             ((LCD_TypeDef *) LCD_BASE)
//
 
//??????
#define L2R_U2D  0 //????,????
#define L2R_D2U  1 //????,????
#define R2L_U2D  2 //????,????
#define R2L_D2U  3 //????,????
 
#define U2D_L2R  4 //????,????
#define U2D_R2L  5 //????,????
#define D2U_L2R  6 //????,????
#define D2U_R2L  7 //????,????
 
#define DFT_SCAN_DIR  L2R_U2D  //???????
 
//????
#define WHITE           0xFFFF
#define BLACK           0x0000
#define BLUE            0x001F
#define BRED            0XF81F
#define GRED            0XFFE0
#define GBLUE           0X07FF
#define RED             0xF800
#define MAGENTA         0xF81F
#define GREEN           0x07E0
#define CYAN            0x7FFF
#define YELLOW          0xFFE0
#define BROWN           0XBC40  //??
#define BRRED           0XFC07  //???
#define GRAY            0X8430  //??
//GUI??
 
#define DARKBLUE        0X01CF  //???
#define LIGHTBLUE       0X7D7C  //???
#define GRAYBLUE        0X5458  //???
//?????PANEL???
 
#define LIGHTGREEN      0X841F  //???
#define LGRAY           0XC618  //???(PANNEL),?????
 
#define LGRAYBLUE       0XA651  //????(?????)
#define LBBLUE          0X2B12  //????(???????)
 
void LCD_Init(void);                                                        //???
void LCD_DisplayOn(void);                                                   //???
void LCD_DisplayOff(void);                                                  //???
void LCD_Clear(uint16_t Color);                                                  //??
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);                                     //????
void LCD_DrawPoint(uint16_t x, uint16_t y);                                           //??
void LCD_Fast_DrawPoint(uint16_t x, uint16_t y, uint16_t color);                           //????
uint16_t  LCD_ReadPoint(uint16_t x, uint16_t y);                                           //??
void LCD_Draw_Circle(uint16_t x0, uint16_t y0, uint8_t r);                                 //??
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);                          //??
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);                     //???
void LCD_Fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color);                   //????
void LCD_Color_Fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color);            //??????
void LCD_ShowChar(uint16_t x, uint16_t y, uint8_t num, uint8_t size, uint8_t mode);                  //??????
void LCD_ShowNum(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint8_t size);                   //??????
void LCD_ShowxNum(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint8_t size, uint8_t mode);         //?? ??
void LCD_ShowString(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t size, uint8_t *p);   //???????,12/16??
 
void LCD_WriteReg(uint16_t LCD_Reg, uint16_t LCD_RegValue);
uint16_t LCD_ReadReg(uint16_t LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(uint16_t RGB_Code);
void LCD_SSD_BackLightSet(uint8_t pwm);                          //SSD1963 ????
void LCD_Scan_Dir(uint8_t dir);                                  //???????
void LCD_Display_Dir(uint8_t dir);                               //????????
void LCD_Set_Window(uint16_t sx, uint16_t sy, uint16_t width, uint16_t height); //????
 
//LCD?????
#define SSD_HOR_RESOLUTION      800     //LCD?????
#define SSD_VER_RESOLUTION      480     //LCD?????
//LCD??????
#define SSD_HOR_PULSE_WIDTH     1       //????
#define SSD_HOR_BACK_PORCH      46      //????
#define SSD_HOR_FRONT_PORCH     210     //????
 
#define SSD_VER_PULSE_WIDTH     1       //????
#define SSD_VER_BACK_PORCH      23      //????
#define SSD_VER_FRONT_PORCH     22      //????
//??????,????
#define SSD_HT  (SSD_HOR_RESOLUTION+SSD_HOR_BACK_PORCH+SSD_HOR_FRONT_PORCH)
#define SSD_HPS (SSD_HOR_BACK_PORCH)
#define SSD_VT  (SSD_VER_RESOLUTION+SSD_VER_BACK_PORCH+SSD_VER_FRONT_PORCH)
#define SSD_VPS (SSD_VER_BACK_PORCH)
#endif
