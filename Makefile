CC = h8300-hms-gcc
AS = h8300-hms-as
OBJCOPY = h8300-hms-objcopy

CFLAGS = -mh -mn -nostdlib

LDFLAGS = -m h8300h -T $(LDSCRIPT) -nostdlib

# The type of build to create: either a small payload to be injected into RAM
# via IR, or a ROM image.
# Valid options are: payload, rom
CONFIG ?= rom

# Set this to the name of the target system.
# Valid options are: ntr027, ntr032
SYSTEM ?= ntr032

# Set this to the name of the target binary.
TARGET ?= main

ifeq ($(SYSTEM),ntr027)
CFLAGS += -DST_SYSTEM=ST_SYSTEM_NTR027
else ifeq ($(SYSTEM),ntr032)
CFLAGS += -DST_SYSTEM=ST_SYSTEM_NTR032
else
$(error Unknown SYSTEM specified: $(SYSTEM))
endif

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
BIN_EXT = payload
ifeq ($(SYSTEM),ntr027)
MAX_SIZE = 1024
else ifeq ($(SYSTEM),ntr032)
MAX_SIZE = 2048
endif
CFLAGS += -Os -fomit-frame-pointer -ffunction-sections -fdata-sections
else
LDSCRIPT = link_rom.ld
VECTOR_SRC = link_rom.S
BIN_EXT = bin
ifeq ($(SYSTEM),ntr027)
MAX_SIZE = 16384
else ifeq ($(SYSTEM),ntr032)
MAX_SIZE = 49152
endif
endif

all: $(TARGET).elf $(TARGET).$(BIN_EXT)

$(TARGET).elf: link.o $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

link.o: $(VECTOR_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).$(BIN_EXT): $(TARGET).elf
	$(OBJCOPY) -O binary $< $@
	@size=$$(stat -c %s $@); \
	if [ "$$size" -gt $(MAX_SIZE) ]; then \
		echo "ERROR: Output binary size ($$size bytes) exceeds limit ($(MAX_SIZE) bytes) for CONFIG=$(CONFIG)!"; \
	fi

clean:
	rm -f *.o *.elf *.bin
