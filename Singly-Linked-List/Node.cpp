/*
Title: Singly Linked List Node
Author: Edwin Khew
Description: Singly linked list node class implementation.
Date Created: 5/27/2021
*/

template<typename ItemType>
Node<ItemType>::Node():next_ptr_(nullptr) { }

template<typename ItemType>
Node<ItemType>::Node(const ItemType &item):next_ptr_(nullptr), item_(item) { }

template<typename ItemType>
Node<ItemType>::Node(const ItemType &item, Node<ItemType> *next):next_ptr_(next), item_(item) { }

template<typename ItemType>
void Node<ItemType>::setItem(const ItemType &item)
{
    item_ = item;
}

template<typename ItemType>
void Node<ItemType>::setNext(Node<ItemType> *next)
{
    next_ptr_ = next;
}

template<typename ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item_;
}

template<typename ItemType>
Node<ItemType> *Node<ItemType>::getNext() const
{
    return next_ptr_;
}
