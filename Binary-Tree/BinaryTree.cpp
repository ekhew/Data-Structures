/*
Title: Binary Tree
Author: Edwin Khew
Description: Binary tree class implementation.
Date Created: 6/4/2021
*/

template<typename ItemType>
BinaryTree<ItemType>::BinaryTree():root_ptr_(nullptr), item_count_(0) { }

/*
template<typename ItemType>
BinaryTree<ItemType>::BinaryTree(const BinaryTree<ItemType> &tree)
{

}
*/

template<typename ItemType>
BinaryTree<ItemType>::~BinaryTree()
{
    clear();
}

/*
template<typename ItemType>
void BinaryTree<ItemType>::insert(const ItemType &new_item)
{

}
*/

/*
template<typename ItemType>
void BinaryTree<ItemType>::remove(const ItemType &item)
{

}
*/

/*
template<typename ItemType>
void BinaryTree<ItemType>::clear()
{

}
*/

template<typename ItemType>
bool BinaryTree<ItemType>::isEmpty() const
{
    return item_count_ == 0;
}

/*
template<typename ItemType>
ItemType BinaryTree<ItemType>::search(const ItemType &item) const
{

}
*/

/*
template<typename ItemType>
void BinaryTree<ItemType>::preorderTraverse()
{

}
*/

/*
template<typename ItemType>
void BinaryTree<ItemType>::inorderTraverse()
{

}
*/

/*
template<typename ItemType>
void BinaryTree<ItemType>::postorderTraverse()
{

}
*/
