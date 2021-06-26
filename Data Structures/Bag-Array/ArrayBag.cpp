/*
Title: Array Bag
Author: Edwin Khew
Description: Array bag class implementation.
Date Created: 5/26/2021
*/

template<typename ItemType>
ArrayBag<ItemType>::ArrayBag():item_count_(0) { }

template<typename ItemType>
bool ArrayBag<ItemType>::insert(const ItemType &item)
{
    if(!isFull())
    {
        bag_[item_count_] = item; //add item to the next empty index
        item_count_++;

        return true;
    }
    else
    {
        return false;
    }
}

template<typename ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &item)
{
    int location = getIndexOf(item);

    if((!isEmpty()) && (location != -1))
    {
        bag_[location] = bag_[item_count_]; //replace the item with the last item in the bag

        item_count_--;
        return true;
    }
    else
    {
        return false;
    }
}

template<typename ItemType>
void ArrayBag<ItemType>::clear()
{
    item_count_ = 0;
}


template<typename ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &item) const
{
    int frequency = 0;

    //loop through every index, and increment 'frequency' everytime a mathing element is found
    for(int i = 0; i < item_count_; i++)
    {
        if(bag_[i] == item)
        {
            frequency++;
        }
    }

    return frequency;
}

template<typename ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &item) const
{
    return getIndexOf(item) > -1; //if index of the item > -1, then the item exists
}

template<typename ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return item_count_;
}

template<typename ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return item_count_ == 0;
}

template<typename ItemType>
bool ArrayBag<ItemType>::isFull() const
{
    return item_count_ == CAPACITY;
}

template<typename ItemType>
void ArrayBag<ItemType>::display() const
{
    for(int i = 0; i < item_count_; i++)
    {
        std::cout << bag_[i] << std::endl;
    }
}

template<typename ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &item) const
{
    bool found = false;
    int result = -1;
    int search_index = 0;

    while (!found && (search_index < item_count_))
    {
        if (bag_[search_index] == item)
        {
            found = true;
            result = search_index;
        }
        else
        {
            search_index++;
        }
    }

    return result;
}
