CC=gcc
CFLAGS=-g3 -Wall

all: main

trx.o: trx.c trx.h headers.h
	$(CC) $(CFLAGS) -c trx.c -o trx.o

part.o: part.c headers.h
	$(CC) $(CFLAGS) -c part.c -o part.o

inv.o: inv.c headers.h
	$(CC) $(CFLAGS) -c inv.c -o inv.o

main.o: main.c headers.h
	$(CC) $(CFLAGS) -c main.c -o main.o

main: part.o trx.o inv.o  main.o
	$(CC) $(CFLAGS) -o main part.o trx.o inv.o main.o

clean:
	rm -f *.o main
