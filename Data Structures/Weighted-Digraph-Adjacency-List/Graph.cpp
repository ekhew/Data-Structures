/*
Title: Weighted Digraph (Adjacency List)
Author: Edwin Khew
Description: Weighted digraph (adjacency list) class implementation.
Date Created: 7/24/2021
*/

#include <map>
#include <list>
#include <queue> //for BFS
#include <stack> //for DFS
#include <utility> //for pairs

template <typename ItemType>
Graph<ItemType>::Graph() { }

template <typename ItemType>
void Graph<ItemType>::addVertex(ItemType item)
{
    Vertex<ItemType> new_vertex = Vertex<ItemType>(item); //create a new vertex object with the specified item
    std::list<std::pair<Vertex<ItemType>, int>> new_list; //create a new adjacency list that corresponds to the new vertex

    graph_[new_vertex] = new_list; //insert a new key-value pair, 'pair<new_vertex, new_list>', into the graph
}

template <typename ItemType>
void Graph<ItemType>::removeVertex(ItemType item)
{
    if(!isEmpty()) //can only remove vertex if the graph is not empty
    {
        graph_.erase(Vertex<ItemType>(item)); //erase the vertex with the specified item from the map

        typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::iterator i; //iterator used to traverse the map
        typename std::list<std::pair<Vertex<ItemType>, int>>::iterator j; //iterator used to traverse the adjacency lists

        //for every vertex currently in the map, remove any instance of the vertex to be removed from its adjacency list
        for(i = graph_.begin(); i != graph_.end(); i++)
        {
            for(j = i->second.begin(); j != i->second.end(); j++)
            {
                if(j->first.getItem() == item)
                {
                    j = i->second.erase(j);
                }
            }
        }
    }
}

template <typename ItemType>
void Graph<ItemType>::addEdge(ItemType item1, ItemType item2, int weight)
{
    typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::iterator i = graph_.find(Vertex<ItemType>(item1)); //find the vertex key with 'item1' and store into the iterator
    typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::iterator j = graph_.find(Vertex<ItemType>(item2)); //find the vertex key with 'item2' and store into the iterator

    if(!isEmpty() && i != graph_.end() && j != graph_.end()) //can only add an edge if graph is not empty and both vertices exist
    {
        i->second.push_back(std::pair<Vertex<ItemType>, int> (j->first, weight)); //insert the second vertex object into the first vertex object's adjacency list
    }
}

template <typename ItemType>
void Graph<ItemType>::removeEdge(ItemType item1, ItemType item2)
{
    typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::iterator i = graph_.find(Vertex<ItemType>(item1)); //find the vertex key with 'item1' and store into the iterator
    typename std::list<std::pair<Vertex<ItemType>, int>>::iterator j; //iterator used to traverse the adjacency lists

    if(!isEmpty() && i != graph_.end()) //can only remove an edge if graph is not empty and vertex with 'item1' exists
    {
        //remove the vertex with 'item2' from the adjacency list of the vertex with 'item1'
        for(j = i->second.begin(); j != i->second.end(); j++)
        {
            if(j->first.getItem() == item2)
            {
                j = i->second.erase(j);
            }
        }
    }
}

template <typename ItemType>
bool Graph<ItemType>::isEmpty() const
{
    return graph_.empty();
}

template <typename ItemType>
bool Graph<ItemType>::checkAdj(ItemType item1, ItemType item2) const
{
    typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::const_iterator i = graph_.find(Vertex<ItemType>(item1)); //find the vertex key with 'item1' and store into the iterator
    typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::const_iterator j = graph_.find(Vertex<ItemType>(item2)); //find the vertex key with 'item2' and store into the iterator

    if(!isEmpty() && i != graph_.end() && j != graph_.end()) //can only check adjacency if graph is not empty and both vertices exist
    {
        for(auto j : i->second) //loop through the adjacency list of the vertex with 'item1'
        {
            if(j.first.getItem() == item2) //if a matching item was found, then the vertices are adjacent
            {
                return true;
            }
        }
    }

    return false;
}

template <typename ItemType>
void Graph<ItemType>::printAdjVertices(ItemType item) const
{
    typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::const_iterator i = graph_.find(Vertex<ItemType>(item)); //find the vertex key with 'item' and store into the iterator

    if(!isEmpty() && i != graph_.end()) //can only print adjacent vertices if graph is not empty and vertex exist
    {
        for(auto j : i->second) //loop through the adjacency list of the vertex with 'item1'
        {
            std::cout << j.first.getItem() << " ";
        }
    }
    else
    {
        std::cout << "Vertex not found!";
    }
}

template <typename ItemType>
void Graph<ItemType>::BFS(ItemType start) const
{
    std::queue<Vertex<ItemType>> Q; //queue used to keep track of unvisited vertices
    std::map<Vertex<ItemType>, bool> visited_map; //map used to keep track of visited vertices; key = vertex and value = 'true'

    typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::const_iterator i = graph_.find(Vertex<ItemType>(start)); //find the starting vertex

    if(i != graph_.end()) //can only begin BFS if the starting vertex exists
    {
        Q.push(i->first); //push the starting vertex into queue
        visited_map[i->first] = true; //mark starting vertex as visited

        while(!Q.empty()) //continue traversing while the queue is not empty
        {
            Vertex<ItemType> curr_vertex = Q.front(); //vertex at the front of the queue
            std::cout << curr_vertex.getItem() << " ";
            Q.pop();

            typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::const_iterator j = graph_.find(Vertex<ItemType>(curr_vertex)); //find the current vertex to get its list

            for(auto adj_vertex : j->second) //traverse the current vertex's adjacency list
            {
                typename std::map<Vertex<ItemType>, bool>::const_iterator k = visited_map.find(Vertex<ItemType>(adj_vertex.first)); //check to see if the vertex has already been visited

                if(k == visited_map.end()) //if the adjacent vertex was not found in the 'visited' map, then push to queue and mark as visited
                {
                    Q.push(adj_vertex.first);
                    visited_map[adj_vertex.first] = true;
                }
            }
        }
    }
    else
    {
        std::cout << "Start vertex not found!";
    }
}

template <typename ItemType>
void Graph<ItemType>::iterativeDFS(ItemType start) const
{
    std::stack<Vertex<ItemType>> S; //stack used to keep track of unvisited vertices
    std::map<Vertex<ItemType>, bool> visited_map; //map used to keep track of visited vertices; key = vertex and value = 'true'

    typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::const_iterator i = graph_.find(Vertex<ItemType>(start)); //find the starting vertex

    if(i != graph_.end()) //can only begin DFS if the starting vertex exists
    {
        S.push(i->first); //push the starting vertex into stack
        visited_map[i->first] = true; //mark starting vertex as visited

        while(!S.empty()) //continue traversing while the stack is not empty
        {
            Vertex<ItemType> curr_vertex = S.top(); //vertex at the top of the stack
            std::cout << curr_vertex.getItem() << " ";
            S.pop();

            typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::const_iterator j = graph_.find(Vertex<ItemType>(curr_vertex)); //find the current vertex to get its list

            for(auto adj_vertex : j->second) //traverse the current vertex's adjacency list
            {
                typename std::map<Vertex<ItemType>, bool>::const_iterator k = visited_map.find(Vertex<ItemType>(adj_vertex.first)); //check to see if the vertex has already been visited

                if(k == visited_map.end()) //if the adjacent vertex was not found in the 'visited' map, then push to stack and mark as visited
                {
                    S.push(adj_vertex.first); //Note: the first element of the list is pushed first, so it will be the last element of the list visited in the stack
                    visited_map[adj_vertex.first] = true;
                }
            }
        }
    }
    else
    {
        std::cout << "Start vertex not found!";
    }
}

template <typename ItemType>
void Graph<ItemType>::recursiveDFS(ItemType start) const
{
    typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::const_iterator i = graph_.find(Vertex<ItemType>(start)); //search for the start vertex

    if(i != graph_.end()) //can only begin DFS if the starting vertex exists
    {
        std::map<Vertex<ItemType>, bool> visited_map; //map used to keep track of visited vertices; key = vertex and value = 'true'

        recursiveDFSHelper(start, &visited_map);
    }
    else
    {
        std::cout << "Start vertex not found!";
    }
}

template <typename ItemType>
void Graph<ItemType>::recursiveDFSHelper(ItemType curr_vertex, std::map<Vertex<ItemType>, bool> *visited_map) const
{
    typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::const_iterator i = graph_.find(Vertex<ItemType>(curr_vertex)); //find the current vertex
    (*visited_map)[i->first] = true; //mark current vertex as visited

    std::cout << i->first.getItem() << " ";

    for(auto adj_vertex : i->second) //traverse through the current vertex's adjacency list
    {
        typename std::map<Vertex<ItemType>, bool>::const_iterator k = visited_map->find(Vertex<ItemType>(adj_vertex.first)); //check to see if the vertex has already been visited

        if(k == visited_map->end())
        {
            recursiveDFSHelper(adj_vertex.first.getItem(), visited_map); //recursively call the function if the vertex has not been visited already
        }
    }
}

template <typename ItemType>
void Graph<ItemType>::display() const
{
    if(!isEmpty()) //can only print if the graph is not empty
    {
        typename std::map<Vertex<ItemType>, std::list<std::pair<Vertex<ItemType>, int>>>::const_iterator i; //iterator used to traverse the graph

        for(i = graph_.begin(); i != graph_.end(); i++)
        {
            std::cout << i->first.getItem(); //print the key of the current element

            for(auto j : i->second) //print every element in the adjacency list
            {
                std::cout << " --> (" << j.first.getItem() << " , " << j.second << ")";
            }

            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "Graph is empty!" << std::endl;
    }
}
