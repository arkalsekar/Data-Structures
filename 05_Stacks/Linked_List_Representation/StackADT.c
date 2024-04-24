#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
    int capacity;
};

// isEmpty Implementation
int isEmpty(struct Stack *s)
{
    if (s->top == NULL)
    {
        return 1;
    }

    return 0;
}

// Creating the Push Operation
void push(struct Stack *s, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *currentHead = s->top;

    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

// Printing the Stack
void printStack(struct Stack *s)
{
    if (!isEmpty(s))
    {
        struct Node *currentNode = s->top;

        while (currentNode != NULL)
        {
            printf("Element : %d \n", currentNode->data);
            currentNode = currentNode->next;
        }
    }
    else
    {
        printf("Stack is Already Empty \n");
    }
}

// Popping Elements from the Stack
int pop(struct Stack *s)
{
    if (!isEmpty(s))
    {
        struct Node *currentHead = s->top;
        struct Node *newHead = s->top->next;

        s->top = newHead;
        int value = currentHead->data;
        free(currentHead);
        return value;
    }

    else
    {
        printf("Nothing to Pop. Stack is Already Empty \n");
        return -1;
    }
}

int peek(struct Stack* s, int index) {
    struct Node* currentNode = s->top;
    
    int i = 0;
    while (i <= index -1  && currentNode != NULL)
    {
        currentNode = currentNode->next;
        i++;
    }
    
    if (currentNode != NULL)
    {
        return currentNode->data;
    }
    else {
        return -1;
    }
}

// stackTop
int stackTop(struct Stack* s) {
    if (!isEmpty(s))
    {
        return s->top->data;
    }
    return -1;
}

// stackBottom 
int stackBottom(struct Stack* s) {
    struct Node* currentNode = s->top;
    
    if (!isEmpty(s))
    {
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        return currentNode->data;
    }
    
    return -1;
}

int main()
{
    // Create a Linked List
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = first;

    first->data = 22;
    first->next = second;

    second->data = 33;
    second->next = NULL;

    // Creating the Stack using Linked List
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->capacity = 20;
    s->top = head;

    // Pushing Elements
    push(s, 54);
    push(s, 112);
    push(s, 52);

    // Popping Elements from the Stacks
    // printf("Popped ELement %d from the Stack \n", pop(s));
    // printf("Popped ELement %d from the Stack \n", pop(s));

    // Prints the Whole Stack
    printStack(s);

    // Peeks A Stack
    printf("ELement at index 2 is %d \n", peek(s, 4));
    
    // Returns the Top Most Element of the Stack
    printf("ELement Top is %d \n", stackTop(s));
    
    // Returns the Bottom Most Element of the Stack
    printf("ELement Bottom is %d \n", stackBottom(s));
    
    return 0;
}