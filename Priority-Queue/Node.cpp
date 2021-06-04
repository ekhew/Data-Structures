/*
Title: Priority Queue Node
Author: Edwin Khew
Description: Priority queue node class implementation.
Date Created: 6/3/2021
*/

template<typename ItemType>
Node<ItemType>::Node():next_ptr_(nullptr) { }

template<typename ItemType>
Node<ItemType>::Node(const ItemType &item, int priority):next_ptr_(nullptr), item_(item), priority_(priority) { }

template<typename ItemType>
Node<ItemType>::Node(const ItemType &item, Node<ItemType> *next, int priority):next_ptr_(next), item_(item), priority_(priority) { }

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
void Node<ItemType>::setPriority(int &priority)
{
    priority_ = priority;
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

template<typename ItemType>
int Node<ItemType>::getPriority() const
{
    return priority_;
}
