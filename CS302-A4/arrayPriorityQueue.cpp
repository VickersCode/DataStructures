#include "arrayPriorityQueue.h"


template<class ItemType>
ArrayPriorityQueue<ItemType>::ArrayPriorityQueue() {
    this->front = 0;
    this->back = -1;
    this->max = this->DEFAULT_CAPACITY;
}

template<class ItemType>
ArrayPriorityQueue<ItemType>::ArrayPriorityQueue(const ArrayPriorityQueue<ItemType>& oldArrayPriorityQueue) {
    this->front = oldArrayPriorityQueue.front;
    this->back = oldArrayPriorityQueue.back;
    this->max = oldArrayPriorityQueue.max;

    for (int i = 0; i < oldArrayPriorityQueue.max; i++) {
        this->items[i] = oldArrayPriorityQueue.items[i];
        this->priority[i] = oldArrayPriorityQueue.priority[i];
    }
}

template<class ItemType>
bool ArrayPriorityQueue<ItemType>::enqueue(const ItemType& newEntry, int entryPriority) {
    bool ableToEnqueue = (((this->front - this->back) != 1 && (this->back - this->front) != this->max) || this->isEmpty());
    bool placementFound = false;

    int i = this->back;
    if (ableToEnqueue) {
        if (this->isEmpty()) {
            this->back++;
            this->items[this->back] = newEntry;
            priority[this->back] = entryPriority;
            placementFound = true;
        } else {
            while (!placementFound) {
            if (entryPriority >= priority[i]) {
                if (i == this->max - 1) {
                    this->items[0] = newEntry;
                    this->priority[0] = entryPriority;
                } else {
                    this->items[(i + 1)] = newEntry;
                    this->priority[(i + 1)] = entryPriority;
                }
                placementFound = true;
            } else if (entryPriority < priority[i]) {
                if (i == this->max - 1) {
                    this->items[0] = this->items[i];
                    this->priority[0] = this->priority[i];
                } else {
                    this->items[(i + 1)] = this->items[i];
                    this->priority[(i + 1)] = this->priority[i];
                }
                i--;
            }
        }

        if (this->back == this->max - 1) {
            this->back = 0;
        } else {
            this->back++;
        }
        }
    }

    return ableToEnqueue;
}