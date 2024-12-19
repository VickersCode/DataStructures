

## Project Goals
The goal of this project is to review:
1.	**C++**
2.  **Templates**
3.  **Interfaces**
4.  **Operator Overloading**
5.  **makefiles**

## Program
Moving and shaking! We're going to create a program that moves trains carrying cargo and buses carrying people. 

Trains and buses are "transporters". Any transporter MUST be able to **load** one item, **unload** one item, **empty** all items, **move** They must also be able to report back whether or not they **are empty** and **how many items** they are carrying.  

Additionally, while a *train* and a *bus* must be able to **store items of any type**, in this project a train should store *cargo* and a bus should transport *people*. When cargo is loaded onto a train, it doesn't matter where it goes but people on the bus should "sit" from shortest to tallest. Also, a train must be able to report on the weight of all its cargo and a bus must be able to change its fare and give the total fair for all the people on the bus. When a train moves, it can display that it's reached the next destination. When a bus moves, it can display that it's reached the next stop.

Finally, each cargo must have a type (like coal or hay) and a weight, and each person must have a name and a height.

The main driver of your program must create a train and load it with some cargo. It must create a bus and let people board. It should also demonstrate that all other functions for the bus and train work properly. All console input and output should occur in the main function (except for what's displayed in the move functions).

