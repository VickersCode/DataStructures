/*
Interface for Trains and Buses. Holds virtual functions and that's it.
*/

#ifndef ITRANSPORTER_H
#define ITRANSPORTER_H

template <typename T>
class ITransporter
{
     public:
        virtual void load(T& item) = 0;
        virtual void unload() = 0;
        virtual void empty() = 0;
        virtual void move() = 0;
        virtual bool isEmpty() = 0;
        virtual int itemCount() = 0;
};

#endif