# Seengreat 2.42inch OLED Display demo
# Author(s):Andy Li from Seengreat

from PIL import ImageDraw, Image, ImageFont
import time
from oled import *
from gui import *
from image import *
import wiringpi
'''define pin conection in wiringpi number
2.42 OLED Display    Raspberry Pi
      VCC   --->   3.3V
      GND   --->   GND
      DIN   --->   MOSI/ SDA.1
	  CLK   --->   SCLK/ SCL.1
      CS    --->   (CE0)P10
      D/C   --->   P6
      RST   --->   P0
'''
'''
screen coordinates gor gui functions
-----------------> x (0~127)
|
|
|
|
y(0~64)
'''
if __name__ == '__main__':
    gui = GUI()
    gui.oled.oled_init()  # oled initialization
    gui.oled.display(bmp1) # Refresh the picture
    time.sleep(2)  # delay 2s
    gui.oled.oled_clear() # Clear screen 

    gui.oled.oled_init()  # oled initialization
    gui.oled.display(bmp2) # Refresh the picture
    time.sleep(2)  # delay 2s
    gui.oled.oled_clear() # Clear screen
 
    # Drawing
    gui.clear(BLACK)
    font_16 = ImageFont.truetype("MiSans-Light.ttf", FONT_SIZE_16)  # read chinese font file
    font_20 = ImageFont.truetype("MiSans-Light.ttf", FONT_SIZE_20)  # read chinese font file
    font_24 = ImageFont.truetype("MiSans-Light.ttf", FONT_SIZE_24)  # read chinese font file
    font_28 = ImageFont.truetype("MiSans-Light.ttf", FONT_SIZE_28)  # read chinese font file
    # Point
    gui.draw_point(1, 1, WHITE, PIXEL_1X1, DOT_STYLE_DFT)
    gui.draw_point(128, 64, WHITE, PIXEL_1X1, DOT_STYLE_DFT)
    gui.draw_point(5, 80, WHITE, PIXEL_2X2, DOT_STYLE_DFT)
    gui.draw_point(5, 100, WHITE, PIXEL_3X3, DOT_STYLE_DFT)
    gui.draw_point(5, 55, WHITE, PIXEL_4X4, DOT_STYLE_DFT)
    # Line
    gui.draw_line(5, 5, 15, 5, WHITE, PIXEL_1X1, LINE_SOLID)
    gui.draw_line(30, 5, 30, 28, WHITE, PIXEL_1X1, LINE_SOLID)
     # Rectangle
    gui.draw_rectangle(10, 10, 45, 45, WHITE, FILL_EMPTY, PIXEL_1X1)
    gui.draw_rectangle(20, 20, 35, 35, WHITE, FILL_FULL, PIXEL_1X1)
     # Circle
    gui.draw_circle(65, 25, 10, WHITE, FILL_EMPTY, PIXEL_1X1)
    gui.draw_circle(65, 25, 5, WHITE, FILL_FULL, PIXEL_1X1)
    gui.draw_str(10, 45, "abcdefg01234", WHITE, FONT_SIZE_16, font_16)
    gui.oled.display(gui.img)
    time.sleep(2)

    gui.clear(BLACK)
    gui.draw_str(20,25, "Black&White", WHITE, FONT_SIZE_16, font_16)
    gui.draw_str(30, 45, "2.42 OLED", WHITE, FONT_SIZE_16, font_16)
    gui.draw_str(10, 0, "SEENGREAT", WHITE, FONT_SIZE_20, font_20)
    gui.oled.display(gui.img)  # display image
    time.sleep(2)  # 2s
    gui.oled.oled_clear()

    time.sleep(2)
    print("end")
    exit()
    while True:
        pass
