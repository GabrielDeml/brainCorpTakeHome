CC = g++
CFLAGS = -Wall -Werror -std=c++11

all: main

main: main.o matrix.o
	$(CC) $(CFLAGS) main.o matrix.o -o main

main.o: main.cpp matrix.h
	$(CC) $(CFLAGS) -c main.cpp

matrix.o: matrix.cpp matrix.h
	$(CC) $(CFLAGS) -c matrix.cpp

clean:
	rm -f main.o main matrix.o

.PHONY: clean