/*
Title: Binary Search Tree (BST) Node
Author: Edwin Khew
Description: Binary search tree node class implementation.
Date Created: 6/4/2021
*/

template<typename ItemType>
Node<ItemType>::Node():left_ptr_(nullptr), right_ptr_(nullptr) { }

template<typename ItemType>
Node<ItemType>::Node(const ItemType &item):left_ptr_(nullptr), right_ptr_(nullptr), item_(item) { }

template<typename ItemType>
Node<ItemType>::Node(const ItemType &item, Node<ItemType> *left, Node<ItemType> *right):left_ptr_(left), right_ptr_(right), item_(item) { }

template<typename ItemType>
void Node<ItemType>::setItem(const ItemType &item)
{
    item_ = item;
}

template<typename ItemType>
void Node<ItemType>::setLeft(Node<ItemType> *left)
{
    left_ptr_ = left;
}

template<typename ItemType>
void Node<ItemType>::setRight(Node<ItemType> *right)
{
    right_ptr_ = right;
}

template<typename ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item_;
}

template<typename ItemType>
Node<ItemType> *Node<ItemType>::getLeft() const
{
    return left_ptr_;
}

template<typename ItemType>
Node<ItemType> *Node<ItemType>::getRight() const
{
    return right_ptr_;
}

template<typename ItemType>
bool Node<ItemType>::isLeaf() const
{
    return ((left_ptr_ == nullptr) && (right_ptr_ == nullptr));
}
