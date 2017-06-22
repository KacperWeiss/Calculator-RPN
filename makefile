CC=gcc
CFLAGS= -I. -lm -Wall -pedantic
DEPS=Kalkulator.h
OBJ=main.c Kalkulator.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $ <$(CFLAGS)

Kalkulator: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
