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


// Structs to chain list
// Examples
typedef struct node
{
    int data;
    node* next;
} node;

bool checkEmpty(node *list){
    if (list == NULL)
    {
        return true;
    }
    else return false;
}

node insertNodeHead(int term, node *list){
    node *newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->data= term; // Set newNode data to term
    newNode->next = list; // Get the second node
    list= newNode; // Head points to new Node

    return *list; // Return the list with the new Node
}

node insertNodeTail(int term, node *list){
    node *aux , *newNode;
    aux->next = list; // Aux to find the last node

    newNode = (node*) malloc(sizeof(node));
    newNode->data = term;
    newNode->next = NULL; //New node will be the last term

    while (aux->next != NULL)
    {
        aux = aux->next; // Fiding the last node
    }
    aux->next = newNode;
    return *list;
}

node insertNodeBefore(int term, int key, node *list){
    // Create a function to test if key is the first node

    node *aux, *newNode;
    aux = list;
    if (aux->data = key)
    {
        insertNodeHead(term, list);
    }
    else{
        newNode = (node*) malloc(sizeof(node));
        newNode->data = term;
        // Find the node BEFORE the key element
        while (aux->next->data != key)
        {
            aux = aux->next; // At the end of the loop, aux is the antecessor of newNode and aux->next is the sucessor.
        }

        newNode->next = aux->next;
        aux->next = newNode;
        return *list;
    }
}

node insertNodeAfter(int term, int key, node *list){
    // Create a function to test if key is the last node;

    node *aux, *newNode;
    aux = list;
    
    newNode = (node*) malloc(sizeof(node));
    newNode->data = term;
    // Find the node AFTER the key element
    while (aux->data != key)
    {
        aux = aux->next; // At the end of the loop, aux is the node of key and aux->next is the sucessor.
    }

    newNode->next = aux->next;
    aux = newNode;
    return *list;
}
