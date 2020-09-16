llfifomake:main.c llfifo.c test_llfifo.c cbfifo.c test_cbfifo.c
	gcc -o -Wall -Werror llfifomake main.c cbfifo.c test_cbfifo.c  llfifo.c test_llfifo.c -I.
