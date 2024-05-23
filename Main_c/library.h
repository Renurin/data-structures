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
            swap(&array[check], &array[i]); 
            check--;
        }
    }
    
}


