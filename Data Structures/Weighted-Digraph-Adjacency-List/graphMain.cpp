/*
Title: Weighted Digraph (Adjacency List)
Author: Edwin Khew
Description: Weighted digraph (adjacency list) test file.
Date Created: 7/24/2021
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
    //myGraph.addEdge("Yy", "Zz", 99); //vertices do not exists

    //myGraph.removeVertex("Ff");
    //myGraph.removeVertex("Zz"); //vertex does not exists

    //myGraph.removeEdge("Aa", "Bb");
    //myGraph.removeEdge("Aa", "Cc"); //edge does not exist
    //myGraph.removeEdge("Aa", "Zz"); //vertices do not exists

    cout << "Is Empty: " << myGraph.isEmpty() << endl;
    cout << "Check Adjacency: " << myGraph.checkAdj("Bb", "Dd") << endl;
    cout << "Adjacent Vertices: ";
    myGraph.printAdjVertices("Ee");
    cout << endl << "BFS: ";
    myGraph.BFS("Aa");
    cout << endl << "DFS (Iterative): ";
    myGraph.iterativeDFS("Aa");
    cout << endl << "DFS (Recursive): ";
    myGraph.recursiveDFS("Aa");
    cout << endl << "Display: " << endl << endl;

    myGraph.display();
}
