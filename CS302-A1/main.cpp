/*

Main driver creates and loads a bus and a train, 
loads them with cargo and people respectively,
and demonstrates that all functions work properly,
allowing each to load, unload, empty, and get count 
of "items".
*/

#include <iostream>
#include <iomanip>
#include <ostream>
#include "Train.h"
#include "Bus.h"
#include "Cargo.h"

int main() {

    // For displaying the moneys
    std::cout << std::fixed << std::right << std::setprecision(2);

// --------------------TRAIN-------------------------- //

    std::cout << "\n\n======================TRAIN======================\n\n";
    Cargo cargo1(150, "hay");
    Cargo cargo2(250, "coal");
    Cargo cargo3(100, "coffee");
    Train<Cargo> train;

    if (train.isEmpty())
    {
        std::cout << "The train is empty.\n\n";
    } else
        {
            std::cout  << "The train is not empty.\n\n";   
        }

    train.move();
    train.load(cargo1);
    std::cout << "Train loaded with the following cargo:\n";
    std::cout << cargo1;
    std::cout << "---------------\n";
    std::cout << "Total Weight: " << train.getWeight() << std::endl;
    std::cout << "Total items: " << train.itemCount() << std::endl;
    if (train.isEmpty())
    {
        std::cout << "The train is empty.\n\n";
    } else
        {
            std::cout  << "The train is not empty.\n\n";   
        }


    train.move();
    train.load(cargo2);
    std::cout << "Train loaded with the following cargo:\n";
    std::cout << cargo2;
    std::cout << "---------------\n";
    std::cout << "Total Weight: " << train.getWeight() << std::endl;
    std::cout << "Total items: " << train.itemCount() << std::endl;
        if (train.isEmpty())
    {
        std::cout << "The train is empty.\n\n";
    } else
        {
            std::cout  << "The train is not empty.\n\n";   
        }

    train.move();
    train.load(cargo3);
    std::cout << "Train loaded with the following cargo:\n";
    std::cout << cargo3;
    std::cout << "---------------\n";
    std::cout << "Total Weight: " << train.getWeight() << std::endl;
    std::cout << "Total items: " << train.itemCount() << std::endl;
        if (train.isEmpty())
    {
        std::cout << "The train is empty.\n\n";
    } else
        {
            std::cout  << "The train is not empty.\n\n";   
        }

    train.move();
    std::cout << "The following is being unloaded:\n";
    std::cout << cargo3; 
    std::cout << "---------------\n";                                              
    train.unload();
    std::cout << "Total Weight: " << train.getWeight() << std::endl;
    std::cout << "Total items: " << train.itemCount() << std::endl;
        if (train.isEmpty())
    {
        std::cout << "The train is empty.\n\n";
    } else
        {
            std::cout  << "The train is not empty.\n\n";   
        }

    train.move();
    train.empty();
    std::cout << "The train has been emptied.\n";
    std::cout << "Total Weight: " << train.getWeight() << std::endl;
    std::cout << "Total items: " << train.itemCount() << std::endl;
        if (train.isEmpty())
    {
        std::cout << "The train is empty.\n\n";
    } else
        {
            std::cout  << "The train is not empty.\n\n";   
        }


// --------------------BUS-------------------------- //

    std::cout << "\n\n======================BUS======================\n\n";
    Person person1("Jimmy", 400);
    Person person2("Frank", 300);
    Person person3("Alexa", 500);
    Person person4("Doe", 200);
    Person person5("James", 600);
    Person person6("Samantha", 2);
    Person person7("George", 0);
    Person person8("Wallis", 10);

    Bus<Person> bus;
    bus.setCurrentFare(2.75);
    bus.load(person1);              // Bus will be pre-loaded with people to easier
    bus.load(person2);              // see the sorting by height work. height is 
    bus.load(person3);              // intended to be ints of centimeters, but I will
    bus.load(person4);              // use unrealistic values for easier readability


    std::cout << "People on bus (unsorted): \n" << "---------------\n";
    std::cout << bus;
    std::cout << "---------------\n";
    bus.sortPeople();
    std::cout << "People on board: " << bus.itemCount() << std::endl;
    std::cout << "Total fare: $" << bus.getTotalFare() << "\n\n";

    std::cout << "People on bus (sorted): \n" << "---------------\n";
    std::cout << bus;
    std::cout << "---------------\n";
    std::cout << "People on board: " << bus.itemCount() << std::endl;
    std::cout << "Total fare: $" << bus.getTotalFare() << "\n\n";

    bus.move();
    bus.unloadSpecific("Frank");
    std::cout << "People on bus (sorted): \n" << "---------------\n";
    std::cout << bus;
    std::cout << "---------------\n";
    std::cout << "People on board: " << bus.itemCount() << std::endl;
    std::cout << "Total fare: $" << bus.getTotalFare() << "\n\n";

    bus.setCurrentFare(3.00);
    std::cout << "Fare changed to $" << bus.getCurrentFare() << "\n\n";

    bus.move();
    bus.load(person5);
    bus.load(person6);
    bus.load(person7);
    bus.load(person8);
    bus.sortPeople();
    std::cout << "People on bus (sorted): \n" << "---------------\n";
    std::cout << bus;
    std::cout << "---------------\n";
    std::cout << "People on board: " << bus.itemCount() << std::endl;
    std::cout << "Total fare: $" << bus.getTotalFare() << "\n\n";

    bus.move();
    std::cout << "Final destination. Everyone must get off.\n";
    bus.empty();
    std::cout << "People on board: " << bus.itemCount() << std::endl;
    std::cout << "Total fare: $" << bus.getTotalFare() << "\n\n";


    return 0;
}