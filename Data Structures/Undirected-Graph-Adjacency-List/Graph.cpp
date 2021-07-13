/*
Title: Undirected Graph (Adjacency List)
Author: Edwin Khew
Description: Undirected graph (adjacency list) class implementation.
Date Created: 7/11/2021
*/

#include <map>
#include <list>

template <typename ItemType>
Graph<ItemType>::Graph():vertices_(0), edges_(0) { }

template <typename ItemType>
void Graph<ItemType>::addVertex(ItemType item)
{
    Vertex<ItemType> new_vertex = Vertex<ItemType>(item);
    std::list<Vertex<ItemType>> new_list;

    graph_[new_vertex] = new_list;
}

template <typename ItemType>
void Graph<ItemType>::removeVertex(ItemType item)
{
    graph_.erase(Vertex<ItemType>(item));
}

template <typename ItemType>
void Graph<ItemType>::addEdge(ItemType item1, ItemType item2)
{
    typename std::map<Vertex<ItemType>, std::list<Vertex<ItemType>>>::iterator i = graph_.find(Vertex<ItemType>(item1));
    typename std::map<Vertex<ItemType>, std::list<Vertex<ItemType>>>::iterator j = graph_.find(Vertex<ItemType>(item2));

    i->second.push_back(j->first);
    j->second.push_back(i->first);
}

template <typename ItemType>
bool Graph<ItemType>::isEmpty()
{
    return vertices_ == 0;
}

template <typename ItemType>
void Graph<ItemType>::display()
{
    typename std::map<Vertex<ItemType>, std::list<Vertex<ItemType>>>::iterator i;

    for(i = graph_.begin(); i != graph_.end(); i++)
    {
        std::cout << i->first.getItem();

        for(auto j : i->second)
        {
            std::cout << " --> " << j.getItem();
        }

        std::cout << std::endl;
    }
}
