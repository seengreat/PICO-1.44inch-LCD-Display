
#ifndef __FONTS_H
#define __FONTS_H
   
#include <stdint.h>

//ASCII
typedef struct tFont
{    
  const uint8_t *table;
  uint16_t size;
  uint16_t w; //width
  uint16_t h; //height
  
}FONT;

extern FONT Font16;
extern FONT Font24;

#endif 
 
