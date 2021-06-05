/*
Title: Binary Search Tree (BST)
Author: Edwin Khew
Description: Binary search tree class implementation.
Date Created: 6/4/2021
*/

template<typename ItemType>
BST<ItemType>::BST():root_ptr_(nullptr), item_count_(0) { }

/*
template<typename ItemType>
BST<ItemType>::BST(const BinaryTree<ItemType> &tree)
{

}
*/

template<typename ItemType>
BST<ItemType>::~BST()
{
    clear();
}

template<typename ItemType>
void BST<ItemType>::insert(const ItemType &new_item)
{
    Node<ItemType> *new_node_ptr = new Node<ItemType>(new_item); //create a new node with the specified item

    if(root_ptr_ == nullptr) //if the tree is empty, insert the first node
    {
        root_ptr_ = new_node_ptr;
    }
    else //traverse the tree and insert at the correct position
    {
        insertHelper(root_ptr_, new_node_ptr);
    }
}

/*
template<typename ItemType>
void BST<ItemType>::remove(const ItemType &item)
{

}
*/

template<typename ItemType>
void BST<ItemType>::clear()
{
    destroyTree(root_ptr_);
}

template<typename ItemType>
bool BST<ItemType>::isEmpty() const
{
    return item_count_ == 0;
}

/*
template<typename ItemType>
ItemType BST<ItemType>::search(const ItemType &item) const
{

}
*/

template<typename ItemType>
void BST<ItemType>::preorderTraverse()
{
    preorderHelper(root_ptr_);
}


template<typename ItemType>
void BST<ItemType>::inorderTraverse()
{
    inorderHelper(root_ptr_);
}

template<typename ItemType>
void BST<ItemType>::postorderTraverse()
{
    postorderHelper(root_ptr_);
}


/*
Helper functions below
*/


template<typename ItemType>
Node<ItemType> *BST<ItemType>::insertHelper(Node<ItemType> *subtree_ptr, Node<ItemType> *new_node_ptr)
{
    if(subtree_ptr == nullptr) //base case
    {
        return new_node_ptr;
    }
    else
    {
        if(new_node_ptr->getItem() < subtree_ptr->getItem()) //if the new item is less than the root node, traverse to the left subtree
        {
            subtree_ptr->setLeft(insertHelper(subtree_ptr->getLeft(), new_node_ptr));
        }
        else //if the new item is greater than the root node, traverse to the right subtree
        {
            subtree_ptr->setRight(insertHelper(subtree_ptr->getRight(), new_node_ptr));
        }
        return subtree_ptr;
    }
}

template<typename ItemType>
void BST<ItemType>::destroyTree(Node<ItemType> *subtree_ptr)
{
    if(subtree_ptr != nullptr) //base case
    {
        //destroying a tree uses postorder traversal (delete a node only after both its subtrees are destroyed)
        destroyTree(subtree_ptr->getLeft()); //traverse the left subtree
        destroyTree(subtree_ptr->getRight()); //traverse the right subtree
        delete subtree_ptr; //delete the root node of the subtree
        subtree_ptr = nullptr;
    }
}

template<typename ItemType>
void BST<ItemType>::preorderHelper(Node<ItemType> *root)
{
    if(root != nullptr) //base case
    {
        std::cout << root->getItem() << " "; //visit the node
        preorderHelper(root->getLeft()); //traverse the left subtree
        preorderHelper(root->getRight()); //traverse the right subtree
    }
}

template<typename ItemType>
void BST<ItemType>::inorderHelper(Node<ItemType> *root)
{
    if(root != nullptr) //base case
    {
        inorderHelper(root->getLeft()); //traverse the left subtree
        std::cout << root->getItem() << " "; //visit the node
        inorderHelper(root->getRight()); //traverse the right subtree
    }
}

template<typename ItemType>
void BST<ItemType>::postorderHelper(Node<ItemType> *root)
{
    if(root != nullptr) //base case
    {
        postorderHelper(root->getLeft()); //traverse the left subtree
        postorderHelper(root->getRight()); //traverse the right subtree
        std::cout << root->getItem() << " "; //visit the node
    }
}
