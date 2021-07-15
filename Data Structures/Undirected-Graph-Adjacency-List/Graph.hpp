/*
Title: Undirected Graph (Adjacency List)
Author: Edwin Khew
Description: Undirected graph (adjacency list) class declaration.
Date Created: 7/11/2021
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <list>

template <class ItemType>
class Graph
{
public:
    /*
        default constructor
    */
    Graph();

    /*
        adds a new vertex into the graph
        @param item, the new vertex to add into the graph
    */
    void addVertex(ItemType item);

    /*
        removes a vertex from the graph
        @param item, vertex to remove from the graph
    */
    void removeVertex(ItemType item);

    /*
        adds an edge connecting two specified vertices
        @param item1, first vertex
        @param item2, second vertex
    */
    void addEdge(ItemType item1, ItemType item2);

    /*
        removes an edge connecting two specified vertices
        @param item1, first vertex
        @param item2, second vertex
    */
    void removeEdge(ItemType item1, ItemType item2);

    /*
        checks if the graph is currently empty
        @return true if the graph is empty, and false otherwise
    */
    bool isEmpty() const;

    /*
        checks if two specified vertices are adjacent
        @param item1, first vertex
        @param item2, second vertex
        @return true if the vertices are adjacent, and false otherwise
    */
    bool checkAdj(ItemType item1, ItemType item2) const;

    /*
        prints every adjacent vertex of the specified vertex
        @param item, the vertex to print every adjacent vertex of
    */
    void printAdjVertices(ItemType item) const;

    /*
        traverses the graph using BFS and prints every vertex
        @param start, the vertex to start the traversal from
    */
    void breadthFirstSearch(ItemType start) const;

    /*
        traverses the graph using DFS and prints every vertex
        @param start, the vertex to start the traversal from
    */
    void depthFirstSearch(ItemType start) const;

    /*
        prints out every adjacency list that makes up the graph
    */
    void display() const;
private:
    size_t vertices_; //number of vertices currently in the graph
    size_t edges_; //number of edges currently in the graph
    std::map<Vertex<ItemType>, std::list<Vertex<ItemType>>> graph_; //map of vertex - adjacency lists pairs
};

#include "Graph.cpp"
#endif
