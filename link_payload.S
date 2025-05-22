.h8300h
.global _main

.text
.global _start
_start:
  mov.l  #0xff80, er7 ; initialize stack pointer
  jmp _main ; jump to user program
