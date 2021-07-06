/*
Title: Trie Node
Author: Edwin Khew
Description: Trie node class declaration.
Date Created: 7/4/2021
*/

#ifndef NODE_H_
#define NODE_H_

class Node
{
public:
    /*
        default constructor
    */
    Node();

    /*
        paramterized constructor
        @param c, character that the node will represent
    */
    Node(char c);

    /*
        sets the character of the calling node
        @param c, character that the node will represent
    */
    void setChar(char c);

    /*
        sets the ‘is_word_’ indicator to either true or false
        @param is_word, either true or false
    */
    void setIsWord(bool is_word);

    /*
        returns the character of the calling node
        @return 'character_'
    */
    char getChar();

    /*
        returns the value of the boolean private member
        @return 'is_word_'
    */
    bool getIsWord();

    /*
        checks whether the node has any children
        @return true if at least one child is present, and false if no children are present
    */
    bool hasChildren();

    static const int CHILDREN_ = 26; //maximum number of children that a node can have; 26 in this case for characters a-z
    Node *children_[CHILDREN_]; //array of pointer to the children of the node
private:
    char character_; //character that the node represents
    bool is_word_; //true if the node represents the end of a word, and false otherwise
};

#include "Node.cpp"
#endif
