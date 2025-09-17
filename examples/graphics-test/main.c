#include <stride/sys.h>

static const unsigned short colors[4] = { 0x0000, 0xFF00, 0x00FF, 0xFFFF };

static unsigned char x_pos = 0;
static unsigned char y_pos = 0;
static unsigned char color_index = 1;
static unsigned char button_left = 0;
static unsigned char button_right = 0;
static unsigned char button_center = 0;
static unsigned char prev_left = 0;
static unsigned char prev_right = 0;
static unsigned char prev_center = 0;

const unsigned char sineTable[64] = {
    0, 1, 3, 4, 6, 7, 9, 10,
    11, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 26,
    27, 28, 28, 29, 29, 30, 30, 31,
    31, 31, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 31, 31, 31,
    30, 30, 29, 29, 28, 28, 27, 26,
    26, 25, 24, 23, 22, 21, 20, 19
};

void demo_sinewave_int(void)
{
    int t = 0;
    int x, y;

    while (1)
    {
        for (x = 0; x < 128; x++)
        {
            // Compute index into sine table
            int idx = (x + t) & 63;   // wrap around 0–63
            y = 32 + sineTable[idx];  // center at y=32

            int color = ((x + t) >> 3) & 3; // cycle 4 colors

            st_gfx_pixel(x, y, 0);
        }

        t++; // scroll wave

        // optional: delay for visible animation
    }
}


__attribute__((noreturn)) int main(void)
{
  int i = 0, j = 0;

  st_init();

#if 1
  while (1)
  {
    button_center = st_button_center();

    if (button_center && !prev_center)
    {
      color_index++;
      color_index %= 4;
    }

    prev_center = button_center;

    st_gfx_fill_rect(color_index, 0, 0, 96, 64);
  }
#else
  demo_sinewave_int();
#endif
}
