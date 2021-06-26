/*
Title: Linked Queue
Author: Edwin Khew
Description: Linked queue test file.
Date Created: 6/1/2021
*/

#include <iostream>
#include "Node.hpp"
#include "LinkedQueue.hpp"

using namespace std;

int main()
{
    LinkedQueue<string> myQueue;

    myQueue.enqueue("one");
    myQueue.enqueue("two");
    myQueue.enqueue("three");
    myQueue.enqueue("four");
    myQueue.enqueue("five");
    myQueue.enqueue("six");

    myQueue.dequeue();
    //myQueue.dequeue();
    //myQueue.dequeue();

    cout << "Peek: ";
    myQueue.peek();
    cout << endl << "Empty?: " << myQueue.isEmpty() << endl;
    cout << "Size: " << myQueue.size() << endl << endl;

    /*
        copy constructor test
    */
    LinkedQueue<string> myCopiedQueue = myQueue;
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
