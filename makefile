
CC = gcc
CFLAGS  = -g -Wall 


default: llfifomake


llfifomake:  llfifo.o test_llfifo.o main.o cbfifo.o test_cbfifo.o
	$(CC) $(CFLAGS) -o llfifomake llfifo.o test_llfifo.o main.o test_llfifo.o cbfifo.o test_cbfifo.o


llfifo.o:  llfifo.c 
	$(CC) $(CFLAGS) -c llfifo.c 


main.o: main.c
	$(CC) $(CFLAGS) -c main.c

cbfifo.o:  cbfifo.c 
	$(CC) $(CFLAGS) -c cbfifo.c 

test_cbfifo.o:  test_cbfifo.c cbfifo.c 
	$(CC) $(CFLAGS) -c test_cbfifo.c cbfifo.c 


test_llfifo.o:  test_llfifo.c llfifo.c 
	$(CC) $(CFLAGS) -c test_llfifo.c llfifo.c 

clean: 
	$(RM) llfifomake *.o *~
