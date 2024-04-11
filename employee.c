#include <stdio.h>
#include <stdlib.h>

// In this struct, we will define the attributes of an employee
struct employee
{
    char name[60];
    int age;
    float salary;
} employee;

// main
int main()
{    
    FILE *rgst; // register is a pointer for a file
    rgst = fopen("registration.DAT", "w");
    char option = 'Y';
    if (rgst == NULL)
    {
        puts ("Something went wrong...");
        exit (0);
    }
    struct employee worker; // Creates variable type employee worker
    while (option =='Y'||option=='y')
    {
        printf("Enter a name, an age and a salary: \n");
        scanf("%s %d %f", worker.name, &worker.age, &worker.salary); // Gets user input
        fprintf(rgst, "%s %d %0.2f\n", worker.name, worker.age, worker.salary); // Prints the attributes of worker in registration.DAT

        puts("Would you like to register another employee? [Y or N]"); // Checks if user wants to continue
        fflush(stdin); // Clear buffer
        scanf("%c", &option); // Gets the option

    }
    
    fclose(rgst); // Closes file


    return 0;
}
