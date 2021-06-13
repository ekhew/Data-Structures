/*
Title: Binary Tree
Author: Edwin Khew
Description: Binary tree test file.
Date Created: 6/4/2021
*/

#include <iostream>
#include "Node.hpp"
#include "BinaryTree.hpp"

using namespace std;

int main()
{
	BinaryTree<int> myTree;

	myTree.insert(6);
	myTree.insert(2);
	myTree.insert(7);
	myTree.insert(1);
	myTree.insert(4);
	myTree.insert(3);
	myTree.insert(5);
	myTree.insert(9);
	myTree.insert(8);

	myTree.remove(6);

	cout << "Node Count: " << myTree.nodeCount() << endl;
	cout << "Height: " << myTree.getHeight() << endl;

	cout << "Level Order: ";
	myTree.levelorderTraverse(); //6, 2, 7, 1, 4, 3, 5, 9, 8
	cout << endl;

	myTree.printTree();
}

