#include "../include/stride/sys.h"

#include "../include/stride/config.h"

#if ST_SYSTEM == ST_SYSTEM_NTR032
  #include "../include/stride/lcd.h"
#elif ST_SYSTEM == ST_SYSTEM_NTR027
  #include "../include/stride/led.h"
#else
  #error "Unsupported system. Please define STRIDE_SYSTEM as NTR032 or NTR027."
#endif

void st_init(void)
{
  st_lcd_init();
}
