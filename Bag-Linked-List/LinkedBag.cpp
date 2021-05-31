/*
Title: Linked Bag
Author: Edwin Khew
Description: Linked bag class implementation.
Date Created: 5/29/2021
*/

template<typename ItemType>
LinkedBag<ItemType>::LinkedBag():head_ptr_(nullptr), item_count_(0) { }

template<typename ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType> &bag)
{
    if(bag.isEmpty()) //if the original list is empty, create an empty list
    {
        head_ptr_ = nullptr;
        item_count_ = 0;
    }
    else //if the original list is not empty
    {
        item_count_ = bag.item_count_; //copy item count
        Node<ItemType> *orig_list_ptr = bag.head_ptr_; //create a pointer that will traverse the original list
        head_ptr_ = new Node<ItemType>(orig_list_ptr->getItem()); //create the first node in the new list with the same item as in the original list
        Node<ItemType> *new_list_ptr = head_ptr_; //create a pointer that will traverse the new list

        while(orig_list_ptr->getNext() != nullptr)
        {
            orig_list_ptr = orig_list_ptr->getNext(); //traverse to the next node in the original list
            Node<ItemType>* new_node_ptr = new Node<ItemType>(orig_list_ptr->getItem()); //create a new node with the same item as in the original list
            new_list_ptr->setNext(new_node_ptr); //connect the new node to the new list
            new_list_ptr = new_node_ptr; //traverse to the next node in the new list (the node that was just copied)
        }
    }
}

template<typename ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
    clear();
}

template<typename ItemType>
bool LinkedBag<ItemType>::insert(const ItemType &new_item)
{
    Node<ItemType> *new_node_ptr = new Node<ItemType>(new_item); //create a new node with the specified item

    if(isEmpty()) //if the list is empty, add the first node
    {
        head_ptr_ = new_node_ptr;
        new_node_ptr->setNext(nullptr);
    }
    else //always insert to the front of the list, since it takes O(1) time complexity
    {
        new_node_ptr->setNext(head_ptr_);
        head_ptr_ = new_node_ptr;
    }

    item_count_++;
    return true;
}

template<typename ItemType>
bool LinkedBag<ItemType>::remove(const ItemType &item)
{
    Node<ItemType> *temp_ptr = getPointerTo(item); //pointer to the node with the item to remove

    if(!isEmpty() && (temp_ptr != nullptr)) //if the list is not empty and the item exists
    {
        if(item_count_ == 1) //if the list has only one node
        {
            head_ptr_ = nullptr;
            delete temp_ptr;
            temp_ptr = nullptr;
        }
        else //always remove from the front of the list, since it takes O(1) time complexity
        {
            temp_ptr->setItem(head_ptr_->getItem()); //copy the item in the first node into the node with the item to be removed
            temp_ptr = head_ptr_; //point 'temp_ptr' to the first node
            head_ptr_ = head_ptr_->getNext(); //move 'head_ptr_' to the second node
            temp_ptr->setNext(nullptr);
            delete temp_ptr;
            temp_ptr = nullptr;
        }

        item_count_--;
        return true;
    }
    else
    {
        return false;
    }
}

template<typename ItemType>
void LinkedBag<ItemType>::clear()
{
    Node<ItemType> *traverse_ptr = head_ptr_; //create a pointer to traverse through the entire list, starting from the front

    while(head_ptr_ != nullptr) //while list is not empty
    {
        head_ptr_ = head_ptr_->getNext(); //move the head pointer to the next node
        traverse_ptr->setNext(nullptr);
        delete traverse_ptr;
        traverse_ptr = head_ptr_; //move the traverse pointer to the next node
    }

    item_count_ = 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType &item) const
{
    Node<ItemType> *traverse_ptr = head_ptr_; //create a pointer to traverse through the entire list, starting from the front
    int frequency = 0;

    while(traverse_ptr != nullptr) //while 'traverse_ptr' has not reached the end of the list
    {
        if(traverse_ptr->getItem() == item)
        {
            frequency++;
        }
        traverse_ptr = traverse_ptr->getNext();
    }

    return frequency;
}

template<typename ItemType>
bool LinkedBag<ItemType>::contains(const ItemType &item) const
{
    return getPointerTo(item) != nullptr;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
    return item_count_;
}

template<typename ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
    return item_count_ == 0;
}

template<typename ItemType>
void LinkedBag<ItemType>::display() const
{
    Node<ItemType> *traverse_ptr = head_ptr_; //create a pointer that will traverse the entire list

    if(!isEmpty())
    {
        while(traverse_ptr != nullptr)
        {
            std::cout << traverse_ptr->getItem() << " ";
            traverse_ptr = traverse_ptr->getNext(); //traverse to the next item
        }
    }
    else
    {
        std::cout << "List is empty!" << std::endl;
    }
}

template<typename ItemType>
Node<ItemType> *LinkedBag<ItemType>::getPointerTo(const ItemType &item) const
{
    Node<ItemType> *get_ptr = head_ptr_; //pointer that will traverse the list
    bool found = false;

    while(!found && (get_ptr != nullptr)) //while item is not found and the traversal pointer has not reached the end of the list
    {
        if(get_ptr->getItem() == item) //if there is a match
        {
            found = true;
        }
        else //if not a match, traverse to the next node in the list
        {
            get_ptr = get_ptr->getNext();
        }
    }

    return get_ptr;
}
