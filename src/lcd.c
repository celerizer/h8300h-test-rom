#include "lcd.h"

#include "ssu.h"
#include "sys.h"

unsigned char st_lcd_in_single(void)
{
  unsigned char value;

  /* Select LCD in data mode */
  *H8_PDR1 = 0x06;

  value = st_ssu_in_singleton();

  /* Deselect LCD */
  *H8_PDR1 = 0x05;

  return value;
}

void st_lcd_out_data(const void *buffer, unsigned length)
{
  /* Select LCD in data mode */
  *H8_PDR1 = 0x06;

  st_ssu_out(buffer, length);

  /* Deselect LCD */
  *H8_PDR1 = 0x05;
}

void st_lcd_out_single(unsigned char output)
{
  /* Select LCD */
  *H8_PDR1 = 0x04;

  st_ssu_out_singleton(output);

  /* Deselect LCD */
  *H8_PDR1 = 0x05;
}

void st_lcd_out_double(unsigned char command, unsigned char data)
{
  unsigned char buffer[2];

  buffer[0] = command;
  buffer[1] = data;

  /* Select LCD */
  *H8_PDR1 = 0x04;

  st_ssu_out(buffer, 2);

  /* Deselect LCD */
  *H8_PDR1 = 0x05;
}

static const unsigned char init_sequence[] =
{
  0xE2, /* Software reset */
  0xB0, /* Y offset */
  0xE1, /* Power save OFF */

  0x48, 0x40, /* Multiplex ratio */

  0xA0, /* Segment remap */
  0xC0, /* Y-flip OFF */

  0x44, 0x20, /* Display offset +32 */

  0xAB, /* Internal oscillator ON */
  0x67, /* DCDC factor */
  0x25, /* IRR ratio */

  0x81, 0x1A, /* Contrast */

  0x52, /* LCD bias */
  0x95, /* PWM */

  0x88, 0x00, /* Palette color 1 */
  0x89, 0x00, /* Palette color 2 */
  0x8A, 0x55, /* Palette color 3 */
  0x8B, 0x55, /* Palette color 4 */
  0x8C, 0x77, /* Palette color 5 */
  0x8D, 0x77, /* Palette color 6 */
  0x8E, 0x99, /* Palette color 7 */
  0x8F, 0x99, /* Palette color 8 */

  0x4C, 0x04, /* Nline inversion */

  0xF1, 0x00, /* Reserved */
  0xF7, 0x02, /* Reserved */
  0xF6, 0x0A, /* Reserved */

  0x2F, /* Power control */
  0x40, 0x00, /* Start line 0 */
  0xA6, /* Invert display OFF */
  0x81, 0x1F, /* Contrast */
};

void st_lcd_init(void)
{
  unsigned i;

  for (i = 0; i < sizeof(init_sequence); i++)
    st_lcd_out_single(init_sequence[i]);
}

void st_lcd_set_x(unsigned char x)
{
  st_lcd_out_single(0x00 | (x & 0x0F));
  st_lcd_out_single(0x10 | ((x >> 4) & 0x0F));
}

void st_lcd_set_y(unsigned char y)
{
  st_lcd_out_single(0xB0 | y);
}
