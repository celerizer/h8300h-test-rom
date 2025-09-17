#ifndef STRIDE_LCD_H
#define STRIDE_LCD_H

void st_lcd_init(void);

/**
 * @brief Send a buffer of data to the LCD.
 *
 * @param buffer Pointer to the data buffer to send.
 * @param length Length of the data buffer.
 */
void st_lcd_out_data(const void *buffer, unsigned length);

/**
 * @brief Send a single-byte command to the LCD.
 */
void st_lcd_out_single(unsigned char output);

/**
 * @brief Send a command and data to the LCD.
 */
void st_lcd_out_double(unsigned char command, unsigned char data);

/**
 * @brief Set the X (column) position of the LCD cursor.
 * @param x The X position (0-127).
 */
void st_lcd_set_x(unsigned char x);

/**
 * @brief Set the Y (page) position of the LCD cursor.
 * @param y The Y position (0-15).
 */
void st_lcd_set_y(unsigned char y);

unsigned char st_lcd_in_single(void);

#endif
