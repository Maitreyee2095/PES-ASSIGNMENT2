llfifomake:main.o llfifo.o test_llfifo.o cbfifo.o test_cbfifo.o
	gcc -o llfifomake main.o cbfifo.o test_cbfifo.o  llfifo.o test_llfifo.o -I.
