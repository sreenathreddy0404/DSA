#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

typedef struct Queue
{
    int items[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue *q)
{
    return (q->rear == MAX - 1);
}

// Check if the queue is empty
int isEmpty(Queue *q)
{
    return (q->front == -1 || q->front > q->rear);
}

// Enqueue an element to the queue
void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot enqueue %d\n", value);
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0; // Set front to 0 for the first element
        }
        q->items[++(q->rear)] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

// Dequeue an element from the queue
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue an element.\n");
        return -1;
    }
    else
    {
        int value = q->items[q->front++];
        if (q->front > q->rear)
        {
            // Reset the queue if all elements are dequeued
            q->front = q->rear = -1;
        }
        return value;
    }
}

// Peek the front element of the queue
int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. No element to peek.\n");
        return -1;
    }
    else
    {
        return q->items[q->front];
    }
}

// Display the elements in the queue
void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Main function to test the queue operations
int main()
{
    Queue queue;
    initQueue(&queue);

    int choice, value;

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(&queue, value);
            break;
        case 2:
            value = dequeue(&queue);
            if (value != -1)
            {
                printf("Dequeued value: %d\n", value);
            }
            break;
        case 3:
            value = peek(&queue);
            if (value != -1)
            {
                printf("Front value: %d\n", value);
            }
            break;
        case 4:
            display(&queue);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
