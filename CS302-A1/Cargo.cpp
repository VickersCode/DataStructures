#include "Cargo.h"

Cargo::Cargo() 
{
    weight = 0;
    type = "";
}

Cargo::Cargo(double inputWeight, std::string inputType)
{
    weight = inputWeight;
    type = inputType;
}

double Cargo::getWeight() const
{
    return weight;
}

std::string Cargo::getType() const
{
    return type;
}

std::ostream &operator<< (std::ostream &out, const Cargo &cargo)
{
    out << "Cargo Type: " << cargo.getType() << std::endl << "Weight: " << cargo.getWeight() << std::endl;

    return out;
}