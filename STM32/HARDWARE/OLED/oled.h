#ifndef __OLED_H
#define __OLED_H 

#include "sys.h"
#include "stdlib.h"	


/******************************************************************************************/
/* LED PIN*/
#define LED(x)   do{ x ? \
                      GPIO_SetBits(GPIOC,GPIO_Pin_13) : \
                      GPIO_ResetBits(GPIOC,GPIO_Pin_13); \
                  }while(0)      				
#define LED_OUT PCout(13)				// PC13      

//-----------------OLED PIN---------------- 

#define OLED_SCL_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_5)			//CLK PA5
#define OLED_SCL_Set() GPIO_SetBits(GPIOA,GPIO_Pin_5)

#define OLED_SDA_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_7)			//DIN PA7
#define OLED_SDA_Set() GPIO_SetBits(GPIOA,GPIO_Pin_7)
				  
#define OLED_CS_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_4)			//CS PA4
#define OLED_CS_Set() GPIO_SetBits(GPIOA,GPIO_Pin_4)
				  
#define OLED_DC_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_3)			//D/C PA3
#define OLED_DC_Set() GPIO_SetBits(GPIOA,GPIO_Pin_3)

#define OLED_RES_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_2)			//RST PA2 
#define OLED_RES_Set() GPIO_SetBits(GPIOA,GPIO_Pin_2)

#define use_mode 0 // 1:use spi;0:use i2c

#define ADDR 0x78 // D/C=0:IIC Address=0x78;D/C=1:IIC Address=0x7A

#define OLED_WIDTH   64
#define OLED_HEIGHT  128

#define OLED_CMD  0	//write command
#define OLED_DATA 1	//write data

void OLED_ClearPoint(u8 x,u8 y);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void OLED_WR_Byte(u8 dat,u8 mode);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode);
void OLED_DrawCircle(u8 x,u8 y,u8 r);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode);
void OLED_ShowChar6x8(u8 x,u8 y,u8 chr,u8 mode);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode);
void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1,u8 mode);
void OLED_ScrollDisplay(u8 num,u8 space,u8 mode);
void Oled_Display(const uint8_t *Image);
void Gui_Display(unsigned char *Image);
void OLED_Init(void);
void IIC_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_WaitAck(void);
void Send_Byte(u8 dat);
void SPI1_Init(void);			
void SPI1_SetSpeed(u8 SpeedSet);  
u8 SPI1_ReadWriteByte(u8 TxData);
#endif

