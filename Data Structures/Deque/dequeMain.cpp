/*
Title: Double Ended Queue (Deque)
Author: Edwin Khew
Description: Double ended queue test file.
Date Created: 6/3/2021
*/

#include <iostream>
#include "Node.hpp"
#include "Deque.hpp"

using namespace std;

int main()
{
    Deque<string> myQueue;

    myQueue.enqueueFront("one");
    myQueue.enqueueFront("two");
    myQueue.enqueueFront("three");
    myQueue.enqueueBack("four");
    myQueue.enqueueBack("five");
    myQueue.enqueueBack("six");

    //myQueue.dequeueFront();
    //myQueue.dequeueFront();
    //myQueue.dequeueBack();
    //myQueue.dequeueBack();

    cout << "Peek Front: ";
    myQueue.peekFront();
    cout << endl << "Peek Back: ";
    myQueue.peekBack();
    cout << endl << "Empty?: " << myQueue.isEmpty() << endl;
    cout << "Size: " << myQueue.size() << endl << endl;

    /*
        copy constructor test
    */
    Deque<string> myCopiedQueue = myQueue;
    cout << "Peek Front (Copied List): ";
    myCopiedQueue.peekFront();
    cout << endl << "Peek Back: ";
    myCopiedQueue.peekBack();
    cout << endl << "Empty? (Copied List): " << myCopiedQueue.isEmpty() << endl;
    cout << "Size (Copied List): " << myCopiedQueue.size();
    cout << endl << endl;

    /*
        clear method test
    */
    myQueue.clear();
    cout << "Peek Front (After clear): ";
    myQueue.peekFront();
    cout << endl << "Peek Back: ";
    myQueue.peekBack();
    cout << endl << "Empty? (After clear): " << myQueue.isEmpty() << endl;
    cout << "Size (After clear): " << myQueue.size() << endl;
}
