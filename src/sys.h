#ifndef STRIDE_SYSTEM_H
#define STRIDE_SYSTEM_H

#include "config.h"
#include "lcd.h"
#include "ssu.h"
#include "led.h"
#include "buttons.h"
#include "battery.h"

#define H8_REG8(a) ((volatile unsigned char*)a)
#define H8_REG16(a) ((volatile unsigned short*)a)

#define H8_SSCR H8_REG16(0xf0e3)
#define H8_SSCRH H8_REG8(0xf0e3)
#define H8_SSCRL H8_REG8(0xf0e4)
#define H8_SSRR H8_REG8(0xf0eb)

#define H8_ADRR H8_REG16(0xffbc)
#define H8_ADRRH H8_REG8(0xffbc)
#define H8_ADRRL H8_REG8(0xffbd)
#define H8_AMR H8_REG8(0xffbe)
#define H8_ADSR H8_REG8(0xffbf)

#define H8_PDR8 H8_REG8(0xffdb)

void st_sys_init(void);

#endif
