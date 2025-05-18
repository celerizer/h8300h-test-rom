#include "led.h"

#include "sys.h"

void st_led_on(void)
{
  *H8_PDR8 |= 1;
}

void st_led_off(void)
{
  *H8_PDR8 &= ~1;
}

void st_led_green(void)
{
  *H8_PDR8 |= 2;
}

void st_led_red(void)
{
  *H8_PDR8 &= ~2;
}

int st_led_is_on(void)
{
  return (*H8_PDR8 & 1) ? 1 : 0;
}

int st_led_color(void)
{
  return (*H8_PDR8 & 2) ? ST_LED_COLOR_GREEN : ST_LED_COLOR_RED;
}
