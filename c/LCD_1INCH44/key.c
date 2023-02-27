/********************************
 *  Seengreat 1.44 Inch LCD Display demo
 *  Author(s):Andy Li from Seengreat
 * ********************/
 
#include <string.h>
#include <stdlib.h>		

#include "lcd_gui.h"
#include "lcd_1inch44.h"
#include "key.h"

	
void Key_Init(void)
{
    
    printf("Key Init\r\n");
    gpio_init(PIN_K1);
    gpio_set_dir(PIN_K1, GPIO_IN);
	gpio_pull_up(PIN_K1);
    gpio_init(PIN_K2);
    gpio_set_dir(PIN_K2, GPIO_IN);
	gpio_pull_up(PIN_K2);
    gpio_init(PIN_K3);
    gpio_set_dir(PIN_K3, GPIO_IN);
	gpio_pull_up(PIN_K3);
    gpio_init(PIN_K4);
    gpio_set_dir(PIN_K4, GPIO_IN);
	gpio_pull_up(PIN_K4);
    gpio_init(PIN_UP);
    gpio_set_dir(PIN_UP, GPIO_IN);
	gpio_pull_up(PIN_UP);
    gpio_init(PIN_DOWN);
    gpio_set_dir(PIN_DOWN, GPIO_IN);
	gpio_pull_up(PIN_DOWN);
    gpio_init(PIN_LEFT);
    gpio_set_dir(PIN_LEFT, GPIO_IN);
	gpio_pull_up(PIN_LEFT);
    gpio_init(PIN_RIGHT);
    gpio_set_dir(PIN_RIGHT, GPIO_IN);
	gpio_pull_up(PIN_RIGHT);
    gpio_init(PIN_CENTER);
    gpio_set_dir(PIN_CENTER, GPIO_IN);
	gpio_pull_up(PIN_CENTER);

}

void Key_Task(void)
{
	Gui_Clear(WHITE);
	Gui_draw_rectangle(95, 16, 115, 31, BLACK, 1, FULL); //K1
	Gui_draw_rectangle(95, 43, 115, 58, BLACK, 1, FULL); //K2
	Gui_draw_rectangle(95, 70, 115, 85, BLACK, 1, FULL);//K3
	Gui_draw_rectangle(95, 97, 115, 112, BLACK, 1, FULL);//K4
	Gui_draw_rectangle(30, 40, 50, 50, BLACK, 1, FULL); //UP
	Gui_draw_rectangle(18, 52, 28, 72, BLACK, 1, FULL); //LEFT
	Gui_draw_rectangle(52, 52, 62, 72, BLACK, 1, FULL);//RIGHT
	Gui_draw_rectangle(30, 74, 50, 84, BLACK, 1, FULL); //DOWN
	Gui_draw_circle(40, 62, 10, BLACK, 1, FULL);// CENTER
	Display(Image.img);
	int k1_flag = 0;
	int k2_flag = 0;
	int k3_flag = 0;
	int k4_flag = 0;
	int center_flag = 0;
	int up_flag = 0;
	int left_flag = 0;
	int right_flag = 0;
	int down_flag = 0;
	printf("Key Task\r\n");
	for(;;)
	{
	    //K1 key
	    if(gpio_get(PIN_K1) == 0 && k1_flag == 0)
	    {
	        sleep_ms(10);
            if(gpio_get(PIN_K1) == 0) // make sure the button has been pressed
            {
				 k1_flag = 1;
				 Gui_draw_rectangle(95, 16, 115, 31, GREEN, 1, FULL);
				 Display(Image.img);
				 printf("K1 Press\r\n");
			}
	    }
		else if(gpio_get(PIN_K1) == 1 && k1_flag == 1) // key has been released
		{
			k1_flag = 0;
			Gui_draw_rectangle(95, 16, 115, 31, BLACK, 1, FULL);
			Display(Image.img);
	    }
        //K2 key
	    if(gpio_get(PIN_K2) == 0 && k2_flag == 0)
	    {
	        sleep_ms(10);
			if(gpio_get(PIN_K2) == 0) // make sure the button has been pressed
			{
				 k2_flag = 1;
				 Gui_draw_rectangle(95, 43, 115, 58, GREEN, 1, FULL);
				 Display(Image.img);
				 printf("K2 Press\r\n");
			}
	    }
		else if(gpio_get(PIN_K2) == 1 && k2_flag == 1) // key has been released
		{
			k2_flag = 0;
			Gui_draw_rectangle(95, 43, 115, 58, BLACK, 1, FULL);
			Display(Image.img);
	    }
	    //K3 key
	    if(gpio_get(PIN_K3) == 0 && k3_flag == 0)
	    {
	        sleep_ms(10);
			if(gpio_get(PIN_K3) == 0) // make sure the button has been pressed
			{
				 k3_flag = 1;
				 Gui_draw_rectangle(95, 70, 115, 85, GREEN, 1, FULL);
				 Display(Image.img);
				 printf("K3 Press\r\n");
			}
	    }
		else if(gpio_get(PIN_K3) == 1 && k3_flag == 1) // key has been released
		{
			k3_flag = 0;
			Gui_draw_rectangle(95, 70, 115, 85, BLACK, 1, FULL);
			Display(Image.img);
	    }

	    //K4 key
	    if(gpio_get(PIN_K4) == 0 && k4_flag == 0)
	    {
	        sleep_ms(10);
			if(gpio_get(PIN_K4) == 0) // make sure the button has been pressed
			{
				 k4_flag = 1;
				 Gui_draw_rectangle(95, 97, 115, 112, GREEN, 1, FULL);
				 Display(Image.img);
				 printf("K4 Press\r\n");
			}
	    }
		else if(gpio_get(PIN_K4) == 1 && k4_flag == 1) // key has been released
		{
			k4_flag = 0;
			Gui_draw_rectangle(95, 97, 115, 112, BLACK, 1, FULL);
			Display(Image.img);
	    }

	    //UP key
	    if(gpio_get(PIN_UP) == 0 && up_flag == 0)
	    {
	        sleep_ms(10);
			if(gpio_get(PIN_UP) == 0) // make sure the button has been pressed
			{
				 up_flag = 1;
				 Gui_draw_rectangle(30, 40, 50, 50, GREEN, 1, FULL);
				 Display(Image.img);
				 printf("UP Press\r\n");
			}
	    }
		else if(gpio_get(PIN_UP) == 1 && up_flag == 1) // key has been released
		{
			up_flag = 0;
			Gui_draw_rectangle(30, 40, 50, 50, BLACK, 1, FULL);
			Display(Image.img);
	    }

	    //LEFT key
	    if(gpio_get(PIN_LEFT) == 0 && left_flag == 0)
	    {
	        sleep_ms(10);
			if(gpio_get(PIN_LEFT) == 0) // make sure the button has been pressed
			{
				 left_flag = 1;
				 Gui_draw_rectangle(18, 52, 28, 72, GREEN, 1, FULL);
				 Display(Image.img);
				 printf("LEFT Press\r\n");
			}
	    }
		else if(gpio_get(PIN_LEFT) == 1 && left_flag == 1) // key has been released
		{
			left_flag = 0;
			Gui_draw_rectangle(18, 52, 28, 72, BLACK, 1, FULL);
			Display(Image.img);
	    }
	    
	    //RIGHT key
	    if(gpio_get(PIN_RIGHT) == 0 && right_flag == 0)
	    {
	        sleep_ms(10);
			if(gpio_get(PIN_RIGHT) == 0) // make sure the button has been pressed
			{
				 right_flag = 1;
				 Gui_draw_rectangle(52, 52, 62, 72, GREEN, 1, FULL);
				 Display(Image.img);
				 printf("RIGHT Press\r\n");
			}
	    }
		else if(gpio_get(PIN_RIGHT) == 1 && right_flag == 1) // key has been released
		{
			right_flag = 0;
			Gui_draw_rectangle(52, 52, 62, 72, BLACK, 1, FULL);
			Display(Image.img);
	    }

	    //DOWN key
	    if(gpio_get(PIN_DOWN) == 0 && down_flag == 0)
	    {
	        sleep_ms(10);
			if(gpio_get(PIN_DOWN) == 0) // make sure the button has been pressed
			{
				 down_flag = 1;
				 Gui_draw_rectangle(30, 74, 50, 84, GREEN, 1, FULL);
				 Display(Image.img);
				 printf("DOWN Press\r\n");
			}
	    }
		else if(gpio_get(PIN_DOWN) == 1 && down_flag == 1) // key has been released
		{
			down_flag = 0;
			Gui_draw_rectangle(30, 74, 50, 84, BLACK, 1, FULL);
			Display(Image.img);
	    }
	    //CENTER key
	    if(gpio_get(PIN_CENTER) == 0 && center_flag == 0)
	    {
	        sleep_ms(10);
			if(gpio_get(PIN_CENTER) == 0) // make sure the button has been pressed
			{
				 center_flag = 1;
				 Gui_draw_circle(40, 62, 10, GREEN, 1, FULL);
				 Display(Image.img);
				 printf("Center Press\r\n");
			}
	    }
		else if(gpio_get(PIN_CENTER) == 1 && center_flag == 1) // key has been released
		{
			center_flag = 0;
			Gui_draw_circle(40, 62, 10, BLACK, 1, FULL);
			Display(Image.img);
	    }

    } 		
}
