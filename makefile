#makefile for the program- add lines for each card
CC = g++
CFLAGS = -std=c++11

test: main.o board.o card.o iron_golem.o blademaster.o elite.o hammer.o handgun.o loremaster.o militia.o pharaoh.o spear.o sword.o wizard.o
	$(CC) main.o board.o card.o iron_golem.o blademaster.o elite.o hammer.o handgun.o loremaster.o militia.o pharaoh.o spear.o sword.o wizard.o -o test

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

board.o: board.h board.cpp
	$(CC) -c board.cpp $(CFLAGS)

card.o: card.h card.cpp
	$(CC) -c card.cpp $(CFLAGS)

iron_golem.o: iron_golem.h iron_golem.cpp
	$(CC) -c iron_golem.cpp $(CFLAGS)

blademaster.o: blademaster.h blademaster.cpp
	$(CC) -c blademaster.cpp $(CFLAGS)

elite.o: elite.h elite.cpp
	$(CC) -c elite.cpp $(CFLAGS)

hammer.o: hammer.h hammer.cpp
	$(CC) -c hammer.cpp $(CFLAGS)

handgun.o: handgun.h handgun.cpp
	$(CC) -c handgun.cpp $(CFLAGS)

loremaster.o: loremaster.h loremaster.cpp
	$(CC) -c loremaster.cpp $(CFLAGS)

militia.o: militia.h militia.cpp
	$(CC) -c militia.cpp $(CFLAGS)

pharaoh.o: pharaoh.h pharaoh.cpp
	$(CC) -c pharaoh.cpp $(CFLAGS)

spear.o: spear.h spear.cpp
	$(CC) -c spear.cpp $(CFLAGS)

sword.o: sword.h sword.cpp
	$(CC) -c sword.cpp $(CFLAGS)

wizard.o: wizard.h wizard.cpp
	$(CC) -c wizard.cpp $(CFLAGS)

clean:
	rm *.o test