#makefile for the program- add lines for each card
CC = g++
CFLAGS = -std=c++11

test: main.o board.o card.o goblin.o
	$(CC) main.o board.o card.o goblin.o -o test

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

board.o: board.h board.cpp
	$(CC) -c board.cpp $(CFLAGS)

card.o: card.h card.cpp
	$(CC) -c card.cpp $(CFLAGS)

goblin.o: goblin.h goblin.cpp
	$(CC) -c goblin.cpp $(CFLAGS)

clean:
	rm *.o test