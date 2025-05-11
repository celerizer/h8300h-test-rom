CC = h8300-hms-gcc
AS = h8300-hms-as
OBJCOPY = h8300-hms-objcopy

CFLAGS = -mh -nostdlib

# Allow switching with: make CONFIG=payload or make CONFIG=rom
CONFIG ?= rom

ifeq ($(CONFIG),payload)
LDSCRIPT = link_payload.ld
VECTOR_SRC = link_payload.S
MAX_SIZE = 2048
else
LDSCRIPT = link_rom.ld
VECTOR_SRC = link_rom.S
MAX_SIZE = 49152
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
	@size=$$(stat -c %s $@); \
	if [ "$$size" -gt $(MAX_SIZE) ]; then \
		echo "ERROR: Output binary size ($$size bytes) exceeds limit ($(MAX_SIZE) bytes) for CONFIG=$(CONFIG)!"; \
	fi

clean:
	rm -f *.o *.elf *.bin
