/*
Title: Weighted Digraph (Adjacency Matrix)
Author: Edwin Khew
Description: Weighted digraph (adjacency matrix) test file.
Date Created: 7/20/2021
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
    myGraph.addVertex("Ff");

    myGraph.addEdge("Aa", "Bb", 2);
    myGraph.addEdge("Aa", "Cc", 4);
    myGraph.addEdge("Bb", "Cc", 1);
    myGraph.addEdge("Bb", "Dd", 7);
    myGraph.addEdge("Cc", "Ee", 3);
    myGraph.addEdge("Dd", "Ff", 1);
    myGraph.addEdge("Ee", "Dd", 2);
    myGraph.addEdge("Ee", "Ff", 5);

    //myGraph.removeVertex("Ff");
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

    cout << endl << "Dijkstra's Algorithm: " << endl;
    myGraph.dijkstra("Aa");
}
