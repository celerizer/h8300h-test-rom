#ifndef STRIDE_BUTTONS_H
#define STRIDE_BUTTONS_H

/**
 * @brief Returns whether the main button is pressed.
 * Either the only button on the NTR027 or the center button on the NTR-032.
 * @return Non-zero if the button is pressed, zero otherwise.
 */
#define st_button_center() ((*H8_PDRB) & 0x01)

/**
 * @brief Returns whether the left button is pressed.
 * Only available on the NTR-032.
 * @return Non-zero if the button is pressed, zero otherwise.
 */
#define st_button_left() ((*H8_PDRB) & 0x04)

/**
 * @brief Returns whether the right button is pressed.
 * Only available on the NTR-032.
 * @return Non-zero if the button is pressed, zero otherwise.
 */
#define st_button_right() ((*H8_PDRB) & 0x10)

static inline void st_button_poll(void);

static inline unsigned char st_button_center_pressed(void);

static inline unsigned char st_button_left_pressed(void);

static inline unsigned char st_button_right_pressed(void);

#endif
