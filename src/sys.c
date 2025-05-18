#include "sys.h"

#include "config.h"

#if ST_SYSTEM == ST_SYSTEM_NTR032
  #include "lcd.h"
#elif ST_SYSTEM == ST_SYSTEM_NTR027
  #include "led.h"
#else
  #error "Unsupported system. Please define STRIDE_SYSTEM as NTR032 or NTR027."
#endif

void st_init(void)
{
  st_lcd_init();
}
