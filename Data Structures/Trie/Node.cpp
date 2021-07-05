/*
Title: Trie Node
Author: Edwin Khew
Description: Trie node class implementation.
Date Created: 7/4/2021
*/

Node::Node():character_('\0'), is_word_(false) { }

Node::Node(char c):character_(c), is_word_(false) { }

void Node::setChar(char c)
{
    character_ = c;
}

void Node::setIsWord(bool is_word)
{
    is_word_ = is_word;
}

char Node::getChar()
{
    return character_;
}

bool Node::getIsWord()
{
    return is_word_;
}
