/*
Title: Array Queue
Author: Edwin Khew
Description: Array queue class declaration.
Date Created: 6/2/2021
*/

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

template <class ItemType>
class ArrayQueue
{
public:
    /*
        default constructor
    */
    ArrayQueue();

    /*
        inserts a new item into the queue
        @param new_item, item to be inserted
        @return true if the item was successfully inserted, and false otherwise
    */
    bool enqueue(const ItemType &new_item);

    /*
        removes the item at the front of the queue
        @return true if the item was successfully removed, and false otherwise
    */
    bool dequeue();

    /*
        clears the queue
        @post queue is now empty
    */
    void clear();

    /*
        returns the current number of items in the queue
        @return item_count_
    */
    size_t size() const;

    /*
        checks if the queue is empty
        @return true if the queue is empty, and false otherwise
    */
    bool isEmpty() const;

    /*
        checks if the queue is full
        @return true if the queue is full, and false otherwise
    */
    bool isFull() const;

    /*
        prints a copy of the item at the front of the queue
    */
    void peek() const;
private:
    static const int CAPACITY = 10; //capacity of the array queue
    ItemType queue_[CAPACITY]; //the array queue itself
    int front_index_; //index of the item at the front of the queue
    int back_index_; //index of the item at the back of the queue
    size_t item_count_; //total number of items currently in the queue
};

#include "ArrayQueue.cpp"
#endif
