/*
Title: Double Ended Queue (Deque) Node
Author: Edwin Khew
Description: Double ended queue node class declaration.
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
    Node(const ItemType &item);

    /*
        parameterized constructor
        @param item to be set in the node
        @param next_pointer, pointer to the next node
    */
    Node(const ItemType &item, Node<ItemType> *next, Node<ItemType> *previous);

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
        @param next_pointer, pointer to the next node
    */
    void setNext(Node<ItemType> *next);

    /*
        sets the pointer to the previous node in the calling node
        @param previous, pointer to the previous node
    */
    void setPrev(Node<ItemType> *previous);

    /*
        return the pointer to the next node
        @return pointer to the next node
    */
    Node<ItemType> *getNext() const;

    /*
        return the pointer to the previous node
        @return pointer to the previous node
    */
    Node<ItemType> *getPrev() const;
private:
    ItemType item_; //item that is stored in the node
    Node<ItemType> *next_ptr_; //pointer to the next node in the queue
    Node<ItemType> *prev_ptr_; //pointer to the previous node in the queue
};

#include "Node.cpp"
#endif
