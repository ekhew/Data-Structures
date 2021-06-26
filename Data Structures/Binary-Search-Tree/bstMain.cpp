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

    //myTree.remove(6); //root
    //myTree.remove(1); //case 1: is a leaf
    //myTree.remove(7); //case 2: one child (right)
    //myTree.remove(9); //case 2: one child (left)
    //myTree.remove(2); //case 3: two children
    //myTree.remove(12); //does not exist

    //myTree.remove(8);
    //myTree.remove(5);
    //myTree.remove(3);

    cout << "Node Count: " << myTree.nodeCount() << endl;
    cout << "Height: " << myTree.getHeight() << endl;

    cout << "Preorder: ";
    myTree.preorderTraverse(); //6, 2, 1, 4, 3, 5, 7, 9, 8

    cout << endl << "Inorder: ";
    myTree.inorderTraverse(); //1, 2, 3, 4, 5, 6, 7, 8, 9

    cout << endl << "Postorder: ";
    myTree.postorderTraverse(); //1, 3, 5, 4, 2, 8, 9, 7, 6

    cout << endl << "Level Order: ";
    myTree.levelorderTraverse(); //6, 2, 7, 1, 4, 9, 3, 5, 8

    try
    {
        cout << endl << "Min: " << myTree.findMin() << endl;
    }
    catch(const std::out_of_range& problem)
    {
        cout << "Tree is empty!" << endl;
    }

    try
    {
        cout << "Max: " << myTree.findMax() << endl;
    }
    catch(const std::out_of_range& problem)
    {
        cout << "Tree is empty!" << endl;
    }

    try
    {
        cout << "Search: " << myTree.search(6) << endl;
    }
    catch(const std::out_of_range& problem)
    {
        cout << "Item not found!" << endl;
    }

    try
    {
        cout << "Inorder Successor: " << myTree.inorderSuccessor(6) << endl;
    }
    catch(const std::out_of_range& problem)
    {
        cout << "No successor found!" << endl;
    }

    myTree.printTree();

    /*
        copy constructor test
    */
    BST<int> myCopiedTree = myTree;

    cout << endl << "Node Count (Copied Tree): " << myCopiedTree.nodeCount() << endl;
    cout << "Height (Copied Tree): " << myCopiedTree.getHeight() << endl;

    cout << "Preorder (Copied Tree): ";
    myCopiedTree.preorderTraverse(); //6, 2, 1, 4, 3, 5, 7, 9, 8

    cout << endl << "Inorder (Copied Tree): ";
    myCopiedTree.inorderTraverse(); //1, 2, 3, 4, 5, 6, 7, 8, 9

    cout << endl << "Postorder (Copied Tree): ";
    myCopiedTree.postorderTraverse(); //1, 3, 5, 4, 2, 8, 9, 7, 6

    cout << endl;

    /*
        clear method test
    */
    myTree.clear();

    cout << endl << "Node Count (After Clear): " << myTree.nodeCount() << endl;
    cout << "Height (After Clear): " << myTree.getHeight() << endl;

    cout << "Preorder (After Clear): ";
    myTree.preorderTraverse(); //6, 2, 1, 4, 3, 5, 7, 9, 8

    cout << endl << "Inorder (After Clear): ";
    myTree.inorderTraverse(); //1, 2, 3, 4, 5, 6, 7, 8, 9

    cout << endl << "Postorder (After Clear): ";
    myTree.postorderTraverse(); //1, 3, 5, 4, 2, 8, 9, 7, 6

    cout << endl;
}
