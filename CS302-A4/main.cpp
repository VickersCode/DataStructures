/*
Version: 1.0
Purpose: Main driver which takes in an input file in the directory, and uses the data from that file to create a priority queue
which organizes the events of a customer arrival and departure in chronological order. It also has a separte function which
considers three different tellers which are represented by three different priority queues, and then organizes all of the events
from each teller into a singular priority queue that outputs all the given events.
*/

#include <iostream>
#include <string>
#include <fstream>
#include "arrayQueue.h"
#include "arrayPriorityQueue.h"

float averageTime(int numCustomers, int totalTime);

template <class ItemType>
ArrayQueue<ItemType> processInputFile(std::string inputFileLocation);

typedef struct Event {
    std::string eventType;
    int eventTime;
    int transactionTime;
} Event;

int main(void) {
    
    std::string inputFileLocation = "input.txt";

    ArrayQueue<Event> arrivalEvents = processInputFile<Event>(inputFileLocation);
    ArrayPriorityQueue<Event> eventQueue;

    int numCustomers = 0;
    int totalWaitingTime = 0;
    int currentTime = 0;
    int nextAvailableTime = 0;

    // Inputs arrival events
    while (!arrivalEvents.isEmpty()) {
        Event nextArrival = arrivalEvents.peekFront();
        arrivalEvents.dequeue();
        eventQueue.enqueue(nextArrival, nextArrival.eventTime);  
        numCustomers++;
    }

    std::cout << "Simulation Begins\n";

    while (!eventQueue.isEmpty()) {
        Event nextEvent = eventQueue.peekFront();
        eventQueue.dequeue();
        currentTime = nextEvent.eventTime;

        if (nextEvent.eventType == "arrival") {
            std::cout << "Processing an arrival event at time: " << nextEvent.eventTime << std::endl;

            if (currentTime < nextAvailableTime) {
                totalWaitingTime += (nextAvailableTime - currentTime);
                currentTime = nextAvailableTime;
            }
            
            nextAvailableTime = currentTime + nextEvent.transactionTime;
            Event departureEvent = {"departure", nextAvailableTime, nextEvent.transactionTime};
            eventQueue.enqueue(departureEvent, departureEvent.eventTime);
        } 
        else {
            std::cout << "Processing a departure event at time: " << nextEvent.eventTime << std::endl;
        }
    }
    std::cout << "Simulation Ends\n\n" << std::endl;

    std::cout << "Final Statistics:\n";
    std::cout << "Total number of people processed: " << numCustomers << std::endl;
    std::cout << "Average amount of time spent waiting: " << averageTime(numCustomers, totalWaitingTime) << '\n';

    return 0;
}

// Helper Functions
float averageTime(int numCustomers, int totalTime) {
    if (numCustomers == 0) {
        return 0.0;
    }
    return (float) totalTime / (float) numCustomers;
}

template <class ItemType>
ArrayQueue<ItemType> processInputFile(std::string inputFileLocation) {
    std::ifstream inputFile(inputFileLocation);
    ArrayQueue<ItemType> arrivalQueue;

    int arrivalTime, transactionTime;
    while (inputFile >> arrivalTime >> transactionTime) {
        Event arrivalEvent = {"arrival", arrivalTime, transactionTime};
        arrivalQueue.enqueue(arrivalEvent);
    }

    inputFile.close();
    return arrivalQueue;
}