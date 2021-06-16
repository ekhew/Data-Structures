/*
Title: Binary Tree
Author: Edwin Khew
Description: Binary tree test file.
Date Created: 6/4/2021
*/

#include <iostream>
#include "Node.hpp"
#include "BinaryTree.hpp"

using namespace std;

int main()
{
    BinaryTree<int> myTree;

    myTree.insert(5);
    myTree.insert(3);
    myTree.insert(8);
    myTree.insert(2);
    myTree.insert(4);
    myTree.insert(7);
    myTree.insert(9);
    myTree.insert(1);

    //myTree.remove(6);
    //myTree.remove(5);
    //myTree.remove(2);
    //myTree.remove(8);
    //myTree.remove(99);

    cout << "Node Count: " << myTree.nodeCount() << endl;
    cout << "Height: " << myTree.getHeight() << endl;

    cout << "Preorder: ";
    myTree.preorderTraverse();

    cout << endl << "Inorder: ";
    myTree.inorderTraverse();

    cout << endl << "Postorder: ";
    myTree.postorderTraverse();

    cout << endl << "Level Order: ";
    myTree.levelorderTraverse(); //5, 3, 8, 2, 4, 7, 9, 1

    try
    {
        cout << endl << "Search: " << myTree.search(5) << endl;
    }
    catch(const std::out_of_range& problem)
    {
        cout << "Item not found!" << endl;
    }

    try
    {
        cout << "Min: " << myTree.findMin() << endl;
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

    cout << "Is a BST: " << myTree.isBST() << endl;

    myTree.printTree();

    /*
        copy constructor test
    */
    BinaryTree<int> myCopiedTree = myTree;

    cout << endl << "Node Count (Copied Tree): " << myCopiedTree.nodeCount() << endl;
    cout << "Height (Copied Tree): " << myCopiedTree.getHeight() << endl;

    cout << "Preorder (Copied Tree): ";
    myCopiedTree.preorderTraverse();

    cout << endl << "Inorder (Copied Tree): ";
    myCopiedTree.inorderTraverse();

    cout << endl << "Postorder (Copied Tree): ";
    myCopiedTree.postorderTraverse();

    cout << endl << "Level Order (Copied Tree): ";
    myTree.levelorderTraverse();

    cout << endl;

    /*
        clear method test
    */
    myTree.clear();

    cout << endl << "Node Count (After Clear): " << myTree.nodeCount() << endl;
    cout << "Height (After Clear): " << myTree.getHeight() << endl;

    cout << "Preorder (After Clear): ";
    myTree.preorderTraverse();

    cout << endl << "Inorder (After Clear): ";
    myTree.inorderTraverse();

    cout << endl << "Postorder (After Clear): ";
    myTree.postorderTraverse();

    cout << endl << "Level Order (After Clear): ";
    myTree.levelorderTraverse();

    cout << endl;
}
