/*
Title: Singly Linked List
Author: Edwin Khew
Description: Singly linked list test file.
Date Created: 5/27/2021
*/

#include <iostream>
#include "Node.hpp"
#include "SinglyLinkedList.hpp"

using namespace std;

int main()
{
    SinglyLinkedList<string> myList;

    myList.insert(1, "one");
    myList.insert(2, "two");
    myList.insert(3, "three");
    myList.insert(4, "four");
    myList.insert(5, "five");
    myList.insert(6, "six");
    myList.insert(3, "two-and-a-half");

    myList.remove(0);
    //myList.remove(4);
    //myList.remove(2);

    cout << "Display: ";
    myList.display();
    cout << endl << "Empty?: " << myList.isEmpty() << endl;
    cout << "Length: " << myList.getLength() << endl;

    try
    {
        cout << "Get Item: " << myList.getItemAtPos(7) << endl;
    }
    catch(const std::out_of_range& problem)
    {
        cout << "Position out of range!" << endl;
    }

    /*
        copy constructor test
    */
    SinglyLinkedList<string> myCopiedList = myList;
    cout << endl << "Display (Copied List): ";
    myCopiedList.display();
    cout << endl << "Empty? (Copied List): " << myCopiedList.isEmpty() << endl;
    cout << "Length (Copied List): " << myCopiedList.getLength() << endl << endl;

    /*
        clear method test
    */
    myList.clear();
    cout << "Display (Afetr clear): ";
    myCopiedList.display();
    cout << endl << "Empty? (After clear): " << myList.isEmpty() << endl;
    cout << "Length (After clear): " << myList.getLength() << endl;
}
