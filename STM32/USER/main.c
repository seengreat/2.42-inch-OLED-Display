#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
#include "gui.h"
#include "fonts.h"

/****************************
* 3.3V-----VCC
* GND------GND
* PA5-----CLK
* PA7-----DIN
* PA4-----CS
* PA3-----D/C
* PA2-----RST
***************************/
/******************************
 * image :
 * 0------------> x (1~128) 
 * |
 * |
 * |
 * |
 * y (1~64)
 * 
 * */

unsigned char image[1024];

int main(void)
{
	delay_init();
	delay_ms(500);
	OLED_Init();
	OLED_ColorTurn(0);//0:normal, 1:color conversion
	OLED_DisplayTurn(0);//0:normal 1:rotation 180 degrees
	while(1)
	{
		Oled_Display(BMP1); //Refresh the picture
    delay_ms(1000);
    delay_ms(500);
    OLED_Clear(); // Clear screen

		Oled_Display(BMP2); //Refresh the picture
    delay_ms(1000);
    delay_ms(500);
    OLED_Clear(); // Clear screen
    ///////////////////////////GUI///////////////////////////////////////////////////////////////////////////////////
   //Data initialization settings
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
		//Circle
		Gui_Draw_Circle(65, 25, 10, WHITE, EMPTY, PIXEL_1X1);
		Gui_Draw_Circle(65, 25, 5, WHITE, FULL, PIXEL_1X1);
		Gui_Draw_Str(20, 45, "abcdefg01234", &Font12, WHITE, WHITE); //7*12
    Gui_Display(image);//display image 
    delay_ms(1000);   
    delay_ms(500);		
    Gui_Clear(BLACK);

		Gui_Draw_Str(30,25, "Black&White", &Font12, WHITE, WHITE); //7*12
		Gui_Draw_Str(15,45 , "2.42 OLED", &Font16, WHITE, WHITE); //11*16
		Gui_Draw_Str(0, 0, "SEENGREAT", &Font20, WHITE, WHITE); //14*20
    Gui_Display(image);//display image 
    delay_ms(1000);    
    delay_ms(500);		
    OLED_Clear();
	  while(1);
	}
}

