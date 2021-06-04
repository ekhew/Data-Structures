/*
Title: Binary Tree
Author: Edwin Khew
Description: Binary tree class declaration.
Date Created: 6/4/2021
*/

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

template <class ItemType>
class BinaryTree
{
public:
    /*
        default constructor
    */
    BinaryTree();

    /*
        copy constructor
        @param tree to be copied
    */
    BinaryTree(const BinaryTree<ItemType> &tree);

    /*
        destructor
    */
    ~BinaryTree();

    /*
        inserts a new node into the tree
        @param new_item, item to be added
    */
    void insert(const ItemType &new_item);

    /*
        removes a node from the tree
        @param item, item to be removed
    */
    void remove(const ItemType &item);

    /*
        removes every item in the tree
        @post tree is empty
    */
    void clear();

    /*
        checks if the tree is empty
        @return true if the tree is empty, and false otherwise
    */
    bool isEmpty() const;

    /*
        searches the three for a specified item
        @param item, item to look for in the tree
        @return a copy of the item if it is found
    */
    ItemType search(const ItemType &item) const;

    /*
        performs a preorder traversal of the entire tree
    */
    void preorderTraverse();

    /*
        performs an inorder traversal of the entire tree
    */
    void inorderTraverse();

    /*
        performs a postorder traversal of the entire tree
    */
    void postorderTraverse();
private:
    Node<ItemType> *root_ptr_; //pointer to the root node of the tree
    size_t item_count_; //total number of items currently in the tree
};

#include "BinaryTree.cpp"
#endif
