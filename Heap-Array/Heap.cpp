/*
Title: Array Heap
Author: Edwin Khew
Description: Array heap class implementation.
Date Created: 6/21/2021
*/

#include <math.h> //for finding height of heap

template<typename ItemType>
Heap<ItemType>::Heap():item_count_(0) { }

template<typename ItemType>
void Heap<ItemType>::insert(const ItemType &new_item)
{
    if(!isFull()) //can only insert if the heap is not full
    {
        item_count_++;
        heap_[item_count_ - 1] = new_item; //insert the new item to the end of the array

        insertHeapify(item_count_ - 1); //heapify the array
    }
}

template<typename ItemType>
void Heap<ItemType>::insertHeapify(const ItemType &item_index)
{
    int parent_index = (item_index - 1) / 2; //index of the item's parent

    if(heap_[item_index] > heap_[parent_index]) //swap if the child is greater (or less than for min-heap) than its parent; use '>' for max-heap and '<' for min-heap
    {
        //swap
        ItemType temp = heap_[item_index];
        heap_[item_index] = heap_[parent_index];
        heap_[parent_index] = temp;

        //recursively call the function to continue heapifying
        insertHeapify(parent_index);
    }
}

template<typename ItemType>
void Heap<ItemType>::remove()
{
    if(!isEmpty()) //can only remove if the heap is not empty
    {
        heap_[0] = heap_[item_count_ - 1]; //replace the item at the root with the item at the end of the array
        item_count_--;

        removeHeapify(0); //heapify the array
    }
}

//max-heap heapify
template<typename ItemType>
void Heap<ItemType>::removeHeapify(const ItemType &item_index)
{
    int left_child_index = (2 * item_index) + 1; //index of the item's left child
    int right_child_index = (2 * item_index) + 2; //index of the item's right child
    int greater_child_index = item_index; //index of the child that is greater; if no children are present, then the index will be that of the root

    //if the index of 'left_child' exists and its item is greater than that of the current greater child
    if((left_child_index < item_count_) && (heap_[left_child_index] > heap_[greater_child_index]))
    {
        greater_child_index = left_child_index;
    }

    //if the index of 'right_child' exists and its item is greater than that of the current greater child
    if((right_child_index < item_count_) && (heap_[right_child_index] > heap_[greater_child_index]))
    {
        greater_child_index = right_child_index;
    }

    if(greater_child_index != item_index) //can only swap if a child is present
    {
        //swap
        ItemType temp = heap_[item_index];
        heap_[item_index] = heap_[greater_child_index];
        heap_[greater_child_index] = temp;

        //recursively call the function to continue heapifying
        removeHeapify(greater_child_index);
    }
}

/*

//min-heap heapify
template<typename ItemType>
void Heap<ItemType>::removeHeapify(const ItemType &item_index)
{
    int left_child_index = (2 * item_index) + 1; //index of the item's left child
    int right_child_index = (2 * item_index) + 2; //index of the item's right child
    int lesser_child_index = item_index; //index of the child that is lesser; if no children are present, then the index will be that of the root

    //if the index of 'left_child' exists and its item is less than that of the current lesser child
    if((left_child_index < item_count_) && (heap_[left_child_index] < heap_[lesser_child_index]))
    {
        lesser_child_index = left_child_index;
    }

    //if the index of 'right_child' exists and its item is less than that of the current lesser child
    if((right_child_index < item_count_) && (heap_[right_child_index] < heap_[lesser_child_index]))
    {
        lesser_child_index = right_child_index;
    }

    if(lesser_child_index != item_index) //can only swap if a child is present
    {
        //swap
        ItemType temp = heap_[item_index];
        heap_[item_index] = heap_[lesser_child_index];
        heap_[lesser_child_index] = temp;

        //recursively call the function to continue heapifying
        removeHeapify(lesser_child_index);
    }
}

*/

template<typename ItemType>
void Heap<ItemType>::clear()
{
    item_count_ = 0;
}

template<typename ItemType>
int Heap<ItemType>::getHeight() const
{
    return ceil(log2(item_count_ + 1));
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
