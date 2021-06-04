/*
Title: Priority Queue
Author: Edwin Khew
Description: Priority queue class implementation.
Date Created: 6/3/2021
*/

template<typename ItemType>
PriorityQueue<ItemType>::PriorityQueue():front_ptr_(nullptr), back_ptr_(nullptr), item_count_(0) { }

template<typename ItemType>
PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue<ItemType> &queue)
{
    if(queue.isEmpty()) //if the original queue is empty, create an empty queue
    {
        front_ptr_ = nullptr;
        back_ptr_ = nullptr;
        item_count_ = 0;
    }
    else //if the original queue is not empty
    {
        item_count_ = queue.item_count_; //copy item count
        Node<ItemType> *orig_queue_ptr = queue.front_ptr_; //create a pointer that will traverse the original queue
        front_ptr_ = new Node<ItemType>(orig_queue_ptr->getItem(), orig_queue_ptr->getPriority()); //create the first node in the new queue with the same item as in the original queue
        Node<ItemType> *new_queue_ptr = front_ptr_; //create a pointer that will traverse the new queue

        while(orig_queue_ptr->getNext() != nullptr)
        {
            orig_queue_ptr = orig_queue_ptr->getNext(); //traverse to the next node in the original queue
            Node<ItemType>* new_node_ptr = new Node<ItemType>(orig_queue_ptr->getItem(), orig_queue_ptr->getPriority()); //create a new node with the same item as in the original queue
            new_queue_ptr->setNext(new_node_ptr); //connect the new node to the new queue
            new_queue_ptr = new_node_ptr; //traverse to the next node in the new queue (the node that was just copied)
        }

        back_ptr_ = new_queue_ptr;
    }
}

template<typename ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
{
    clear();
}

template<typename ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType &new_item, int priority)
{
    Node<ItemType> *new_node_ptr = new Node<ItemType>(new_item, priority); //create a new node with the specified item

    if(isEmpty()) //if the queue is empty, insert the first node
    {
        front_ptr_ = new_node_ptr;
        back_ptr_ = new_node_ptr;
        new_node_ptr->setNext(nullptr);
    }
    else if(priority < front_ptr_->getPriority()) //insert at the very front of the queue, if the new item's priority is less than that of the first item
    {
        new_node_ptr->setNext(front_ptr_);
        front_ptr_ = new_node_ptr;
    }
    else if(priority >= back_ptr_->getPriority()) //insert to the very back of the queue, if the new item's priority is greater than that of the last item
    {
        back_ptr_->setNext(new_node_ptr);
        back_ptr_ = new_node_ptr;
        new_node_ptr->setNext(nullptr);
    }
    else //insert in the middle of the queue
    {
        Node<ItemType> *traverse_ptr = front_ptr_; //pointer that will traverse the queue, starting from the front

        //look at the priority of the next node; stop traversing once the priority of the next node is >= the priority of the new node
        while(traverse_ptr->getNext()->getPriority() <= new_node_ptr->getPriority())
        {
            traverse_ptr = traverse_ptr->getNext(); //traverse to the next node
        }

        new_node_ptr->setNext(traverse_ptr->getNext());
        traverse_ptr->setNext(new_node_ptr);
    }

    item_count_++;
    return true;
}

template<typename ItemType>
bool PriorityQueue<ItemType>::dequeue()
{
    if(!isEmpty())
    {
        if(item_count_ == 1) //if the queue has only one node
        {
            Node<ItemType> *temp_ptr = front_ptr_;

            front_ptr_ = nullptr;
            back_ptr_ = nullptr;
            temp_ptr->setNext(nullptr);
            delete temp_ptr;
            temp_ptr = nullptr;
        }
        else //remove the first node in the queue
        {
            Node<ItemType> *temp_ptr = front_ptr_;

            front_ptr_ = front_ptr_->getNext(); //move the 'front_ptr_' to the second node in the queue
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
void PriorityQueue<ItemType>::clear()
{
    Node<ItemType> *traverse_ptr = front_ptr_; //create a pointer to traverse through the entire list, starting from the front

    while(front_ptr_ != nullptr) //while list is not empty
    {
        front_ptr_ = front_ptr_->getNext(); //move the front pointer to the next node
        traverse_ptr->setNext(nullptr);
        delete traverse_ptr;
        traverse_ptr = front_ptr_; //move the traverse pointer to the next node
    }

    item_count_ = 0;
}

template<typename ItemType>
size_t PriorityQueue<ItemType>::size() const
{
    return item_count_;
}

template<typename ItemType>
bool PriorityQueue<ItemType>::isEmpty() const
{
    return front_ptr_ == nullptr; //if front_ptr_ is equal to 'nullptr', then the list is empty
}

template<typename ItemType>
void PriorityQueue<ItemType>::peek() const
{
    if(!isEmpty())
    {
        std::cout << front_ptr_->getItem();
    }
    else
    {
        std::cout << "List is empty!";
    }
}
