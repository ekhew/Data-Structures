/*
Title: Priority Queue Node
Author: Edwin Khew
Description: Priority queue node class declaration.
Date Created: 6/3/2021
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
    Node(const ItemType &item, int priority);

    /*
        parameterized constructor
        @param item to be set in the node
        @param next_pointer, pointer to the next node
    */
    Node(const ItemType &item, Node<ItemType> *next, int priority);

    /*
        sets an item in the calling node
        @param item to be set in the node
    */
    void setItem(const ItemType &item);

    /*
        sets the pointer to the next node in the calling node
        @param next_pointer, pointer to the next node
    */
    void setNext(Node<ItemType> *next);

    /*
        sets the pointer to the next node in the calling node
        @param next_pointer, pointer to the next node
    */
    void setPriority(int &priority);

    /*
        returns the item in the calling node
        @return a copy of the item in the node
    */
    ItemType getItem() const;

    /*
        return the pointer to the next node
        @return pointer to the next node
    */
    Node<ItemType> *getNext() const;

    /*
        return the priority of the item in the node
        @return an integer representing the priority of the item in the node
    */
    int getPriority() const;
private:
    ItemType item_; //item that is stored in the node
    int priority_; //priority of the item in the node
    Node<ItemType> *next_ptr_; //pointer to the next node in the queue
};

#include "Node.cpp"
#endif
