#include <stdlib.h>
#include <stdio.h>

// This is suposed to be an alternative to C

void swap(int *original, int *change){
    int temp = *original;
    *original = *change;
    *change = temp;
}

// Sort algorithms

void bubblesort(int *array, int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; i < size-i-1; i++) // Loop to float the greatest term
        {
            if (array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
                
            }
        }
    }
}

void selectionsort(int *array, int size){
    for (int i = 0; i < size; i++)
    {
        int min = i; // Setup a minimum index
        for (int j = 0; i < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j; // Update the minimum index
            }
            
        }
        swap(&array[i], &array[min]);
    }
    
}