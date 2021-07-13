/*
Title: Undirected Graph (Adjacency List) Vertex
Author: Edwin Khew
Description: Undirected graph (adjacency list) vertex class implementation.
Date Created: 7/11/2021
*/

template<typename ItemType>
Vertex<ItemType>::Vertex() { }

template<typename ItemType>
Vertex<ItemType>::Vertex(ItemType item):item_(item) { }

template<typename ItemType>
void Vertex<ItemType>::setItem(ItemType item)
{
    item_ = item;
}

template<typename ItemType>
ItemType Vertex<ItemType>::getItem() const
{
    return item_;
}

template<typename ItemType>
bool Vertex<ItemType>::operator < (const Vertex& v) const
{
    if(item_ < v.item_) //if the item of the calling vertex is less than the comparing vertex's item
    {
        return true;
    }

    return false;
}
