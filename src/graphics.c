#include "graphics.h"

#define LCD_STATUS (*(volatile unsigned char*)0xF0E4)
#define LCD_DATA (*(volatile unsigned char*)0xF0EB)
#define LCD_CONTROL (*(volatile unsigned char*)0x00D4)

#define LCD_BUSY2 (1 << 2)
#define LCD_BUSY3 (1 << 3)

void st_gfx_fill_rect(unsigned char mode, unsigned short width, unsigned short height)
{
  unsigned char value;
  unsigned short y, x;

  switch (mode)
  {
  case 0:
    value = 0x00;
    break;
  case 1:
    value = (x % 2 == 0) ? 0x00 : 0xFF;
    break;
  case 2:
    value = (x % 2 == 0) ? 0xFF : 0x00;
    break;
  case 3:
  default:
    value = 0xFF;
    break;
  }

  for (y = 0; y < height; y++)
  {
    for (x = 0; x < width; x++)
    {
      while (LCD_STATUS & LCD_BUSY2);
      LCD_DATA = value;
    }
    
    while (LCD_STATUS & LCD_BUSY3);
  }

  LCD_CONTROL |= 0x01;
}
