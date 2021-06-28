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

    myTable.remove(301);

    myTable.display();
}
