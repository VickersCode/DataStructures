driver: main.o
	g++ main.o -o driver

driver.o: main.cpp linkedBTree.h linkedBSearchTree.h
	g++ -c main.cpp -g

clean:
	rm *.o driver *.txt