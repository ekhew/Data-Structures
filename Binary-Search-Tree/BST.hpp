/*
Title: Binary Search Tree (BST)
Author: Edwin Khew
Description: Binary search tree class declaration.
Date Created: 6/4/2021
*/

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

template <class ItemType>
class BST
{
public:
    /*
        default constructor
    */
    BST();

    /*
        copy constructor
        @param tree to be copied
    */
    BST(const BST<ItemType> &tree);

    /*
        destructor
    */
    ~BST();

    /*
        inserts a new node into the tree
        @param new_item, item to be added
    */
    void insert(const ItemType &new_item);

    /*
        removes a node from the tree
        @param item, item to be removed
    */
    void remove(const ItemType &item);

    /*
        removes every item in the tree
        @post tree is empty
    */
    void clear();

    /*
        checks the number of nodes currently in the tree
        @return an integer representing the number of nodes currently in the tree
    */
    size_t nodeCount() const;

    /*
        checks the height of the tree
        @return an integer representing the height of the tree
    */
    size_t getHeight() const;

    /*
        checks if the tree is empty
        @return true if the tree is empty, and false otherwise
    */
    bool isEmpty() const;

    /*
        searches the tree for a specified item
        @param item, item to look for in the tree
        @return a copy of the item if it is found
    */
    ItemType search(const ItemType &item) const;

    /*
        performs a preorder traversal of the entire tree; calls its helper function
    */
    void preorderTraverse();

    /*
        performs an inorder traversal of the entire tree; calls its helper function
    */
    void inorderTraverse();

    /*
        performs a postorder traversal of the entire tree; calls its helper function
    */
    void postorderTraverse();
private:
    Node<ItemType> *root_ptr_; //pointer to the root node of the tree

    /*
        copy constructor helper
        @param old_tree_root_ptr, pointer to the root node of the tree to be copied
    */
    Node<ItemType> *copyConstructorHelper(Node<ItemType> *root) const;

    /*
        removes every node in the tree
        @param subtree_ptr, pointer to the root node of a subtree to be deleted
    */
    void destroyTreeHelper(Node<ItemType> *subtree_ptr);

    /*
        inserts a node into the tree
        @param subtree_ptr, pointer to the subtree to traverse
        @param new_node_ptr, pointer to the new node
    */
    Node<ItemType> *insertHelper(Node<ItemType> *subtree_ptr, Node<ItemType> *new_node_ptr);

    /*
        remves a node from the tree
        @param subtree_ptr, pointer to the subtree to traverse
        @param new_node_ptr, pointer to the node to remove
    */
    Node<ItemType> *removeHelper(Node<ItemType> *subtree_ptr, const ItemType &item);

    /*
        checks the number of nodes currently in the tree
        @return an integer representing the number of nodes currently in the tree
    */
    size_t nodeCountHelper(Node<ItemType> *root) const;

    /*
        checks the height of the tree
        @param root, pointer to the root node of a subtree
        @return an integer representing the height of the tree
    */
    size_t getHeightHelper(Node<ItemType> *root) const;

    /*
        finds the inorder successor of the specified node
        @param root, pointer to the node to find the inorder successor of
    */
    Node<ItemType> *inorderSuccessor(Node<ItemType> *root) const;

    /*
        searches the tree for the specified item
        @param root, pointer to the root node of the subtree
        @param item, item to search the tree for
    */
    Node<ItemType> *searchHelper(Node<ItemType> *root, const ItemType &item) const;

    /*
        performs a preorder traversal of the entire tree
        @param root, pointer to the root node of a subtree
    */
    void preorderHelper(Node<ItemType> *root);

    /*
        performs an inorder traversal of the entire tree
        @param root, pointer to the root node of a subtree
    */
    void inorderHelper(Node<ItemType> *root);

    /*
        performs a postorder traversal of the entire tree
        @param root, pointer to the root node of a subtree
    */
    void postorderHelper(Node<ItemType> *root);
};

#include "BST.cpp"
#endif
