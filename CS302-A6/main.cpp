#include "linkedBTree.h"
#include "linkedBST.h"

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <ctime>
#include <cstdlib>

void display(int&);

std::unordered_set<int> createRands(int length);
LinkedBTree<int> fillTree(std::unordered_set<int> randSet);
LinkedBST<int> fillBST(std::unordered_set<int> randSet);

int main() {

    std::unordered_set<int> setOfRands;
    setOfRands = createRands(100);

    LinkedBST<int> myBST = fillBST(setOfRands);
    LinkedBTree<int> myBTree = fillTree(setOfRands);

    std::ofstream fout;
    fout.open("data.txt");
    fout << "\nTree Height: " << myBST.getHeight() << std::endl;
    fout << "\nInorder Traversal: \n";
    fout.close();
    myBST.inorderTraverse(display);
    fout.open("data.txt", std::ios::app);
    fout << "\nPreorder Traversal: \n";
    fout.close();
    myBST.preorderTraverse(display);
    fout.open("data.txt", std::ios::app);
    fout << "\nPostorder Traversal: \n";
    fout.close();
    myBST.postorderTraverse(display);

    return 0;
}

std::unordered_set<int> createRands(int length) {
    int DEFAULT_RANGE = 200;
    std::unordered_set<int> rands;
    int randomNumber;

    srand((unsigned) time(0));
    while (rands.size() <= length) {
        randomNumber = (rand() % DEFAULT_RANGE) + 1;
        rands.insert(randomNumber);
    }
    return rands;
}

LinkedBTree<int> fillTree(std::unordered_set<int> randSet) {
    LinkedBTree<int> treeToFill;

    for (const int& element : randSet) {
        treeToFill.add(element);
    }

    return treeToFill;
}

LinkedBST<int> fillBST(std::unordered_set<int> randSet) {
    LinkedBST<int> treeToFill;

    for (const int& element : randSet) {
        treeToFill.add(element);
    }

    return treeToFill;
}

void display(int& num) {
    std::ofstream fout("data.txt", std::ios::app);
    std::cout << num << std::endl;
    fout << num << std::endl;
    fout.close();
}