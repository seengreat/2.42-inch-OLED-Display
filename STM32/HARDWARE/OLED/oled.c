#include "oled.h"
#include "stdlib.h"
#include "oledfont.h"  	 
#include "delay.h"
#include "spi.h"
#include "gui.h"


void IIC_delay(void)
{
	u8 t=3;
	while(t--);
}

//Screen color inversion
void OLED_ColorTurn(u8 i)
{
	if(i==0)
		{
			OLED_WR_Byte(0xA6,OLED_CMD);//normal
		}
	if(i==1)
		{
			OLED_WR_Byte(0xA7,OLED_CMD);//color conversion
		}
}

//Screen rotation 180 degrees
void OLED_DisplayTurn(u8 i)
{
	if(i==0)
		{
			OLED_WR_Byte(0xC0,OLED_CMD);//normal
			OLED_WR_Byte(0xA1,OLED_CMD);
		}
	if(i==1)
		{
			OLED_WR_Byte(0xC8,OLED_CMD);//Reverse display
			OLED_WR_Byte(0xA0,OLED_CMD);
		}
}

void IIC_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_7;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; 		 			
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					
 	GPIO_Init(GPIOA, &GPIO_InitStructure);	  							
 	GPIO_SetBits(GPIOA,GPIO_Pin_5|GPIO_Pin_7);

	OLED_CS_Clr();														
	OLED_DC_Clr();
}

void SPI1_Init(void)
{
	SPI_InitTypeDef  SPI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
  
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE );	
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7 ;					
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  						
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1 ,ENABLE);

	SPI_InitStructure.SPI_Direction 			= SPI_Direction_2Lines_FullDuplex ;		
	SPI_InitStructure.SPI_Mode 					= SPI_Mode_Master;						
	SPI_InitStructure.SPI_DataSize 				= SPI_DataSize_8b;						
	SPI_InitStructure.SPI_CPOL 					= SPI_CPOL_High;						
	SPI_InitStructure.SPI_CPHA 					= SPI_CPHA_2Edge;						
	SPI_InitStructure.SPI_NSS 					= SPI_NSS_Soft;							
	SPI_InitStructure.SPI_BaudRatePrescaler 	= SPI_BaudRatePrescaler_8;				
	SPI_InitStructure.SPI_FirstBit 				= SPI_FirstBit_MSB;						
	SPI_InitStructure.SPI_CRCPolynomial 		= 7;									
	SPI_Init(SPI1, &SPI_InitStructure);  												
 
	SPI_Cmd(SPI1, ENABLE); 																
		 
}   
//SPI speed set
//SpeedSet:
//SPI_BaudRatePrescaler_2     (SPI 36M     @sys 72M)
//SPI_BaudRatePrescaler_4     (SPI 18M     @sys 72M)
//SPI_BaudRatePrescaler_8     (SPI 9M   	 @sys 72M)
//SPI_BaudRatePrescaler_16    (SPI 4.5M    @sys 72M)
//SPI_BaudRatePrescaler_256   (SPI 281.25K @sys 72M)
  
/*void SPI1_SetSpeed(u8 SpeedSet)
{
	SPI_InitStructure.SPI_BaudRatePrescaler = SpeedSet ;
  	SPI_Init(SPI1, &SPI_InitStructure);
	SPI_Cmd(SPI1,ENABLE);
} */


u8 SPI1_ReadWriteByte(u8 TxData)
{		
	//u8 retry=0;				 	
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET); 			
		/*{
			retry++;
			if(retry>200)return 0;
		}		*/	  
	SPI_I2S_SendData(SPI1, TxData); 										
	
//	retry=0;
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);		
//		{
//			retry++;
//			if(retry>200)return 0;
//		}	  						    
	return SPI_I2S_ReceiveData(SPI1); 														    
}


//Write a byte
void Send_Byte(u8 dat)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		if(dat&0x80)//Writes from the highest bit
		{
			OLED_SDA_Set();
    }
		else
		{
			OLED_SDA_Clr();
    }
		IIC_delay();
		OLED_SCL_Set();
		IIC_delay();
		OLED_SCL_Clr();
		dat<<=1;
  }
}

void OLED_WR_Byte(u8 dat,u8 cmd)
{	
	if(use_mode){
		if(cmd)
			OLED_DC_Set();
		else 
		  OLED_DC_Clr();		  
			OLED_CS_Clr();
			SPI1_ReadWriteByte(dat);
			OLED_CS_Set();
			OLED_DC_Set();  
	}
 	else{
		I2C_Start();
		Send_Byte(ADDR);
		I2C_WaitAck();
		if(cmd){Send_Byte(0x40);}
		else{Send_Byte(0x00);}
		I2C_WaitAck();
		Send_Byte(dat);
		I2C_WaitAck();
		I2C_Stop();
	}
}

//Turn on OLED display 
void OLED_DisPlay_On(void)
{
	OLED_WR_Byte(0x8D,OLED_CMD);
	OLED_WR_Byte(0x14,OLED_CMD);
	OLED_WR_Byte(0xAF,OLED_CMD);
}

//Turn off OLED display
void OLED_DisPlay_Off(void)
{
	OLED_WR_Byte(0x8D,OLED_CMD);
	OLED_WR_Byte(0x10,OLED_CMD);
	OLED_WR_Byte(0xAE,OLED_CMD);
}

//OLED initialization
void OLED_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 			//Enable clock on port A
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 			//Enable clock on port C
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_3 | GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_4|GPIO_Pin_3|GPIO_Pin_2);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;	 						//PC13 LED cycle flash
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 			
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					
 	GPIO_Init(GPIOC, &GPIO_InitStructure);	  							
	if(use_mode){
		SPI1_Init();
	}
	else{
		IIC_Init();
	}
	
	OLED_RES_Set();
	delay_ms(200);
	OLED_RES_Clr();
	delay_ms(200);
	OLED_RES_Set();
	delay_ms(200);
	
	OLED_WR_Byte(0xFD,OLED_CMD);
	OLED_WR_Byte(0x12,OLED_CMD);
	OLED_WR_Byte(0xAE,OLED_CMD);//--turn off oled panel
	OLED_WR_Byte(0xd5,OLED_CMD);//--set display clock divide ratio/oscillator frequency
//	OLED_WR_Byte(0x10,OLED_CMD);
	OLED_WR_Byte(0xA0,OLED_CMD);
	OLED_WR_Byte(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
	OLED_WR_Byte(0x3f,OLED_CMD);//--1/64 duty
	OLED_WR_Byte(0xD3,OLED_CMD);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	OLED_WR_Byte(0x00,OLED_CMD);//-not offset
	OLED_WR_Byte(0x40,OLED_CMD);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
//	OLED_WR_Byte(0xA1,OLED_CMD);//--Set SEG/Column Mapping     0xa0:flip horizontal 0xa1:normal
//	OLED_WR_Byte(0xC0,OLED_CMD);//Set COM/Row Scan Direction   0xc0:flip vertical; 0xc8:normal
	OLED_WR_Byte(0xDA,OLED_CMD);//--set com pins hardware configuration
	OLED_WR_Byte(0x12,OLED_CMD);
	OLED_WR_Byte(0x81,OLED_CMD);//--set contrast control register
	OLED_WR_Byte(0x6F,OLED_CMD);// Set SEG Output Current Brightness
	OLED_WR_Byte(0xD9,OLED_CMD);//--set pre-charge period
	OLED_WR_Byte(0x82,OLED_CMD);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	OLED_WR_Byte(0xDB,OLED_CMD);//--set vcomh
	OLED_WR_Byte(0x34,OLED_CMD);//Set VCOM Deselect Level
	OLED_WR_Byte(0xA4,OLED_CMD);// Disable Entire Display On (0xa4/0xa5)
	OLED_WR_Byte(0xA6,OLED_CMD);// Disable Inverse Display On (0xa6/a7)
	OLED_Clear();
	OLED_WR_Byte(0xAF,OLED_CMD);
}

void Gui_Display(unsigned char *Image)
{
  	unsigned char temp,height,i,j;
    height = OLED_HEIGHT;

    for ( j = 0; j < 8; j++) 
    {
			/* set page address */
			OLED_WR_Byte(0xB0 + j,OLED_CMD);
			/* set low column address */
			OLED_WR_Byte(0x00,OLED_CMD);
			/* set high column address */
			OLED_WR_Byte(0x10,OLED_CMD);
        for ( i = 0; i < height; i++) 
        {
          temp = Image[(7-j) + i*8];
          OLED_WR_Byte(temp,OLED_DATA);
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
			OLED_WR_Byte(0xB0 + j,OLED_CMD);
			/* set low column address */
			OLED_WR_Byte(0x00,OLED_CMD);
			/* set high column address */
			OLED_WR_Byte(0x10,OLED_CMD);
        for ( i = 0; i < height; i++) 
        {
          temp = Image[(7-j) + i*8];
          OLED_WR_Byte(temp,OLED_DATA);
        }
    } 
}

void OLED_Clear(void)
{
  unsigned char height,i,j;
  height = OLED_HEIGHT;
	for(i=0;i<8;i++)
	{
     /* set page address */
     OLED_WR_Byte(0xB0 + i,OLED_CMD);
     /* set low column address */
     OLED_WR_Byte(0x00,OLED_CMD);
     /* set high column address */
     OLED_WR_Byte(0x10,OLED_CMD);
	   for(j=0;j<height;j++)
			{
        OLED_WR_Byte(0x00,OLED_DATA);
			}
  } 
}

//Start signal
void I2C_Start(void)
{
	OLED_SDA_Set();
	OLED_SCL_Set();
	IIC_delay();
	OLED_SDA_Clr();
	IIC_delay();
	OLED_SCL_Clr();
	IIC_delay();
}

//end signal
void I2C_Stop(void)
{
	OLED_SDA_Clr();
	OLED_SCL_Set();
	IIC_delay();
	OLED_SDA_Set();
}

//Wait for signal response
void I2C_WaitAck(void)
{
	OLED_SDA_Set();
	IIC_delay();
	OLED_SCL_Set();
	IIC_delay();
	OLED_SCL_Clr();
	IIC_delay();
}
