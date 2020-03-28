COMMON_OBJECTS =
CPU	       = msp430g2553
CFLAGS         = -mmcu=${CPU} -I../h
LDFLAGS	       = -L/opt/ti/msp430_gcc/include

CC	       = msp430-elf-gcc
AS	       = msp430-elf-as

all:
	project2.elf

project2.elf: ${COMMON_OBJECTS} buzzer.o p1_interrupt_handler.o led.o switches.o main.o ../../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: project2.elf
	msp430loader.sh project2.elf

clean:
	rm -f *.o *.elf

