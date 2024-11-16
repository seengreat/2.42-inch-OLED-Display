#include <stdio.h>
#include <wiringPiSPI.h>
#include <wiringPi.h>
#include "oled.h"
#include "bmp.h"	
#include "gui.h"
#include "fonts.h"

/***define pin conection in wiringpi number
2.42 OLED Display    Raspberry Pi
      VCC   --->   3.3V
      GND   --->   GND
      DIN   --->   MOSI/ SDA.1
	  CLK   --->   SCLK/ SCL.1
      CS    --->   (CE0)P10
      D/C   --->   P6
      RST   --->   P0
*****************************/
 
int	main(void)
{
	printf("2.42inch oled demo\r\n");
	Oled_Gpio_Init();       //OLED GPIO initialization
	Oled_Init();
	Oled_Clear();
	while(1)
	{
		///************picture display*******************/
		Oled_Display(bmp1);//Refresh the picture
		delay(2000); //2s
		Oled_Clear(); //Clear			
		
		Oled_Display(bmp2);//Refresh the picture
		delay(2000); //2s	
		Oled_Clear(); //Clear		
		/////////////////////////GUI///////////////////////////////////////////////////////////////////////////////////
		//Data initialization settings
    	unsigned char image[1024];
    	Image_Init(image, OLED_WIDTH, OLED_HEIGHT, 90, BLACK); //Set screen size and display orientation
    	Gui_SelectImage(image);
    	Gui_Clear(BLACK);
    	/**************Drawing**********************/
 		//Point   
		Gui_Draw_Point(1, 1, WHITE, PIXEL_1X1, DOT_STYLE_DFT);
		Gui_Draw_Point(128, 64, WHITE, PIXEL_1X1, DOT_STYLE_DFT);
		Gui_Draw_Point(80, 3, WHITE, PIXEL_2X2, DOT_STYLE_DFT);
		Gui_Draw_Point(100, 5, WHITE, PIXEL_3X3, DOT_STYLE_DFT);
		Gui_Draw_Point(55, 5, WHITE, PIXEL_4X4, DOT_STYLE_DFT);
		//Line
		Gui_Draw_Line(5, 5, 5, 15, WHITE, PIXEL_1X1, SOLID);
		Gui_Draw_Line(30, 5, 30, 28, WHITE, PIXEL_1X1, SOLID);
		//Rectangle
		Gui_Draw_Rectangle(10, 10, 45, 45, WHITE, EMPTY, PIXEL_1X1);
		Gui_Draw_Rectangle(20, 20, 35, 35, WHITE, FULL, PIXEL_1X1);
		// //Circle
		Gui_Draw_Circle(65, 25, 10, WHITE, EMPTY, PIXEL_1X1);
		Gui_Draw_Circle(65, 25, 5, WHITE, FULL, PIXEL_1X1);
		Gui_Draw_Str(20, 45, "abcdefg01234", &Font12, WHITE, WHITE); //7*12
    	Oled_Display(image);//display image  
    	delay(2000);    
    	Gui_Clear(BLACK);

		Gui_Draw_Str(30,25, "Black&White", &Font12, WHITE, WHITE); //7*12
		Gui_Draw_Str(15,45, "2.42 Oled", &Font16, WHITE, WHITE); //11*16
		Gui_Draw_Str(0, 0, "SEENGREAT", &Font20, WHITE, WHITE); //14*20
    	Oled_Display(image);//display image 
    	delay(2000);         
    	// Clear screen
    	Oled_Clear();
        printf("end\n");
		return 0;		
	}
}	


