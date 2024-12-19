#include <algorithm>

#include "linkedBST.h"

template<class ItemType>
LinkedBST<ItemType>::LinkedBST() : rootPtr(nullptr) {}

template<class ItemType>
bool LinkedBST<ItemType>::isEmpty() const {
    return rootPtr == nullptr;
}

template<class ItemType>
int LinkedBST<ItemType>::getHeight() const {
    return this->getHeightHelper(rootPtr);
}

template<class ItemType>
int LinkedBST<ItemType>::getNumberOfNodes() const {
    return this->getNumberOfNodesHelper(rootPtr);
}

template<class ItemType>
ItemType LinkedBST<ItemType>::getRootData() const {
    return rootPtr->getItem();
}

template<class ItemType>
bool LinkedBST<ItemType>::add(const ItemType& newData) {
    LinkedTreeNode<ItemType>* newNodePtr = new LinkedTreeNode<ItemType>(newData);

    rootPtr = placeNode(rootPtr, newNodePtr);

    return true;
}

//Code acquired from https://www.geeksforgeeks.org/cpp-binary-search-tree/
template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBST<ItemType>::placeNode(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr) {
    if (subTreePtr == nullptr) {
        return newNodePtr;
    }

    if (newNodePtr->getItem() < subTreePtr->getItem()) {
        subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), newNodePtr));
    }
    else if (newNodePtr->getItem() > subTreePtr->getItem()) {
        subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr(), newNodePtr));
    }

    return subTreePtr;
}

template<class ItemType>
bool LinkedBST<ItemType>::remove(const ItemType& data) {
    bool isSuccessful = false;

    rootPtr = removeValue(rootPtr, data, isSuccessful);

    return isSuccessful;
}

// Code obtained from https://www.geeksforgeeks.org/cpp-binary-search-tree/
template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBST<ItemType>::removeValue(LinkedTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful) {
    if (subTreePtr == nullptr) {
        isSuccessful = false;
        return subTreePtr;
    }

    if (target < subTreePtr->getItem()) {
        subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful));
    }
    else if (target > subTreePtr->getItem()) {
        subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful));
    }
    else {
        subTreePtr = removeNode(subTreePtr);
        isSuccessful = true;
    }

    return subTreePtr;
}

template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBST<ItemType>::removeNode(LinkedTreeNode<ItemType>* nodePtr) {
    if (nodePtr->getLeftChildPtr() == nullptr && nodePtr->getRightChildPtr() == nullptr) {
        delete nodePtr;
        return nullptr;
    }
    else if (nodePtr->getLeftChildPtr() == nullptr) {
        LinkedTreeNode<ItemType>* tempPtr = nodePtr->getRightChildPtr();
        delete nodePtr;
        return tempPtr;
    }
    else if (nodePtr->getRightChildPtr() == nullptr) {
        LinkedTreeNode<ItemType>* tempPtr = nodePtr->getLeftChildPtr();
        delete nodePtr;
        return tempPtr;
    }
    else {
        ItemType inorderSuccesor;
        LinkedTreeNode<ItemType>* tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), inorderSuccesor);

        nodePtr->setItem(inorderSuccesor);

        return nodePtr;
    }
}


template<class ItemType>
void LinkedBST<ItemType>::clear() {
    this->destroyTree(rootPtr);
    rootPtr = nullptr;
}

template<class ItemType>
bool LinkedBST<ItemType>::contains(const ItemType& anEntry) const {
    LinkedTreeNode<ItemType>* tempNode = findNode(rootPtr, anEntry);

    return tempNode != nullptr;
}

// Code obtained from https://www.geeksforgeeks.org/cpp-binary-search-tree/
template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBST<ItemType>::removeLeftmostNode(LinkedTreeNode<ItemType>* nodePtr, ItemType& inorderSuccessor) {
    LinkedTreeNode<ItemType>* newNode = nodePtr;

    while (newNode != nullptr && newNode->getLeftChildPtr() != nullptr) {
        newNode = newNode->getLeftChildPtr();
    }
    
    inorderSuccessor = newNode->getItem();

    LinkedTreeNode<ItemType>* parent = nodePtr;
    while (parent != nullptr && parent->getLeftChildPtr() != newNode) {
        parent = parent->getLeftChildPtr();
    }

    if (newNode->getLeftChildPtr() == nullptr && newNode->getRightChildPtr() == nullptr) {
        delete newNode;
        return nullptr;
    }

    LinkedTreeNode<ItemType>* child = newNode->getLeftChildPtr() != nullptr ? newNode->getRightChildPtr() : newNode->getLeftChildPtr();
    delete newNode;
    return child;
}

// Code obtained from https://www.geeksforgeeks.org/cpp-binary-search-tree/
template<class ItemType>
LinkedTreeNode<ItemType>* LinkedBST<ItemType>::findNode(LinkedTreeNode<ItemType>* treePtr, const ItemType& target) const {
    if (treePtr == nullptr) {
        return treePtr;
    }
    else if (treePtr->getItem() == target) {
        return treePtr;
    }

    if (treePtr->getItem() < target) {
        return findNode(treePtr->getRightChildPtr(), target);
    }

    return findNode(treePtr->getLeftChildPtr(), target);
}

// All traversals referenced here: https://www.geeksforgeeks.org/binary-search-tree-traversal-inorder-preorder-post-order/
template<class ItemType>
void LinkedBST<ItemType>::inorderTraverse(void visit(ItemType&)) const {
    inorder(visit, rootPtr);
}

template<class ItemType>
void LinkedBST<ItemType>::inorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const {
    if (treePtr != nullptr) {
        inorder(visit, treePtr->getLeftChildPtr());

        ItemType theItem = treePtr->getItem();
        visit(theItem);

        inorder(visit, treePtr->getRightChildPtr());
    }
}

template<class ItemType>
void LinkedBST<ItemType>::preorderTraverse(void visit(ItemType&)) const {
    preorder(visit, rootPtr);
}

template<class ItemType>
void LinkedBST<ItemType>::preorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const {
    if (treePtr != nullptr) {
        ItemType theItem = treePtr->getItem();
        visit(theItem);

        preorder(visit, treePtr->getLeftChildPtr());

        preorder(visit, treePtr->getRightChildPtr());
    }
}

template<class ItemType>
void LinkedBST<ItemType>::postorderTraverse(void visit(ItemType&)) const {
    postorder(visit, rootPtr);
}

template<class ItemType>
void LinkedBST<ItemType>::postorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const {
    if (treePtr != nullptr) {
        postorder(visit, treePtr->getLeftChildPtr());

        postorder(visit, treePtr->getRightChildPtr());

        ItemType theItem = treePtr->getItem();
        visit(theItem);
    }
}

template<class ItemType>
LinkedBST<ItemType>::~LinkedBST() {
    this->destroyTree(rootPtr);
}