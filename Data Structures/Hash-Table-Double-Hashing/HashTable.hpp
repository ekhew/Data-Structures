/*
Title: Hash Table (using double hashing)
Author: Edwin Khew
Description: Hash table class declaration.
Date Created: 7/3/2021
*/

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <list>

template <class ItemType>
class HashTable
{
public:
    /*
        default constructor
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
        returns the number of items currently in the table
        @return an integer representing the number of items currently in the table
    */
    size_t itemCount();

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
    size_t item_count_; //current number of items in the table
    size_t table_size_; //capacity of the hash table; the total number of available buckets
    HashItem<ItemType> **hash_table_; //array of hash items

    /*
        first hash function; converts a key to an address
        @param key, key of the item to hash
        @return an integer representing the address of the item
    */
    int hashFunction1(int key);

    /*
        second hash function; converts a key to a value to increment with when collision occurs
        @param key, key of the item to hash
        @return an integer representing the address of the item
    */
    int hashFunction2(int key);

    /*
        returns the load factor of the hash table
        @return a decimal number representing the current load factor of the table
    */
    double loadFactor();

    /*
        rehashes the table when the load factor exceeds the limit
    */
    void rehashTable();
};

#include "HashTable.cpp"
#endif
