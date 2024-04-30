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

void *addArray(char *pvetchar, int *ptammax, int *pqtde, char include)
{
    if (*pqtde == *ptammax)
    {
        *pvetchar = realloc(*pvetchar, *ptammax * 2);
        *ptammax = *ptammax * 2;
    }

    pvetchar[*pqtde + 1] = include;
    *pqtde++;
}
void *deleteInArray(char *pvetchar, int *ptammax, int *pqtde, char exclude)
{
    char *aux = malloc(*ptammax);
    for (int i = 0; i < *pqtde; i++)
    {
        if (pvetchar[i] == exclude)
        {
            continue;
        }
        aux[i] = pvetchar[i];
    }
    *pqtde--;
    free(pvetchar);
    pvetchar = aux;
    free(aux);
}