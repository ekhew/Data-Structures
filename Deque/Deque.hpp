/*
Title: Double Ended Queue (Deque)
Author: Edwin Khew
Description: Double ended queue class declaration.
Date Created: 6/3/2021
*/

#ifndef DEQUE_H_
#define DEQUE_H_

template <class ItemType>
class Deque
{
public:
    /*
        default constructor
    */
    Deque();

    /*
        copy constructor
        @param queue to be copied
    */
    Deque(const Deque<ItemType> &queue);

    /*
        destructor
    */
    ~Deque();

    /*
        inserts a new item into the front of the queue
        @param new_item, item to be inserted
        @return true if the item was successfully inserted, and false otherwise
    */
    bool enqueueFront(const ItemType &new_item);

    /*
        inserts a new item into the back of the queue
        @param new_item, item to be inserted
        @return true if the item was successfully inserted, and false otherwise
    */
    bool enqueueBack(const ItemType &new_item);

    /*
        removes the item at the front of the queue
        @return true if the item was successfully removed, and false otherwise
    */
    bool dequeueFront();

    /*
        removes the item at the back of the queue
        @return true if the item was successfully removed, and false otherwise
    */
    bool dequeueBack();

    /*
        clears the queue
        @post queue is now empty
    */
    void clear();

    /*
        returns the current number of items in the queue (current number of nodes)
        @return item_count_
    */
    size_t size() const;

    /*
        checks if the queue is empty
        @return true if the queue is empty, and false otherwise
    */
    bool isEmpty() const;

    /*
        prints a copy of the item at the front of the queue
    */
    void peekFront() const;

    /*
        prints a copy of the item at the back of the queue
    */
    void peekBack() const;
private:
    Node<ItemType> *front_ptr_; //pointer to the first node in the queue
    Node<ItemType> *back_ptr_; //pointer to the last node in the queue
    size_t item_count_; //total number of items currently in the queue
};

#include "Deque.cpp"
#endif
