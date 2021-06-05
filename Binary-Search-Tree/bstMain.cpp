/*
Title: Binary Search Tree (BST)
Author: Edwin Khew
Description: Binary search tree test file.
Date Created: 6/4/2021
*/

#include <iostream>
#include "Node.hpp"
#include "BST.hpp"

using namespace std;

int main()
{
    BST<int> myTree;

    myTree.insert(5);
    myTree.insert(2);
    myTree.insert(7);

    myTree.inorderTraverse();
}
