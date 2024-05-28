#include <stdio.h>
#include <stdlib.h>

void swap(int *original, int *change)
{
    int temp = *original;
    *original = *change;
    *change = temp;
}

// O(N²)
// Ascending
// Worst case: Inverted array

void bubblesort(int *array, int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i-1 ; j++)
        {
            if (array[j]>array[j+1])
            {
                swap(&array[j], &array[j+1]);
            }
            
        }
        
    }
}

// O(N²)
// Ascending
// Worst case: Random array

void selectionsort(int *array, int size){
    for (int i = 0; i < size; i++)
    {
        int min = i; // Force minimum index
        for (int j = i+1; j < size; j++)
        {
            if (array[j]<array[min]) // If the min is not the smaller
            {
                min = j; // Change the index
            }
            
        }
        swap(&array[min], &array[i]);
    }
    
}

// O(N²)
// Worst case: Inverted array
// Ascending

void insertionsort(int *array, int size){
    for (int i = 1; i < size; i++) // Supose the first is already ordenaded
    {
        int key = array[i]; // Key is the i element
        int check = i -1; // Set a check to compare terms to the left

        while ( key < array[check] && check>=0) // While key is smaller than array[check],
        {
            array[check + 1] = array[check];
            --check; // Uses and then decreases
        }
        array[check + 1] = key;
    }
    
}

// O(N*Log N)
// Ascending
// Worst case: O(n²), almost-sorted array

int partition(int *array, int left, int right){
    int pivot = array[right]; // Defining pivot: The right element
    int mid = left-1; // Pointer for greater element

    for (int i = left; i < right; i++)
    {
        if (array[i] <= pivot)
        {
            // if an element smaller than pivot is found
            // swap it with greater element pointed by mid
             
            mid++;
            swap(&array[mid], &array[i]);
        }
    }
    // Swap pivot element with the greater pointed by mid
    swap(&array[mid+1], &array[right]);

    return mid+1; // Partition point
}

void quicksort(int *array, int left, int right){
    if (left < right)
    {
        int mid = partition(array,left,right); // Defining mid
        quicksort(array, left, mid-1);
        quicksort(array, mid+1, right);

    }
    
}

//O(N * Log N)
// Ascending
//

void mergesort(int *array, int left, int right){
    if (left< right-1)
    {
        int mid= (left+right)/2;
        mergesort(array, left, mid);
        mergesort(array, mid+1, right);
        
    }
    
}