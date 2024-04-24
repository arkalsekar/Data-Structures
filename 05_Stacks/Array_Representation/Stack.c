#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Stack {
    int capacity;
    int top;
    int *arr;
};

void displayStack(struct Stack * s) {
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d \t", s->arr[i]);
    }
    
}

// Checks if the Stack is Empty
bool isEmpty(struct Stack* s) {
    if (s->top <= -1)
    {
        return true;
    }
    return false;
}

// Checks if the Stack is Full
bool isFull(struct Stack* s) {
    if (s->top >= s->capacity -1)
    {
        return true;
    }
    return false;
}

// Pushes new Elements into the Stack
int push(struct Stack* s, int data) {
    // Checks if the Stack is not Full
    if (!isFull(s))
    {
        s->top = s->top + 1;
        s->arr[s->top] = data;
        return 1;
    }
    printf("StackOverFlow");
    return -1;
}

int pop(struct Stack* s) {
    // Checks if the Stack is not Empty
    if (!isEmpty(s))
    {
        int value = s->arr[s->top];
        s->arr[s->top] = 0;
        s->top--;
        return value;
    }
    return -1;
}

int main () {
    // Creating a Dynamic Stack
    struct Stack* s = (struct Stack*) malloc(sizeof(struct Stack));
    s->capacity = 10;
    s->top = -1;

    // Allocating Dynamic Size to Stack
    s->arr = (int *) calloc(s->capacity, sizeof(int));
    
    push(s, 11);
    push(s, 22);
    push(s, 33);
    push(s, 55);
    push(s, 3023);
    push(s, 22);
    push(s, 33);
    push(s, 55);
    push(s, 3023);

    // printf("Popped the %d Value \n", pop(s));
    // printf("Popped the %d Value \n", pop(s));
    // printf("Popped the %d Value \n", pop(s));

    printf("Below is our Stack \n");
    displayStack(s);
   

    return 0;
}