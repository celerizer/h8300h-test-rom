.h8300h
.global _crt0
.global _main
.global _null_handler

.section .vectors
.word _crt0 ; reset
.word _null_handler ; reserved1
.word _null_handler ; reserved2
.word _null_handler ; reserved3
.word _null_handler ; reserved4
.word _null_handler ; reserved5
.word _null_handler ; reserved6
.word _null_handler ; nmi
.word _null_handler ; trapa0
.word _null_handler ; trapa1
.word _null_handler ; trapa2
.word _null_handler ; trapa3
.word _null_handler ; reserved12
.word _null_handler ; sleep
.word _null_handler ; reserved14
.word _null_handler ; reserved15
.word _null_handler ; irq0
.word _null_handler ; irq1
.word _null_handler ; irqaec
.word _null_handler ; reserved19
.word _null_handler ; reserved20
.word _null_handler ; comp0
.word _null_handler ; comp1
.word _null_handler ; rtc_quarter_second
.word _null_handler ; rtc_half_second
.word _null_handler ; rtc_second
.word _null_handler ; rtc_minute
.word _null_handler ; rtc_hour
.word _null_handler ; rtc_day
.word _null_handler ; rtc_week
.word _null_handler ; rtc_free_running
.word _null_handler ; watchdog_timer
.word _null_handler ; async_event_counter
.word _null_handler ; timer_b1
.word _null_handler ; ssu_iic2
.word _null_handler ; timer_w
.word _null_handler ; reserved36
.word _null_handler ; sci3
.word _null_handler ; ad_conversion_end
.word _null_handler ; reserved39

.text
_null_handler:
  rte ; dummy handler: return from exception immediately

_crt0:
  mov.l #0xff80, er7 ; initialize stack pointer
  
  ; Transfer the data section from ROM to RAM
  start_data:
    mov.l #_data_src_start, er0
    mov.l #_data_start, er1
  start_data_loop:
    mov.l @er0+, er3 ; load from rom
    mov.l er3, @er1 ; store to ram
    adds.l #4, er1 ; increment
    cmp.l #_data_src_end, er0
      blt start_data_loop

  ; Zero-fill the BSS section
  start_bss:
    mov.l #_bss_end, er0
    mov.l #0, er1
  start_bss_loop:
    mov.b r1l, @-er0
    cmp.l #_bss_start, er0
      bne start_bss_loop

  ; Jump to user program
  jmp _main
