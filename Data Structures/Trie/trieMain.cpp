/*
Title: Trie
Author: Edwin Khew
Description: Trie test file.
Date Created: 7/4/2021
*/

#include <iostream>
#include "Node.hpp"
#include "Trie.hpp"

using namespace std;

int main()
{
    Trie myTrie;

    myTrie.insert("the");
    myTrie.insert("there");
    myTrie.insert("theory");
    myTrie.insert("theoretical");
    myTrie.insert("time");
    myTrie.insert("apple");
    myTrie.insert("apply");
    myTrie.insert("apocalypse");
    myTrie.insert("agriculture");
    myTrie.insert("energy");
    myTrie.insert("energetic");
    myTrie.insert("dinosaur");
    myTrie.insert("keyboard");

    myTrie.remove("there");

    cout << "Is Empty: " << myTrie.isEmpty() << endl;
    cout << "Word Count: " << myTrie.getWordCount() << endl;
    cout << "Prefix Count: " << myTrie.startsWith("theo") << endl;
    cout << "Search: " << myTrie.search("apple") << endl;
    cout << "Display: " << endl << endl;
    myTrie.display();
}
