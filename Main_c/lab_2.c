#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void stack_up(node *stack, char term){
    if (stack->next == NULL)
    {

    node *newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->data= term; // Set newNode data to term
    newNode->next = stack; // Get the second node
    stack = newNode; // Head points to new Node

    return stack; // Return the stack with the new Node
    }
    else
    {
        node *aux, *newNode;
        aux = stack;
        
        newNode = (node*) malloc(sizeof(node));
        newNode->data = term;
        // Find the node AFTER the key element
        while (aux->data != NULL)
        {
            aux = aux->next; // At the end of the loop, aux is the last node
        }

        newNode->next = aux->next;
        aux = newNode;
        return stack;
    }
    
    
}

void unstack(node *stack){
    node *aux;

}

int pair(char f, char d){
    switch (f)
    {
    case ')': // Check if stack is closing
        if ( d == '(')
        {
            return 1;
        } else return 0;
        break;

    case ']': // Check if stack is closing
        if ( d == '[')
        {
            return 1;
        } else return 0;
        break;

    case '}': // Check if stack is closing
        if (d == '{')
        {
            return 1;
        } else return 0;
        break;

    default:
        break;
    }
    return 0;
}

int formation(char *exp){

    node *stack; // Inicialize an empty stack
    stack = (node*) malloc(sizeof(node)); // alloc space
    int test;

    for (int i = 0; i < sizeof(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '[', exp[i] == '{' ) // test if is opening 
        {
            stack_up(stack,exp[i]); // Stack if parenthesis
        }
        else if (exp[i] == ')' || exp[i] == ']', exp[i] == '}') // test if is closing
        {
            test = pair(exp[i], stack->next->data); // check if parenthesis is closing
            if (test == 0)
            {   
                break;
                return 0;
            }
        }

    }
    if (test == 1)
    {
        return 1;
    }
    else return 0;
}


int main(int argc, char const *argv[])
{
    char exp[50];

    printf("Type an expression: ");
    scanf("%49[^\n]",exp); // Get the expression
    printf("\nExpression %s\nReturn: %d\n", exp, formation(exp));
    return 0;
}

