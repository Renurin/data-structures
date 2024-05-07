#include <stdio.h>
#include <stdlib.h>

void swap(int *original, int *trocar)
{
    int temp = *original;
    *original = *trocar;
    *trocar = temp;
}
