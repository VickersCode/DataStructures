#ifndef ARRAY_PRIORITY_QUEUE_H
#define ARRAY_PRIORITY_QUEUE_H

#include "arrayQueue.h"

template<class ItemType>
class ArrayPriorityQueue : public ArrayQueue<ItemType> {
    private:
        int priority[ArrayQueue<ItemType>::DEFAULT_CAPACITY];
    public:
        ArrayPriorityQueue();
        ArrayPriorityQueue(const ArrayPriorityQueue<ItemType>& oldArrayPriorityQueue);

        bool enqueue(const ItemType& newEntry, int entryPriority);

        ~ArrayPriorityQueue() {};
};

#include "arrayPriorityQueue.cpp"
#endif