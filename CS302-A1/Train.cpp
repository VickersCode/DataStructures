#include "Train.h"
#include <iostream>

template <typename T>
Train<T>::Train() : ITransporter<T>()
{ 
    totalWeight = 0.0;
}

template <typename T>
Train<T>::Train(T firstCargo) : ITransporter<T>()
{
    totalWeight += firstCargo.getWeight(); 
    cargoArray.push_back(firstCargo);
}

template <typename T>
double Train<T>::getWeight() 
{
    return totalWeight;
}

template <typename T>
void Train<T>::load(T& inCargo) 
{
    totalWeight += inCargo.getWeight();
    cargoArray.push_back(inCargo);
}

template <typename T>
void Train<T>::unload() 
{
    totalWeight -= cargoArray.back().getWeight(); // I was trying to reference the last element using cargoArray[-1], but
    cargoArray.pop_back();                        // that wasn't working. Found the .back() method in <vector> lib  
}

template <typename T>
void Train<T>::empty() 
{
    if (!cargoArray.empty())
    {
    cargoArray.clear();
    totalWeight = 0;
    }
}

template <typename T>
void Train<T>::move() 
{
    std::cout << "The train has reached the next destination.\n";
}

template <typename T>
bool Train<T>::isEmpty()
{
    if (cargoArray.empty())
    {
        return true;
    }
    else { return false; }
}

template <typename T>
int Train<T>::itemCount()
{
    return cargoArray.size();
}