/*
Title: Double Ended Queue (Deque) Node
Author: Edwin Khew
Description: Double ended queue node class implementation.
Date Created: 6/3/2021
*/

template<typename ItemType>
Node<ItemType>::Node():next_ptr_(nullptr), prev_ptr_(nullptr) { }

template<typename ItemType>
Node<ItemType>::Node(const ItemType &item):next_ptr_(nullptr), prev_ptr_(nullptr), item_(item) { }

template<typename ItemType>
Node<ItemType>::Node(const ItemType &item, Node<ItemType> *next, Node<ItemType> *previous):next_ptr_(next), prev_ptr_(previous), item_(item) { }

template<typename ItemType>
void Node<ItemType>::setItem(const ItemType &item)
{
    item_ = item;
}

template<typename ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item_;
}

template<typename ItemType>
void Node<ItemType>::setNext(Node<ItemType> *next)
{
    next_ptr_ = next;
}

template<typename ItemType>
void Node<ItemType>::setPrev(Node<ItemType> *previous)
{
    prev_ptr_ = previous;
}

template<typename ItemType>
Node<ItemType> *Node<ItemType>::getNext() const
{
    return next_ptr_;
}

template<typename ItemType>
Node<ItemType> *Node<ItemType>::getPrev() const
{
    return prev_ptr_;
}
