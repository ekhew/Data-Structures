/*
Title: Doubly Linked List
Author: Edwin Khew
Description: Doubly linked list test file.
Date Created: 5/28/2021
*/

#include <iostream>
#include "Node.hpp"
#include "DoublyLinkedList.hpp"

using namespace std;

int main()
{
    DoublyLinkedList<string> myList;

    myList.insert(1, "one");
    myList.insert(2, "two");
    myList.insert(3, "three");
    myList.insert(4, "four");
    myList.insert(5, "five");
    myList.insert(6, "six");
    //myList.insert(3, "two-and-a-half");

    myList.remove(0);
    //myList.remove(4);
    myList.remove(2);

    cout << "Display: ";
    myList.display();
    cout << endl << "Display Backwards: ";
    myList.displayBackwards();
    cout << endl << "Empty?: " << myList.isEmpty() << endl;
    cout << "Length: " << myList.getLength() << endl;

    try
    {
        cout << "Get Item: " << myList.getItemAtPos(1) << endl;
    }
    catch(const std::out_of_range& problem)
    {
        cout << "Position out of range!" << endl;
    }

    /*
        copy constructor test
    */
    DoublyLinkedList<string> myCopiedList = myList;
    cout << endl << "Display (Copied List): ";
    myCopiedList.display();
    cout << endl << "Display Backwards (Copied List): ";
    myCopiedList.displayBackwards();
    cout << endl << "Empty? (Copied List): " << myCopiedList.isEmpty() << endl;
    cout << "Length (Copied List): " << myCopiedList.getLength() << endl << endl;

    /*
        clear method test
    */
    myList.clear();
    cout << "Display (Copied List): ";
    myList.display();
    cout << "Display Backwards (Copied List): ";
    myList.displayBackwards();
    cout << endl << "Empty? (After clear): " << myList.isEmpty() << endl;
    cout << "Length (After clear): " << myList.getLength() << endl;
}
