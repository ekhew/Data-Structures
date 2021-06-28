/*
Title: Hash Item (Key-Value pair)
Author: Edwin Khew
Description: Hash item class declaration.
Date Created: 6/27/2021
*/

#ifndef HASH_ITEM_H_
#define HASH_ITEM_H_

template <class ItemType>
class HashItem
{
public:
    /*
        default constructor
    */
    HashItem();

    /*
        parameterized constructor
        @param key, key of the item
        @param value, value stored in the item
    */
    HashItem(int key, const ItemType value);

    /*
        sets the key of the calling item
        @param key, the new key to be set
    */
    void setKey(int key);

    /*
        sets the new value in the calling item
        @param value, new value to be set in the item
    */
    void setValue(const ItemType value);

    /*
        returns the key of the calling item
        @return an integer representing the key of the item
    */
    int getKey() const;

    /*
        returns the value of the calling item
        @return the value of the item
    */
    ItemType getValue() const;
private:
    int key_; //the key of the item
    ItemType value_; //the value stored in the item
};

#include "HashItem.cpp"
#endif
