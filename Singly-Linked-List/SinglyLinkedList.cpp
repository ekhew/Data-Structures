/*
Title: Singly Linked List
Author: Edwin Khew
Description: Singly linked list class implementation.
Date Created: 5/27/2021
*/

template<typename ItemType>
SinglyLinkedList<ItemType>::SinglyLinkedList():head_ptr_(nullptr), item_count_(0) { }

template<typename ItemType>
SinglyLinkedList<ItemType>::SinglyLinkedList(const SinglyLinkedList<ItemType> &list)
{
    if(list.isEmpty()) //if the original list is empty, create an empty list
    {
        head_ptr_ = nullptr;
        item_count_ = 0;
    }
    else //if the original list is not empty
    {
        item_count_ = list.item_count_; //copy item count
        Node<ItemType> *orig_list_ptr = list.head_ptr_; //create a pointer that will traverse the original list
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
SinglyLinkedList<ItemType>::~SinglyLinkedList()
{
    clear();
}

template<typename ItemType>
bool SinglyLinkedList<ItemType>::insert(size_t position, const ItemType &new_item)
{
    Node<ItemType> *new_node_ptr = new Node<ItemType>(new_item); //create a new node with the specified item
    Node<ItemType> *pos_ptr = getPointerTo(position); //pointer to the position that the node will be inserted into

    if(isEmpty()) //if the list is empty, add the first node
    {
        head_ptr_ = new_node_ptr;
        new_node_ptr->setNext(nullptr);
    }
    else if(pos_ptr == head_ptr_) //insert to the front of the list
    {
        new_node_ptr->setNext(head_ptr_);
        head_ptr_ = new_node_ptr;
    }
    else if(pos_ptr == nullptr) //insert to the back of the list
    {
        Node<ItemType> *tail_ptr = getPointerTo(item_count_); //pointer to the last node

        tail_ptr->setNext(new_node_ptr);
        new_node_ptr->setNext(nullptr);
    }
    else //insert in the middle of the list
    {
        Node<ItemType> *next_pos_ptr = getPointerTo(position + 1); //pointer to the node directly after the position specified

        pos_ptr->setNext(new_node_ptr);
        new_node_ptr->setNext(next_pos_ptr);
    }

    item_count_++;
    return true;
}

template<typename ItemType>
bool SinglyLinkedList<ItemType>::remove(size_t position)
{
    if(!isEmpty() && position <= item_count_ && position > 0)
    {
        if(item_count_ == 1) //if the list has only one node
        {
            Node<ItemType> *temp_ptr = head_ptr_;

            head_ptr_ = nullptr;
            temp_ptr->setNext(nullptr);
            delete temp_ptr;
            temp_ptr = nullptr;
        }
        else if(position == 1) //remove the first node in the list
        {
            Node<ItemType> *temp_ptr = head_ptr_;

            head_ptr_ = head_ptr_->getNext(); //move the 'head_ptr_' to the second node in the list
            temp_ptr->setNext(nullptr);
            delete temp_ptr;
            temp_ptr = nullptr;
        }
        else if(position == item_count_) //remove the last node in the list
        {
            Node<ItemType> *temp_ptr = getPointerTo(item_count_); //pointer to the last node in the list
            Node<ItemType> *new_tail_ptr = getPointerTo(item_count_ - 1); //pointer to the second to last node in the list

            new_tail_ptr->setNext(nullptr);
            delete temp_ptr;
            temp_ptr = nullptr;
        }
        else //remove a node in the middle of the list
        {
            Node<ItemType> *temp_ptr = getPointerTo(position); //pointer to the node to be removed
            Node<ItemType> *prev_pos_ptr = getPointerTo(position - 1); //pointer to the node directly before the node to be removed
            Node<ItemType> *next_pos_ptr = getPointerTo(position + 1); //pointer to the node directly after the node to be removed

            prev_pos_ptr->setNext(next_pos_ptr);
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
void SinglyLinkedList<ItemType>::clear()
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
ItemType SinglyLinkedList<ItemType>::getItemAtPos(size_t position) const
{
    Node<ItemType> *pos_ptr = getPointerTo(position); //pointer to the node at the specified position

    if(pos_ptr == nullptr) //if the position does not exist, i.e. list is empty or position out of range
    {
        throw(std::out_of_range("Position out of range!"));
    }
    else
    {
        return pos_ptr->getItem();
    }
}

template<typename ItemType>
size_t SinglyLinkedList<ItemType>::getLength() const
{
    return item_count_;
}

template<typename ItemType>
bool SinglyLinkedList<ItemType>::isEmpty() const
{
    return head_ptr_ == nullptr; //if head_ptr_ is equal to 'nullptr', then the list is empty
}

template<typename ItemType>
void SinglyLinkedList<ItemType>::display() const
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
Node<ItemType> *SinglyLinkedList<ItemType>::getPointerTo(size_t position) const
{
    Node<ItemType> *get_ptr = nullptr; //create a new pointer to traverse the list; return 'nullptr' if there is no node at position

    if(position <= item_count_ && position > 0) //if the position exists and greater than 0
    {
        get_ptr = head_ptr_;
        //traverse to the node directly before the one at position, since its 'next_' is the pointer we want
        for(size_t i = 1; i < position; i++)
        {
            get_ptr = get_ptr->getNext();
        }
    }

    return get_ptr;
}
