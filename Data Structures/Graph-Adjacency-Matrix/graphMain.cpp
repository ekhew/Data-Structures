/*
Title: Undirected Graph (Adjacency Matrix)
Author: Edwin Khew
Description: Undirected graph (adjacency matrix) test file.
Date Created: 7/16/2021
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
    myGraph.addEdge("Aa", "Cc");
    myGraph.addEdge("Aa", "Dd");
    myGraph.addEdge("Bb", "Cc");
    myGraph.addEdge("Cc", "Ee");

    //myGraph.removeVertex("Ee");
    //myGraph.removeVertex("Zz");

    //myGraph.removeEdge("Cc", "Ee");

    cout << "Is Empty: " << myGraph.isEmpty() << endl;
    cout << "Vertex Count: " << myGraph.getVertexCount() << endl;
    cout << "Check Adjacency: " << myGraph.checkAdj("Aa", "Cc") << endl;
    cout << "Adjacent Vertices: ";
    myGraph.printAdjVertices("Bb");
    cout << endl << "BFS: ";
    myGraph.BFS("Aa");
    cout << endl << "DFS (Iterative): ";
    myGraph.iterativeDFS("Aa");
    cout << endl << "DFS (Recursive): ";
    myGraph.recursiveDFS("Aa");
    cout << endl << "Display: " << endl << endl;

    myGraph.display();
}
