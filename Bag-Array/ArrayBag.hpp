/*
Title: Array Bag
Author: Edwin Khew
Description: Array bag class declaration.
Date Created: 5/26/2021
*/

#ifndef ARRAY_BAG_H_
#define ARRAY_BAG_H_

template <class ItemType>
class ArrayBag
{
public:
    /*
        default constructor
    */
    ArrayBag();

    /*
        insert an element into the array bag
        @param item to be inserted
        @return true if successfully inserted, false otherwise
    */
    bool insert(const ItemType &item);

    /*
        remove an element from the array bag
        @param item to be removed
        @return true if successfully removed, false otherwise
    */
    bool remove(const ItemType &item);

    /*
        clears the array bag
        @post item_count_ is set to 0
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
        checks if the bag is full
        @return true if full, and false otherwise
    */
    bool isFull() const;

    /*
        prints each individual element in the bag on a separate line
    */
    void display();

private:
    static const int CAPACITY = 20; //capacity of the array bag
    ItemType bag_[CAPACITY]; //the array bag itself
    int item_count_; //total number of items in the bag currently

    /*
        helper function; gets the index of a specified item
        @param item to find the index of
        @return an integer representing the index of the item
    */
    int getIndexOf(const ItemType &item) const;
};

#include "ArrayBag.cpp"
#endif
