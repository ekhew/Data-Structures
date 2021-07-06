/*
Title: Trie
Author: Edwin Khew
Description: Trie class implementation.
Date Created: 7/4/2021
*/

#include <string>

Trie::Trie()
{
    root_ptr_ = new Node(); //default node constructor creates an empty node
}

void Trie::insert(std::string new_word)
{
    Node *curr_ptr = root_ptr_; //pointer that will be used to traverse the tree

    for(int i = 0; i < new_word.length(); i++) //loop through every character in the word
    {
        char c = new_word[i]; //extract each character in the word
        int index = c - 'a'; //index of the current character

        //if the character does not exist, create a new node with the character and insert
        if(curr_ptr->children_[index] == nullptr)
        {
            curr_ptr->children_[index] = new Node(c);
        }

        curr_ptr = curr_ptr->children_[index]; //traverse down the tree to the next character
    }

    curr_ptr->setIsWord(true); //mark the last character as the end of the word
}

void Trie::remove(std::string word)
{
    removeHelper(root_ptr_, word, 0);
}

bool Trie::search(std::string word)
{
    Node *word_ptr = searchHelper(word); //pointer to the last node of the word if found, or 'nullptr' if not found

    return word_ptr != nullptr && word_ptr->getIsWord(); //true if the word exists and not just as a prefix of a larger word
}

int Trie::startsWith(std::string prefix)
{
    Node *prefix_ptr = searchHelper(prefix); //pointer to the last node of the prefix if found, or 'nullptr' if the prefix was not found
    int counter = 0;

    if(prefix_ptr != nullptr) //can only count words if the prefix exists
    {
        counter = wordCountHelper(prefix_ptr); //count the number of nodes marked as the end of a word starting using 'prefix_ptr' as the root
    }

    return counter;
}

bool Trie::isEmpty()
{
    return wordCountHelper(root_ptr_) == 0;
}

size_t Trie::getWordCount()
{
    return wordCountHelper(root_ptr_);
}

void Trie::display()
{
    if(!isEmpty()) //can only display if trie is not empty
    {
        char word_array[100]; //array used to build words; 100 character limit for word size
        displayHelper(root_ptr_, word_array, 0);
    }
    else
    {
        std::cout << "Trie is Empty!" << std::endl;
    }
}

/**************************************************************************************************
                                    Helper functions below.
**************************************************************************************************/

Node *Trie::removeHelper(Node *root, std::string word, int depth)
{
    //can only remove if the trie is not empty
    if(isEmpty())
    {
        return nullptr;
    }

    //once the last character of the word is reached
    if(depth == word.length())
    {
        if(root->getIsWord())
        {
            root->setIsWord(false);
        }

        if(!root->hasChildren())
        {
            delete root;
            root = nullptr;
        }

        return root;
    }

    int index = word[depth] - 'a'; //get the index of the current character
    root->children_[index] = removeHelper(root->children_[index], word, depth + 1);

    if(!root->hasChildren() && !root->getIsWord())
    {
        delete root;
        root = nullptr;
    }

    return root;
}

void Trie::displayHelper(Node *root, char word_array[], int pos)
{
    //if the current node is marked as the end of a word, print every character in the array
    if(root->getIsWord())
    {
        for(int i = 0; i < pos; i++)
        {
            std::cout << word_array[i];
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < 26; i++) //loop through the children of the node
    {
        if(root->children_[i] != nullptr)
        {
            word_array[pos] = i + 'a'; //insert the character to the word array
            displayHelper(root->children_[i], word_array, pos + 1); //recursively call the function to continue building the word
        }
    }
}

Node *Trie::searchHelper(std::string word)
{
    Node *curr_ptr = root_ptr_; //pointer that will be used to traverse the tree

    for(int i = 0; i < word.length(); i++) //loop through every character in the word
    {
        char c = word[i]; //extract each character in the word
        int index = c - 'a'; //index of the current character

        //if the character does not exist, return 'nullptr'
        if(curr_ptr->children_[index] == nullptr)
        {
            return nullptr;
        }

        curr_ptr = curr_ptr->children_[index]; //traverse down the tree to the next character of the word
    }

    return curr_ptr;
}

int Trie::wordCountHelper(Node *root)
{
    int total = 0;

    if(root->getIsWord()) //if the current node is marked as the end of a word, increment the total
    {
        total++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(root->children_[i] != nullptr)
        {
            total += wordCountHelper(root->children_[i]); //recursively call the function
        }
    }

    return total;
}
