#include "linkedStack.h"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() {
    top = nullptr;
}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& rhs) {
    top = nullptr;
    Node<ItemType>* temp = rhs.top;

    while (temp != nullptr) {
        push(temp->data);
        temp = temp->next;
    }
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const {
    return top == nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem) { //modified from GeeksForGeeks exampmle
    Node<ItemType>* temp = new Node<ItemType>;
    
    temp->setItem(newItem);
    temp->setNext(top);
    top = temp;

    return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop() {
    bool canPop = !isEmpty();

    if (canPop) {
        Node<ItemType>* temp = top;
        top = top->getNext();
        delete temp;

        return true;
    }

    throw "Empty Stack";
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const {
    bool canPeek = !isEmpty();

    if (canPeek) {
        return top->getItem();
    }

    throw "Empty Stack";
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack() {
    while (!isEmpty()) {
        pop();
    }
}