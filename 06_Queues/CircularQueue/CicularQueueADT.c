#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Queue {
    int capacity;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *q) {
    return 1;
}

int isEmpty(struct Queue *q) {
    return 0;
}

void enqueue(struct Queue* q, int data) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = data;
    printf("Enqueued : %d \n", data);
}

void traverse(struct Queue * q) {
    for (int i = (q->front + 1); i <= q->rear; i++)
    {
        printf("Element at %d is %d \n", i, q->arr[i]);
    }  
}

int dequeue(struct Queue * q) {
    q->front = (q->front + 1) % q->capacity;
    int val = q->arr[q->front];
    printf("Dequeued : %d \n", val);
}

void main () {
    struct Queue * q = (struct Queue*) malloc(sizeof(struct Queue));
    q->capacity = 5;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *) malloc(q->capacity * sizeof(int));
    

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    enqueue(q, 1);
    enqueue(q, 1);
    enqueue(q, 1);
    printf("Q Front is %d \n", q->front);
    printf("Q Front is %d \n", q->rear);
    // traverse(q);
}