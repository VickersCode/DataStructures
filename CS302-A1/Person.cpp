/*
Person class holds people to store on a bus.
Attributes: name and height in cm
*/

#include "Person.h"

Person::Person()
{
    name = "";
    cmHeight = 0;
}  

Person::Person(std::string newName, int newCmHeight)
{
    name = newName;
    cmHeight = newCmHeight;
}

double Person::getHeight() const
    { return cmHeight;}

std::string Person::getName() const
    { return name; }

bool Person::operator<(const Person& other)  
    {
        return this->getHeight() < other.getHeight();
    }