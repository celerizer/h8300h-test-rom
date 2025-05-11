CC = h8300-hms-gcc
AS = h8300-hms-as
OBJCOPY = h8300-hms-objcopy

CFLAGS = -mh -nostdlib

# Allow switching with: make CONFIG=payload or make CONFIG=rom
CONFIG ?= rom

ifeq ($(CONFIG),payload)
LDSCRIPT = link_payload.ld
VECTOR_SRC = link_payload.S
else
LDSCRIPT = link_rom.ld
VECTOR_SRC = link_rom.S
endif

LDFLAGS = -mh -T $(LDSCRIPT) -nostdlib

all: main.elf main.bin

main.elf: link.o main.o
	$(CC) $(LDFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

link.o: $(VECTOR_SRC)
	$(AS) -o $@ $<

main.bin: main.elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f *.o *.elf *.bin
