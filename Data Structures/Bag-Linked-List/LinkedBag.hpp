/*
Title: Linked Bag
Author: Edwin Khew
Description: Linked bag class declaration.
Date Created: 5/29/2021
*/

#ifndef LINKED_BAG_H_
#define LINKED_BAG_H_

template <class ItemType>
class LinkedBag
{
public:
    /*
        default constructor
    */
    LinkedBag();

    /*
        copy constructor
        @param bag to be copied
    */
    LinkedBag(const LinkedBag<ItemType> &bag);

    /*
        destructor
    */
    ~LinkedBag();

    /*
        insert an element into the front of the linked bag
        @param item to be inserted
        @return true if successfully inserted, false otherwise
    */
    bool insert(const ItemType &new_item);

    /*
        remove an element from the linked bag
        @param item to be removed
        @return true if successfully removed, false otherwise
    */
    bool remove(const ItemType &item);

    /*
        clears the linked bag
        @post memory is freed and item_count_ is set to 0
    */
    void clear();

    /*
        gets the frequency of a specified item in the bag
        @param item to find the frequency of
        @return an integer representing the frequency of the item
    */
    int getFrequencyOf(const ItemType &item) const;

    /*
        checks the array bag for the existence of a specified item
        @param item to check th existence of
        @return true if the item exists in the bag, and false otherwise
    */
    bool contains(const ItemType &item) const;

    /*
        returns the number of items currently in the bag
        @return item_count_
    */
    int getCurrentSize() const;

    /*
        checks if the bag is empty
        @return true if empty, and false otherwise
    */
    bool isEmpty() const;

    /*
        prints each individual element in the bag on a separate line
    */
    void display() const;
private:
    Node<ItemType> *head_ptr_; //pointer to the first node in the list
    size_t item_count_; //total number of items currently in the list

    /*
        helper function; gets the pointer to specified item
        @param item to find the pointer of
        @return a pointer to the node
    */
    Node<ItemType> *getPointerTo(const ItemType &item) const;
};

#include "LinkedBag.cpp"
#endif
