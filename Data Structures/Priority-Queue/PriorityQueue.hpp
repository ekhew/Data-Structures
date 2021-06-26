/*
Title: Priority Queue
Author: Edwin Khew
Description: Priority queue class declaration.
Date Created: 6/3/2021
*/

#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

template <class ItemType>
class PriorityQueue
{
public:
    /*
        default constructor
    */
    PriorityQueue();

    /*
        copy constructor
        @param queue to be copied
    */
    PriorityQueue(const PriorityQueue<ItemType> &queue);

    /*
        destructor
    */
    ~PriorityQueue();

    /*
        inserts a new item into the queue, based on its priority
        @param new_item, item to be inserted
        @return true if the item was successfully inserted, and false otherwise
    */
    bool enqueue(const ItemType &new_item, int priority);

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
    void peek() const;
private:
    Node<ItemType> *front_ptr_; //pointer to the first node in the queue
    Node<ItemType> *back_ptr_; //pointer to the last node in the queue
    size_t item_count_; //total number of items currently in the queue
};

#include "PriorityQueue.cpp"
#endif
