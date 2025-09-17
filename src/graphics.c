#include "../include/stride/graphics.h"

#include "../include/stride/lcd.h"

void st_gfx_fill_rect(unsigned mode, unsigned char x, unsigned char y,
  unsigned char width, unsigned char height)
{
  unsigned short value;
  unsigned char pos_y, pos_x;

  switch (mode)
  {
  case 0:
    value = 0x0000;
    break;
  case 1:
    value = 0x00FF;
    break;
  case 2:
    value = 0xFF00;
    break;
  case 3:
  default:
    value = 0xFFFF;
    break;
  }

  for (pos_y = y; pos_y < y + height / 8; pos_y++)
  {
    st_lcd_set_y(pos_y);
    st_lcd_set_x(x);

    for (pos_x = x; pos_x < x + width; pos_x++)
      st_lcd_out_data(&value, 2);
  }
}

void st_gfx_image(const unsigned char *image_data, unsigned x, unsigned y,
  unsigned width, unsigned height)
{
  unsigned char page;
  unsigned col;
  unsigned short row;

  for (page = 0; page < height / 8; page++)
  {
    st_lcd_set_y((y / 8) + page);
    st_lcd_set_x(x);

    for (col = 0; col < width; col++)
    {
      unsigned char data_a = *image_data++;
      unsigned char data_b = *image_data++;

      st_lcd_out_data(&data_a, 1);
      st_lcd_out_data(&data_b, 1);
    }
  }
}

void st_gfx_pixel(unsigned char x, unsigned char y, unsigned char color)
{
  unsigned char data_a, data_b;
  unsigned char mask = 1 << (y & 7);

  /* Set the cursor to the correct position */
  st_lcd_set_x(x);
  st_lcd_set_y(y / 8);

  /* Retrieve and edit the pixel */
  data_a = st_lcd_in_single() & ~mask;
  data_b = st_lcd_in_single() & ~mask;

  /* Set new bits from color */
  if (color & 0x02) data_a |= mask;
  if (color & 0x01) data_b |= mask;

  /* Write back the modified data */
  st_lcd_set_x(x);
  st_lcd_set_y(y / 8);
  st_lcd_out_data(&data_a, 1);
  st_lcd_out_data(&data_b, 1);
}
