/*
Title: Hash Item (Key-Value pair)
Author: Edwin Khew
Description: Hash item class implementation.
Date Created: 6/27/2021
*/

template<typename ItemType>
HashItem<ItemType>::HashItem() { }

template<typename ItemType>
HashItem<ItemType>::HashItem(int key, const ItemType value):key_(key), value_(value) { }

template<typename ItemType>
void HashItem<ItemType>::setKey(int key)
{
    key_ = key;
}

template<typename ItemType>
void HashItem<ItemType>::setValue(const ItemType value)
{
    value_ = value;
}

template<typename ItemType>
int HashItem<ItemType>::getKey() const
{
    return key_;
}

template<typename ItemType>
ItemType HashItem<ItemType>::getValue() const
{
    return value_;
}
