#include "Bus.h"
#include "Person.h"
#include <iostream>
#include <ostream>

template <typename T>
Bus<T>::Bus() : ITransporter<T>()
{
    totalFare = 0.0;
    currentFare = 0.0;
}

template <typename T>
Bus<T>::Bus(T firstPerson) : ITransporter<T>()
{
    peopleOnbus.push_back(firstPerson);
}

template <typename T>
void Bus<T>::setCurrentFare(double fare)
{
    currentFare = fare;
}

template <typename T>
double Bus<T>::getCurrentFare() const
{
    return currentFare;
}

template <typename T>
double Bus<T>::getTotalFare() const
{
    return totalFare;
}

template <typename T>
void Bus<T>::load(T& person)
{
    peopleOnbus.push_back(person);
    totalFare += currentFare;
    totalPeople += 1;
}

template <typename T>
void Bus<T>::unload()
{
    peopleOnbus.pop_back();
    totalFare -= currentFare;
}

template <typename T>
void Bus<T>::unloadSpecific(const std::string& name)
{
    int index;
    for (int i = 0; i < totalPeople; i++)
    {
        if (peopleOnbus[i].getName() == name){
            index = i;
            break;
        }
    }

    
    for (int k = index; k < totalPeople -1; k++)
    {   
        peopleOnbus[k] = peopleOnbus[k+1];
    }

    peopleOnbus.pop_back(); // This is the only way I could fix duplicates
    totalPeople -= 1;       // at the back of the bus when removing a person
    totalFare -= currentFare;
};

template <typename T>
void Bus<T>::empty()
{
    if (!peopleOnbus.empty())
    {
        peopleOnbus.clear();
        totalFare = 0.0;
        totalPeople = 0;
    }
}

template <typename T>
void Bus<T>::move()
{
    std::cout << "The bus has reached the next stop.\n";
}

template <typename T>
bool Bus<T>::isEmpty()
{
    if (peopleOnbus.empty())
    {
        return true;
    }
    else { return false; }
}

template <typename T>
int Bus<T>::itemCount()
{
    return peopleOnbus.size();
}

template <typename T>
void Bus<T>::sortPeople()
{
    for (int i = 0; i <= peopleOnbus.size() - 1; i++) 
    {    
        for(int j = 0; j <= peopleOnbus.size() - 1; j++)
        { 
            if(peopleOnbus[i] < peopleOnbus[j])
            {
                std::swap(peopleOnbus[j], peopleOnbus[i]); // found std::swap in StackOverflow
            }
        }
    }
}

template <typename T>
std::ostream &operator<< (std::ostream &out, const Bus<T> &bus)
{
    for (const auto &person :  bus.peopleOnbus)
    {
        out << person.getName() << std::endl;
    }
    
    return out;
}