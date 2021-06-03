/*
Title: Array Stack
Author: Edwin Khew
Description: Array stack class implementation.
Date Created: 5/31/2021
*/

template<typename ItemType>
ArrayStack<ItemType>::ArrayStack():top_index_(-1), item_count_(0) { }

template<typename ItemType>
bool ArrayStack<ItemType>::push(const ItemType &new_item)
{
    if(!isFull()) //can only add an item if the array is not full
    {
        stack_[item_count_] = new_item; //push the new item into the next available index
        top_index_++;
        item_count_++;

        return true;
    }
    else
    {
        return false;
    }
}

template<typename ItemType>
bool ArrayStack<ItemType>::pop()
{
    if(!isEmpty())
    {
        top_index_--;
        item_count_--;

        return true;
    }
    else
    {
        return false;
    }
}

template<typename ItemType>
void ArrayStack<ItemType>::clear()
{
    top_index_ = -1;
    item_count_ = 0;
}

template<typename ItemType>
size_t ArrayStack<ItemType>::size() const
{
    return item_count_;
}

template<typename ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
    return item_count_ == 0;
}

template<typename ItemType>
bool ArrayStack<ItemType>::isFull() const
{
    return item_count_ == CAPACITY;
}

template<typename ItemType>
void ArrayStack<ItemType>::peek() const
{
    if(!isEmpty()) //can only peek at the top if the stack is not empty
    {
        std::cout << stack_[top_index_];
    }
    else
    {
        std::cout << "Stack is empty!";
    }
}
