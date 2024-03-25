CC=g++ -std=c++11 -g
exe=wumpus

# Complete the makefile
# Your code here: 
$(exe): event.o game.o gold.o pool.o room.o stalactites.o wumpus.o main.o
	$(CC) event.o game.o gold.o pool.o room.o stalactites.o wumpus.o main.o -o $(exe)

event.o: event.cpp
	$(CC) -c event.cpp

game.o : game.cpp
	$(CC) -c game.cpp

gold.o : gold.cpp
	$(CC) -c gold.cpp

pool.o : pool.cpp
	$(CC) -c pool.cpp

room.o : room.cpp
	$(CC) -c room.cpp

stalactites.o : stalactites.cpp
	$(CC) -c stalactites.cpp

wumpus.o : wumpus.cpp
	$(CC) -c wumpus.cpp

main.o: main.cpp
	$(CC) -c main.cpp 

clean: 
	rm -f *.o $(exe)

leak_check: event.o game.o gold.o pool.o room.o stalactites.o wumpus.o main.o
	$(CC) event.o game.o gold.o pool.o room.o stalactites.o wumpus.o main.o -o $(exe)
	valgrind --leak-check=full ./$(exe)


