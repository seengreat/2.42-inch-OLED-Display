//#include <avr/pgmspace.h>
////////////////array/////////////////////////////////////////////////////////////////////////////////////
const unsigned char bmp1[1024] PROGMEM = { 
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XEA,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XEA,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE2,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XF4,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XF9,0X9F,0XFF,0XFF,0XE0,0XFF,0XFF,0XFF,0XF0,0X8F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XF0,0XCF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF6,0X6F,0XFF,0XFF,0XF0,0XFF,0XFF,
0XFF,0XF6,0X6F,0XFF,0XFF,0XF4,0XFF,0XFF,0XFF,0XF2,0X6F,0XFF,0XFF,0XF0,0XFF,0XFF,
0XFF,0XF1,0X0F,0XFF,0XFF,0XF8,0XFF,0XFF,0XFF,0XF9,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF2,0XFF,0XFF,
0XFF,0XFF,0XEF,0XFF,0XFF,0XF6,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XF2,0XFF,0XFF,
0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF2,0X6F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XF2,0X6F,0XFF,0XFF,0XE0,0XFF,0XFF,0XFF,0XF2,0X6F,0XFF,0XFF,0XF9,0XFF,0XFF,
0XFF,0XF2,0X6F,0XFF,0XFF,0XF0,0XFF,0XFF,0XFF,0XF2,0X6F,0XFF,0XFF,0XFE,0XFF,0XFF,
0XFF,0XFF,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XE2,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XE0,0XFF,0XFF,
0XFF,0XF0,0X0F,0XFF,0XFF,0XE4,0XFF,0XFF,0XFF,0XF2,0X6F,0XFF,0XFF,0XFC,0XFF,0XFF,
0XFF,0XF2,0X6F,0XFF,0XFF,0XFE,0XFF,0XFF,0XFF,0XF2,0X6F,0XFF,0XFF,0XE7,0XFF,0XFF,
0XFF,0XF2,0X6F,0XFF,0XFF,0XF1,0XFF,0XFF,0XFF,0XF2,0X6F,0XFF,0XFF,0XFC,0XFF,0XFF,
0XFF,0XFF,0XEF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFC,0XFF,0XFF,
0XFF,0XF0,0X0F,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XF8,0XFF,0XFF,0XFF,0XEF,0XFF,0XFF,
0XFF,0XFC,0X7F,0XFF,0XFF,0XE0,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XE0,0XFF,0XFF,
0XFF,0XFF,0X0F,0XFF,0XFF,0XF7,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XF3,0XFF,0XFF,
0XFF,0XF0,0X0F,0XFF,0XFF,0XF8,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0XFF,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XE8,0XFF,0XFF,
0XFF,0XF8,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF1,0X8F,0XFF,0XFF,0XF0,0XFF,0XFF,
0XFF,0XF3,0XCF,0XFF,0XFF,0XF0,0XFF,0XFF,0XFF,0XF7,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XF7,0X6F,0XFF,0XFF,0XF8,0XFF,0XFF,0XFF,0XF3,0X6F,0XFF,0XFF,0XF0,0XFF,0XFF,
0XFF,0XF3,0X4F,0XFF,0XFF,0XF6,0XFF,0XFF,0XFF,0XF9,0X0F,0XFF,0XFF,0XF8,0XFF,0XFF,
0XFF,0XFD,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XF0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF2,0X4F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XF2,0X7F,0XFF,0XFF,0XFF,0XFF,0XC0,0XFF,0XF2,0X7F,0XFF,0XFF,0XFF,0XFE,0X00,
0XFF,0XF2,0X3F,0XFF,0XFF,0XFF,0XF8,0X00,0XFF,0XF2,0X1F,0XFF,0XFF,0XFF,0X80,0X00,
0XFF,0XF0,0X8F,0XFF,0XFF,0XFE,0X00,0X00,0XFF,0XF8,0XEF,0XFF,0XFF,0XF0,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X0E,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X1F,0X80,
0XFF,0XF0,0X0F,0XFF,0XFF,0X00,0X31,0X80,0XFF,0XF0,0X0F,0XFF,0XFF,0X00,0X30,0X80,
0XFF,0XF2,0X6F,0XFF,0XFF,0X00,0X20,0X80,0XFF,0XF2,0X6F,0XFF,0XFF,0XC0,0X20,0X80,
0XFF,0XF2,0X6F,0XFF,0XFF,0XF8,0X31,0X80,0XFF,0XF2,0X6F,0XFF,0XFF,0XF8,0X19,0X80,
0XFF,0XF2,0X6F,0XFF,0XFF,0XF8,0X0F,0X00,0XFF,0XF2,0X6F,0XFF,0XFF,0XF8,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X00,0X00,
0XFF,0XFF,0X8F,0XFF,0XFF,0XF8,0X00,0X00,0XFF,0XFE,0X0F,0XFF,0XFF,0XF8,0X00,0X00,
0XFF,0XF8,0X3F,0XFF,0XFF,0XF8,0X00,0X00,0XFF,0XF0,0XBF,0XFF,0XFF,0XF8,0X00,0X00,
0XFF,0XF1,0XBF,0XFF,0XFF,0XFC,0X00,0X00,0XFF,0XF0,0X3F,0XFF,0XFF,0XFC,0X1E,0X00,
0XFF,0XFC,0X0F,0XFF,0XFF,0XFC,0X3B,0X00,0XFF,0XFF,0X8F,0XFF,0XFF,0XF8,0X31,0X80,
0XFF,0XFF,0XEF,0XFF,0XFF,0XF0,0X20,0X80,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X20,0X80,
0XFF,0XF7,0XFF,0XFF,0XFF,0X80,0X20,0X80,0XFF,0XF3,0XFF,0XFF,0XFF,0X00,0X31,0X80,
0XFF,0XF3,0XFF,0XFF,0XFE,0X00,0X1F,0X00,0XFF,0XF3,0XEF,0XFF,0XFF,0X00,0X0F,0X00,
0XFF,0XF0,0X0F,0XFF,0XFF,0XC0,0X00,0X00,0XFF,0XF0,0X0F,0XFF,0XFF,0XF0,0X00,0X00,
0XFF,0XF3,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0XFF,0XF3,0XFF,0XFF,0XFF,0XFF,0X80,0X00,
0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF4,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X7F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
};

const unsigned char bmp2[1024]PROGMEM = { 
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X01,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0XC0,0X00,0X00,0X0C,0X00,0X00,0X00,0X00,0X60,0X00,0X00,0X1C,0X00,0X30,0XE0,
0X00,0X60,0X00,0X00,0X18,0X00,0X31,0XE0,0X00,0X30,0X06,0X00,0X30,0X00,0X33,0XA0,
0X00,0X30,0X06,0X00,0X30,0X00,0X37,0X20,0X00,0X18,0X06,0X00,0X60,0X00,0X3E,0X20,
0X00,0X18,0X06,0X00,0X60,0X00,0X1C,0X20,0X00,0X08,0X06,0X00,0XC0,0X00,0X00,0X00,
0X00,0X0C,0X06,0X01,0XC0,0X00,0X00,0X60,0X00,0X04,0X06,0X01,0X80,0X00,0X00,0X60,
0X00,0X06,0X06,0X03,0X00,0X00,0X00,0X60,0X60,0X02,0X00,0X07,0X00,0X00,0X00,0X00,
0X30,0X02,0X00,0X06,0X01,0X80,0X03,0X80,0X1C,0X00,0X7F,0XE0,0X03,0X80,0X07,0X80,
0X0E,0X00,0XFF,0XF8,0X07,0X00,0X0C,0X80,0X03,0X03,0XFF,0XFC,0X0E,0X00,0X1C,0X80,
0X01,0X87,0XFF,0XFF,0X1C,0X00,0X3F,0XE0,0X00,0XCF,0XFF,0XFF,0X38,0X00,0X3F,0XE0,
0X00,0X4F,0XFF,0XFF,0X80,0X00,0X00,0X80,0X00,0X1F,0XFF,0XFF,0XC0,0X00,0X00,0X00,
0X00,0X1F,0XFF,0XFF,0XC0,0X00,0X30,0XE0,0X00,0X3F,0XFF,0XFF,0XC1,0XF0,0X31,0XE0,
0X00,0X3F,0XFF,0XFF,0XC3,0XF0,0X33,0XA0,0X00,0X3F,0XFF,0XFF,0XC7,0XF0,0X37,0X20,
0X7F,0X3F,0XFF,0XFF,0XCF,0XF0,0X3E,0X20,0X7F,0X3F,0XFF,0XFF,0X8F,0XF0,0X1C,0X20,
0X00,0X3F,0XFF,0XFF,0X1F,0XF0,0X00,0X00,0X00,0X3F,0XFF,0XFC,0X3F,0XF0,0X00,0X00,
0X00,0X3F,0XFF,0XE0,0X3F,0XF0,0X00,0X00,0X00,0X3F,0XFF,0XC1,0XFF,0XF0,0X00,0X00,
0X00,0X1F,0XFF,0X0F,0XFF,0XF0,0X00,0X00,0X00,0X1F,0XFE,0X3F,0XFF,0XF0,0X3F,0XE0,
0X00,0XCF,0XFC,0X7F,0XFF,0XF0,0X3F,0XE0,0X03,0XC7,0XF8,0XFF,0XFF,0XF0,0X3F,0XE0,
0X07,0X83,0XF9,0XFF,0XFF,0XF0,0X00,0X00,0X0E,0X01,0XF3,0XFF,0XFF,0XF0,0X00,0X00,
0X0C,0X00,0XF3,0XFF,0XFF,0XF0,0X07,0XE0,0X00,0X02,0X07,0XFF,0XFF,0XF0,0X0F,0XE0,
0X00,0X02,0X07,0XFF,0XFF,0XF0,0X0C,0X00,0X00,0X06,0X07,0XFF,0XFF,0XF0,0X0C,0X00,
0X00,0X0C,0X07,0XFF,0XFF,0XF0,0X0F,0XE0,0X00,0X08,0X07,0XFF,0XFF,0XF0,0X07,0XE0,
0X00,0X18,0X07,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X30,0X07,0XFF,0XFF,0XF0,0X00,0X00,
0X00,0X60,0X07,0XFF,0XFF,0XF0,0X07,0XE0,0X00,0X60,0X07,0XFF,0XFF,0XF0,0X0F,0XE0,
0X00,0XC0,0X07,0XFF,0XFF,0XF0,0X0C,0X60,0X00,0XC0,0X1F,0XFF,0XFF,0XF0,0X0C,0X60,
0X01,0X80,0X3F,0XFF,0XFF,0XF0,0X0C,0X60,0X01,0X80,0X7F,0XFF,0XFF,0XF0,0X00,0X00,
0X00,0X00,0XFF,0XFF,0XFF,0XF0,0X7F,0XE0,0X00,0X01,0XFF,0XFF,0XFF,0XF0,0X7F,0XE0,
0X00,0X01,0XFF,0XFF,0XFF,0XF0,0X06,0X00,0X00,0X01,0XFF,0XFF,0XFF,0XF0,0X06,0X00,
0X00,0X01,0XFF,0XFF,0XFF,0XF0,0X07,0XE0,0X00,0X01,0XFF,0XFF,0XFF,0XF0,0X07,0XE0,
0X00,0X01,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X01,0XFF,0XFF,0XFF,0XF0,0X00,0X00,
0X00,0X01,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XF0,0X00,0X00,
0X00,0X00,0X7F,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFF,0XF0,0X00,0X00,
0X00,0X00,0X3F,0XFF,0XFF,0XF0,0X1F,0XC0,0X00,0X00,0X3F,0XFF,0XFF,0XF0,0X3F,0XE0,
0X00,0X00,0X1F,0XFF,0XFF,0XF0,0X30,0X60,0X00,0X00,0X1F,0XFF,0XFF,0XF0,0X30,0X60,
0X00,0X00,0X0F,0XFF,0XFF,0XF0,0X30,0X60,0X00,0X00,0X07,0XFF,0XFF,0XF0,0X30,0X60,
0X00,0X00,0X03,0XFF,0XFF,0XF0,0X3F,0XE0,0X00,0X00,0X03,0XFF,0XFF,0XF0,0X1F,0XC0,
0X00,0X00,0X07,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XF0,0X00,0X00,
0X00,0X00,0X0F,0XFF,0XFF,0XF0,0X3F,0XE0,0X00,0X00,0X1F,0XFF,0XFF,0XF0,0X3F,0XE0,
0X00,0X00,0X1F,0XFF,0XFF,0XF0,0X00,0X60,0X00,0X00,0X1F,0XFF,0XFF,0XF0,0X00,0X60,
0X00,0X00,0X1F,0XFF,0XFF,0XF0,0X00,0X60,0X00,0X00,0X1F,0XFF,0XFF,0XF0,0X00,0X60,
0X00,0X00,0X0F,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XF0,0X3F,0XE0,
0X00,0X00,0X07,0XFF,0XFF,0XF0,0X3F,0XE0,0X00,0X00,0X03,0XFF,0XFF,0XF0,0X32,0X60,
0X00,0X00,0X01,0XFF,0XFF,0XF0,0X32,0X60,0X00,0X00,0X00,0XFF,0XEF,0XF0,0X32,0X60,
0X00,0X00,0X00,0X7F,0XC7,0XF0,0X00,0X60,0X00,0X00,0X00,0X1F,0X83,0XF0,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0XF0,0X3F,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XE0,
0X00,0X00,0X00,0X00,0X00,0X00,0X30,0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X30,0X60,
0X00,0X00,0X00,0X00,0X00,0X00,0X30,0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X30,0X60,
0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XC0,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};



/////////////////////////////////////////////
