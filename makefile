CC = gcc
CFLAGS = -Wall -Werror

all: main

main: llfifo.o cbfifo.o main.o Makefile test_llfifo.o test_cbfifo.o
	$(CC) -o main llfifo.o cbfifo.o main.o test_llfifo.o test_cbfifo.o

%.o: %.c %.h Makefile	
	$(CC) -c $(CFLAGS) $< -o $@

clean:	
	-rm -f main *.o
