CC = h8300-hms-gcc
AS = h8300-hms-as
OBJCOPY = h8300-hms-objcopy

CFLAGS = -mh -mn -nostdlib

LDFLAGS = -m h8300h -T $(LDSCRIPT) -nostdlib

# Allow switching with: make CONFIG=payload or make CONFIG=rom
CONFIG ?= rom

SOURCES := \
	main.c \
	src/battery.c \
	src/buttons.c \
	src/eeprom.c \
	src/lcd.c \
	src/led.c \
	src/ssu.c \
	src/sys.c

OBJECTS := $(SOURCES:.c=.o)

ifeq ($(CONFIG),payload)
LDSCRIPT = link_payload.ld
VECTOR_SRC = link_payload.S
MAX_SIZE = 2048
CFLAGS += -Os -fomit-frame-pointer -ffunction-sections -fdata-sections
else
LDSCRIPT = link_rom.ld
VECTOR_SRC = link_rom.S
MAX_SIZE = 49152
endif

all: main.elf main.bin

main.elf: link.o $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

link.o: $(VECTOR_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

main.bin: main.elf
	$(OBJCOPY) -O binary $< $@
	@size=$$(stat -c %s $@); \
	if [ "$$size" -gt $(MAX_SIZE) ]; then \
		echo "ERROR: Output binary size ($$size bytes) exceeds limit ($(MAX_SIZE) bytes) for CONFIG=$(CONFIG)!"; \
	fi

clean:
	rm -f *.o *.elf *.bin
