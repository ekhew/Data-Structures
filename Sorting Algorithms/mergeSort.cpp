/*
Title: Merge Sort
Author: Edwin Khew
Description: Using merge sort to sort a given array.
Date Created: 7/25/2021
*/

#include <iostream>

/*
	This function merges two subarrays into a one larger sorted array.
	@param arr[], subarray that will be sorted
	@param left, first value of the array
	@param mid, middle value of the array
	@param right, last value of the array
*/
void merge(int arr[], int left, int mid, int right)
{
    int temp[right - left + 1]; //create a temporary array of the same size as the original
    int i = left; //for iterating through the first half of the original array
    int j = mid + 1; //for iterating through the second half of the original array
    int k = 0; //for iterating through temporary array

    //while there are still values to be compared in either halves
    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++; //since the an element in the first half was picked and added to the temporary array, increment to the next unpicked element in this half
        }
        else
        {
            temp[k] = arr[j];
            j++; //since the an element in the second half was picked and added to the temporary array, increment to the next unpicked element in this half
        }

        k++; //after an element has been added to the temporary array, move up to the next empty index in the temporary array
    }

    //if the second half ran out of elements to compare, add the rest of the elements in the first half into the merged array
    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    //if the first half ran out of elements to compare, add the rest of the elements in the second half into the merged array
    while(j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    //copy the sorted temporary array to the original array
    for(int i = left; i <= right; i++)
    {
        arr[i] = temp[i - left];
    }
}

/*
	This function recursively divides the array in half, and then calls the merge() function when it can no longer divide.
	@param arr[], array that will be sorted
	@param left, index of leftmost/first element of the array
	@param right, index of rightmost/last element of the array
*/
void mergeSort(int arr[], int left, int right)
{
    //base case; when left >= right, this means that the array cannot be divided in half anymore; arrays of 1 element have been successfully created since that 1 element would be both the first and last element
    if(left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2; //find the index of the middle element
    mergeSort(arr, left, mid); //recursive case; divide the left side in half (from left to middle)
    mergeSort(arr, mid + 1, right); //recursive case; divide the right side in half (from middle+1 to right)
    merge(arr, left, mid, right);
}

/*
	sorts a given array using merge sort
	@param arr[], array that will be sorted
	@param size, size of the array to be sorted
*/
void mergeSortWrapper(int arr[], int size)
{
    mergeSort(arr, 0, size - 1);
}

int main()
{
    int arr[] = {4, 2, 15, 6, 18, 12, 10, 9, 8, 27, 23}; //array to sort

    int size = sizeof(arr) / sizeof(arr[0]); //size of the array to sort

    mergeSortWrapper(arr, size);

    //print the sorted array
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
