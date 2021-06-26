/*
Title: Array Stack
Author: Edwin Khew
Description: Array stack class test file.
Date Created: 5/31/2021
*/

#include <iostream>
#include "ArrayStack.hpp"

using namespace std;

int main()
{
    ArrayStack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    myStack.push(6);
    myStack.push(7);
    myStack.push(8);
    myStack.push(9);
    myStack.push(10);

    //myStack.pop();
    //myStack.pop();
    //myStack.pop();

    cout << "Peek: ";
    myStack.peek();
    cout << endl << "Empty?: " << myStack.isEmpty() << endl;
    cout << "Full?: " << myStack.isFull() << endl;
    cout << "Size: " << myStack.size() << endl << endl;

    myStack.clear();
    cout << "Peek (After Clear): ";
    myStack.peek();
    cout << endl << "Empty? (After Clear): " << myStack.isEmpty() << endl;
    cout << "Full? (After Clear): " << myStack.isFull() << endl;
    cout << "Size (After Clear): " << myStack.size() << endl;
}
