#include "battery.h"

#include "sys.h"

unsigned short st_battery_level(void)
{
  /** @todo actually pull new data */
  
  return *H8_ADRR;
}
