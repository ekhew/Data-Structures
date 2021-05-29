/*
Title: Singly Linked List Node
Author: Edwin Khew
Description: Singly linked list node class declaration.
Date Created: 5/27/2021
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
        @param item, item to be set in the node
        @param next, pointer to the next node
    */
    Node(const ItemType &item, Node<ItemType> *next);

    /*
        sets an item in the calling node
        @param item to be set in the node
    */
    void setItem(const ItemType &item);

    /*
        returns the item in the calling node
        @return a copy of the item in the node
    */
    ItemType getItem() const;

    /*
        sets the pointer to the next node in the calling node
        @param next, pointer to the next node
    */
    void setNext(Node<ItemType> *next);

    /*
        return the pointer to the next node
        @return pointer to the next node
    */
    Node<ItemType> *getNext() const;
private:
    ItemType item_; //item that is stored in the node
    Node<ItemType> *next_ptr_; //pointer to the next node in the linked list
};

#include "Node.cpp"
#endif
