/*
Title: Array Heap
Author: Edwin Khew
Description: Array heap class declaration.
Date Created: 6/21/2021
*/

#ifndef HEAP_H_
#define HEAP_H_

template <class ItemType>
class Heap
{
public:
    /*
        default constructor
    */
    Heap();

    /*
        inserts a new item into the heap
        @param new_item, item to insert into the heap
    */
    void insert(const ItemType &new_item);

    /*
        removes the item in the root node of the heap
    */
    void remove();

    /*
        removes every node from the heap
    */
    void clear();

    /*
        returns the right child of the specified item
        @param item, item to get right child of
    */
    ItemType getRightChild(ItemType &item);

    /*
        returns the right child of the specified item
        @param item, item to get left child of
    */
    ItemType getLeftChild(ItemType &item);

    /*
        checks if the heap is empty
        @return true if the heap is empty, and false otherwise
    */
    bool isEmpty() const;

    /*
        checks if the heap is full
        @return true if the heap is full, and false otherwise
    */
    bool isFull() const;

    /*
        prints the item in the root node of the heap
    */
    void peek() const;

    /*
        prints the entire array heap
    */
    void display() const;
private:
    static const int CAPACITY = 20; //capacity of the array heap
    ItemType heap_[CAPACITY]; //the array heap itself
    size_t item_count_; //total number of items currently in the heap

    /*
        heapifies the array
        @param item, item to check with parent to see if heap conditions are satisfied
    */
    void heapify(const ItemType &item);
};

#include "Heap.cpp"
#endif
