#include <SPI.h>
#include <Wire.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "oled.h"
#include "gui.h"

/////////////////////delay//////////////////////////////////////
void driver_delay_us(unsigned int xus)  //1us
{
    for(;xus>1;xus--);
}
void driver_delay_xms(unsigned long xms) //1ms
{  
    unsigned long i = 0 , j=0;

    for(j=0;j<xms;j++)
    {
        for(i=0; i<256; i++);
    }
}
void DELAY_S(unsigned int delaytime)     
{
    int i,j,k;
    for(i=0;i<delaytime;i++)
    {
        for(j=0;j<4000;j++)           
        {
            for(k=0;k<222;k++);               
        }
    }
}
//////////////////////transfer///////////////////////////////////
// void SPI_Delay(unsigned char xrate)
// {
//   unsigned char i;
//   while(xrate)
//   {
//       for(i=0;i<2;i++);
//       xrate--;
//   }
// }

// void SPI_Write(unsigned char value)                                    
// {                                                           
//     unsigned char i;  
//     SPI_Delay(1);
//     for(i=0; i<8; i++)   
//     {
//         Oled_CLK_0;
//         SPI_Delay(1);
//         if(value & 0x80)
//            Oled_MOSI_1;
//         else
//            Oled_MOSI_0;   
//         value = (value << 1); 
//         SPI_Delay(1);
//         driver_delay_us(1);
//         Oled_CLK_1; 
//         SPI_Delay(1);
//     }
// }

void Send_Byte(u8 dat,u8 cmd)
{
  Wire.beginTransmission(ADDR);
  Wire.write(cmd);
  Wire.write(dat);
  Wire.endTransmission(true);
}

void Oled_Write_cmd(unsigned char cmd)
{
  if(use_mode){
    Oled_CS_0;                   
    Oled_DC_0;   // command write
    SPI.transfer(cmd);
    Oled_CS_1;
  }
	else{
    Send_Byte(cmd,OLED_CMD);
  } 
}
void Oled_Write_data(unsigned char data)
{
  if(use_mode){
    Oled_CS_0;                   
    Oled_DC_1;   // data write
    SPI.transfer(data);
    Oled_CS_1;
  }
	else{
    Send_Byte(data,OLED_DATA);
  }
}

void Config_Init(void)
{
  if(use_mode){
    SPI.begin();
    SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE3));
  }
	else{
    Oled_DC_0;
    Oled_CS_0;
    Wire.setClock(1000000);
    Wire.begin();
  }
}

void Oled_Init(void)
{
  Oled_RST_1; //hard reset  
  delay(1); 
  Oled_RST_0;     
  delay(1); 
  Oled_RST_1; //hard reset  
  delay(1); 

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
	Oled_Write_cmd(0xA1);										//--Set SEG/Column Mapping     
	// Oled_Write_cmd(0xC8);										//Set COM/Row Scan Direction   
	Oled_Write_cmd(0xDA);										//--set com pins hardware configuration
	Oled_Write_cmd(0x12);
	Oled_Write_cmd(0x81);										//--set contrast control register
//	Oled_Write_cmd(0xff);										// Set SEG Output Current Brightness
	Oled_Write_cmd(0xD9);										//--set pre-charge period
	Oled_Write_cmd(0x82);										//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	Oled_Write_cmd(0xDB);										//--set vcomh
	Oled_Write_cmd(0x34);										//Set VCOM Deselect Level
	Oled_Write_cmd(0xA4);										// Disable Entire Display On (0xa4/0xa5)
	Oled_Write_cmd(0xA6);	
	Oled_Clear();
  driver_delay_xms(200);
	Oled_Write_cmd(0xAF);
  
}

void Oled_Clear(void)
{
  unsigned char height,i,j;
  height = OLED_HEIGHT;
	for(i=0;i<8;i++)
	{
        /* set page address */
        Oled_Write_cmd(0xB0 + i);
        /* set low column address */
        Oled_Write_cmd(0x00);
        /* set high column address */
        Oled_Write_cmd(0x10);
	   for(j=0;j<height;j++)
			{
        Oled_Write_data(0x00);
			}
  } 
}

void Oled_Display(const uint8_t *Image)
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
          temp = pgm_read_byte(&Image[(7-j) + i*8]);
          Oled_Write_data(temp);
        }
    } 
}

void GUI_Display(uint8_t *Image)
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
          temp = Image[(7-j) + i*8];
          Oled_Write_data(temp);
        }
    } 
}



//////////////////////////////////END//////////////////////////////////////////////////
