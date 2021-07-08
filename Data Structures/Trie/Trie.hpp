/*
Title: Trie
Author: Edwin Khew
Description: Trie class declaration.
Date Created: 7/4/2021
*/

#ifndef TRIE_H_
#define TRIE_H_

#include <string>

class Trie
{
public:
    /*
        constructor
    */
    Trie();

    /*
        inserts a new word into the trie
        @param new_word, the new word to be inserted into the trie
    */
    void insert(std::string new_word);

    /*
        removes a word from the trie
        @param word, word to remove from the trie
    */
    void remove(std::string word);

    /*
        removes every word currently in the trie
    */
    void clear();

    /*
        checks the trie for the existence of a specified word
        @param word, the word to search for
        @return true if the word was found, and false if the word was not found
    */
    bool search(std::string word) const;

    /*
        returns the number of words currently in the trie
        @return 'word_count_'
    */
    int getWordCount() const;

    /*
        checks the trie for words that begin with the specified prefix
        @param prefix, the prefix to search for
        @return an integer representing the number of words that begin with the prefix
    */
    int getPrefixCount(std::string prefix) const;

    /*
        returns the numbe of occurences of the specified word
        @param word, word to find the occurrence count of
        @return an integer representing the occurrence count of the word
    */
    int getOccurrenceCount(std::string word) const;

    /*
        checks to see if the trie is currently empty
        @return true if the trie is empty, and false if not empty
    */
    bool isEmpty() const;

    /*
        displays all the words currently in the trie
    */
    void display() const;
private:
    Node *root_ptr_; //pointer to the root node of the trie

    /*
        removes a word from the trie
        @param root, the current node being visited
        @param word, the word to remove
        @param depth, current depth of the traversal
        @return pointer to the node that was just modified
    */
    Node *removeHelper(Node *root, std::string word, int depth);

    /*
        removes every word currently in the trie
        @param root, current node being visited
        @return pointer to the node that was just modified
    */
    Node *clearHelper(Node *root);

    /*
        checks the trie for the existence of a specified word or prefix
        @param word, the word or prefix to search for
        @return pointer to the last node of the word or prefix if found, or 'nullptr' if not found
    */
    Node *searchHelper(std::string word) const;

    /*
        counts the number of nodes starting from the specified root node
        @param root, node to start counting from
        @return integer representing the word count
    */
    int wordCountHelper(Node *root) const;

    /*
        displays all the words currently in the trie
        @param root, current node being visited
        @param word_array[], array used to build words
        @param pos, current position in the word array
    */
    void displayHelper(Node *root, char word_array[], int pos) const;
};

#include "Trie.cpp"
#endif
