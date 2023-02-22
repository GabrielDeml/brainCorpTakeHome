CC = g++
CFLAGS = -Wall -Werror -std=c++11

all: main

main: main.cpp matrix.h linalg.h
	$(CC) $(CFLAGS) main.cpp -o main

test: main 
	./main

clean:
	rm -f main matrix.h.gch

.PHONY: clean test