#ifndef __LCD_GUI_H
#define __LCD_GUI_H

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "fonts.h"
#include "lcd_1inch44.h"

#define RED       0XF800
#define WHITE     0XFFFF
#define BLACK     0X0000
#define BLUE      0X001F
#define GREEN     0X07E0
#define YELLOW    0XFFE0

#define FONT_BACKGROUND  WHITE

#define MIRROR_NONE        0
#define MIRROR_HORIZONTAL  1
#define MIRROR_VERTICAL    2
#define MIRROR_ORGIN       3

#define ROTATE_0     0
#define ROTATE_90    1
#define ROTATE_180   2
#define ROTATE_270   3

//in bmp file,if it is 24-bit storage,use 3 bytes to store one pixel,
//arranged in BGR order
#define BGR888_TO_RGB565(b,g,r)    (((r>>3)<<11)|((g>>2)<<5)|(b>>3))

typedef struct{
	uint16_t img[LCD_SIZE];
	uint16_t w;
	uint16_t h;
	uint16_t rotate;
	uint16_t mirror;
}IMAGE;

typedef enum{
    EMPTY = 0,
    FULL,	
} FILL;

typedef enum{
    SOLID = 0,  //_______________
    DOTTED,	    //---------------
} LINE_STYLE;

typedef enum{
    ROUND = 0,             
    SQUAER,	    
} DOT_STYLE;

extern IMAGE Image;

//bmp file haeder(14 bytes)
typedef struct {
	int16_t type;      //type(byte 1-2)
	uint32_t size;    //file size (byte 3-6)
	int16_t reserved1; // 0(byte 7-8)
	int16_t reserved2; // 0(byte 9-10)
	uint32_t offbits; // start position of the bitmap data,relative to the bitmap file(byte 11-14)
}__attribute__ ((packed)) BMP_HEADER;
//extern BMP_HEADER bmp_header;

//bmp file infomation(40 bytes)
typedef struct {
	uint32_t size;//the number of bytes occupied by this structure (byte 15-18)
	uint32_t width;
	uint32_t height;
	int16_t planes;
	uint16_t bit_count; //number of bits required per pixel,which must be 1 (dual color),4(16 colors),8(256 colors) or 24(true color)
	int32_t compression;
	uint32_t size_img;
	uint32_t x_pel;
	uint32_t y_pel;
	uint32_t clrused;
	int32_t clrImportant;
	
}__attribute__ ((packed)) BMP_INFO;
//extern BMP_INFO bmp_info;


void Image_Init( uint16_t img_w, uint16_t img_h, uint16_t rotate, uint16_t mirror);
void Gui_set_pix(uint16_t x, uint16_t y, uint16_t color);
void Gui_Clear(uint16_t color);
void Gui_draw_point(uint16_t x, uint16_t y, uint16_t color, uint16_t width);
void Gui_draw_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color, uint16_t width, LINE_STYLE type);
void Gui_draw_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color, uint16_t width, FILL fill);
void Gui_draw_circle(uint16_t x, uint16_t y, uint16_t r, uint16_t color, uint16_t width, FILL fill);
void Gui_draw_char(uint16_t x, uint16_t y, const char str_char,FONT* Font, uint16_t color, uint16_t background);
void Gui_draw_str(uint16_t x, uint16_t y, const char *str_char, FONT* Font, uint16_t color, uint16_t background);
int Gui_show_bmp(const char *path);

#endif
