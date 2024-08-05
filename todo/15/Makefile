CC=gcc
CFLAGS=-g3 -Wall

all: main

part.o: part.c part.h
	$(CC) $(CFLAGS) -c part.c -o part.o

trx.o: trx.c trx.h
	$(CC) $(CFLAGS) -c trx.c -o trx.o

inv.o: inv.c inv.h part.h trx.h
	$(CC) $(CFLAGS) -c inv.c -o inv.o

main.o: main.c headers.h part.h trx.h inv.h
	$(CC) $(CFLAGS) -c main.c -o main.o

main: part.o trx.o inv.o  main.o
	$(CC) $(CFLAGS) -o main part.o trx.o inv.o main.o

clean:
	rm -f *.o main
