/***************************************************************************************
 * Project  :
 * Experimental Platform :Arduino ESP32 + 2.42 OLED Display
 * Hardware Connection :Arduino ESP32-> 2.42 OLED Display
 *      IO33  --> RST
 *      IO26  --> DC
 *      IO25  --> CS
 *      SPI:IO18/IIC:IO22 --> CLK
 *      SPI:IO23/IIC:IO21 --> DIN
 * Author      : Andy Li
 * Web Site    :www.seengreat.com
***************************************************************************************/
#include "bmp.h"
#include "oled.h"
#include "gui.h"
#include "fonts.h"
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
void setup() {
   Serial.begin(115200);
  printf("Init gpio for esp32\r\n");
   pinMode(CS_Pin, OUTPUT);
   pinMode(RES_Pin, OUTPUT); 
   pinMode(DC_Pin, OUTPUT);    
   pinMode(2, OUTPUT); //LED 
   digitalWrite(2,HIGH);
   Config_Init();//SPI/ IIC initialization
   Oled_Init(); //OLED initialization
   delay(2000);
   Oled_Clear();
}


void loop() {
    Oled_Display(bmp1); //Refresh the picture
    delay(2000);
    Oled_Clear(); // Clear screen 
  
    Oled_Display(bmp2); //Refresh the picture 
    delay(2000);
    Oled_Clear();
    ///////////////////////////GUI///////////////////////////////////////////////////////////////////////////////////
   //Data initialization settings
    unsigned char image[1024];//Define canvas space
    Image_Init(image, Oled_WIDTH, Oled_HEIGHT, 90, BLACK); //Set screen size and display orientation
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
    GUI_Display(image);//display image 
    delay(2000);    
    Gui_Clear(BLACK);

		Gui_Draw_Str(30,25, "Black&White", &Font12, WHITE, WHITE); //7*12
		Gui_Draw_Str(15,45 , "2.42 OLED", &Font16, WHITE, WHITE); //11*16
		Gui_Draw_Str(0, 0, "SEENGREAT", &Font20, WHITE, WHITE); //14*20
    GUI_Display(image);//display image
    delay(2000);         
    Oled_Clear();
    while(1); 
}
