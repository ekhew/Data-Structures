/*
Title: Binary Search Tree (BST)
Author: Edwin Khew
Description: Binary search tree class implementation.
Date Created: 6/4/2021
*/

template<typename ItemType>
BST<ItemType>::BST():root_ptr_(nullptr), node_count_(0) { }

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
    else //call the helper function to traverse the tree and insert at the correct position
    {
        insertHelper(root_ptr_, new_node_ptr);
    }

    node_count_++;
}

template<typename ItemType>
void BST<ItemType>::remove(const ItemType &item)
{
    if(!isEmpty()) //can only remove if the tree is not empty
    {
        if((node_count_ == 1) && (root_ptr_->getItem() == item)) //if the tree has only one node and the specified item matches
        {
            delete root_ptr_;
            root_ptr_ = nullptr;
        }
        else //call the helper function to search for a matching node and delete it
        {
            removeHelper(root_ptr_, item);
            std::cout << removeHelper(root_ptr_, item);
        }

        //node_count_--;
    }
}

template<typename ItemType>
void BST<ItemType>::clear()
{
    destroyTree(root_ptr_);
}

template<typename ItemType>
size_t BST<ItemType>::nodeCount() const
{
    return node_count_;
}

template<typename ItemType>
bool BST<ItemType>::isEmpty() const
{
    return node_count_ == 0;
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
Node<ItemType> *BST<ItemType>::removeHelper(Node<ItemType> *subtree_ptr, const ItemType &item)
{
    if(subtree_ptr == nullptr) //base case
    {
        return subtree_ptr;
    }
    else
    {
        if(subtree_ptr->getItem() > item)
        {
            subtree_ptr->setLeft(removeHelper(subtree_ptr->getLeft(), item));
        }
        else if(subtree_ptr->getItem() < item)
        {
            subtree_ptr->setRight(removeHelper(subtree_ptr->getRight(), item));
        }
        else //if the specififed item matches the root item, then the node to be deleted is found
        {
            if(subtree_ptr->isLeaf()) //case 1: no children (is a leaf)
            {
                delete subtree_ptr;
                subtree_ptr = nullptr;
            }
            else if(subtree_ptr->getLeft() == nullptr) //case 2: one child (a right child)
            {
                Node<ItemType> *temp_ptr = subtree_ptr;
                subtree_ptr = subtree_ptr->getRight();
                delete temp_ptr;
                temp_ptr = nullptr;
            }
            else if(subtree_ptr->getRight() == nullptr) //case 2: one child (a left child)
            {
                Node<ItemType> *temp_ptr = subtree_ptr;
                subtree_ptr = subtree_ptr->getLeft();
                delete temp_ptr;
                temp_ptr = nullptr;
            }
            else //case 3: two children
            {
                Node<ItemType> *temp_ptr = inorderSuccessor(subtree_ptr->getRight());
                subtree_ptr->setItem(temp_ptr->getItem());
                subtree_ptr->setRight(removeHelper(subtree_ptr->getRight(), temp_ptr->getItem()));
            }
        }
        return subtree_ptr;
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
Node<ItemType> *BST<ItemType>::searchHelper(Node<ItemType> *root, const ItemType &item) const
{
    if((root == nullptr) || (root->getItem() == item)) //base case; if the item does not exist or the item has been found
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
