#include "ssu.h"

#include "sys.h"

void st_ssu_out(const unsigned char *buffer, unsigned int length)
{
  unsigned char dummy = 0;
  unsigned short i;

  /* Enable SSU transmit */
  *H8_SSCRH = 0x80;

  for (i = 0; i < length; i++)
  {
    /* Send the byte */
    *H8_SSRR = buffer[i];

    /* Wait for transmit data to be empty */
    do dummy = *H8_SSCRL;
    while (!(dummy & 0x04));
  }

  /* Disable SSU transmit */
  *H8_SSCRH = 0x00;
}

void st_ssu_out_singleton(unsigned char value)
{
  unsigned char dummy = 0;

  /* Enable SSU transmit */
  *H8_SSCRH = 0x80;

  *H8_SSRR = value;

  /* Wait for transmit data to be empty */
  do dummy = *H8_SSCRL;
  while (!(dummy & 0x04));

  /* Disable SSU transmit */
  *H8_SSCRH = 0x00;
}
