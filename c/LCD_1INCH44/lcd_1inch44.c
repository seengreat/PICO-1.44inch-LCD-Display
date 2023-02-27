/********************************
 *  Seengreat 1.44 Inch LCD Display demo
 *  Author(s):Andy Li from Seengreat
 * ********************************/
 
#include <string.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"	
#include "hardware/spi.h"
#include "hardware/pwm.h"
#include "lcd_1inch44.h"

void Lcd_Gpio_Init(void)
{
	printf("Init gpio for pico lcd\r\n");
    gpio_init(PIN_CS);
    gpio_set_dir(PIN_CS, GPIO_OUT);

    gpio_init(PIN_CS);
    gpio_set_dir(PIN_CS, GPIO_OUT);
	gpio_init(PIN_RST);
    gpio_set_dir(PIN_RST, GPIO_OUT);
	gpio_init(PIN_DC);
    gpio_set_dir(PIN_DC, GPIO_OUT);
	// gpio_init(PIN_BL);
    // gpio_set_dir(PIN_BL, GPIO_OUT);

	    /* Select spix  Set spi baud rate */
    spi_init(spi0, 10000 * 1000);
    gpio_set_function(PIN_CLK, GPIO_FUNC_SPI);
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);

	gpio_set_function(PIN_BL, GPIO_FUNC_PWM);
	uint slice_num = pwm_gpio_to_slice_num(PIN_BL);
	pwm_set_wrap(slice_num, 100);
	pwm_set_chan_level(slice_num, PWM_CHAN_A, 40);
	pwm_set_chan_level(slice_num, PWM_CHAN_B, 80);
	pwm_set_enabled(slice_num, true);

}

/*******************************************************************************
function:
	Hardware reset
*******************************************************************************/
static void Lcd_Reset(void)
{
	CS(1);
	sleep_ms(100);
	RST(0);
	sleep_ms(100);
	RST(1);
	sleep_ms(100);
}

/*******************************************************************************
function:
		Write data and commands
*******************************************************************************/
static void Spi_write_cmd(uint8_t data)	 
{	
	CS(0);
	DC(0);
	spi_write_blocking(spi0, &data, 1);
}

static void Spi_write_data(uint8_t data) 
{	
	CS(0);
	DC(1);
	spi_write_blocking(spi0, &data, 1);
	CS(1);
}  

void Spi_write_word(uint16_t data)
{
	uint8_t temp = 0;
	CS(0);
	DC(1);
	temp = (data>>8) & 0xff;
	spi_write_blocking(spi0, &temp, 1);
	temp = data & 0xff;
	spi_write_blocking(spi0, &temp, 1);
	CS(1);
}	  


/******************************************************************************
function:	
		Common register initialization
******************************************************************************/
void Lcd_Init(void)
{
	Lcd_Gpio_Init();
	Lcd_Reset();

	Spi_write_cmd(0x01);
	sleep_ms(20); 

	Spi_write_cmd(0x11); 
	sleep_ms(50); 

	Spi_write_cmd(0xB1);
	Spi_write_data(0x02);
	Spi_write_data(0x35);
	Spi_write_data(0x36);

	Spi_write_cmd(0xB2);
	Spi_write_data(0x02);
	Spi_write_data(0x35);
	Spi_write_data(0x36);

	Spi_write_cmd(0xB3);
	Spi_write_data(0x02);
	Spi_write_data(0x35);
	Spi_write_data(0x36);
	Spi_write_data(0x02);
	Spi_write_data(0x35);
	Spi_write_data(0x36);

	Spi_write_cmd(0xB4);
	Spi_write_data(0x03); 

	Spi_write_cmd(0xBB);
	Spi_write_data(0x1F);

	Spi_write_cmd(0xC0);
	Spi_write_data(0xA2);
	Spi_write_data(0x02);
	Spi_write_data(0x84);

	Spi_write_cmd(0xC1);
	Spi_write_data(0xC5);

	Spi_write_cmd(0xC2);
	Spi_write_data(0x0D);
	Spi_write_data(0x00);
	
	Spi_write_cmd(0xC3);
	Spi_write_data(0x8D);   
	Spi_write_data(0x2A);   

	Spi_write_cmd(0xC4);
	Spi_write_data(0x8D);
	Spi_write_data(0xEE);

	Spi_write_cmd(0xC5);
	Spi_write_data(0x0A); 

	Spi_write_cmd(0x36);
	Spi_write_data(0x68); 

	Spi_write_cmd(0xE0);
	Spi_write_data(0x12);
	Spi_write_data(0x1C);
	Spi_write_data(0x10);
	Spi_write_data(0x18);
	Spi_write_data(0x33);
	Spi_write_data(0x2C);
	Spi_write_data(0x25);
	Spi_write_data(0x28);
	Spi_write_data(0x28);
	Spi_write_data(0x27);
	Spi_write_data(0x2F);
	Spi_write_data(0x3C);
	Spi_write_data(0x00);
	Spi_write_data(0x03);
	Spi_write_data(0x03);
	Spi_write_data(0x10);

	Spi_write_cmd(0xE1);
	Spi_write_data(0x12);
	Spi_write_data(0x1C);
	Spi_write_data(0x10);
	Spi_write_data(0x18);
	Spi_write_data(0x2D);
	Spi_write_data(0x28);
	Spi_write_data(0x23);
	Spi_write_data(0x28);
	Spi_write_data(0x28);
	Spi_write_data(0x26);
	Spi_write_data(0x2F);
	Spi_write_data(0x3B);
	Spi_write_data(0x00);
	Spi_write_data(0x03);
	Spi_write_data(0x03);
	Spi_write_data(0x10);
	
	Spi_write_cmd(0xF0);
	Spi_write_data(0x01);

	Spi_write_cmd(0xF6);
	Spi_write_data(0x00);

	Spi_write_cmd(0x3A);
	Spi_write_data(0x05);
	

	Spi_write_cmd(0x29);
	sleep_ms(50);
}


//select the srceen area(from point(start_x,start_y) to point(end_x,end_y))
void Set_Window(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t  end_y)
{ 
	start_x += 1;
	end_x += 1;
	start_y += 2;
	end_y += 2;
	Spi_write_cmd(0x2a);
	Spi_write_data(start_x >>8);
	Spi_write_data(start_x & 0xff);
	Spi_write_data(end_x >> 8);
	Spi_write_data(end_x & 0xff);

	Spi_write_cmd(0x2b);
	Spi_write_data(start_y >>8);
	Spi_write_data(start_y & 0xff);
	Spi_write_data(end_y >> 8);
	Spi_write_data(end_y & 0xff);

	Spi_write_cmd(0x2C);
}


//set cursor to the point(x, y)
void Set_Cursor(uint16_t x, uint16_t y)
{ 
	x += 1;
	y += 2;
	Spi_write_cmd(0x2a);
	Spi_write_data(x >> 8);
	Spi_write_data(x);
	Spi_write_data(x >> 8);
	Spi_write_data(x);

	Spi_write_cmd(0x2b);
	Spi_write_data(y >> 8);
	Spi_write_data(y);
	Spi_write_data(y >> 8);
	Spi_write_data(y);

	Spi_write_cmd(0x2C);
}

//refresh the entire screen to color
void Lcd_Clear(uint16_t color)
{
	uint16_t i;
	uint16_t image[LCD_W];
	for(i=0;i<LCD_W;i++)
	{
		image[i] = color>>8 | (color&0xff)<<8;
	}
	uint8_t *p = (uint8_t *)(image);
	Set_Window(0, 0, LCD_W-1, LCD_H-1);
	DC(1);
	for(i = 0; i < LCD_H; i++)
	{
		spi_write_blocking(spi0, (unsigned char *)p, LCD_W*2);
	}
}


//display the image to whole screen 
void Display(uint16_t *image)
{
	uint16_t i;
	uint16_t p[LCD_SIZE];
    memcpy(p,image,LCD_SIZE);
	Set_Window(0, 0, LCD_W-1, LCD_H-1);
	DC(1);
	for(i = 0; i < LCD_H; i++)
	{
		spi_write_blocking(spi0, (unsigned char *)p+LCD_W*2*i, LCD_W*2);
		
	}
}

//set the point(x,y) to color
void Draw_Point(uint16_t x, uint16_t y, uint16_t Color)
{
	Set_Cursor(x, y);
	Spi_write_word(Color); 	    
}

