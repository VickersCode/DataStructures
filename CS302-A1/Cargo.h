/*
Cargo class for storage on train. Stores type, like 
'hay', 'coal', or 'coffee'. Also stores weight in pounds.

operator '<<' overload for printing cargo type and weight
*/

#ifndef CARGO_H
#define CARGO_H
#include <string>
#include <iostream>


class Cargo
{
    private:
        double weight;
        std::string type;

    public:
        Cargo();
        Cargo(double inputWeight,std::string inputType);
        double getWeight() const;
        std::string getType() const;

        friend std::ostream &operator<<(std::ostream &out, const Cargo &cargo);
};
#endif