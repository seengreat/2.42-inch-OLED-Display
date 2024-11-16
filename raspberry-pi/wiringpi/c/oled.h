#ifndef _OLED_H_
#define _OLED_H_

#define OLED_WIDTH   64
#define OLED_HEIGHT  128

//define pin conection in wiringpi number
#define PIN_CS      10      
#define PIN_DC      6   
#define PIN_RST     0

#define use_mode 1 // 1:use spi;0:use i2c

#define ADDR 0x3c // D/C=0:IIC Address=0x3c;D/C=1:IIC Address=0x3d

#define OLED_CMD  0x00	
#define OLED_DATA 0x40	

//EPD
void Oled_Gpio_Init(void);
void Oled_Write_cmd(unsigned char cmd);
void Oled_Write_data(unsigned char data);

void Oled_Init(void); //OLED initialization
void Oled_Clear(void);
//Display 
void Oled_Display(unsigned char *Image); 


#endif
/***********************************************************
						end file
***********************************************************/


