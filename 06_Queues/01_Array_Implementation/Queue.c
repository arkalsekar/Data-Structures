#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

// Methods in Queue ADT
// enqueue()
// dequeue()
// isEmpty()
// isFull()
// firstVal()
// lastVal()
// peek()

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
    if (q->front >= q->capacity - 1)
    {
        return true;
    }
    return false;
}

// isEmpty
bool isEmpty(struct Queue *q)
{
    if (q->front == q->rear)
    {
        return true;
    }
    return false;
}

// enqueue
void enqueue(struct Queue *q, int data)
{
    if (!isFull(q))
    {
        q->front = q->front + 1;
        q->arr[q->front] = data;
    }
}

// Dequeue
int dequeue(struct Queue *q)
{
    if (!isEmpty(q))
    {
        q->rear = q->rear + 1;
        int val = q->arr[q->rear];
        // printf("%d", q->rear);
        return val;
    }
    else
    {
        printf("Stack Already Empty !! Nothing to remove.");
        return -1;
    }
}

// Traverse the Queue
void traverse(struct Queue *q)
{
    if (q->rear == -1)
    {
        for (int i = 0; i <= q->front; i++)
        {
            printf("%d \n", q->arr[i]);
        }
    }
    else
    {
        for (int i = q->rear + 1; i <= q->front; i++)
        {
            printf("%d \n", q->arr[i]);
        }
    }
}

int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->capacity = 20;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->capacity * sizeof(int));

    // Enqueue
    enqueue(q, 11);
    enqueue(q, 22);
    enqueue(q, 33);
    enqueue(q, 44);
    enqueue(q, 55);
    enqueue(q, 66);
    enqueue(q, 77);
    enqueue(q, 88);

    // Deque Opertion
    printf("Popped Element from the Queue %d \n", dequeue(q));
    printf("Popped Element from the Queue %d \n", dequeue(q));
    // printf("Popped Element from the Queue %d \n", dequeue(q));

    // Traversal of a Queue
    traverse(q);

    return 0;
}