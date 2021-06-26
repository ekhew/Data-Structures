/*
Title: Priority Queue
Author: Edwin Khew
Description: Priority queue test file.
Date Created: 6/3/2021
*/

#include <iostream>
#include "Node.hpp"
#include "PriorityQueue.hpp"

using namespace std;

int main()
{
    PriorityQueue<string> myQueue;

    myQueue.enqueue("five", 5);
    myQueue.enqueue("one", 1);
    myQueue.enqueue("three", 3);
    myQueue.enqueue("three-2", 3);
    myQueue.enqueue("two", 2);
    myQueue.enqueue("four", 4);
    myQueue.enqueue("six", 6);
    myQueue.enqueue("three-3", 3);

    //myQueue.dequeue();
    //myQueue.dequeue();
    //myQueue.dequeue();

    cout << "Peek: ";
    myQueue.peek();
    cout << endl << "Empty?: " << myQueue.isEmpty() << endl;
    cout << "Size: " << myQueue.size() << endl << endl;

    /*
        copy constructor test
    */
    PriorityQueue<string> myCopiedQueue = myQueue;
    cout << "Peek (Copied List): ";
    myCopiedQueue.peek();
    cout << endl << "Empty? (Copied List): " << myCopiedQueue.isEmpty() << endl;
    cout << "Size (Copied List): " << myCopiedQueue.size();
    cout << endl << endl;

    /*
        clear method test
    */
    myQueue.clear();
    cout << "Peek (After clear): ";
    myQueue.peek();
    cout << endl << "Empty? (After clear): " << myQueue.isEmpty() << endl;
    cout << "Size (After clear): " << myQueue.size() << endl;
}
