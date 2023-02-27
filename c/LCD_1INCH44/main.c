/********************************
 *  Seengreat 1.44 Inch LCD Display demo
 *  Author(s):Andy Li from Seengreat
 * ********************/

#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "lcd_1inch44.h"
#include "lcd_gui.h"
#include "fonts.h"
#include "key.h"


/******************************
 * when set image in ROTATE_0:
 * 0------------> x (1~128) 
 * |
 * |
 * |
 * |
 * y (1~128)
 * 
 * */


int main(void)
{
	stdio_init_all();
	Image_Init(LCD_W, LCD_H, ROTATE_0, MIRROR_NONE);
	Key_Init();
	Lcd_Init();

	Gui_Clear(WHITE);
	Gui_draw_point(30, 18, RED, 6);
	Gui_draw_line(10, 15, 95, 15, BLUE, 1, SOLID);
	Gui_draw_line(5, 10, 5, 118, RED, 2, SOLID);
	Gui_draw_rectangle(105, 40, 125, 50, BLUE, 1, EMPTY);
	Gui_draw_circle(110, 20, 10, RED,1, EMPTY);
	Gui_draw_circle(110, 20, 5, YELLOW,1, FULL);
	Gui_draw_str(10, 30, "abc3210!", &Font16, BLACK, WHITE);
	Gui_draw_str(10, 60, "SEENGREAT!", &Font16, GREEN, WHITE);
	Gui_draw_str(10, 80, "1.44 Inch", &Font16, RED, WHITE);
	Display(Image.img);
	sleep_ms(1500);
	sleep_ms(1500);
	
	Key_Task();

	
}
