#ifndef STRIDE_LCD_H
#define STRIDE_LCD_H

void st_lcd_init(void);

/**
 * @brief Send a buffer of data to the LCD.
 *
 * @param buffer Pointer to the data buffer to send.
 * @param length Length of the data buffer.
 */
void st_lcd_out_data(const unsigned char *buffer, unsigned length);

/**
 * @brief Send a single-byte command to the LCD.
 */
void st_lcd_out_single(unsigned char output);

/**
 * @brief Send a command and data to the LCD.
 */
void st_lcd_out_double(unsigned char command, unsigned char data);

#endif
