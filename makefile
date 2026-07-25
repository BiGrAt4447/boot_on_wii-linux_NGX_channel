LIBOGC = /usr/local/libogc
CC = powerpc-eabi-gcc
CFLAGS = -O2 -m32 -mcpu=750 -meabi -I$(LIBOGC)/include
LDFLAGS = -L$(LIBOGC)/lib -logc -lfat
OBJS = forwarder.o

all: forwarder.dol

forwarder.o: forwarder.c
    $(CC) $(CFLAGS) -c forwarder.c -o forwarder.o

forwarder.elf: $(OBJS)
    $(CC) $(CFLAGS) -o forwarder.elf $(OBJS) $(LDFLAGS)

forwarder.dol: forwarder.elf
    $(LIBOGC)/bin/elf2dol forwarder.elf forwarder.dol

clean:
    rm -f *.o forwarder.elf forwarder.dol
