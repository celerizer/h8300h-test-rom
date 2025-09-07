#include "buttons.h"

#include "sys.h"

static unsigned char button_state;
static unsigned char prev_button_state;

static inline void st_button_poll(void)
{
  prev_button_state = button_state;
  button_state = *H8_PDRB;
}

static inline unsigned char st_button_center_pressed(void)
{
  return ((button_state & 0x01) && !(prev_button_state & 0x01));
}

static inline unsigned char st_button_left_pressed(void)
{
  return ((button_state & 0x04) && !(prev_button_state & 0x04));
}

static inline unsigned char st_button_right_pressed(void)
{
  return ((button_state & 0x10) && !(prev_button_state & 0x10));
}
