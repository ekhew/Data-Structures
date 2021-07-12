/*
Title: Undirected Graph (Adjacency List) Vertex
Author: Edwin Khew
Description: Undirected graph (adjacency list) vertex class declaration.
Date Created: 7/11/2021
*/

#ifndef VERTEX_H_
#define VERTEX_H_

template <class ItemType>
class Vertex
{
public:
    /*
        default constructor
    */
    Vertex();

    /*
        parameterized constructor
    */
    Vertex(ItemType item);

    /*
        sets the item in the vertex to the specified item
        @param item, item to be set in the vertex
    */
    void setItem(ItemType item);

    /*
        returns the item of the calling vertex
        @return 'item_'
    */
    ItemType getItem() const;
private:
    ItemType item_; //item that is stored in the vertex
};

#include "Vertex.cpp"
#endif
