/*
Title: Hash Table (using chaining)
Author: Edwin Khew
Description: Hash table class declaration.
Date Created: 6/27/2021
*/

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <list>

template <class ItemType>
class HashTable
{
public:
    /*
        constructor
    */
    HashTable();

    /*
        inserts a new item into the hash table
        @param key, key of the item to insert
        @param value, value of the item to insert
    */
    void insert(int key, const ItemType value);

    /*
        removes an item with the specified key from the hash table
        @param key, key of the item to remove
    */
    void remove(int key);

    /*
        removes every item from the hash table
    */
    void clear();

    /*
        checks if the table is currently empty
        @return true if the table is empty, false otherwise
    */
    bool isEmpty();

    /*
        returns the item with the specified key
        @param key, key of the item to search for
        @return the item with the matching key
    */
    ItemType getValue(int key);

    /*
        checks the table to see if a an item with the specified key exists
        @param key, key of the item to search for
        @return true if the item exists in the table, and false otherwise
    */
    bool contains(int key);

    /*
        prints every item currently in the table
    */
    void display();
private:
    static const int TABLE_SIZE = 11; //capacity of the hash table; the total number of available buckets
    std::list<HashItem<ItemType>> hash_table_[TABLE_SIZE]; //array of linked lists

    /*
        hash function; converts a key to an address
        @param key, key of the item to hash
        @return an integer representing the address of the item
    */
    int hashFunction(int key);
};

#include "HashTable.cpp"
#endif
