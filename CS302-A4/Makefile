main: main.o
	g++ -std=c++17 main.o -o main

main.o: main.cpp arrayQueue.h arrayPriorityQueue.h
	g++ -std=c++17 -c main.cpp

clean:
	rm *.o main