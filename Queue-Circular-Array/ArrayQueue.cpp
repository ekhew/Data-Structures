/*
Title: Array Queue
Author: Edwin Khew
Description: Array queue class implementation.
Date Created: 6/2/2021
*/

template<typename ItemType>
ArrayQueue<ItemType>::ArrayQueue():front_index_(-1), back_index_(-1), item_count_(0) { }

template<typename ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType &new_item)
{
    if(!isFull()) //can only insert if the array is not full
    {
        back_index_ = (back_index_ + 1) % CAPACITY; //increments 'back_index_'; will loop back to the first index if it is the next available index
        queue_[back_index_] = new_item;

        //if the item being inserted is the first item to be inserted, set 'front_index_' to 0 to indicate that the array is no longer empty
        if(item_count_ == 0)
        {
            front_index_ = 0;
        }

        item_count_++;
        return true;
    }
    else
    {
        return false;
    }
}

template<typename ItemType>
bool ArrayQueue<ItemType>::dequeue()
{
    if(!isEmpty()) //can only remove if the array is not empty
    {
        front_index_ = (front_index_ + 1) % CAPACITY; //increments 'front_index_'; will loop back to the first index when the last index has been reached

        //if the item being removed is the only item in the queue, set 'back_index_' to -1 to indicate that the array is empty
        if(item_count_ == 1)
        {
            back_index_ = -1;
        }

        item_count_--;
        return true;
    }
    else
    {
        return false;
    }
}

template<typename ItemType>
void ArrayQueue<ItemType>::clear()
{
    front_index_ = -1;
    back_index_ = -1;
    item_count_ = 0;
}

template<typename ItemType>
size_t ArrayQueue<ItemType>::size() const
{
    return item_count_;
}

template<typename ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
    return item_count_ == 0;
}

template<typename ItemType>
bool ArrayQueue<ItemType>::isFull() const
{
    return item_count_ == CAPACITY;
}

template<typename ItemType>
void ArrayQueue<ItemType>::peek() const
{
    if(!isEmpty()) //can only peek at the front if the queue is not empty
    {
        std::cout << queue_[front_index_];
    }
    else
    {
        std::cout << "Queue is empty!";
    }
}
