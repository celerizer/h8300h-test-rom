#include "buttons.h"

#include "sys.h"

unsigned char st_button_center(void)
{
  return (*H8_PDR8 & 0x01) ? 1 : 0;
}

unsigned char st_button_left(void)
{
  return (*H8_PDR8 & 0x04) ? 1 : 0;
}

unsigned char st_button_right(void)
{
  return (*H8_PDR8 & 0x10) ? 1 : 0;
}
