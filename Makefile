CC = h8300-hms-gcc
AS = h8300-hms-as
OBJCOPY = h8300-hms-objcopy

CFLAGS = -mh -nostdlib
LDFLAGS = -mh -T vectors.ld -nostdlib

all: main.elf main.bin

main.elf: vectors.o main.o
	$(CC) $(LDFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

vectors.o: vectors.S
	$(AS) -o $@ $<

main.bin: main.elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f *.o *.elf *.bin
