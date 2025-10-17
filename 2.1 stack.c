#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int top = -1, stack[MAX_SIZE];

void push()
{
    int item;

    if (top == MAX_SIZE - 1)
    {
        printf("\nStack Overflow!!");
    }
    else
    {
        printf("\nEnter the element: ");
        scanf("%d", &item);
        top = top + 1;
        stack[top] = item;
        printf("element inserted");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!!");
    }
    else
    {
        printf("\nPopped element is: %d", stack[top]);
        top = top - 1;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("\nStack Underflow!!");
    }
    else
    {
        printf("\nValue at the top of stack is: %d", stack[top]);
        
    }
}

void display()
{
    if (top == -1)
    {
        printf("\nStack Underflow!!");
    }
    else
    {
        printf("\nElements present in the stack:\n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n\nPerform operations on the stack:\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);

        default:
            printf("\nInvalid choice!!");
        }
    }
    return 0;
}