#include <stdio.h>
#define n 5
int queue[n];
int front = -1;
int rear = -1;

int isfull()
{
    return (front == 0 && rear == n - 1) || (front == rear + 1);
}

int isempty()
{
    return front == -1 && rear == -1;
}

void reset()
{
    if (front == rear)
    {
        front == -1;
        rear == -1;
    }
}
void enqueue(int value)
{
    if (isfull())
    {
        printf("Queueoverflow\n");
        return;
    }
    if (isempty())
    {
        front++;
        queue[++rear] = value;
    }
    else if (rear == n - 1)
    {
        rear = 0;
        queue[rear] = value;
    }
    else
    {
        queue[++rear] = value;
    }
}
void dequeue()
{
    if (isempty())
    {
        printf("QueueUnderflow\n");
        return;
    }
    if (front == n - 1 && rear == n - 1)
    {
        printf("%d\n", queue[front]);
        reset();
    }
    else if (front == n - 1)
    {
        printf("%d\n", queue[front]);
        front = 0;
    }
    else
    {
        printf("%d\n", queue[front++]);
        reset();
    }
}
void displayfront()
{
    printf("%d\n", queue[front]);
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.displayfront\n");
        printf("4.exit()");
        printf("Enter your choice :\n");
        scanf("%d", &choice);
        if (choice == 4)
        {
            break;
        }
        switch (choice)
        {
        case 1:
            printf("Enter value to push in queue : \n");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            displayfront();
            break;
        default:
            printf("Invalid Input\n");
        }
    }

    return 0;
}