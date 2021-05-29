/*
Title: Singly Linked List
Author: Edwin Khew
Description: Singly linked list class declaration.
Date Created: 5/27/2021
*/

#ifndef SINGLY_LINKED_LIST_H_
#define SINGLY_LINKED_LIST_H_

template <class ItemType>
class SinglyLinkedList
{
public:
    /*
        default constructor
    */
    SinglyLinkedList();

    /*
        copy constructor
        @param list to be copied
    */
    SinglyLinkedList(const SinglyLinkedList<ItemType> &list);

    /*
        destructor
    */
    ~SinglyLinkedList();

    /*
        inserts a new item into the linked list
        @param new_item, item to be inserted
        @return true if the item was successfully inserted, and false otherwise
    */
    bool insert(size_t position, const ItemType &new_item);

    /*
        removes the item at the specified position
        @param position of the item to be removed
        @return true if the item was successfully removed, and false otehrwise
    */
    bool remove(size_t position);

    /*
        clears the linked list
        @post list is now empty
    */
    void clear();

    /*
        returns the current number of items in the list (current number of nodes)
        @return item_count_
    */
    size_t getLength() const;

    /*
        returns the item at the specified position
        @param position of the item in the list
        @return a copy of the item at the specified position
    */
    ItemType getItemAtPos(size_t position) const;

    /*
        checks if the list is empty
        @return true if the list is empty, and false otherwise
    */
    bool isEmpty() const;

    /*
        prints every element on a single line
    */
    void display() const;

private:
    Node<ItemType> *head_ptr_; //pointer to the first node in the list
    size_t item_count_; //total number of items currently in the list

    /*
        helper function; gets the pointer to a node at a specified position
        @param position of the node to find position of
        @return a pointer to the node
    */
    Node<ItemType> *getPointerTo(size_t position) const;
};

#include "SinglyLinkedList.cpp"
#endif
