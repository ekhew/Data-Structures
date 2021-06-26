/*
Title: Singly Linked List
Author: Edwin Khew
Description: Singly linked list test file.
Date Created: 5/29/2021
*/

#include <iostream>
#include "Node.hpp"
#include "LinkedBag.hpp"

using namespace std;

int main()
{
    LinkedBag<int> myBag;

    myBag.insert(1);
    myBag.insert(2);
    myBag.insert(25);
    myBag.insert(3);
    myBag.insert(4);
    myBag.insert(5);
    myBag.insert(6);
    myBag.insert(7);
    myBag.insert(8);
    myBag.insert(9);
    myBag.insert(25);
    myBag.insert(25);
    myBag.insert(10);

    myBag.remove(1);
    myBag.remove(10);
    myBag.remove(5);

    cout << "Display: ";
    myBag.display();
    cout << endl << endl << "Empty?: " << myBag.isEmpty() << endl;
    cout << "Current Size: " << myBag.getCurrentSize() << endl;
    cout << "Frequency: " << myBag.getFrequencyOf(25) << endl;
    cout << "Contains: " << myBag.contains(25) << endl;

    /*
        copy constructor test
    */
    LinkedBag<int> myCopiedBag = myBag;
    cout << "Current Size (Copied List): " << myCopiedBag.getCurrentSize() << endl;
    cout << endl << "Display (Copied List): ";
    myCopiedBag.display();
    cout << endl << endl;

    /*
        clear method test
    */
    myBag.clear();
    cout << "Empty? (After clear): " << myBag.isEmpty() << endl;
    cout << "Length (After clear): " << myBag.getCurrentSize() << endl;
}
