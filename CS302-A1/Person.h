/*
Person class for storage on bus. Stores height in cm and their name. 
Operator '<' overloaded for sorting through the people within the Bus class
*/

#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <string>

class Person
{
    private: 
        std::string name;
        int cmHeight;

    public:
        Person();
        Person(std::string newName, int newCmHeight);
        double getHeight() const;
        std::string getName() const;

        
        bool operator<(const Person& other);
};
#endif