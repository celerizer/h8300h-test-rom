#include "lcd.h"

#include "ssu.h"

void st_lcd_out_data(const unsigned char *buffer, unsigned length)
{
  /* Select LCD in data mode */
  *(unsigned char*)(0xffd4) = 0x06;

  st_ssu_out(buffer, length);

  /* Deselect LCD */
  *(unsigned char*)(0xffd4) = 0x05;
}

void st_lcd_out_single(unsigned char output)
{
  /* Select LCD */
  *(unsigned char*)(0xffd4) = 0x04;

  st_ssu_out_singleton(output);

  /* Deselect LCD */
  *(unsigned char*)(0xffd4) = 0x05;
}

void st_lcd_out_double(unsigned char command, unsigned char data)
{
  unsigned char buffer[2];

  buffer[0] = command;
  buffer[1] = data;

  /* Select LCD */
  *(unsigned char*)(0xffd4) = 0x04;

  st_ssu_out(buffer, 2);

  /* Deselect LCD */
  *(unsigned char*)(0xffd4) = 0x05;
}

void st_lcd_init(void)
{
  st_lcd_out_single(0xE2); /* Software reset */
  st_lcd_out_single(0xB0); /* Y offset */
  st_lcd_out_single(0xE1); /* Power save OFF */

  st_lcd_out_double(0x48, 0x40); /* Multiplex ratio */

  st_lcd_out_single(0xA0); /* Segment remap */
  st_lcd_out_single(0xC0); /* Y-flip OFF */

  st_lcd_out_double(0x44, 0x20); /* Display offset +32 */

  st_lcd_out_single(0xAB); /* Internal oscillator ON */
  st_lcd_out_single(0x67); /* DCDC factor */
  st_lcd_out_single(0x25); /* IRR ratio */

  st_lcd_out_double(0x81, 0x1A); /* Contrast */

  st_lcd_out_single(0x52); /* LCD bias */
  st_lcd_out_single(0x95); /* PWM */

  st_lcd_out_double(0x88, 0x00); /* Palette color 1 */
  st_lcd_out_double(0x89, 0x00); /* Palette color 2 */
  st_lcd_out_double(0x8A, 0x55); /* Palette color 3 */
  st_lcd_out_double(0x8B, 0x55); /* Palette color 4 */
  st_lcd_out_double(0x8C, 0x77); /* Palette color 5 */
  st_lcd_out_double(0x8D, 0x77); /* Palette color 6 */
  st_lcd_out_double(0x8E, 0x99); /* Palette color 7 */
  st_lcd_out_double(0x8F, 0x99); /* Palette color 8 */

  st_lcd_out_double(0x4C, 0x04); /* Nline inversion */

  st_lcd_out_double(0xF1, 0x00); /* Reserved */
  st_lcd_out_double(0xF7, 0x02); /* Reserved */
  st_lcd_out_double(0xF6, 0x0A); /* Reserved */

  st_lcd_out_single(0x2F); /* Power control */
  st_lcd_out_double(0x40, 0x00); /* Start line 0 */
  st_lcd_out_single(0xA6); /* Invert display OFF */
  st_lcd_out_double(0x81, 0x1F); /* Contrast */
}
