################# Makefile ####################
CC=gcc
CFLAGS=-I.
DEPS = tradutor.h tabelaSimbolo.h
OBJ = montador.o tradutor.o tabelaSimbolo.o

all: montador

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

montador: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lm
clean:
	rm -rf *.o
mrproper:
	rm -rf main
