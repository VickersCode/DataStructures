#include <algorithm>

#include "linkedBTree.h"

template<class ItemType>
LinkedBTree<ItemType>::LinkedBTree() : rootPtr(nullptr) {}

template<class ItemType>
bool LinkedBTree<ItemType>::isEmpty() const {
    return rootPtr == nullptr;
}

template<class ItemType>
int LinkedBTree<ItemType>::getHeight() const {
    return getHeightHelper(rootPtr);
}

template<class ItemType>
int LinkedBTree<ItemType>::getHeightHelper(LinkedTreeNode<ItemType>* subTreePtr) const {
    if (subTreePtr == nullptr) {
        return 0;
    }
    else {
        int leftHeight = getHeightHelper(subTreePtr -> getLeftChildPtr());
        int rightHeight = getHeightHelper(subTreePtr -> getRightChildPtr());

        return std::max(leftHeight, rightHeight) + 1;
    }
}

template<class ItemType>
int LinkedBTree<ItemType>::getNumberOfNodes() const {
    return getNumberOfNodesHelper(rootPtr);
}

template<class ItemType>
int LinkedBTree<ItemType>::getNumberOfNodesHelper(LinkedTreeNode<ItemType>* subTreePtr) const {
    LinkedTreeNode<ItemType>* leftPtr, rightPtr;

    if (subTreePtr == nullptr) {
        return 0;
    }
    return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) +
               getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}

template<class ItemType>
ItemType LinkedBTree<ItemType>::getRootData() const {
    return rootPtr->getItem();
}

template<class ItemType>
bool LinkedBTree<ItemType>::add(const ItemType& newData) {
    LinkedTreeNode<ItemType>* newNodePtr = new LinkedTreeNode<ItemType>(newData);

    rootPtr = balancedAdd(rootPtr, newNodePtr);

    return true;
}

template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBTree<ItemType>::balancedAdd(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr) {

    if (subTreePtr == nullptr) {
        return newNodePtr;
    }

    LinkedTreeNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
    LinkedTreeNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();

    leftPtr = subTreePtr->getLeftChildPtr();
    rightPtr = subTreePtr->getRightChildPtr();

    if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)) {
        rightPtr = balancedAdd(rightPtr, newNodePtr);
        subTreePtr->setRightChildPtr(rightPtr);
    }
    else {
        leftPtr = balancedAdd(leftPtr, newNodePtr);
        subTreePtr->setLeftChildPtr(leftPtr);
    }
    return subTreePtr;
}

template<class ItemType>
bool LinkedBTree<ItemType>::remove(const ItemType& data) {
    bool isSuccessful = false;

    rootPtr = removeValue(rootPtr, data, isSuccessful);

    return isSuccessful;
}

template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBTree<ItemType>::removeValue(LinkedTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful) {
    if (subTreePtr == nullptr) {
        isSuccessful = false;
        return nullptr;
    }

    if (subTreePtr->getItem() == target) {
        isSuccessful = true;

        if (subTreePtr->getLeftChildPtr() == nullptr && subTreePtr->getRightChildPtr() == nullptr) {
            delete subTreePtr;
            return nullptr;
        }

        if (subTreePtr->getLeftChildPtr() == nullptr) {
            LinkedTreeNode<ItemType>* tempPtr = subTreePtr->getRightChildPtr();
            delete subTreePtr;
            return tempPtr;
        }
        if (subTreePtr->getRightChildPtr() == nullptr) {
            LinkedTreeNode<ItemType>* tempPtr = subTreePtr->getLeftChildPtr();
            delete subTreePtr;
            return tempPtr;
        }

        LinkedTreeNode<ItemType>* tempPtr = moveValuesUpTree(subTreePtr->getRightChildPtr());
        subTreePtr->setItem(tempPtr->getItem());
        subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), tempPtr->getItem(), isSuccessful));

    }
    else {
        subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful));
        if (!isSuccessful) {
            subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful));
        }
    }

    return subTreePtr;
}

template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBTree<ItemType>::moveValuesUpTree(LinkedTreeNode<ItemType>* subTreePtr) {
    while (subTreePtr->getLeftChildPtr() != nullptr) {
        subTreePtr = subTreePtr->getLeftChildPtr();
    }
    return subTreePtr;
}

template<class ItemType>
void LinkedBTree<ItemType>::clear() {
    destroyTree(rootPtr);
    rootPtr = nullptr;
}

template<class ItemType>
void LinkedBTree<ItemType>::destroyTree(LinkedTreeNode<ItemType>* subTreePtr) {
    if (subTreePtr != nullptr) {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
    }

    delete subTreePtr;
}

template<class ItemType>
bool LinkedBTree<ItemType>::contains(const ItemType& anEntry) const {
    bool isSuccessful = false;
    
    if (rootPtr == nullptr) {
        return false;
    }

    findNode(rootPtr, anEntry, isSuccessful);
    
    return isSuccessful;
}

template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBTree<ItemType>::findNode(LinkedTreeNode<ItemType>* subTreePtr, const ItemType& target, bool& isSuccessful) const {
    if (subTreePtr == nullptr) {
        return subTreePtr;
    }

    if (subTreePtr->getItem() == target) {
        isSuccessful = true;
        return subTreePtr;
    }

    findNode(subTreePtr->getLeftChildPtr(), target, isSuccessful);
    findNode(subTreePtr->getRightChildPtr(), target, isSuccessful);

    return subTreePtr;
}

template<class ItemType>
LinkedBTree<ItemType>::~LinkedBTree() {
    destroyTree(rootPtr);
}