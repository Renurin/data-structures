/*

The objective of this program is to receive a file .txt, copy it's content and paste it in a new .txt file

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fOriginal, *fNew;
    char ch;
    fOriginal = fopen("example.txt", "r");
    if (fOriginal== NULL)
    {
        puts("There was an error opening the file 'example.txt' was not found.");
        exit(0);
    }
    fNew = fopen("example_copy.txt", "w");
    if (fNew== NULL)
    {
        puts("There was an error writing the file 'examples_copy.txt'.");
        exit(0);
    }

    while ( 1 )
    {
        ch = fgetc(fOriginal);
        if (ch == EOF)
        {
            break;
        }
        fputc(ch,fNew);
    }
    printf ("Copy created sucessfully!");
    fclose (fOriginal);
    fclose (fNew);
    return 0;
}
