/*
Title: Linked Stack
Author: Edwin Khew
Description: Linked stack test file.
Date Created: 5/31/2021
*/

#include <iostream>
#include "Node.hpp"
#include "LinkedStack.hpp"

using namespace std;

int main()
{
    LinkedStack<string> myStack;

    myStack.push("one");
    myStack.push("two");
    myStack.push("three");
    myStack.push("four");
    myStack.push("five");
    myStack.push("six");

    myStack.pop();
    //myStack.pop();
    //myStack.pop();

    cout << "Peek: ";
    myStack.peek();
    cout << endl << "Empty?: " << myStack.isEmpty() << endl;
    cout << "Size: " << myStack.size() << endl << endl;

    /*
        copy constructor test
    */
    LinkedStack<string> myCopiedStack = myStack;
    cout << "Peek (Copied List): ";
    myCopiedStack.peek();
    cout << endl << "Empty? (Copied List): " << myCopiedStack.isEmpty() << endl;
    cout << "Size (Copied List): " << myCopiedStack.size();
    cout << endl << endl;

    /*
        clear method test
    */
    myStack.clear();
    cout << "Peek (After clear): ";
    myStack.peek();
    cout << endl << "Empty? (After clear): " << myStack.isEmpty() << endl;
    cout << "Size (After clear): " << myStack.size() << endl;
}
