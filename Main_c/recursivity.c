#include <stdio.h>
#include <stdlib.h>

// Recursivity

// 1

long int addArray(int *array, int terms){ 
    if (terms-1 == 0)
    {
        return array[0]; // Stoping condition
    }
    return array[terms-1] + addArray(array, terms-1); // Recursivity
}

// 2

int stringEquals(char *string1, char *string2, int size){
    if (size - 1 == 0)
    {
        if (string1[0] == string2[0])
        {
            return 1;
        }
        
    }
    if (string1[size-1] == string2[size-1])
    {
        return stringEquals(string1, string2, size-1);
    }
    else return 0;
}

// 3

long int fibonacci(int number){
    if (number > 1)
    {
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
    if (number == 1)
    {
        return 1;
    }
    else return 0;
    
    
}

