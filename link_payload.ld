OUTPUT_ARCH(h8300h)
ENTRY(_main)

SECTIONS
{
  . = 0xf780;

  .text : {
    *(.text)
  }

  .data : {
    *(.data)
  }

  .bss : {
    *(.bss)
  }
}
