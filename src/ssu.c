#include "../include/stride/ssu.h"

#include "../include/stride/sys.h"

unsigned char st_ssu_in_singleton(void)
{
  unsigned char dummy = 0;

  /* Enable SSU receive */
  *H8_SSCRH = 0x40;

  /* Wait for receive data to be ready */
  do dummy = *H8_SSCRL;
  while (!(dummy & 0x01));

  /* Read the received byte */
  dummy = *H8_SSRDR;

  /* Disable SSU receive */
  *H8_SSCRH = 0x00;

  return dummy;
}

void st_ssu_out(const void *buffer, unsigned int length)
{
  unsigned char dummy = 0;
  unsigned short i;

  /* Enable SSU transmit */
  *H8_SSCRH = 0x80;

  for (i = 0; i < length; i++)
  {
    /* Send the byte */
    *H8_SSRR = ((unsigned char*)buffer)[i];

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
