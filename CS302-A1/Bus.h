/*
Templated class to hold a vector of people objects with name and height 
attributes. Bus can sort people by height, report total fare on the bus,
load and unload people, and empty itself.
*/

#ifndef BUS_H
#define BUS_H
#include "ITransporter.h"
#include "Person.h"
#include <vector>
#include <string>

template <typename T>
class Bus : public ITransporter<T>
{
    private:
        double currentFare, totalFare; 
        int totalPeople;             
        std::vector<T> peopleOnbus;   
                                           
    public:                                
        Bus();                             
        Bus(T firstPerson);                                     // For creating the bus with a person
        void setCurrentFare(double fare);
        double getCurrentFare() const;
        double getTotalFare() const;
        void load(T& person);
        void unload();                                          // removes the person in the back of the vector                                                                
        void unloadSpecific(const std::string& name);           // prefer to unloadSpecific(), but both work
        void empty();        
        void move();
        bool isEmpty();
        int itemCount();

        void sortPeople();

        template <typename U>                                                   // Had a huge bug, where I called the typename "T" here. 
        friend std::ostream &operator<< (std::ostream &out, const Bus<U> &bus); // Should be different than the Transporter's template, 
                                                                                // found solution to my problem in StackOverflow
                                                                          
};
#include "Bus.cpp"
#endif