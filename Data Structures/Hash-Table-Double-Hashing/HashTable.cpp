/*
Title: Hash Table (using double hashing)
Author: Edwin Khew
Description: Hash table class implementation.
Date Created: 7/3/2021
*/

#include <list>

template<typename ItemType>
HashTable<ItemType>::HashTable():item_count_(0), table_size_(11)
{
    hash_table_ = new HashItem<ItemType> *[table_size_];

//set each index to 'nullptr'
    for(int i = 0; i < table_size_; i++)
    {
        hash_table_[i] = nullptr;
    }
}

template<typename ItemType>
void HashTable<ItemType>::insert(int key, ItemType value)
{
    int hash1 = hashFunction1(key); //hash the key to get its address
    int hash2 = hashFunction2(key); //hash the key to get a value to increment with when collision occurs
    int i = 0; //used for incrementing when collision occurs

    HashItem<ItemType> *new_item = new HashItem<ItemType>(key, value); //create a new hash item (key-value pair)

    //insert at the first available (i * hash2)'th index found in the i'th iteration
    while(hash_table_[(hash1 + i * hash2) % table_size_] != nullptr)
    {
        i++;
    }

    hash_table_[(hash1 + i * hash2) % table_size_] = new_item;

    item_count_++;

    //if the load factor exceeds the specified limit after insertion of the new item, expand and rehash the table
    if(loadFactor() > 0.7)
    {
        rehashTable();
    }
}

template<typename ItemType>
void HashTable<ItemType>::remove(int key)
{
    int hash1 = hashFunction1(key); //hash the key to get its address
    int hash2 = hashFunction2(key); //hash the key to get a value to increment with when collision occurs
    int i = 0; //used for incrementing when collision occurs

    while(hash_table_[(hash1 + i * hash2) % table_size_] != nullptr) //checks all consecutive items until an empty index is reached; when an empty index is reached, then the item does not exist
    {
        //when an item with a matching key is found, remove it
        if(hash_table_[(hash1 + i * hash2) % table_size_]->getKey() == key)
        {
            hash_table_[(hash1 + i * hash2) % table_size_] = nullptr;
            break;
        }

        i++;
    }
}

template<typename ItemType>
void HashTable<ItemType>::clear()
{
    for(int i = 0; i < table_size_; i++) //loop through each index of the array
    {
        hash_table_[i] = nullptr;
    }

    item_count_ = 0;
}

template<typename ItemType>
bool HashTable<ItemType>::isEmpty()
{
    return item_count_ == 0;
}

template<typename ItemType>
size_t HashTable<ItemType>::itemCount()
{
    return item_count_;
}

template<typename ItemType>
ItemType HashTable<ItemType>::getValue(int key)
{
    int hash1 = hashFunction1(key); //hash the key to get its address
    int hash2 = hashFunction2(key); //hash the key to get a value to increment with when collision occurs
    int i = 0; //used for incrementing when collision occurs

    while(hash_table_[(hash1 + i * hash2) % table_size_] != nullptr)
    {
        //when an item with a matching key is found, return its value
        if(hash_table_[(hash1 + i * hash2) % table_size_]->getKey() == key)
        {
            return hash_table_[(hash1 + i * hash2) % table_size_]->getValue();
        }

        i++;
    }

    //if no matching key was found, throw an exception
    throw(std::out_of_range("Position out of range!"));
}

template<typename ItemType>
bool HashTable<ItemType>::contains(int key)
{
    int hash1 = hashFunction1(key); //hash the key to get its address
    int hash2 = hashFunction2(key); //hash the key to get a value to increment with when collision occurs
    int i = 0; //used for incrementing when collision occurs

    while(hash_table_[(hash1 + i * hash2) % table_size_] != nullptr)
    {
        //when an item with a matching key is found, return true
        if(hash_table_[(hash1 + i * hash2) % table_size_]->getKey() == key)
        {
            return true;
        }

        i++;
    }

    //if no matching key was found, return false
    return false;
}

template<typename ItemType>
void HashTable<ItemType>::display()
{
    for(int i = 0; i < table_size_; i++)
    {
        if(hash_table_[i] == nullptr)
        {
            std::cout << i << " " << std::endl;
        }
        else
        {
            std::cout << i << " " << hash_table_[i]->getValue() << std::endl;
        }
    }
}

template<typename ItemType>
int HashTable<ItemType>::hashFunction1(int key)
{
    return key % table_size_;
}

template<typename ItemType>
int HashTable<ItemType>::hashFunction2(int key)
{
    return 7 - (key % 7);
}

template<typename ItemType>
double HashTable<ItemType>::loadFactor()
{
    return (1.0 * item_count_) / table_size_;
}

template<typename ItemType>
void HashTable<ItemType>::rehashTable()
{
    HashItem<ItemType> **temp = hash_table_; //create a temporary copy of the old table

    size_t temp_size = table_size_; //create a temporary copy of the old table size
    table_size_ = 2 * table_size_; //increase the table size
    item_count_ = 0; //reset the item count

    hash_table_ = new HashItem<ItemType> *[table_size_]; //create a new array of pointers with the increased size

    //loop through the temporary copy and insert each item into the new table
    for(int i = 0; i < temp_size; i++)
    {
        if(temp[i] != nullptr)
        {
            insert(temp[i]->getKey(), temp[i]->getValue());
        }
    }

    //delete the old table and free memory
    delete[] temp;
    temp = nullptr;
}
