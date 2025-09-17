#ifndef STRIDE_LED_H
#define STRIDE_LED_H

#define ST_LED_COLOR_RED   0x01
#define ST_LED_COLOR_GREEN 0x02

void st_led_on(void);
void st_led_off(void);
void st_led_green(void);
void st_led_red(void);
int st_led_is_on(void);
int st_led_color(void);

#endif
