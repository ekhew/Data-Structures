/*
Title: Linked Stack
Author: Edwin Khew
Description: Linked stack class implementation.
Date Created: 5/31/2021
*/

template<typename ItemType>
LinkedStack<ItemType>::LinkedStack():top_ptr_(nullptr), item_count_(0) { }

template<typename ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType> &stack)
{
    if(stack.isEmpty()) //if the original stack is empty, create an empty stack
    {
        top_ptr_ = nullptr;
        item_count_ = 0;
    }
    else //if the original stack is not empty
    {
        item_count_ = stack.item_count_; //copy item count
        Node<ItemType> *orig_stack_ptr = stack.top_ptr_; //create a pointer that will traverse the original stack
        top_ptr_ = new Node<ItemType>(orig_stack_ptr->getItem()); //create the first node in the new stack with the same item as in the original stack
        Node<ItemType> *new_stack_ptr = top_ptr_; //create a pointer that will traverse the new stack

        while(orig_stack_ptr->getNext() != nullptr)
        {
            orig_stack_ptr = orig_stack_ptr->getNext(); //traverse to the next node in the original stack
            Node<ItemType>* new_node_ptr = new Node<ItemType>(orig_stack_ptr->getItem()); //create a new node with the same item as in the original stack
            new_stack_ptr->setNext(new_node_ptr); //connect the new node to the new stack
            new_stack_ptr = new_node_ptr; //traverse to the next node in the new stack (the node that was just copied)
        }
    }
}

template<typename ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
    clear();
}

template<typename ItemType>
bool LinkedStack<ItemType>::push(const ItemType &new_item)
{
    Node<ItemType> *new_node_ptr = new Node<ItemType>(new_item); //create a new node with the specified item

    if(isEmpty()) //if the stack is empty, add the first node
    {
        top_ptr_ = new_node_ptr;
        new_node_ptr->setNext(nullptr);
    }
    else //insert to the top of the stack
    {
        new_node_ptr->setNext(top_ptr_);
        top_ptr_ = new_node_ptr;
    }

    item_count_++;
    return true;
}

template<typename ItemType>
bool LinkedStack<ItemType>::pop()
{
    if(!isEmpty()) //can only remove if the stack is not empty
    {
        Node<ItemType> *temp_ptr = top_ptr_; //pointer that points to the top node in the stack

        top_ptr_ = top_ptr_->getNext(); //move 'head_ptr_' to the next node down in the stack
        temp_ptr->setNext(nullptr);
        delete temp_ptr;
        temp_ptr = nullptr;

        item_count_--;
        return true;
    }
    else
    {
        return false;
    }
}

template<typename ItemType>
void LinkedStack<ItemType>::clear()
{
    Node<ItemType> *traverse_ptr = top_ptr_;

    while(top_ptr_ != nullptr) //while stack is not empty
    {
        top_ptr_ = top_ptr_->getNext(); //move the head pointer to the next node
        traverse_ptr->setNext(nullptr);
        delete traverse_ptr;
        traverse_ptr = top_ptr_; //move the traverse pointer to the next node
    }

    item_count_ = 0;
}

template<typename ItemType>
size_t LinkedStack<ItemType>::size() const
{
    return item_count_;
}

template<typename ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
    return top_ptr_ == nullptr; //if top_ptr_ is equal to 'nullptr', then the stack is empty
}

template<typename ItemType>
void LinkedStack<ItemType>::peek() const
{
    if(!isEmpty())
    {
        std::cout << top_ptr_->getItem(); //print the item at the top of the stack
    }
    else
    {
        std::cout << "Stack is empty!";
    }
}
