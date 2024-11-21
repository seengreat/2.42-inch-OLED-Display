2.42 inch OLED Display from seengreat:www.seengreat.com
 =======================================
# Product Overview
![image](https://github.com/seengreat/2.42-inch-OLED-Display/blob/main/01.png)<br> 

Figure 1-1 Style A Product Image<br>
![image](https://github.com/seengreat/2.42-inch-OLED-Display/blob/main/02.png)<br> 

Figure 1-2 Style B Product Image<br>
This product is a 2.42inch display expansion module, compatible with Raspberry Pi series boards, Arduino, STM32, ESP32 and more. We offer Raspberry Pi example codes in both C and Python, as well as Arduino, STM32 and ESP32 example codes. These codes enable drawing of points, lines, rectangles, and circles, and also support displaying alphanumeric characters and images.<br>
## 1.1 Product parameters
|Pixels	|128 x 64|
|-----------|---------|
|Display Color|	Black and White/Black and Yellow/Black and Blue/Black and Green|
|Voltage Translator	|TXS0108EPWR|
|Signal interface	|SPI / I2C|
|Supply voltage	|3.3V/5V|
|OLED display area	|55.01mm (W) x 27.49mm (H)|
|Driver chip	|SSD1309|
|Dimensions	|Style A:63mm(Length) x 42.4mm(width) Style B:62.1mm(Length) x 39.2mm(width)|
|Weight	                |Style A:23g Style B:21g|<br>

![image](https://github.com/seengreat/2.42-inch-OLED-Display/blob/main/03.png)<br> 

Figure1-3 2.42inch OLED Display A size diagram<br>

![image](https://github.com/seengreat/2.42-inch-OLED-Display/blob/main/04.png)<br> 

Figure1-4 2.42inch OLED Display B size diagram<br>

# Usage
All examples provided with this product are based on SPI mode, so the default position of the switch on the back of the board is set to "SPI". If you want to use I2C mode, please switch the selector on the back of the board to "I2C" and change `use_mode 1` to `use_mode 0` in the `oled.h` file.
This product has two optional I2C addresses, controlled by the high or low level of the D/C pin in I2C mode. If you want to change the I2C address, please modify the `ADDR` and D/C pin levels in the `oled.h` and `oled.c` files to the corresponding parameters.<br>
## 2.1 Module Resource Profile
Module Resource Profile is shown in the figure below:<br>
![image](https://github.com/seengreat/2.42-inch-OLED-Display/blob/main/05.png)<br> 

Figure 2-1 2.42inch OLED Display Resource Overview<br>
1. SPI/I2C selector switch<br>
2. OLED screen connector<br>
3. Voltage Translator TXS0108<br>
4. SPI/I2C control interface1.25mm pitch connector<br>
5. SPI/I2C control interface 2.54mm pitch pin header<br>
## 2.2 Raspberry Pi Demo Codes Usage
Since the bookworm system no longer supports the wiringpi library, the example program for this system uses the lgpio library, and for the bullseye system, the wiringpi library version of the example program can be used.<br>
### 2.2.1 Raspberry Pi Platform Interface Definition

The bullseye system example program for the Raspberry Pi uses the pin definitions number in wiringPi, and the bookworm system uses the pin definition of the BCM number. The definition of the wiring with the Raspberry Pi motherboard is shown in the following table: <br>
|OLED display	|WiringPi number	|BCM number|
|----------------------|-----------------------|--------------|
|VCC	|3.3V|	|	
|GND	|GND|	|
|DIN	|SPI:P12 / I2C:P8	|SPI:D10 / I2C:D2|
|CLK	|SPI:P14 / I2C:P9	|SPI:D11 / I2C:D3|
|CS	|P10	|D8|
|D/C	|P6	|D25|
|RST	|P0	|D17|<br>

Table2-1 Definition of OLED display and Raspberry Pi pin<br>
### 2.2.2 WiringPi library installation
```sudo apt-get install wiringpi```<br>

```wget https://project-downloads.drogon.net/wiringpi-latest.deb ```#<br>
Upgrade Raspberry Pi 4B Version<br>
```sudo dpkg -i wiringpi-latest.deb```<br>
```gpio -v ```<br>
If version 2.52 appears, it indicates that the installation has been successful.<br>
For the Bullseye branch system, use the following command:<br>
```git clone https://github.com/WiringPi/WiringPi```<br>
```cd WiringPi```<br>
```. /build``` <br>
```gpio -v ```#<br>
Running "gpio -v" will show version 2.70. If it doesn't appear, it means there is an installation error.<br>
If an error message "ImportError: No module named 'wiringpi'" appears when running a sample program in Python version, run the following command:<br>
For Python 2.x version<br>
```pip install wiringpi```<br>
For Python 3.x version<br>
```pip3 install wiringpi```<br>
Note: If the installation fails, you can try the following compiled installation.<br>
```git clone --recursive https://github.com/WiringPi/WiringPi-Python.git```<br>
Note: The --recursive option can automatically pull submodules. Otherwise, you need to download them manually.
Enter the newly downloaded WiringPi-Python folder and use the following commands to compile and install:<br>
For Python 2.x version<br>
```sudo python setup.py install```<br>
For Python 3.x version<br>
```sudo python3 setup.py install```<br>
If the following error occurs:<br>
``Error: Building this module requires either that swig is installed``<br>
``(e.g.,'sudo apt install swig')or that wiringpi wrap.c from the``<br>
``source distribution(on pypi) is available.``<br>
In this case, enter the command ```sudo apt install swig``` to install SWIG. After completing the installation, run ```sudo python3 setup.py``` install to compile and install. If you see similar information, it indicates that the installation was successful.<br>
``ges``<br>
``Adding wiringpi 2.60.0 to easy-install.pth file``<br>
``Installed /usr/local/lib/python3.7/dist-packages/wiringpi-2.60.0-py3.7-linux-armv7``<br>
``Processing dependencies for wiringpi==2.60.0``<br>
``Finished processing dependencies for wiringpi==2.60.0``<br>

### 2.2.3 lgpio Library Installation
For the Bookworm system, the example programs use the lgpio library. The installation command for this library is:<br>
```wget https://github.com/joan2937/lg/archive/master.zip```<br>
```unzip master.zip```<br>
```cd lg-master```<br>
```make```<br>
```sudo make install```<br>
### 2.2.4 Open SPI interface
```sudo raspi-config```<br>
Enable SPI interface:<br>
Interfacing Options->SPI->Yes<br>
To view enabled SPI devices:<br>
```ls /dev/spi*```<br>
The following will be printed: "/dev/spidev0.0" and "/dev/spidev0.1"<br>
### 2.2.5 Open I2C interface
```sudo raspi-config```<br>
Enable I2C interface:<br>
Interfacing Options->SPI->Yes<br>
Run the command to check whether I2C is started:<br>
```lsmod```<br>
If i2c_bcm2835 are displayed, it means I2C module is started.<br>
Install the i2c-tools tool to confirm:<br>
```sudo apt-get install i2c-tools```<br>
View connected I2C devices:<br>
```i2cdetect -y 1```<br>
If the display address is 0x3d or 0x3c, it indicates that the OLED is successfully connected to the Raspberry Pi.<br>
### 2.2.6 Installation of python library 
The demo codes uses the python 3 environment. To run the python demo codes, you need to install the pil, numpy, and spiderv libraries. Enter the following commands in order to install:<br>
```sudo apt-get install python3-pil```<br>
```sudo apt-get install python3-numpy```<br>
```sudo apt-get install python3-pip```<br>
```sudo apt-get install spidev```<br>
```sudo pip3 install smbus```<br>
### 2.2.7 C version demo codes
Open \***\raspberry_pi\c directory<br>
```sudo make clean```<br>
```sudo make```<br>
```sudo ./main```<br>
After entering the above command, you can observe the OLED display.<br>
### 2.2.8 Python version demo codes
Open \***\raspberry_pi\python directory<br>
```python3 gui_demo.py```<br>
After entering the above command, you can observe the OLED display.<br>
## 2.3 Arduino Demo Codes Usage
### 2.3.1 Hardware interface configuration description
Table 2-2 is the wiring definition between Arduino Mega and OLED display:<br>
|OLED display	|Arduino Mega|
|----------------------|----------------|
|VCC	|5V|
|GND	|GND|
|DIN	|SPI:D51 / I2C:SDA1|
|CLK	|SPI:D52 / I2C:SCL1|
|CS	|D10|
|D/C	|D9|
|RST	|D8|<br>

Table 2-3 is the wiring definition between Arduino Uno and OLED display:<br>
|OLED display	|Arduino Uno|
|----------------------|--------------|
|VCC	|5V|
|GND	|GND|
|DIN	|SPI:D11 / I2C:SDA|
|CLK	|SPI:D13 / I2C:SCL|
|CS	|D10|
|D/C	|D9|
|RST	|D8|<br>

### 2.3.2 Demo Codes Usage
Open the ```\***\Arduino_MEGA_2.42\Arduino_MEGA_2.42.ino``` or ```\***\Arduino_UNO_2.42\Arduino_UNO_2.42.ino``` with Arduino IDE Click Verify to verify the project file, and then transfer it to the module to observe the OLED display.<br>
## 2.4 STM32 Demo Codes Usage
The STM32 module used in this example program is STM32F103C8T6.<br>
### 2.4.1 Hardware interface configuration description
|OLED display	|STM32|
|----------------------|--------|
|VCC	|3.3V|
|GND	|GND|
|DIN	|SPI / I2C:PA7|
|CLK	|SPI / I2C:PA5|
|CS	|PB4|
|D/C	|PA3|
|RST	|PA2|<br>

### 2.4.2 Demo Codes Usage
Open the demo codes in directory \***\STM32 with Keil uVision5 software, compile it correctly, download it to the module, and observe the OLED display.<br>
## 2.5 ESP32 Demo Codes Usage
The ESP32 module used in this example program is ESP32-WROOM-32E.<br>
### 2.5.1 Hardware interface configuration description
|OLED display	|ESP32|
|----------------------|-------|
|VCC	|3.3V|
|GND	|GND|
|DIN	|SPI:IO23/ I2C:IO21|
|CLK	|SPI:IO18/ I2C:IO22|
|CS	|IO25|
|DC	|IO26|
|RST	|IO33|<br>

### 2.5.2 Demo Codes Usage
Open the demo codes in directory \***\Arduino_ESP32_2.42 with Arduino IDE Click Verify to verify the project file, and then transfer it to the module to observe the OLED display.<br>
## 2.6 Image Creation and Modeling Instructions
### 2.6.1 Image Creation
Create the images you want to display as pure black and white images with a resolution of 128 x 64. Save them as BMP or JPG files (BMP format is recommended).<br>
### 2.6.2 Modeling
Bitmap creation can be done using the "image2lcd" software, which is provided in the package. Taking the example of achieving the effect shown in Figure 2-3, the parameter settings interface for bitmap creation is shown in Figure 2-4:<br>
1. Open the image that needs to be modeled.<br>
2. Output data type: Select "C Language Array (*.c)".<br>
3. Scanning method: Choose "Vertical scanning".<br>
4. Output grayscale: Select "Monochrome".<br>
5. Maximum width and height: Choose "128" "64". After selection, click the arrow next to it to confirm.<br>
6. Do not check any of the 5 items as shown in the figure below. <br>
![image](https://github.com/seengreat/2.42-inch-OLED-Display/blob/main/06.png)<br> 
7. Color Inversion: Check to display the original image; uncheck for color inversion.<br>
8. Click "Save" to save the converted array to a file with the extension ".c".<br>
9. Finally, use the array in the ".c" file to replace the corresponding array in the program.<br>
![image](https://github.com/seengreat/2.42-inch-OLED-Display/blob/main/07.png)<br> 

Image 2-3<br>
![image](https://github.com/seengreat/2.42-inch-OLED-Display/blob/main/08.png)<br> 

Figure 2-4 Image modeling<br>

__Thank you for choosing the products of Shengui Technology Co.,Ltd. For more details about this product, please visit:
www.seengreat.com__
