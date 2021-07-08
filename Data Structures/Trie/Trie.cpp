/*
Title: Trie
Author: Edwin Khew
Description: Trie class implementation.
Date Created: 7/4/2021
*/

#include <string>

Trie::Trie()
{
    root_ptr_ = new Node(); //default node constructor creates a node with character '\0'
}

void Trie::insert(std::string new_word)
{
    Node *curr_ptr = root_ptr_; //pointer that will be used to traverse the tree

    for(int i = 0; i < new_word.length(); i++) //loop through every character in the word
    {
        char c = new_word[i]; //extract the current character in the word and store into 'c'
        int index = c - 'a'; //index of the current character

        //if the character does not exist, create a new node with the character and insert
        if(curr_ptr->children_[index] == nullptr)
        {
            curr_ptr->children_[index] = new Node(c);
        }

        curr_ptr = curr_ptr->children_[index]; //traverse down the tree to the next character
    }

    curr_ptr->setEndOfWord(true); //mark the last character as the end of the word
}

void Trie::remove(std::string word)
{
    removeHelper(root_ptr_, word, 0);
}

void Trie::clear()
{
    clearHelper(root_ptr_);
}

bool Trie::search(std::string word)
{
    Node *word_ptr = searchHelper(word); //pointer to the last node of the word if found, or 'nullptr' if not found

    return word_ptr != nullptr && word_ptr->getEndOfWord(); //true if the word exists and not just as a prefix of a larger word
}

int Trie::startsWith(std::string prefix)
{
    Node *prefix_ptr = searchHelper(prefix); //pointer to the last node of the prefix if found, or 'nullptr' if the prefix was not found
    int total = 0;

    if(prefix_ptr != nullptr) //can only count words if the prefix exists
    {
        total = wordCountHelper(prefix_ptr); //count the number of nodes marked as the end of a word starting at 'prefix_ptr' as the root
    }

    return total;
}

bool Trie::isEmpty()
{
    return !root_ptr_->hasChildren();
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
    //cannot remove if the trie is empty, or if a character in the word does not exist (which means word does not exist)
    if(isEmpty() || root == nullptr)
    {
        return nullptr;
    }

    //executes once the last character of the word is reached
    if(depth == word.length())
    {
        //unmark the last character as the end of a word
        if(root->getEndOfWord())
        {
            root->setEndOfWord(false);
        }

        //if the last character does not have any children, delete it
        if(!root->hasChildren())
        {
            delete root;
            root = nullptr;
        }

        return root;
    }

    int index = word[depth] - 'a'; //get the index of the current character
    root->children_[index] = removeHelper(root->children_[index], word, depth + 1); //recursively call the function on the next character of the word

    //FIXME inserting after removing gives unexpected results; problem might be below

    //deletes the root node after its children have been deleted; do not delete if its the root node, if the node still has children, or is the end of another word
    if(root != root_ptr_ && !root->hasChildren() && !root->getEndOfWord())
    {
        delete root;
        root = nullptr;
    }

    return root;
}

Node *Trie::clearHelper(Node *root)
{
    if(root != nullptr) //can only traverse if the root is pointing to a node
    {
        for(int i = 0; i < 26; i++) //traverse the trie and recursively call the function on each node
        {
            root->children_[i] = clearHelper(root->children_[i]);
        }

        if(root != root_ptr_) //do not delete the root node
        {
            delete root;
            root = nullptr;
        }
    }

    return root;
}

void Trie::displayHelper(Node *root, char word_array[], int pos)
{
    //if the current node is marked as the end of a word, print every character in the array
    if(root->getEndOfWord())
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
        char c = word[i]; //extract the current character in the word and store into 'c'
        int index = c - 'a'; //index of the current character

        //if a character does not exist, then the word does not exist
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

    if(root->getEndOfWord()) //if the current node is marked as the end of a word, increment the total
    {
        total++;
    }

    for(int i = 0; i < 26; i++) //loop through every child of the root
    {
        if(root->children_[i] != nullptr)
        {
            total += wordCountHelper(root->children_[i]); //recursively call the function
        }
    }

    return total;
}
