#include <stdio.h>
#include <stdlib.h>

int *createArrayInt(int size)
{
    int *array = malloc(sizeof(int) * size);
    return array;
}

int *createArrayFloat(int size)
{
    int *array = malloc(sizeof(int) * size);
    return array;
}
