################# Makefile ####################
CC=gcc
CFLAGS=-I.
DEPS = saidaSimples.h tabelaSimbolo.h
OBJ = montador.o saidaSimples.o tabelaSimbolo.o

all: montador

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

montador: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lm
clean:
	rm -rf *.o
mrproper:
	rm -rf main