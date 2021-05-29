/*
Title: Doubly Linked List
Author: Edwin Khew
Description: Doubly linked list class implementation.
Date Created: 5/28/2021
*/

template<typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList():head_ptr_(nullptr), tail_ptr_(nullptr), item_count_(0) { }

template<typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType> &list)
{
    if(list.isEmpty()) //if the original list is empty
    {
        head_ptr_ = nullptr;
        tail_ptr_ = nullptr;
        item_count_ = 0;
    }
    else //if the original list is not empty
    {
        item_count_ = list.item_count_; //copy the item count
        Node<ItemType>* orig_list_ptr = list.head_ptr_; //create a pointer that will traverse the original list

        head_ptr_ = new Node<ItemType>(orig_list_ptr->getItem()); //create the first node with the same item as in the original list
        Node<ItemType>* new_list_ptr = head_ptr_; //create a pointer that will traverse the new list

        while(orig_list_ptr->getNext() != nullptr)
        {
            orig_list_ptr = orig_list_ptr->getNext(); //traverse to the next node in the original list
            Node<ItemType>* new_item_ptr = new Node<ItemType>(orig_list_ptr->getItem()); //create a new node
            new_list_ptr->setNext(new_item_ptr);
            new_item_ptr->setPrev(new_list_ptr);
            new_list_ptr = new_item_ptr; //traverse to the newly created node in the new list
        }

        tail_ptr_ = new_list_ptr; //set the tail pointer to the last node created
    }
}

template<typename ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
    clear();
}

template<typename ItemType>
bool DoublyLinkedList<ItemType>::insert(size_t position, const ItemType &new_item)
{
    Node<ItemType> *new_node_ptr = new Node<ItemType>(new_item); //create a new node with the specified item
    Node<ItemType> *pos_ptr = getPointerTo(position); //pointer to the position that the node will be inserted into

    if(isEmpty()) //if the list is empty, insert the first node of the list
    {
        head_ptr_ = new_node_ptr;
        tail_ptr_ = new_node_ptr;
        new_node_ptr->setNext(nullptr);
        new_node_ptr->setPrev(nullptr);
    }
    else if(pos_ptr == head_ptr_) //insert to the front of the list
    {
        head_ptr_->setPrev(new_node_ptr);
        new_node_ptr->setNext(head_ptr_);
        new_node_ptr->setPrev(nullptr);
        head_ptr_ = new_node_ptr;
    }
    else if(pos_ptr == nullptr) //insert to the back of the list
    {
        tail_ptr_->setNext(new_node_ptr);
        new_node_ptr->setNext(nullptr);
        new_node_ptr->setPrev(tail_ptr_);
        tail_ptr_ = new_node_ptr;
    }
    else //insert in the middle of the list
    {
        new_node_ptr->setNext(pos_ptr);
        new_node_ptr->setPrev(pos_ptr->getPrev());
        pos_ptr->setPrev(new_node_ptr);
        pos_ptr->getPrev()->setNext(new_node_ptr);
    }

    item_count_++;
    return true;
}

template<typename ItemType>
bool DoublyLinkedList<ItemType>::remove(size_t position)
{
    if(!isEmpty() && position <= item_count_ && position > 0)
    {
        Node<ItemType>* pos_ptr = getPointerTo(position); //creates a pointer for the node at the specified position

        if(pos_ptr == head_ptr_) //remove the first node in the list
        {
            head_ptr_ = head_ptr_->getNext(); //point the head pointer to the second node
            head_ptr_->setPrev(nullptr);
            pos_ptr->setNext(nullptr);
            delete pos_ptr;
            pos_ptr = nullptr;
        }
        else if(pos_ptr == tail_ptr_) //remove the last node in the list
        {
            tail_ptr_ = tail_ptr_->getPrev(); //point the tail pointer to the second to last node
            tail_ptr_->setNext(nullptr);
            pos_ptr->setPrev(nullptr);
            delete pos_ptr;
            pos_ptr = nullptr;
        }
        else //remove from the middle of the list
        {
            pos_ptr->getPrev()->setNext(pos_ptr->getNext()); //get the node before the node to delete, and set its next pointer to the node that is after the node to delete
            pos_ptr->getNext()->setPrev(pos_ptr->getPrev()); //get the node after the node to delete, and set its previous pointer to the node that is before the node to delete
            pos_ptr->setPrev(nullptr);
            pos_ptr->setNext(nullptr);
            delete pos_ptr;
            pos_ptr = nullptr;
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
void DoublyLinkedList<ItemType>::clear()
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
ItemType DoublyLinkedList<ItemType>::getItemAtPos(size_t position) const
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
size_t DoublyLinkedList<ItemType>::getLength() const
{
    return item_count_;
}

template<typename ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
    return head_ptr_ == nullptr;
}

template<typename ItemType>
void DoublyLinkedList<ItemType>::display() const
{
    Node<ItemType> *traverse_ptr = head_ptr_; //create a pointer that will traverse the entire list, starting from the head

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
void DoublyLinkedList<ItemType>::displayBackwards() const
{
    Node<ItemType> *traverse_ptr = tail_ptr_; //create a pointer that will traverse the entire list, starting from the tail

    if(!isEmpty())
    {
        while(traverse_ptr != nullptr)
        {
            std::cout << traverse_ptr->getItem() << " ";
            traverse_ptr = traverse_ptr->getPrev(); //traverse to the next item
        }
    }
    else
    {
        std::cout << "List is empty!" << std::endl;
    }
}

template<typename ItemType>
Node<ItemType> *DoublyLinkedList<ItemType>::getPointerTo(size_t position) const
{
    Node<ItemType> *get_ptr = nullptr; //create a new pointer to traverse the list; return 'nullptr' if there is no node at position

    if(position <= item_count_ && position > 0) //if the position exists
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
