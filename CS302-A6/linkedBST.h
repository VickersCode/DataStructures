#ifndef LINKED_BST
#define LINKED_BST

#include "linkedtreenode.h"
#include "linkedBTree.h"

template<class ItemType>
class LinkedBST: public LinkedBTree<ItemType> {
    private:
        LinkedTreeNode<ItemType>* rootPtr;

    public:
        LinkedBST();

        bool isEmpty() const;
        int getHeight() const;
        int getNumberOfNodes() const;
        ItemType getRootData() const;
        bool add(const ItemType& newData);
        bool remove(const ItemType& data);
        void clear();
        bool contains(const ItemType& anEntry) const;

        void preorderTraverse(void visit(ItemType&)) const;
        void inorderTraverse(void visit(ItemType&)) const;
        void postorderTraverse(void visit(ItemType&)) const;

        ~LinkedBST();

    protected:
        LinkedTreeNode<ItemType>* placeNode(LinkedTreeNode<ItemType>* subTreePtr, LinkedTreeNode<ItemType>* newNodePtr);
        LinkedTreeNode<ItemType>* removeValue(LinkedTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful);
        LinkedTreeNode<ItemType>* removeNode(LinkedTreeNode<ItemType>* nodePtr);
        LinkedTreeNode<ItemType>* removeLeftmostNode(LinkedTreeNode<ItemType>* nodePtr, ItemType& inorderSuccessor);
        LinkedTreeNode<ItemType>* findNode(LinkedTreeNode<ItemType>* treePtr, const ItemType& target) const;

        void preorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const;
        void inorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const;
        void postorder(void visit(ItemType&), LinkedTreeNode<ItemType>* treePtr) const;
};


#include "linkedBST.cpp"
#endif