/*
Title: Build Heap & Heapify
Author: Edwin Khew
Description: Building a heap from a given non-heap array.
Date Created: 6/24/2021
*/

#include <iostream>

/*
    checks to see if the specified root node satisfies the conditions of a heap  by checking with its children
    @param arr[], array where the heapifying will take place
    @param size, size of the array
    @param root_index, index of a root node to check with its children to see if it satisfies the conditions of a heap
*/
void heapify(int arr[], int size, int root_index)
{
    int left_child_index = (2 * root_index) + 1; //index of the item's left child
    int right_child_index = (2 * root_index) + 2; //index of the item's right child
    int greater_child_index = root_index; //index of the child that is greater (or lesser in a min-heap); if no children are present, then the index will be that of the root

    //if the index of 'left_child' exists and its item is greater than that of the current greater child; use '<' in second condition for min-heap
    if((left_child_index < size) && (arr[left_child_index] > arr[greater_child_index]))
    {
        greater_child_index = left_child_index;
    }

    //if the index of 'right_child' exists and its item is greater than that of the current greater child; use '<' in second condition for min-heap
    if((right_child_index < size) && (arr[right_child_index] > arr[greater_child_index]))
    {
        greater_child_index = right_child_index;
    }

    if(greater_child_index != root_index) //can only swap if a child is present
    {
        //swap
        int temp = arr[root_index];
        arr[root_index] = arr[greater_child_index];
        arr[greater_child_index] = temp;

        //recursively call the function to continue heapifying
        heapify(arr, greater_child_index, size);
    }
}

/*
    builds a heap from the given array by heapifying every node starting from the deepest non-leaf node
    @param arr[], array to create a heap with
    @param size, size of the array
*/
void buildHeap(int arr[], int size)
{
    int start_index = (size / 2) - 1; //index of the deepest non-leaf node; start here because leaves are already considered heapified

    for(int i = start_index; i >= 0; i--) //backwards level order traversal; heapify each node
    {
        heapify(arr, size, i);
    }
}

int main()
{
    int arr[] = {2, 4, 15, 6, 18, 12, 10, 9, 8, 23, 27}; //array to heapify

    int size = sizeof(arr) / sizeof(arr[0]); //size of the array to heapify

    buildHeap(arr, size);

    //print the heapified array
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
