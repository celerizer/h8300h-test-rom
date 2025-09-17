#ifndef STRIDE_GRAPHICS_H
#define STRIDE_GRAPHICS_H

void st_gfx_fill_rect(unsigned mode, unsigned char x, unsigned char y,
  unsigned char width, unsigned char height);

/**
 * @brief Modifies the color of a single pixel on the display. This is a slow
 * method and should not be used for drawing large areas.
 * @param x The X coordinate of the pixel (0-127).
 * @param y The Y coordinate of the pixel (0-63).
 * @param color The color to set the pixel to (0-3).
 */
void st_gfx_pixel(unsigned char x, unsigned char y, unsigned char color);

/**
 * @brief Draws a bitmap image onto the display at the specified coordinates.
 * @param image_data Pointer to the image data in memory.
 * @param x The X coordinate (0-95).
 * @param y The Y coordinate (0-63, must be a multiple of 8).
 * @param width The width of the image (in pixels).
 * @param height The height of the image (in pixels, must be a multiple of 8).
 */
void st_gfx_image(const unsigned char *image_data, unsigned x, unsigned y,
  unsigned width, unsigned height);

#endif
