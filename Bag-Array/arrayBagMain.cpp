/*
Title: Array Bag
Author: Edwin Khew
Description: Array bag class testing.
Date Created: 5/26/2021
*/

#include <iostream>
#include "ArrayBag.hpp"

using namespace std;

int main()
{
    /*
        Integer Array Bag
    */

    ArrayBag<int> myBag;

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

    myBag.display();

    cout << endl << "Empty?: " << myBag.isEmpty() << endl;
    cout << "Full?: " << myBag.isFull() << endl;
    cout << "Current Size: " << myBag.getCurrentSize() << endl;
    cout << "Frequency: " << myBag.getFrequencyOf(25) << endl;
    cout << "Contains: " << myBag.contains(25) << endl;

    myBag.clear();
    cout << "Bag Empty After Clear?: " << myBag.isEmpty() << endl << endl;


    /*
        String Array Bag
    */

    ArrayBag<string> myBag2;

    myBag2.insert("one");
    myBag2.insert("two");
    myBag2.insert("twenty five");
    myBag2.insert("three");
    myBag2.insert("four");
    myBag2.insert("five");
    myBag2.insert("six");
    myBag2.insert("seven");
    myBag2.insert("eight");
    myBag2.insert("nine");
    myBag2.insert("twenty five");
    myBag2.insert("twenty five");
    myBag2.insert("ten");

    myBag2.remove("one");
    myBag2.remove("ten");
    myBag2.remove("five");

    myBag2.display();

    cout << endl << "Empty?: " << myBag2.isEmpty() << endl;
    cout << "Full?: " << myBag2.isFull() << endl;
    cout << "Current Size: " << myBag2.getCurrentSize() << endl;
    cout << "Frequency: " << myBag2.getFrequencyOf("twenty five") << endl;
    cout << "Contains: " << myBag2.contains("twenty five") << endl;

    myBag2.clear();
    cout << "Bag Empty After Clear?: " << myBag2.isEmpty() << endl;
}
