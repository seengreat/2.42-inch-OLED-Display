#include <string.h>
#include <stdlib.h>	
#include <stdio.h>
#include <stdio.h>	
#include <wiringPiSPI.h>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include "oled.h"

int i2c_fd;

void Oled_Gpio_Init(void)
{
	printf("Init gpio for wiringpi\r\n");
	// wiringPiSetup();
    if(wiringPiSetup() < 0)//use wiringpi Pin number
    { 
        printf("wiringPi lib init failed! \r\n");
    } 
    pinMode(PIN_CS, OUTPUT);
    pinMode(PIN_RST, OUTPUT);
    pinMode(PIN_DC, OUTPUT);
	if(use_mode){
		printf("Use spi\r\n");
    	wiringPiSPISetup(0,8000000);
	}
	else{
		printf("Use i2c\r\n");
		digitalWrite(PIN_CS, 0); 
		digitalWrite(PIN_DC, 0); 
		i2c_fd = wiringPiI2CSetup(ADDR);
	}
}

void delay_xms(unsigned int xms)
{
	unsigned int i;
	while(xms--)
	{
		i=12000;
		while(i--);
	}
}

void Oled_Write_cmd(unsigned char cmd)
{
	if(use_mode){
		digitalWrite(PIN_CS, 1); 
		digitalWrite(PIN_CS, 0); 
		digitalWrite(PIN_DC, 0);   // D/C#   0:command  1:data
		wiringPiSPIDataRW(0,&cmd,1); 
		digitalWrite(PIN_CS, 1);
	}
	else{
		wiringPiI2CWriteReg8(i2c_fd,OLED_CMD,cmd);
	}
 
}

void Oled_Write_data(unsigned char data)
{
	if(use_mode){
		digitalWrite(PIN_CS, 1); 
		digitalWrite(PIN_CS, 0); 
		digitalWrite(PIN_DC, 1);   // D/C#   0:command  1:data
		wiringPiSPIDataRW(0,&data,1); 
		digitalWrite(PIN_CS, 1); 
	}
	else{
		wiringPiI2CWriteReg8(i2c_fd,OLED_DATA,data);
	}

}
	
//////////////////////////////////////////////////////////////////////////////////////////////////

//SSD1309
void Oled_Init(void)
{
	digitalWrite(PIN_RST, 0);  // Module reset   
	delay_xms(10);//At least 10ms delay 
	digitalWrite(PIN_RST, 1);
	delay_xms(10); //At least 10ms delay 
		
    Oled_Write_cmd(0xFD);
	Oled_Write_cmd(0x12);
	Oled_Write_cmd(0xAE);										//--turn off oled panel
	Oled_Write_cmd(0xd5);										//--set display clock divide ratio/oscillator frequency
	Oled_Write_cmd(0xA0);
	Oled_Write_cmd(0xA8);										//--set multiplex ratio(1 to 64)
	Oled_Write_cmd(0x3f);										//--1/64 duty
	Oled_Write_cmd(0xD3);										//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	Oled_Write_cmd(0x00);										//-not offset
	Oled_Write_cmd(0x40);										//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	Oled_Write_cmd(0xA1);										//--Set SEG/Column Mapping     0xa0:flip horizontal; 0xa1:normal
	// Oled_Write_cmd(0xC8);										//Set COM/Row Scan Direction   0xc0:flip vertical; 0xc8:normal
	Oled_Write_cmd(0xDA);										//--set com pins hardware configuration
	Oled_Write_cmd(0x12);
	Oled_Write_cmd(0x81);										//--set contrast control register
	Oled_Write_cmd(0x7f);										// Set SEG Output Current Brightness
	Oled_Write_cmd(0xD9);										//--set pre-charge period
	Oled_Write_cmd(0x82);										//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	Oled_Write_cmd(0xDB);										//--set vcomh
	Oled_Write_cmd(0x34);										//Set VCOM Deselect Level
	Oled_Write_cmd(0xA4);										// Disable Entire Display On (0xa4/0xa5)
	Oled_Write_cmd(0xA6);	
	Oled_Clear();
	delay(200);
	Oled_Write_cmd(0xAF);
	
}

void Oled_Clear(void)
{
    unsigned char height,i,j;
    height = OLED_HEIGHT;
    for ( j = 0; j < 8; j++) 
	{
		/* set page address */
        Oled_Write_cmd(0xB0 + j);
        /* set low column address */
        Oled_Write_cmd(0x00);
        /* set high column address */
        Oled_Write_cmd(0x10);
        for ( i = 0; i < height; i++) 
		{
        	Oled_Write_data(0x00);
        }
    }
}

void Oled_Display(unsigned char *Image)
{
    unsigned char temp,height,i,j;
    height = OLED_HEIGHT;
    for ( j = 0; j < 8; j++) 
	{
		/* set page address */
        Oled_Write_cmd(0xB0 + j);
        /* set low column address */
        Oled_Write_cmd(0x00);
        /* set high column address */
        Oled_Write_cmd(0x10);
        for ( i = 0; i < height; i++) 
		{
			temp = Image[(7-j) + i * 8];
        	Oled_Write_data(temp);
        }
    }		 
}



/***********************************************************
						end file
***********************************************************/

