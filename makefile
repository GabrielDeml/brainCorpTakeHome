CC = g++
CFLAGS = -Wall -Werror -std=c++11

all: main

main: main.cpp test.cpp matrix.h linalg.h
	$(CC) $(CFLAGS) main.cpp test.cpp -o main


runTest: main
	./main

clean:
	rm -f main 

.PHONY: clean runTest