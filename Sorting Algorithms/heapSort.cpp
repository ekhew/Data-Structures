/*
Title: Heap Sort
Author: Edwin Khew
Description: Using heap sort to sort a given array.
Date Created: 6/25/2021
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
    sorts a given array using heap sort
    @param arr[], array to sort using heap sort
    @param size, size of the array
*/
void heapSort(int arr[], int size)
{
    //build heap; backwards level order traversal; heapify each node; start at index of the deepest non-leaf node because leaves are already considered heapified
    for(int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    //sorts using the heap that was just built
    for(int i = size - 1; i > 0; i--) //'i', the index of the last item, decrements after each iteration
    {
        //swap the first item with the last item in the 'unsorted' section of the array
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        //heapify the 'unsorted' section of the array
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {2, 4, 15, 6, 18, 12, 10, 9, 8, 23, 27}; //array to sort

    int size = sizeof(arr) / sizeof(arr[0]); //size of the array to sort

    heapSort(arr, size);

    //print the sorted array
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
