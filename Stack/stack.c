#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the stack

typedef struct Stack
{
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *s)
{
    s->top = -1;
}

// Check if the stack is full
int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack is full. Cannot push %d\n", value);
    }
    else
    {
        s->items[++(s->top)] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

// Pop an element from the stack
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty. Cannot pop an element.\n");
        return -1;
    }
    else
    {
        return s->items[(s->top)--];
    }
}

// Peek the top element of the stack
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty. No element to peek.\n");
        return -1;
    }
    else
    {
        return s->items[s->top];
    }
}

// Display the stack
void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack: ");
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

// Main function to test the stack operations
int main()
{
    Stack stack;
    initStack(&stack);

    int choice, value;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            value = pop(&stack);
            if (value != -1)
            {
                printf("Popped value: %d\n", value);
            }
            break;
        case 3:
            value = peek(&stack);
            if (value != -1)
            {
                printf("Top value: %d\n", value);
            }
            break;
        case 4:
            display(&stack);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
