CC = g++
CFLAGS = -Wall -Werror -std=c++11

all: main

main: main.o matrix.o linalg.o
	$(CC) $(CFLAGS) main.o matrix.o linalg.o -o main

main.o: main.cpp matrix.h
	$(CC) $(CFLAGS) -c main.cpp

matrix.o: matrix.h
	$(CC) $(CFLAGS) -c matrix.h

linalg.o: linalg.h
	$(CC) $(CFLAGS) -c linalg.h

clean:
	rm -f main.o main matrix.o

.PHONY: clean