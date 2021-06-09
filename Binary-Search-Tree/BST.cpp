/*
Title: Binary Search Tree (BST)
Author: Edwin Khew
Description: Binary search tree class implementation.
Date Created: 6/4/2021
*/

template<typename ItemType>
BST<ItemType>::BST():root_ptr_(nullptr) { }

template<typename ItemType>
BST<ItemType>::BST(const BST<ItemType> &tree)
{
    root_ptr_ = copyConstructorHelper(tree.root_ptr_);
}

template<typename ItemType>
BST<ItemType>::~BST()
{
    destroyHelper(root_ptr_);
}

template<typename ItemType>
void BST<ItemType>::insert(const ItemType &new_item)
{
    root_ptr_ = insertHelper(root_ptr_, new_item);
}

template<typename ItemType>
void BST<ItemType>::remove(const ItemType &item)
{
    if(!isEmpty()) //can only remove if the tree is not empty
    {
        bool success = false;

        if((nodeCount() == 1) && (root_ptr_->getItem() == item)) //if the tree has only one node and the specified item matches
        {
            delete root_ptr_;
            root_ptr_ = nullptr;
        }
        else //call the helper function to search for a matching node and delete it
        {
            removeHelper(root_ptr_, item);
        }
    }
}

template<typename ItemType>
void BST<ItemType>::clear()
{
    destroyHelper(root_ptr_);
}

template<typename ItemType>
size_t BST<ItemType>::nodeCount() const
{
    return nodeCountHelper(root_ptr_);
}

template<typename ItemType>
size_t BST<ItemType>::getHeight() const
{
    return getHeightHelper(root_ptr_);
}

template<typename ItemType>
bool BST<ItemType>::isEmpty() const
{
    return root_ptr_ == nullptr;
}

template<typename ItemType>
ItemType BST<ItemType>::search(const ItemType &item) const
{
    Node<ItemType> *search_ptr = searchHelper(root_ptr_, item); //pointer to the node that is being searched for

    if(search_ptr == nullptr) //if the item cannot be found, throw an exception
    {
        throw(std::out_of_range("Position out of range!"));
    }
    else //return the item being pointed to by 'search_ptr'
    {
        return search_ptr->getItem();
    }
}

template<typename ItemType>
void BST<ItemType>::preorderTraverse()
{
    if(!isEmpty()) //can only traverse if the tree is not empty
    {
        preorderHelper(root_ptr_); //traverse using the helper function
    }
    else
    {
        std::cout << "Tree is empty!";
    }
}


template<typename ItemType>
void BST<ItemType>::inorderTraverse()
{
    if(!isEmpty()) //can only traverse if the tree is not empty
    {
        inorderHelper(root_ptr_); //traverse using the helper function
    }
    else
    {
        std::cout << "Tree is empty!";
    }
}

template<typename ItemType>
void BST<ItemType>::postorderTraverse()
{
    if(!isEmpty()) //can only traverse if the tree is not empty
    {
        postorderHelper(root_ptr_); //traverse using the helper function
    }
    else
    {
        std::cout << "Tree is empty!";
    }
}

/**************************************************************************************************
                                    Helper functions below.
**************************************************************************************************/

template<typename ItemType>
Node<ItemType> *BST<ItemType>::copyConstructorHelper(Node<ItemType> *root) const
{
    if(root == nullptr) //base case; return if a subtree is empty
    {
        return root;
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
void BST<ItemType>::destroyHelper(Node<ItemType> *root)
{
    if(root == nullptr) //base case; return if a subtree is empty
    {
        return;
    }
    else
    {
        //destroying a tree uses postorder traversal (delete a node only after both its subtrees are destroyed)
        destroyHelper(root->getLeft()); //traverse the left subtree
        destroyHelper(root->getRight()); //traverse the right subtree
        delete root; //delete the root node of the subtree
        root = nullptr;

        root_ptr_ = nullptr; //set 'root_ptr_' to 'nullptr' once the entire tree has been destroyed
    }
}

template<typename ItemType>
Node<ItemType> *BST<ItemType>::insertHelper(Node<ItemType> *root, const ItemType &new_item)
{
    if(root == nullptr) //base case; once the correct position to insert is reached, create a new node with the new item
    {
        Node<ItemType> *new_node_ptr = new Node<ItemType>(new_item);
        root = new_node_ptr;
    }
    else if(new_item < root->getItem()) //if the new item is less than the root node, traverse to the left subtree
    {
        root->setLeft(insertHelper(root->getLeft(), new_item));
    }
    else //if the new item is greater than the root node, traverse to the right subtree
    {
        root->setRight(insertHelper(root->getRight(), new_item));
    }
    return root;
}

template<typename ItemType>
Node<ItemType> *BST<ItemType>::removeHelper(Node<ItemType> *root, const ItemType &item)
{
    if(root == nullptr) //base case; return if a subtree is empty
    {
        return root;
    }
    else
    {
        if(root->getItem() > item) //if root item is greater than the item to delete, search the left subtree
        {
            root->setLeft(removeHelper(root->getLeft(), item));
        }
        else if(root->getItem() < item) //if root item is less than the item to delete, search the right subtree
        {
            root->setRight(removeHelper(root->getRight(), item));
        }
        else //if the root item matches the item to delete, then the node to be deleted is found and can now be deleted
        {
            if(root->isLeaf()) //case 1: no children (is a leaf)
            {
                delete root;
                root = nullptr;
            }
            else if(root->getLeft() == nullptr) //case 2: one child (a right child)
            {
                Node<ItemType> *temp_ptr = root;
                root = root->getRight();
                delete temp_ptr;
                temp_ptr = nullptr;
            }
            else if(root->getRight() == nullptr) //case 2: one child (a left child)
            {
                Node<ItemType> *temp_ptr = root;
                root = root->getLeft();
                delete temp_ptr;
                temp_ptr = nullptr;
            }
            else //case 3: two children
            {
                Node<ItemType> *temp_ptr = inorderSuccessor(root->getRight()); //find the inorder successor and create a pointer to point to it
                root->setItem(temp_ptr->getItem()); //replace the old item with a copy of the inorder successor item
                root->setRight(removeHelper(root->getRight(), temp_ptr->getItem())); //traverse the right subtree and remove the inorder successor
            }
        }
        return root;
    }
}

template<typename ItemType>
Node<ItemType> *BST<ItemType>::inorderSuccessor(Node<ItemType> *root) const
{
    Node<ItemType> *smallest_ptr = root; //pointer that will traverse the subtree, starting from the root

    //find the leftmost node in the subtree (this would be the node with the smallest value)
    while(smallest_ptr->getLeft() != nullptr)
    {
        smallest_ptr = smallest_ptr->getLeft();
    }

    return smallest_ptr;
}

template<typename ItemType>
size_t BST<ItemType>::nodeCountHelper(Node<ItemType> *root) const
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
size_t BST<ItemType>::getHeightHelper(Node<ItemType> *root) const
{
    if(root_ptr_ == nullptr) //if the tree is empty, the height is 0
    {
        return 0;
    }

    if(root == nullptr) //base case; return if a subtree is empty
    {
        return -1; //since height of a leaf is 0, return '-1' since '+ 1' will occur in the previous call once this call returns
    }
    else
    {
        //get the height of the left and right subtrees, then return the greater of the two; the '+ 1' accounts for the root of the subtree
        return 1 + std::max(getHeightHelper(root->getLeft()), getHeightHelper(root->getRight()));
    }
}

template<typename ItemType>
Node<ItemType> *BST<ItemType>::searchHelper(Node<ItemType> *root, const ItemType &item) const
{
    if((root == nullptr) || (root->getItem() == item)) //base case; if the item does not exist or if the item has been found
    {
        return root;
    }
    else
    {
        if((root->getItem() > item)) //if the root of the subtree is greater than the specified item, search the left subtree
        {
            return searchHelper(root->getLeft(), item);
        }
        else //if the root of the subtree is less than the specified item, search the right subtree
        {
            return searchHelper(root->getRight(), item);
        }
    }
}

template<typename ItemType>
void BST<ItemType>::preorderHelper(Node<ItemType> *root)
{
    if(root != nullptr) //base case; return if a subtree of a root is empty
    {
        std::cout << root->getItem() << " "; //visit the node
        preorderHelper(root->getLeft()); //traverse the left subtree
        preorderHelper(root->getRight()); //traverse the right subtree
    }
}

template<typename ItemType>
void BST<ItemType>::inorderHelper(Node<ItemType> *root)
{
    if(root != nullptr) //base case; return when a subtree of a root is empty
    {
        inorderHelper(root->getLeft()); //traverse the left subtree
        std::cout << root->getItem() << " "; //visit the node
        inorderHelper(root->getRight()); //traverse the right subtree
    }
}

template<typename ItemType>
void BST<ItemType>::postorderHelper(Node<ItemType> *root)
{
    if(root != nullptr) //base case; return when a subtree of a root is empty
    {
        postorderHelper(root->getLeft()); //traverse the left subtree
        postorderHelper(root->getRight()); //traverse the right subtree
        std::cout << root->getItem() << " "; //visit the node
    }
}
