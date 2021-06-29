/*
Title: Hash Table (using chaining)
Author: Edwin Khew
Description: Hash table test file.
Date Created: 6/27/2021
*/

#include <iostream>
#include "HashItem.hpp"
#include "HashTable.hpp"

using namespace std;

int main()
{
    HashTable<string> myTable;

    myTable.insert(279, "Penny");
    myTable.insert(298, "Shelly");
    myTable.insert(264, "Colt");
    myTable.insert(302, "Spike");
    myTable.insert(301, "Brock");
    myTable.insert(287, "Edgar");
    myTable.insert(289, "Sandy");
    myTable.insert(304, "Leon");
    myTable.insert(280, "Bea");
    myTable.insert(294, "Jessie");
    myTable.insert(295, "Tara");
    myTable.insert(334, "Rosa");
    myTable.insert(292, "Crow");
    myTable.insert(300, "Lou");

    //myTable.remove(301);

    cout << "Is Empty: " << myTable.isEmpty() << endl;
    cout << "Item Count: " << myTable.itemCount() << endl;
    cout << "Contains: " << myTable.contains(301) << endl;

    try
    {
        cout << "Get Value: " << myTable.getValue(279) << endl;
    }
    catch(const std::out_of_range& problem)
    {
        cout << "Item not found!" << endl;
    }

    cout << "Display: " << endl << endl;
    myTable.display();

    myTable.clear();

    cout << endl << "Is Empty (After clear): " << myTable.isEmpty() << endl;
    cout << "Item Count (After clear): " << myTable.itemCount() << endl;
    cout << "Display (After clear): " << endl << endl;
    myTable.display();
}
