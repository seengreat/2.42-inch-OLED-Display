#include <string.h>
#include <stdlib.h>	
#include <stdio.h>
#include <stdint.h>

#include <linux/types.h>
#include <fcntl.h>
#include "oled.h"
#include "sg_lgpio.h"
#include <unistd.h>
#include <stdint.h>
#include <linux/types.h> 


void Oled_Gpio_Init(void)
{
    Lgpio_export(); 
    Lgpio_set_pinmode(PIN_RST,LGPIO_OUTPUT);
    Lgpio_set_pinmode(PIN_DC,LGPIO_OUTPUT);
	Lgpio_set_pinmode(PIN_CS,LGPIO_OUTPUT);
	if(use_mode){
		printf("Use spi\r\n");
    	LG_SPI_Init(0, 0, 10000000);
	}
	else{
		printf("Use i2c\r\n");
		Lgpio_write_pin(PIN_CS,LGPIO_LOW);
		Lgpio_write_pin(PIN_DC,LGPIO_LOW);
		LG_I2C_Init(ADDR);
	}
}

void Oled_Write_cmd(unsigned char cmd)
{
	if(use_mode){
		Lgpio_write_pin(PIN_DC,LGPIO_LOW);  // D/C#   0:command  1:data
		LG_SPI_writebyte(cmd);
	}
	else{
		lgI2cWriteByteData(I2C_handle,OLED_CMD,cmd);
	}
}

void Oled_Write_data(unsigned char data)
{
	if(use_mode){
		Lgpio_write_pin(PIN_DC,LGPIO_HIGH); // D/C#   0:command  1:data
		LG_SPI_writebyte(data);
	}
	else{
		lgI2cWriteByteData(I2C_handle,OLED_DATA,data);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

//SSD1309
void Oled_Init(void)
{
	Lgpio_write_pin(PIN_RST,LGPIO_HIGH); 
	delay(10); //At least 10ms delay 
	Lgpio_write_pin(PIN_RST,LGPIO_LOW);  // Module reset   
	delay(10);//At least 10ms delay 
	Lgpio_write_pin(PIN_RST,LGPIO_HIGH); 
	delay(10); //At least 10ms delay 

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

