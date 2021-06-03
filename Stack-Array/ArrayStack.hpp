/*
Title: Array Stack
Author: Edwin Khew
Description: Array stack class declaration.
Date Created: 5/31/2021
*/

#ifndef ARRAY_STACK_H_
#define ARRAY_STACK_H_

template <class ItemType>
class ArrayStack
{
public:
    /*
        default constructor
    */
    ArrayStack();

    /*
        inserts a new item into the top of the stack
        @param new_item, item to be inserted
        @return true if the item was successfully inserted, and false otherwise
    */
    bool push(const ItemType &new_item);

    /*
        removes the item at the top of the stack
        @return true if the item was successfully removed, and false otherwise
    */
    bool pop();

    /*
        clears the stack
        @post stack is now empty
    */
    void clear();

    /*
        returns the current number of items in the stack
        @return item_count_
    */
    size_t size() const;

    /*
        checks if the stack is empty
        @return true if the stack is empty, and false otherwise
    */
    bool isEmpty() const;

    /*
        checks if the stack is full
        @return true if full, and false otherwise
    */
    bool isFull() const;

    /*
        prints a copy of the item at the top of the stack
    */
    void peek() const;
private:
    static const int CAPACITY = 20; //capacity of the array stack
    ItemType stack_[CAPACITY]; //the array stack itself
    int top_index_; //index of the topmost item
    size_t item_count_; //total number of items currently in the stack
};

#include "ArrayStack.cpp"
#endif
