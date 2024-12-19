/*
Templated Train class holds data of type cargo in a vector. 
Inherits virtual functions from the Transporter interface.
*/

#ifndef TRAIN_H
#define TRAIN_H
#include "ITransporter.h"
#include "Cargo.h"
#include <vector>

template <typename T>
class Train : public ITransporter<T>
{
    private:
        double totalWeight;
        std::vector<T> cargoArray; 

    public:
        Train();
        Train(T firstCargo);
        double getWeight();
        void load(T& inCargo);       
        void unload();        
        void empty();
        void move(); 
        bool isEmpty();
        int itemCount();
};
#include "Train.cpp"
#endif