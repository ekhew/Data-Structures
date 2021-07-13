/*
Title: Undirected Graph (Adjacency List)
Author: Edwin Khew
Description: Undirected graph (adjacency list) test file.
Date Created: 7/11/2021
*/

#include <iostream>
#include "Vertex.hpp"
#include "Graph.hpp"

using namespace std;

int main()
{
    Graph<string> myGraph;

    myGraph.addVertex("Aa");
    myGraph.addVertex("Bb");
    myGraph.addVertex("Cc");
    myGraph.addVertex("Dd");
    myGraph.addVertex("Ee");

    myGraph.addEdge("Aa", "Bb");
    myGraph.addEdge("Aa", "Dd");

    //myGraph.removeVertex("Bb");

    myGraph.display();
}
