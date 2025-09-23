.h8300h

#include <stride/config.h>

.global _main

.text
.global _start
_start:
  mov.l  #H8_STACK_TOP, er7 ; initialize stack pointer
  jmp _main ; jump to user program
