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
    myTrie.insert("theoretical");
    myTrie.insert("time");
    myTrie.insert("keyboard");
    myTrie.insert("a");
    myTrie.insert("apple");
    myTrie.insert("apocalypse");
    myTrie.insert("agriculture");
    myTrie.insert("dinosaur");
    myTrie.insert("dinosaur");
    myTrie.insert("dinosaur");
    //myTrie.insert("number5");
    //myTrie.insert("CAPS");
    //myTrie.insert("space between");
    //myTrie.insert("$ymbol");

    //myTrie.remove("key"); //word that does not exist, but is a prefix of another word
    //myTrie.remove("rhino"); //word that does not exist, and is unique
    //myTrie.remove("dinosaur"); //unique word
    //myTrie.remove("the"); //is a prefix of other words
    //myTrie.remove("theoretical"); //shares prefix with other words
    //myTrie.insert("zebra"); //test; insert after remove

    //myTrie.testArrayDisplay();

    cout << "Is Empty: " << myTrie.isEmpty() << endl;
    cout << "Word Count: " << myTrie.getWordCount() << endl;
    cout << "Prefix Count: " << myTrie.getPrefixCount("ap") << endl;
    cout << "Occurrence Count: " << myTrie.getOccurrenceCount("dinosaur") << endl;
    cout << "Search: " << myTrie.search("there") << endl;
    cout << "Display: " << endl << endl;
    myTrie.display();

    /*
        clear method test
    */

    myTrie.clear();

    cout << endl << "Is Empty (After Clear): " << myTrie.isEmpty() << endl;
    cout << "Word Count (After Clear): " << myTrie.getWordCount() << endl;
    cout << "Prefix Count (After Clear): " << myTrie.getPrefixCount("ap") << endl;
    cout << "Occurrence Count (After Clear): " << myTrie.getOccurrenceCount("dinosaur") << endl;
    cout << "Search (After Clear): " << myTrie.search("there") << endl;
    cout << "Display (After Clear): " << endl << endl;
    myTrie.display();
}
