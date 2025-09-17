CC = h8300-hms-gcc
AS = h8300-hms-as
OBJCOPY = h8300-hms-objcopy

STRIDE_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

CFLAGS = -mh -nostdlib -Os -ffunction-sections -fdata-sections -I$(STRIDE_DIR)/include

LDFLAGS = -m h8300h -T $(LDSCRIPT) -nostdlib -Wl,--gc-sections

# The type of build to create: either a small payload to be injected into RAM
# via IR, or a ROM image.
# Valid options are: payload, rom
CONFIG ?= rom

# Set this to the name of the target system.
# Valid options are: ntr027, ntr032
SYSTEM ?= ntr032

# Set this to the name of the target binary.
TARGET ?= main

MAPFILE = $(TARGET).map

ifeq ($(SYSTEM),ntr027)
CFLAGS += -DST_SYSTEM=ST_SYSTEM_NTR027
else ifeq ($(SYSTEM),ntr032)
CFLAGS += -DST_SYSTEM=ST_SYSTEM_NTR032
else
$(error Unknown SYSTEM specified: $(SYSTEM))
endif

SOURCES += \
	$(STRIDE_DIR)/src/battery.c \
	$(STRIDE_DIR)/src/buttons.c \
	$(STRIDE_DIR)/src/eeprom.c \
	$(STRIDE_DIR)/src/graphics.c \
	$(STRIDE_DIR)/src/lcd.c \
	$(STRIDE_DIR)/src/led.c \
	$(STRIDE_DIR)/src/ssu.c \
	$(STRIDE_DIR)/src/sys.c

OBJECTS := $(SOURCES:.c=.o)

ifeq ($(CONFIG),payload)
LDSCRIPT = $(STRIDE_DIR)/link_payload.ld
VECTOR_SRC = $(STRIDE_DIR)/link_payload.S
BIN_EXT = payload
ifeq ($(SYSTEM),ntr027)
MAX_SIZE = 1024
else ifeq ($(SYSTEM),ntr032)
MAX_SIZE = 2048
endif
else
LDSCRIPT = $(STRIDE_DIR)/link_rom.ld
VECTOR_SRC = $(STRIDE_DIR)/link_rom.S
BIN_EXT = bin
ifeq ($(SYSTEM),ntr027)
MAX_SIZE = 16384
else ifeq ($(SYSTEM),ntr032)
MAX_SIZE = 49152
endif
endif

all: $(TARGET).elf $(TARGET).$(BIN_EXT)

$(TARGET).elf: link.o $(OBJECTS)
	$(CC) $(LDFLAGS) -Wl,-Map=$(MAPFILE) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

link.o: $(VECTOR_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).$(BIN_EXT): $(TARGET).elf
	$(OBJCOPY) -O binary --remove-section=.bss $< $@
	@size=$$(stat -c %s $@); \
	if [ "$$size" -gt $(MAX_SIZE) ]; then \
		echo "ERROR: Output binary size ($$size bytes) exceeds limit ($(MAX_SIZE) bytes) for CONFIG=$(CONFIG)!"; \
	else \
		remain=$$(( $(MAX_SIZE) - $$size )); \
		percent=$$(( 100 * $$size / $(MAX_SIZE) )); \
		echo "OK: Binary size = $$size bytes (limit $(MAX_SIZE)), $$remain bytes free (~$$percent% used)."; \
	fi

clean:
	find . -type f -name '*.o' -exec rm -f {} +
	rm -f *.o *.elf *.bin *.map *.payload
