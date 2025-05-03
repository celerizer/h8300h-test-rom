ENTRY(_main)

SECTIONS
{
  . = 0x0000;

  .vectors : {
    *(.vectors)
  }

  . = 0x0050;

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
