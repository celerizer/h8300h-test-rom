#ifndef STRIDE_BUTTONS_H
#define STRIDE_BUTTONS_H

/**
 * @brief Returns whether the main button is pressed.
 * Either the only button on the NTR027 or the center button on the NTR-032.
 */
unsigned char st_button_center(void);

/**
 * @brief Returns whether the left button is pressed.
 * Only available on the NTR-032.
 */
unsigned char st_button_left(void);

/**
 * @brief Returns whether the right button is pressed.
 * Only available on the NTR-032.
 */
unsigned char st_button_right(void);

#endif
