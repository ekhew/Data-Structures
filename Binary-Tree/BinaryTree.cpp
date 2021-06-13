/*
Title: Binary Tree
Author: Edwin Khew
Description: Binary tree class implementation.
Date Created: 6/4/2021
*/

#include <queue> //for insertion using level order traversal

template<typename ItemType>
BinaryTree<ItemType>::BinaryTree():root_ptr_(nullptr) { }

template<typename ItemType>
BinaryTree<ItemType>::BinaryTree(const BinaryTree<ItemType> &tree)
{
    root_ptr_ = copyConstructorHelper(tree.root_ptr_); //set 'root_ptr_' of the new tree to the tree that was created in the helper function
}

template<typename ItemType>
BinaryTree<ItemType>::~BinaryTree()
{
    destroyTreeHelper(root_ptr_);
}

template<typename ItemType>
void BinaryTree<ItemType>::insert(const ItemType &new_item)
{
    root_ptr_ = insertHelper(root_ptr_, new_item); //update the 'root_ptr_' to the updated tree with the new node
}

template<typename ItemType>
void BinaryTree<ItemType>::remove(const ItemType &item)
{
    if(!isEmpty()) //can only remove if the tree is not empty
    {
        root_ptr_ = removeHelper(root_ptr_, item); //update the 'root_ptr_' to the updated tree with the node deleted
    }
}

template<typename ItemType>
void BinaryTree<ItemType>::clear()
{
    destroyTreeHelper(root_ptr_);
}

template<typename ItemType>
size_t BinaryTree<ItemType>::nodeCount() const
{
    return nodeCountHelper(root_ptr_);
}

template<typename ItemType>
size_t BinaryTree<ItemType>::getHeight() const
{
    return getHeightHelper(root_ptr_);
}

template<typename ItemType>
bool BinaryTree<ItemType>::isEmpty() const
{
    return root_ptr_ == nullptr;
}

template<typename ItemType>
void BinaryTree<ItemType>::levelorderTraverse()
{
    if(!isEmpty()) //can only traverse if the tree is not empty
    {
        levelorderHelper(root_ptr_); //traverse using the helper function
    }
    else
    {
        std::cout << "Tree is empty!";
    }
}

template<typename ItemType>
void BinaryTree<ItemType>::printTree()
{
    if(!isEmpty())
    {
        printTreeHelper(root_ptr_, 0);
    }
}

/**************************************************************************************************
                                    Helper functions below.
**************************************************************************************************/

template<typename ItemType>
Node<ItemType> *BinaryTree<ItemType>::copyConstructorHelper(Node<ItemType> *root) const
{
    if(root == nullptr) //base case; return if a subtree is empty
    {
        return root; //returns 'nullptr'
    }
    else //copying a tree uses preorder traversal (copy the root node of the subtree, then its left and right subtrees)
    {
        Node<ItemType> *new_node_ptr = new Node<ItemType>(root->getItem()); //create a new node with a copy of the root item
        new_node_ptr->setLeft(copyConstructorHelper(root->getLeft())); //copy the left subtree
        new_node_ptr->setRight(copyConstructorHelper(root->getRight())); //copy the right subtree

        return new_node_ptr;
    }
}

template<typename ItemType>
void BinaryTree<ItemType>::destroyTreeHelper(Node<ItemType> *root)
{
    if(root == nullptr) //base case; return if a subtree is empty
    {
        return;
    }
    else
    {
        //destroying a tree uses postorder traversal (delete a node only after both its subtrees are destroyed)
        destroyTreeHelper(root->getLeft()); //traverse the left subtree
        destroyTreeHelper(root->getRight()); //traverse the right subtree
        delete root; //delete the root node of the subtree
        root = nullptr;

        root_ptr_ = nullptr; //set 'root_ptr_' to 'nullptr' once the entire tree has been destroyed
    }
}

template<typename ItemType>
Node<ItemType> *BinaryTree<ItemType>::insertHelper(Node<ItemType> *root, const ItemType &new_item)
{
    if(root == nullptr) //base case; if the tree is empty, create the first node
    {
        Node<ItemType> *new_node_ptr = new Node<ItemType>(new_item);
        root = new_node_ptr;
        return root;
    }
    else
    {
        std::queue<Node<ItemType>*> Q; //create a new queue of item type 'Node<ItemType>*'
        Q.push(root);//push the root node into the queue

        while(!Q.empty())
        {
            Node<ItemType> *current_ptr = Q.front(); //create a pointer to store the address of the node at the front of the queue

            //push the parent node's left child into the queue, if a left child is present
            if(current_ptr->getLeft() != nullptr)
            {
                Q.push(current_ptr->getLeft());
            }
            else
            {
                Node<ItemType> *new_node_ptr = new Node<ItemType>(new_item);
                current_ptr->setLeft(new_node_ptr);
                return root;
            }

            //push the parent node's right child into the queue, if a right child is present
            if(current_ptr->getRight() != nullptr)
            {
                Q.push(current_ptr->getRight());
            }
            else
            {
                Node<ItemType> *new_node_ptr = new Node<ItemType>(new_item);
                current_ptr->setRight(new_node_ptr);
                return root;
            }

            Q.pop(); //pop the parent node from the front of the queue
        }
    }
}

template<typename ItemType>
Node<ItemType> *BinaryTree<ItemType>::removeHelper(Node<ItemType> *root, const ItemType &item)
{
    //if the tree has only one node and the specified item matches
    if((nodeCount() == 1) && (root_ptr_->getItem() == item))
    {
        delete root_ptr_;
        root_ptr_ = nullptr;
    }

    if(root != nullptr) //base case; can only traverse if the tree is not empty
    {
        ItemType last_item = getDeepestNode()->getItem(); //get the item at the deepest node using the helper function

        std::queue<Node<ItemType>*> Q; //create a new queue of item type 'Node<ItemType>*'
        Q.push(root);//push the root node into the queue

        //replaces the item in the node to delete and deletes the deepest node in a single traversal
        while(!Q.empty())
        {
            Node<ItemType> *current_ptr = Q.front(); //create a pointer to store the address of the node at the front of the queue

            //if the current node has an item that matches the item to remove, replace its item with the item at the deepest node
            if(current_ptr->getItem() == item)
            {
                current_ptr->setItem(last_item);
            }

            //push the parent node's left child into the queue, if a left child is present
            if(current_ptr->getLeft() != nullptr)
            {
                if(current_ptr->getLeft()->getItem() == last_item) //if the parent has a left child that is the deepest node, delete the child
                {
                    delete current_ptr->getLeft();
                    current_ptr->setLeft(nullptr);
                }
                else
                {
                    Q.push(current_ptr->getLeft());
                }
            }

            //push the parent node's right child into the queue, if a right child is present
            if(current_ptr->getRight() != nullptr)
            {
                if(current_ptr->getRight()->getItem() == last_item) //if the parent has a right child that is the deepest node, delete the child
                {
                    delete current_ptr->getRight();
                    current_ptr->setRight(nullptr);
                }
                else
                {
                    Q.push(current_ptr->getRight());
                }
            }

            Q.pop(); //pop the parent node from the front of the queue
        }

        return root;
    }
}

template<typename ItemType>
Node<ItemType> *BinaryTree<ItemType>::getDeepestNode()
{
    if(root_ptr_ != nullptr) //base case; can only traverse if the tree is not empty
    {
        std::queue<Node<ItemType>*> Q; //create a new queue of item type 'Node<ItemType>*'
        Q.push(root_ptr_);//push the root node into the queue

        Node<ItemType> *last_node_ptr; //item in the last node in the tree; rightmost item in the last level

        //find the last item in the tree
        while(!Q.empty())
        {
            Node<ItemType> *current_ptr = Q.front(); //create a pointer to store the address of the node at the front of the queue

            //push the parent node's left child into the queue, if a left child is present
            if(current_ptr->getLeft() != nullptr)
            {
                Q.push(current_ptr->getLeft());
            }

            //push the parent node's right child into the queue, if a right child is present
            if(current_ptr->getRight() != nullptr)
            {
                Q.push(current_ptr->getRight());
            }

            last_node_ptr = current_ptr;

            Q.pop(); //pop the parent node from the front of the queue
        }

        return last_node_ptr;
    }
}

template<typename ItemType>
size_t BinaryTree<ItemType>::nodeCountHelper(Node<ItemType> *root) const
{
    int count = 1; //node count of the subtree; count starts at '1' to account for the root node of the subtree

    if(root == nullptr) //base case; return 0 if a subtree is empty
    {
        return 0;
    }
    else
    {
        count += nodeCountHelper(root->getLeft()); //count nodes in the left subtree
        count += nodeCountHelper(root->getRight()); //count nodes in the right subtree
        return count;
    }
}

template<typename ItemType>
size_t BinaryTree<ItemType>::getHeightHelper(Node<ItemType> *root) const
{
    if(root == nullptr) //base case; return if a subtree is empty
    {
        return 0;
    }
    else
    {
        //get the height of the left and right subtrees, then return the greater of the two; the '+ 1' accounts for the root of the subtree
        return 1 + std::max(getHeightHelper(root->getLeft()), getHeightHelper(root->getRight()));

        /*
        Below is basically what the std::max() function does.
        */

        /*
        size_t left_height = getHeightHelper(root->getLeft());
        size_t right_height = getHeightHelper(root->getRight());

        if(left_height > right_height)
        {
        return (left_height + 1);
        }
        else
        {
        return (right_height + 1);
        }
        */
    }
}

template<typename ItemType>
void BinaryTree<ItemType>::levelorderHelper(Node<ItemType> *root)
{
    if(root != nullptr) //base case; can only traverse if the tree is not empty
    {
        std::queue<Node<ItemType>*> Q; //create a new queue of item type 'Node<ItemType>*'
        Q.push(root);//push the root node into the queue

        while(!Q.empty())
        {
            Node<ItemType> *current_ptr = Q.front(); //create a pointer to store the address of the node at the front of the queue

            std::cout << current_ptr->getItem() << " "; //visit the node

            //push the parent node's left child into the queue, if a left child is present
            if(current_ptr->getLeft() != nullptr)
            {
                Q.push(current_ptr->getLeft());
            }

            //push the parent node's right child into the queue, if a right child is present
            if(current_ptr->getRight() != nullptr)
            {
                Q.push(current_ptr->getRight());
            }

            Q.pop(); //pop the parent node from the front of the queue
        }
    }
}

template<typename ItemType>
void BinaryTree<ItemType>::printTreeHelper(Node<ItemType> *root, int space)
{
    if(root == nullptr) //base case; return when a subtree of a root is empty
    {
        return;
    }
    else
    {
        space += 10; //increase distance between levels

        printTreeHelper(root->getRight(), space); //print the right subtree

        std::cout << std::endl;
        for(int i = 10; i < space; i++)
        {
            std::cout << " ";
        }
        std::cout << root->getItem() << std::endl;

        printTreeHelper(root->getLeft(), space); //print the left subtree
    }
}
