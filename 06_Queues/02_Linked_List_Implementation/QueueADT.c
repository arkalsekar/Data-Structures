#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Queue
{
    struct Node* front;
    struct Node* rear;
};

// isEmpty() 
int isEmpty(struct Queue * q) {
    if (q->front == NULL && q->rear == NULL)
    {
        return 1;
    }
    return 0;
}

// Enqueue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* oldFront = q->front; 
    newNode->data = data;
    newNode->next = q->front;
    q->front = newNode;    
    q->rear = oldFront;
}

// Queue Traversal aka Linked List Traversal
void traverse(struct Node* head) {
    struct Node* current = head;
    while (current != NULL)
    {
        printf("%d \n", current->data);
        current = current->next;
    }    
}

// Dequeue Opertion 
int dequeue(struct Queue* q) {
    if (!isEmpty(q))
    {
        struct Node* current = q->front;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        struct Node* temp = current->next;
        int tempVal = temp->data;
        current->next = NULL;
        q->rear = current;
        free(temp);
        return tempVal;
    }
    
    return -1;
    
}

int main () {
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* first = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));
    
    head->data = 11;
    head->next = first;
    
    first->data = 22;
    first->next = second;
    
    second->data = 33;
    second->next = NULL;

    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    
    traverse(q->front);
    
    // printf("%d",dequeue(q));
    // printf("%d",dequeue(q));

    return 0;
}