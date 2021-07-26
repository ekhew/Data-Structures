/*
Title: Insertion Sort
Author: Edwin Khew
Description: Using insertion sort to sort a given array.
Date Created: 7/25/2021
*/

#include <iostream>

/*
    sorts a given array using insertion sort
    @param arr[], array that will be sorted
    @param size, size of the array to be sorted
*/
void insertionSort(int arr[], int size)
{
    //select each element one by one starting with the element at index 1, since element at index 0 is part of the ‘sorted’ section
    for(int i = 1; i < size; i++)
    {
        int value = arr[i]; //the selected element
        int index = i; //the index of the selected element

        //move elements of arr[0 … i-1] that are greater than the selected value one position ahead of their current position, to make room for inserting the selected value
        while(index >= 0 && arr[index - 1] > value)
        {
            arr[index] = arr[index - 1]; //move element one spot to the right
            index--; //move left to the next element in the sorted section that will be moved one spot to the right
        }

        arr[index] = value; //insert the selected element into its correct position in the sorted section
    }
}

int main()
{
    int arr[] = {4, 2, 15, 6, 18, 12, 10, 9, 8, 27, 23}; //array to sort

    int size = sizeof(arr) / sizeof(arr[0]); //size of the array to sort

    insertionSort(arr, size);

    //print the sorted array
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
