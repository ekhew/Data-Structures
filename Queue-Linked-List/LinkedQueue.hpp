/*
Title: Linked Queue
Author: Edwin Khew
Description: Linked queue class declaration.
Date Created: 6/1/2021
*/

#ifndef LINKED_QUEUE_H_
#define LINKED_QUEUE_H_

template <class ItemType>
class LinkedQueue
{
public:
    /*
        default constructor
    */
    LinkedQueue();

    /*
        copy constructor
        @param queue to be copied
    */
    LinkedQueue(const LinkedQueue<ItemType> &queue);

    /*
        destructor
    */
    ~LinkedQueue();

    /*
        inserts a new item into the back of the queue
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

#include "LinkedQueue.cpp"
#endif
