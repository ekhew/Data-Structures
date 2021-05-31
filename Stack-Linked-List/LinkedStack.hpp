/*
Title: Linked Stack
Author: Edwin Khew
Description: Linked stack class declaration.
Date Created: 5/31/2021
*/

#ifndef LINKED_STACK_H_
#define LINKED_STACK_H_

template <class ItemType>
class LinkedStack
{
public:
    /*
        default constructor
    */
    LinkedStack();

    /*
        copy constructor
        @param stack to be copied
    */
    LinkedStack(const LinkedStack<ItemType> &stack);

    /*
        destructor
    */
    ~LinkedStack();

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
        returns the current number of items in the stack (current number of nodes)
        @return item_count_
    */
    size_t size() const;

    /*
        checks if the stack is empty
        @return true if the stack is empty, and false otherwise
    */
    bool isEmpty() const;

    /*
        prints a copy of the item at the top of the stack
    */
    void peek() const;
private:
    Node<ItemType> *top_ptr_; //pointer to the topmost node in the stack
    size_t item_count_; //total number of items currently in the stack
};

#include "LinkedStack.cpp"
#endif
