/*
Title: Quick Sort
Author: Edwin Khew
Description: Using quick sort to sort a given array.
Date Created: 7/25/2021
*/

#include <iostream>

/*
    swaps two elements in a array
    @param num1, first element
    @param num1, second element
*/
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/*
    Selects a pivot and rearranges the array such that the elements less than the pivot are to its left, and elements greater than the pivot are to its right.
    @param arr[], array that will be partitioned
    @param left, leftmost/first element of the array
    @param right, rightmost/last element of the array
    @return the index of the pivot
*/
int partition(int arr[], int left, int right)
{
    int pivot = arr[right]; //select the rightmost element as the pivot
    int part = left; //partition index

    //for every element from the first element to the second to last, compare it to the pivot
    for(int i = left; i < right; i++)
    {
        if(arr[i] < pivot)
        {
            swap(&arr[i], &arr[part]);
            part++;
        }
    }

    swap(&arr[right], &arr[part]); //swap the last element, the pivot, with the element at the partition index; the pivot is now in its sorted spot in the array

    return part; //return the partition index
}

/*
    sorts a given array using quick sort
    @param arr[], array that will be sorted
    @param left, leftmost/first element of the array
    @param right, rightmost/last element of the array
*/
void quickSort(int arr[], int left, int right)
{
    //base case; when left >= right, this means that the array cannot be partitioned anymore; arrays of 1 element have been successfully created since that 1 element would be both the first and last element
    if(left >= right)
    {
        return;
    }

    int part = partition(arr, left, right); //partition the array and store the index of the pivot returned by the function
    quickSort(arr, left, part - 1); //recursive case; partition the elements to the left of the pivot
    quickSort(arr, part + 1, right); //recursive case; partition the elements to the right of the pivot
}

/*
	sorts a given array using quick sort
	@param arr[], array that will be sorted
	@param size, size of the array to be sorted
*/
void quickSortWrapper(int arr[], int size)
{
    quickSort(arr, 0, size - 1);
}

int main()
{
    int arr[] = {4, 2, 15, 6, 18, 12, 10, 9, 8, 27, 23}; //array to sort

    int size = sizeof(arr) / sizeof(arr[0]); //size of the array to sort

    quickSortWrapper(arr, size);

    //print the sorted array
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
