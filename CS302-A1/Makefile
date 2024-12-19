hw1: main.o Train.h Bus.h Bus.cpp Train.cpp Train.h Cargo.o Person.o
	g++ -o hw1 main.o Cargo.o Person.o -g

main.o: main.cpp 
	g++ -c main.cpp -g

Cargo.o: Cargo.h Cargo.cpp
	g++ -c Cargo.cpp

Person.o: Person.h Person.cpp
	g++ -c Person.cpp

clean: 
	rm *.o hw1