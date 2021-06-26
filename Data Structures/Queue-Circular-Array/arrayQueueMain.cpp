/*
Title: Array Queue
Author: Edwin Khew
Description: Array queue class test file.
Date Created: 6/2/2021
*/

#include <iostream>
#include "ArrayQueue.hpp"

using namespace std;

int main()
{
    ArrayQueue<int> myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);
    myQueue.enqueue(7);
    myQueue.enqueue(8);
    myQueue.enqueue(9);
    myQueue.enqueue(10);

    //myQueue.dequeue();
    //myQueue.dequeue();
    //myQueue.dequeue();

    //myQueue.enqueue(11);
    //myQueue.enqueue(12);

    cout << "Peek: ";
    myQueue.peek();
    cout << endl << "Empty?: " << myQueue.isEmpty() << endl;
    cout << "Full?: " << myQueue.isFull() << endl;
    cout << "Size: " << myQueue.size() << endl << endl;

    myQueue.clear();
    cout << "Peek (After Clear): ";
    myQueue.peek();
    cout << endl << "Empty? (After Clear): " << myQueue.isEmpty() << endl;
    cout << "Full? (After Clear): " << myQueue.isFull() << endl;
    cout << "Size (After Clear): " << myQueue.size() << endl;
}
