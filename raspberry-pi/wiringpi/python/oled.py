import os
import sys
import spidev
import smbus
import time
import wiringpi as wpi
import numpy as np
"""the following pin definiting use wiringpi"""
PIN_CS     = 10
PIN_DC     = 6
PIN_RST    = 0
OLED_WIDTH  = 64
OLED_HEIGHT = 128

use_mode = 1 # 1:use spi;0:use i2c

class OLED():
    def __init__(self):
        # gpio init
        wpi.wiringPiSetup()
        wpi.pinMode(PIN_DC, wpi.OUTPUT)  # D/C pin
        wpi.pinMode(PIN_RST, wpi.OUTPUT)  # reset pin
        wpi.pinMode(PIN_CS, wpi.OUTPUT)  # cs pin
        if use_mode == 1:
            # spi init
            self.bus = 0
            self.dev = 0
            self.spi_speed = 10000000
            self.spi = spidev.SpiDev()
            self.spi.open(self.bus, self.dev)
            self.spi.max_speed_hz = self.spi_speed
            self.spi.mode = 0b00
        else:
            # i2c init
            wpi.digitalWrite(PIN_CS,wpi.LOW)
            wpi.digitalWrite(PIN_DC,wpi.LOW)
            self.addr = 0x3c #DC,LOW:IIC Address = 0x3C; DC,HIGH:IIC Address = 0x3D
            self.i2c = smbus.SMBus(1)  # /dev/i2c-1

        self.w = OLED_WIDTH
        self.h = OLED_HEIGHT
        
    def write_cmd(self, cmd):
        """write command"""
        if use_mode == 1:
            wpi.digitalWrite(PIN_DC,wpi.LOW)
            self.spi.writebytes([cmd])
        else:
            self.i2c.write_byte_data(self.addr, 0x00, cmd)

        
    def write_data(self, value):
        """write data"""
        if use_mode == 1:
            wpi.digitalWrite(PIN_DC,wpi.HIGH)
            self.spi.writebytes([value])
        else:
            self.i2c.write_byte_data(self.addr,0x40,value)
        
    def reset(self):
        """reset the oled"""
        wpi.digitalWrite(PIN_RST,wpi.LOW)
        time.sleep(0.1)
        wpi.digitalWrite(PIN_RST,wpi.HIGH)
        time.sleep(0.1)
        
    def oled_init(self):
        """oled init..."""
        self.reset()

        self.write_cmd(0xFD)
        self.write_cmd(0x12)
        self.write_cmd(0xAE)#--turn off oled panel
        self.write_cmd(0xd5)#--set display clock divide ratio/oscillator frequency
        self.write_cmd(0xA0)
        self.write_cmd(0xA8)#--set multiplex ratio(1 to 64)
        self.write_cmd(0x3f)#--1/64 duty
        self.write_cmd(0xD3)                                        #-set display offset    Shift Mapping RAM Counter (0x00~0x3F)
        self.write_cmd(0x00)                                        #-not offset
        self.write_cmd(0x40)                                        #--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
        self.write_cmd(0xA1)                                        #--Set SEG/Column Mapping     0xa0:flip horizontal; 0xa1:normal
	    # Oled_Write_cmd(0xC8);										#Set COM/Row Scan Direction   0xc0:flip vertical; 0xc8:normal
        self.write_cmd(0xDA)                                        #--set com pins hardware configuration
        self.write_cmd(0x12)
        self.write_cmd(0x81)                                        #--set contrast control register
        self.write_cmd(0x7f)                                        # Set SEG Output Current Brightness
        self.write_cmd(0xD9)                                        #--set pre-charge period
        self.write_cmd(0x82)                                        #Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
        self.write_cmd(0xDB)                                        #--set vcomh
        self.write_cmd(0x34)                                        #Set VCOM Deselect Level
        self.write_cmd(0xA4)                                        # Disable Entire Display On (0xa4/0xa5)
        self.write_cmd(0xA6)    
        time.sleep(0.1)
        self.write_cmd(0xAF)

    # display
    def oled_clear(self):
        for i in range(8):
            # /* set page address */
            self.write_cmd(0xB0 + i)
            # /* set low column address */
            self.write_cmd(0x00)
            # /* set high column address */
            self.write_cmd(0x10)
            for j in range(OLED_HEIGHT):
                self.write_data(0x00)

    def display(self, image):
        height = self.h
        for i in range(8):
            self.write_cmd(0xB0 + i)
            self.write_cmd(0x00)
            self.write_cmd(0x10)
            for j in range(height): 
                self.write_data(image[(7-i) + j * 8])