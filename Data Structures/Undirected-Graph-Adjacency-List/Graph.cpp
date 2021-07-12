/*
Title: Undirected Graph (Adjacency List)
Author: Edwin Khew
Description: Undirected graph (adjacency list) class implementation.
Date Created: 7/11/2021
*/

template <class ItemType>
Graph<ItemType>::Graph():vertices_(0), edges_(0)
{
    vertex_list_ = new std::list<Vertex<ItemType>>[10]; //initial size of '10'
}

template <class ItemType>
Graph<ItemType>::Graph(int size):vertices_(0), edges_(0)
{
    vertex_list_ = new std::list<Vertex<ItemType>>[size];
}

template <class ItemType>
void Graph<ItemType>::addVertex(ItemType item)
{
    Vertex<ItemType> *new_vertex = new Vertex<ItemType>(item);
}

template <class ItemType>
bool Graph<ItemType>::isEmpty()
{
    return vertices_ == 0;
}
