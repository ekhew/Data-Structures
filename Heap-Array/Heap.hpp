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
        returns the current height of the heap; counts the height in nodes
        @return integer representing the height of the heap
    */
    int getHeight() const;

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
        heapifies the array in a bottom-up approach
        @param item_index, index of item to check with parent to see if heap conditions are satisfied
    */
    void insertHeapify(const ItemType &item_index);

    /*
        heapifies the array in a top-down approach
        @param item_index, index of item to check with children to see if heap conditions are satisfied
    */
    void removeHeapify(const ItemType &item_index);
};

#include "Heap.cpp"
#endif
