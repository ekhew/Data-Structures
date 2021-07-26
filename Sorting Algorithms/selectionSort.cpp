/*
Title: Selection Sort
Author: Edwin Khew
Description: Using selection sort to sort a given array.
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
    sorts a given array using selection sort
    @param arr[], array that will be sorted
    @param size, size of the array to be sorted
*/
void selectionSort(int arr[], int size)
{
    //maximum number of iterations needed to sort the array
    for(int i = 0; i < size - 1; i++)
    {
        int min = i; //keeps track of the current smallest element

        //find the smallest element
        for(int j = i + 1; j < size; j++)
        {
            //while iterating, if a new smallest element is found, set ‘min’ to that element
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        swap(&arr[i], &arr[min]); //when the smallest element has been found, swap
    }
}

int main()
{
    int arr[] = {4, 2, 15, 6, 18, 12, 10, 9, 8, 27, 23}; //array to sort

    int size = sizeof(arr) / sizeof(arr[0]); //size of the array to sort

    selectionSort(arr, size);

    //print the sorted array
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
