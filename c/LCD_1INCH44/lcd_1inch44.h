#ifndef __LCD_1INCH44_H
#define __LCD_1INCH44_H

#include "pico/stdlib.h"

#define LCD_W   128 //LCD width
#define LCD_H   128 //LCD height

#define PIN_CS   5   
#define PIN_RST  12   
#define PIN_DC   11   
#define PIN_BL   13   

#define PIN_CLK    6   
#define PIN_MOSI   7 

#define LCD_SIZE   (LCD_W*LCD_H*2)                  

#define CS(x)  gpio_put(PIN_CS, x)
#define RST(x) gpio_put(PIN_RST, x)
#define DC(x)  gpio_put(PIN_DC, x)

void Lcd_Gpio_Init(void);
void Lcd_Init(void); 
void Lcd_Clear(uint16_t Color);
void Display(uint16_t *image);
void Draw_Point(uint16_t x, uint16_t y, uint16_t Color);

void Spi_write_word(uint16_t da);
void Set_Cursor(uint16_t x, uint16_t y);
void Set_Window(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t  end_y);


#endif
