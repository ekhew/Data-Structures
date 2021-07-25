/*
Title: Weighted Digraph (Adjacency List)
Author: Edwin Khew
Description: Weighted digraph (adjacency list) class declaration.
Date Created: 7/24/2021
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <list>
#include <utility> //for pairs

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
    void addEdge(ItemType item1, ItemType item2, int weight);

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
    void BFS(ItemType start) const;

    /*
        traverses the graph using DFS and prints every vertex; iterative approach
        @param start, the vertex to start the traversal from
    */
    void iterativeDFS(ItemType start) const;

    /*
        traverses the graph using DFS and prints every vertex; recursive approach
        @param start, the vertex to start the traversal from
    */
    void recursiveDFS(ItemType start) const;

    /*
        prints out every adjacency list that makes up the graph
    */
    void display() const;
private:
    std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>> graph_; //map of vertex - adjacency lists pairs; lists contain vertex - weight pairs

    /*
        traverses the graph using DFS and prints every vertex; recursive approach
        @param curr_vertex, the current vertex being visited
        @param visited_map, map used to keep track of visited vertices; key = vertex and value = 'true'
    */
    void recursiveDFSHelper(ItemType curr_vertex, std::map<Vertex<ItemType>, bool> *visited_map) const;
};

#include "Graph.cpp"
#endif
