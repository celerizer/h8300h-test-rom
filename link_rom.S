.h8300h
.section .vectors
.global _main

.word _main ; Reset vector
.word 0 ; reserved1
.word 0 ; reserved2
.word 0 ; reserved3
.word 0 ; reserved4
.word 0 ; reserved5
.word 0 ; reserved6
.word 0 ; nmi
.word 0 ; trapa0
.word 0 ; trapa1
.word 0 ; trapa2
.word 0 ; trapa3
.word 0 ; reserved12
.word 0 ; sleep
.word 0 ; reserved14
.word 0 ; reserved15
.word 0 ; irq0
.word 0 ; irq1
.word 0 ; irqaec
.word 0 ; reserved19
.word 0 ; reserved20
.word 0 ; comp0
.word 0 ; comp1
.word 0 ; rtc_quarter_second
.word 0 ; rtc_half_second
.word 0 ; rtc_second
.word 0 ; rtc_minute
.word 0 ; rtc_hour
.word 0 ; rtc_day
.word 0 ; rtc_week
.word 0 ; rtc_free_running
.word 0 ; watchdog_timer
.word 0 ; async_event_counter
.word 0 ; timer_b1
.word 0 ; ssu_iic2
.word 0 ; timer_w
.word 0 ; reserved36
.word 0 ; sci3
.word 0 ; ad_conversion_end
.word 0 ; reserved39

.text
.global _start
_start:
  mov.l  #0xff80, er7 ; initialize stack pointer
  jsr _main ; jump to user program
  rte
