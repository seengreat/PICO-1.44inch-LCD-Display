#ifndef __KEY_H
#define __KEY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//define the key button pin in wiringpi number
#define PIN_K1      8
#define PIN_K2      4
#define PIN_K3      3
#define PIN_K4      2
#define PIN_UP      18
#define PIN_LEFT    16
#define PIN_DOWN    20
#define PIN_RIGHT   19
#define PIN_CENTER  17

void Key_Init(void);
void Key_Task(void);


#endif

