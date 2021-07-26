/*
Title: Bubble Sort
Author: Edwin Khew
Description: Using bubble sort to sort a given array.
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
    sorts a given array using bubble sort
    @param arr[], array that will be sorted
    @param size, size of the array to be sorted
*/
void bubbleSort(int arr[], int size)
{
     bool swapped = true; //this variable acts as a signal for the ‘if’ statement; ‘true’ if a swap occurred, and ‘false’ if not

    //maximum number of iterations needed to sort the array
    for(int i = 0; i < size - 1; i++)
    {
        swapped = false;

        //total number of comparisons in each iteration; ‘size - i - 1’ ensures that the loop does not iterate through the already sorted part of the array
        for(int j = 0; j < size - i - 1; j++)
        {
            //if ‘j’ is greater than the following element, swap
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;  //signals that a swap occurred, which means to continue iterating
            }
        }

        //if an iteration occurred where there was no swap, it means that the array has been sorted, so break from the loop; there is no need to iterate any further
        if(swapped == false)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {4, 2, 15, 6, 18, 12, 10, 9, 8, 27, 23}; //array to sort

    int size = sizeof(arr) / sizeof(arr[0]); //size of the array to sort

    bubbleSort(arr, size);

    //print the sorted array
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
