#makefile for the program- add lines for each card
CC = g++
CFLAGS = -std=c++11

test: main.o board.o card.o goblin.o iron_golem.o
	$(CC) main.o board.o card.o goblin.o iron_golem.o -o test

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

board.o: board.h board.cpp
	$(CC) -c board.cpp $(CFLAGS)

card.o: card.h card.cpp
	$(CC) -c card.cpp $(CFLAGS)

goblin.o: goblin.h goblin.cpp
	$(CC) -c goblin.cpp $(CFLAGS)

iron_golem.o: iron_golem.h iron_golem.cpp
	$(CC) -c iron_golem.cpp $(CFLAGS)

clean:
	rm *.o test