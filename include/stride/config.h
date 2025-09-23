#ifndef STRIDE_CONFIG_H
#define STRIDE_CONFIG_H

#define ST_SYSTEM_NTR027 1
#define ST_SYSTEM_NTR031 2
#define ST_SYSTEM_NTR032 3

#ifndef ST_SYSTEM
#define ST_SYSTEM ST_SYSTEM_NTR032
#endif

#if ST_SYSTEM == ST_SYSTEM_NTR032
  #define H8_STACK_TOP 0xff80
#else
  #define H8_STACK_TOP 0xf780
#endif

#endif
