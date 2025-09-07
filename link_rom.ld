OUTPUT_ARCH(h8300h)
ENTRY(_main)

MEMORY
{
  ROM (rx ) : ORIGIN = 0x0000, LENGTH = 0xf020
  RAM (rwx) : ORIGIN = 0xf780, LENGTH = 0x0800
}

SECTIONS
{
  .vectors 0x0000 : {
    *(.vectors)
  } > ROM

  .text 0x0050 : {
    *(.text .text.*)
  } > ROM

  .rodata : {
    *(.rodata .rodata.*)
  } > ROM

  .data : AT(ADDR(.rodata) + SIZEOF(.rodata)) {
    _data_start = .;
    *(.data .data.*)
    _data_end = .;
  } > RAM
  _data_src_start = LOADADDR(.data);
  _data_src_end = LOADADDR(.data) + SIZEOF(.data);
  PROVIDE(_data_size = _data_end - _data_start);

  .bss : {
    _bss_start = .;
    *(.bss .bss.*)
    _bss_end = .;
  } > RAM
  PROVIDE(_bss_size = _bss_end - _bss_start);
}
