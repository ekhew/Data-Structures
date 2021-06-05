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

    myTree.insert(6);
    myTree.insert(2);
    myTree.insert(7);
    myTree.insert(1);
    myTree.insert(4);
    myTree.insert(3);
    myTree.insert(5);
    myTree.insert(9);
    myTree.insert(8);

    cout << "Preorder: ";
    myTree.preorderTraverse(); //6, 2, 1, 4, 3, 5, 7, 9, 8

    cout << endl << "Inorder: ";
    myTree.inorderTraverse(); //1, 2, 3, 4, 5, 6, 7, 8, 9

    cout << endl << "Postorder: ";
    myTree.postorderTraverse(); //1, 3, 5, 4, 2, 8, 9, 7, 6
    cout << endl;
}
