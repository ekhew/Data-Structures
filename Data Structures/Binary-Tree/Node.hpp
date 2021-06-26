/*
Title: Binary Tree Node
Author: Edwin Khew
Description: Binary tree node class declaration.
Date Created: 6/4/2021
*/

#ifndef NODE_H_
#define NODE_H_

template <class ItemType>
class Node
{
public:
    /*
        default constructor
    */
    Node();

    /*
        parameterized constructor
        @param item to be set in the node
    */
    Node(const ItemType &item);

    /*
        parameterized constructor
        @param item to be set in the node
        @param left, pointer to the left child node
        @param right, pointer to the right child node
    */
    Node(const ItemType &item, Node<ItemType> *left, Node<ItemType> *right);

    /*
        sets an item in the calling node
        @param item to be set in the node
    */
    void setItem(const ItemType &item);

    /*
        sets the pointer to the left child node in the calling node
        @param next, pointer to the next node
    */
    void setLeft(Node<ItemType> *left);

    /*
        sets the pointer to the right child node in the calling node
        @param previous, pointer to the previous node
    */
    void setRight(Node<ItemType> *right);

    /*
        returns the item in the calling node
        @return a copy of the item in the node
    */
    ItemType getItem() const;

    /*
        return the pointer to the left child node
        @return pointer to the left child node
    */
    Node<ItemType> *getLeft() const;

    /*
        return the pointer to the right child node
        @return pointer to the right child node
    */
    Node<ItemType> *getRight() const;

    /*
        checks if the calling node is a leaf
        @return true if the node is a leaf, and false otherwise
    */
    bool isLeaf() const;
private:
    ItemType item_; //item that is stored in the node
    Node<ItemType> *left_ptr_; //pointer to the left child node
    Node<ItemType> *right_ptr_; //pointer to the right child node
};

#include "Node.cpp"
#endif
