#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include "queue.h"

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType> {
    protected:
        static const int DEFAULT_CAPACITY = 100;
		int front;
		int back;
        int max;
		ItemType items[DEFAULT_CAPACITY];
    public:
        ArrayQueue();
        ArrayQueue(const ArrayQueue<ItemType>& oldArrayQueue);

        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();
        ItemType peekFront() const;

        ~ArrayQueue() {};
};

#include "arrayQueue.cpp"
#endif