#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

struct Queue
{
    int capacity;
    int rear;  // deletionEnd
    int front; // insetionEnd
    int *arr;
};

// isFull
bool isFull(struct Queue *q)
{
    if (q->rear >= q->capacity - 1)
    {
        return true;
    }
    return false;
}

bool isEmpty(struct Queue *q)
{
    if (q->rear == q->front)
    {
        return true;
    }
    return false;
}

void enqueue(struct Queue *q, int data)
{
    if (!isFull(q))
    {
        q->rear = q->rear + 1;
        q->arr[q->rear] = data;
        printf("Enqueued : %d \n", data);
    }
    else {
        printf("Queue OverFlow \n");
    }
}

int dequeue(struct Queue *q)
{
    if (!isEmpty(q))
    {
        q->front = q->front + 1;
        int val = q->arr[q->front];
        printf("Dequeued : %d \n", val);
        return val;
    }
    else {
        printf("Queue UnderFlow \n");
        return -1;
    }
}

void traverse(struct Queue *q)
{
    if (q->front == q->rear)
    {
        printf("Nothing to Print!! Queue is Empty \n");
    }
    else
    {
        printf("\nElements of the Queue are \n");
        for (int i = q->front + 1; i <= q->rear; i++)
        {
            printf("Element : %d \n", q->arr[i]);
        }
    }
}
void main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->capacity = 5;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->capacity * sizeof(int));

    // Enqueue Operation
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Dequeue Opertion
    dequeue(q);
    dequeue(q);

    traverse(q);
}