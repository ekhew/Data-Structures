/*
Title: Array Heap
Author: Edwin Khew
Description: Array heap class test file.
Date Created: 6/21/2021
*/

#include <iostream>
#include "Heap.hpp"

using namespace std;

int main()
{
    Heap<int> myHeap;

    myHeap.insert(11);
    myHeap.insert(2);
    myHeap.insert(7);
    myHeap.insert(9);
    myHeap.insert(5);
    myHeap.insert(6);
    myHeap.insert(4);
    myHeap.insert(8);
    myHeap.insert(10);
    myHeap.insert(3);
    myHeap.insert(1);

    cout << "Display: ";
    myHeap.display();
    cout << endl<< "Peek: ";
    myHeap.peek();
    cout << endl << "Empty?: " << myHeap.isEmpty() << endl;
    cout << "Full?: " << myHeap.isFull() << endl;

    myHeap.clear();
    cout << "Peek (After Clear): ";
    myHeap.peek();
    cout << endl << "Empty? (After Clear): " << myHeap.isEmpty() << endl;
    cout << "Full? (After Clear): " << myHeap.isFull() << endl;
}
