#ifndef __OLED_H
#define __OLED_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "Arduino.h"
#include <pgmspace.h>

//IO settings
#define RES_Pin   33 
#define DC_Pin    26 
#define CS_Pin    25 

#define Oled_CS_0   digitalWrite(CS_Pin,LOW)
#define Oled_CS_1   digitalWrite(CS_Pin,HIGH)

#define Oled_DC_0   digitalWrite(DC_Pin,LOW)
#define Oled_DC_1   digitalWrite(DC_Pin,HIGH)

#define Oled_RST_0  digitalWrite(RES_Pin,LOW)
#define Oled_RST_1  digitalWrite(RES_Pin,HIGH)

#define use_mode 1 // 1:use spi;  0:use i2c

#define ADDR 0x3c // D/C=0:IIC Address=0x3c;D/C=1:IIC Address=0x3d

#define Oled_WIDTH   64
#define Oled_HEIGHT  128

#define OLED_CMD  0x00	
#define OLED_DATA 0x40

////////FUNCTION//////
void driver_delay_us(unsigned int xus);
void driver_delay_xms(unsigned long xms);
void DELAY_S(unsigned int delaytime);     
// void SPI_Delay(unsigned char xrate);
// void SPI_Write(unsigned char value);
void Send_Byte(unsigned char dat,unsigned char cmd);
void Oled_Write_cmd(unsigned char cmd);
void Oled_Write_data(unsigned char data);
void Config_Init(void);
//OLED
void Oled_Init(void); //OLED initialization
void Oled_Clear(void);
//Display 
void Oled_Display(const uint8_t *Image);
void GUI_Display(uint8_t *Image);
#endif
