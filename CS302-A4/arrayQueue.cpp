#include "arrayQueue.h"

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() {
    front = 0;
	back = -1;
    max = DEFAULT_CAPACITY;
}

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue(const ArrayQueue<ItemType>& oldArrayQueue) {
    this->front = oldArrayQueue.front;
    this->back = oldArrayQueue.back;
    this->max = oldArrayQueue.max;

    for (int i = 0; i < oldArrayQueue.max; i++) {
        this->items[i] = oldArrayQueue.items[i];
    }
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const {
    return back == -1;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)  {
    bool ableToEnqueue = ((front - back) != 1 && (back - front) != max) || isEmpty();

    if (ableToEnqueue) {
        if (back == max - 1) {
            back = 0;
            items[back] = newEntry;
        } else {
            back++;
            items[back] = newEntry;
        }
    }
    return ableToEnqueue;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue() {
    bool ableToDequeue = !isEmpty();

    if (ableToDequeue) {
        if (front == max - 1) {
            front = 0;
        } else if (front == back) {
            front = 0;
            back = -1;
        } else {
            front++;
        }
    }
    return ableToDequeue;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const {
    if (!isEmpty()) {
        return (items[front]);
    } else {
        throw "Queue is empty";
    }
}