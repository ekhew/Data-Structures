/*
Title: Hash Table (using chaining)
Author: Edwin Khew
Description: Hash table class implementation.
Date Created: 6/27/2021
*/

#include <list>

template<typename ItemType>
HashTable<ItemType>::HashTable():item_count_(0) { }

template<typename ItemType>
void HashTable<ItemType>::insert(int key, ItemType value)
{
    int address = hashFunction(key); //hash the key to get its address

    HashItem<ItemType> new_item = HashItem<ItemType>(key, value); //create a new hash item (key-value pair)

    hash_table_[address].push_back(new_item); //insert the new item to the back of the list at the address

    item_count_++;
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
        item_count_--;
    }
}

template<typename ItemType>
void HashTable<ItemType>::clear()
{
    for(int i = 0; i < TABLE_SIZE; i++) //loop through each index of the array
    {
        hash_table_[i].erase(hash_table_[i].begin(), hash_table_[i].end()); //for each list in the array, remove every item (erase in the range: first item -> past the last item)
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
    int address = hashFunction(key); //hash the key to get its address
    ItemType value;

    typename std::list<HashItem<ItemType>>::iterator i; //iterator used to traverse through the list
    for(i = hash_table_[address].begin(); i != hash_table_[address].end(); i++)
    {
        if(i->getKey() == key) //break from loop when a matching key is found
        {
            value = i->getValue();
            break;
        }
    }

    //only return value if a matching key was found; when the iterator reaches past the last item of the list at the address, this means no matching key was found
    if(i != hash_table_[address].end())
    {
        return value;
    }
    else //if no matching key was found, throw an exception
    {
        throw(std::out_of_range("Position out of range!"));
    }
}

template<typename ItemType>
bool HashTable<ItemType>::contains(int key)
{
    int address = hashFunction(key); //hash the key to get its address
    bool found = false;

    typename std::list<HashItem<ItemType>>::iterator i; //iterator used to traverse through the list
    for(i = hash_table_[address].begin(); i != hash_table_[address].end(); i++)
    {
        if(i->getKey() == key) //break from loop when a matching key is found
        {
            found = true;
            break;
        }
    }

    return found;
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
