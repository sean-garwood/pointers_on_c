CC=gcc
CFLAGS=-g3 -Wall

all: inv

inv: main.o inv.o part.o
	$(CC) $(CFLAGS) -o inv main.o inv.o part.o
	echo "inv compiled"

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

inv.o: inv.c headers.h
	$(CC) $(CFLAGS) -c inv.c

part.o: part.c
	$(CC) $(CFLAGS) -c part.c

clean:
	rm -f *.o main
