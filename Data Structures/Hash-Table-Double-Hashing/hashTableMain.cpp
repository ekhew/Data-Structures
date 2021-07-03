/*
Title: Hash Table (using double hashing)
Author: Edwin Khew
Description: Hash table test file.
Date Created: 7/3/2021
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

    //myTable.remove(304);

    //Clustering test
/*
    myTable.insert(3, "A");
    myTable.insert(14, "B");
    myTable.insert(25, "C");
    myTable.insert(36, "D");
    myTable.insert(47, "E");
    myTable.insert(58, "G");
*/

    cout << "Is Empty: " << myTable.isEmpty() << endl;
    cout << "Item Count: " << myTable.itemCount() << endl;
    cout << "Contains: " << myTable.contains(280) << endl;

    try
    {
        cout << "Get Value: " << myTable.getValue(304) << endl;
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
