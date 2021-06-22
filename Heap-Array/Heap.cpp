/*
Title: Array Heap
Author: Edwin Khew
Description: Array heap class implementation.
Date Created: 6/21/2021
*/

template<typename ItemType>
Heap<ItemType>::Heap():item_count_(0) { }

template<typename ItemType>
void Heap<ItemType>::insert(const ItemType &new_item)
{
    if(!isFull()) //can only insert if the heap is not full
    {
        item_count_++;
        heap_[item_count_ - 1] = new_item; //insert the new item to the end of the array

        heapify(item_count_ - 1); //heapify the array
    }
}

template<typename ItemType>
void Heap<ItemType>::heapify(const ItemType &item)
{
    ItemType parent = (item - 1) / 2; //index of the item's parent

    if(heap_[item] > heap_[parent]) //if the child is greater than it parent, swap indices; use '>' for max-heap and '<' for min-heap
    {
        //swap
        ItemType temp = heap_[item];
        heap_[item] = heap_[parent];
        heap_[parent] = temp;

        //recursively call the function to check if the parent is greater than its parent
        heapify(parent);
    }
}

template<typename ItemType>
void Heap<ItemType>::clear()
{
    item_count_ = 0;
}

template<typename ItemType>
bool Heap<ItemType>::isEmpty() const
{
    return item_count_ == 0;
}

template<typename ItemType>
bool Heap<ItemType>::isFull() const
{
    return item_count_ == CAPACITY;
}

template<typename ItemType>
void Heap<ItemType>::peek() const
{
    if(!isEmpty()) //can only peek if the heap is not currently empty
    {
        std::cout << heap_[0];
    }
    else //if the heap is empty, print an error message
    {
        std::cout << "Heap is empty!";
    }
}

template<typename ItemType>
void Heap<ItemType>::display() const
{
    if(!isEmpty()) //can only display if the heap is not currently empty
    {
        for(int i = 0; i < item_count_; i++)
        {
            std::cout << heap_[i] << " ";
        }
    }
    else //if the heap is empty, print an error message
    {
        std::cout << "Heap is empty!";
    }
}
