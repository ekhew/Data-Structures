/*
Title: Hash Table (using chaining)
Author: Edwin Khew
Description: Hash table class implementation.
Date Created: 6/27/2021
*/

#include <list>

template<typename ItemType>
HashTable<ItemType>::HashTable() { }

template<typename ItemType>
void HashTable<ItemType>::insert(int key, ItemType value)
{
    int address = hashFunction(key); //hash the key to get its address

    HashItem<ItemType> new_item = HashItem<ItemType>(key, value); //create a new hash item (key-value pair)

    hash_table_[address].push_back(new_item); //insert the new item to the back of the list at the address
}

template<typename ItemType>
void HashTable<ItemType>::remove(int key)
{
    int address = hashFunction(key); //hash the key to get its address

    typename std::list<HashItem<ItemType>>::iterator i; //iterator used to traverse through the list
    for(i = hash_table_[address].begin(); i != hash_table_[address].end(); i++)
    {
        if(i->getKey() == key) //break from loop when a matching key is found
        {
            break;
        }
    }

    //only remove if a matching key was found; when the iterator reaches past the last item of the list at the address, this means no matching key was found
    if(i != hash_table_[address].end())
    {
        hash_table_[address].erase(i);
    }
}

template<typename ItemType>
void HashTable<ItemType>::display()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        std::cout << i;

        for(auto j : hash_table_[i])
        {
            std::cout << " --> " << j.getValue();
        }

        std::cout << std::endl;
    }
}

template<typename ItemType>
int HashTable<ItemType>::hashFunction(int key)
{
    return key % TABLE_SIZE;
}
