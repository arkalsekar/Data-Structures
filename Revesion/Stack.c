#include <stdio.h>
#include <stdlib.h>

// Creating a Stack Structure
struct Stack {
    int size;
    int arr[10];
    int capacity;
};

// is Full 
int isFull (struct Stack* s ) {
    if (s->capacity >= s->size)
        return 1;
    return 0;    
}

// is Empty
int isEmpty(struct Stack* s) {
    if (s->capacity = -1){
        return 1;
    }
    return 0;
}

int push(struct Stack* s, int data) {
    if (!isFull(s)) {
        s->capacity = s->capacity + 1;
        s->arr[s->capacity] = data;
        return data;
    }
    printf("Stack OverFlow \n");
    return -1;
}

// Pop
int pop(struct Stack* s) {
    if (isEmpty(s))
    {
    printf("Stack Under Flow \n");
    return -1;
    }
    int data = s->arr[s->capacity];
    s->capacity = s->capacity - 1;
    return data; 
}

// Display Function
void display(struct Stack* s) {
    for (int i = 0; i <= s->capacity; i++)
        printf("%d \t", s->arr[i]);
}


void main () {
    struct Stack* s = (struct Stack *) malloc(sizeof(struct Stack));
    s->size = 10;
    s->capacity= -1;
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);
    display(s);
    printf("The Capacity is %d", s->capacity);
    pop(s);
    pop(s);
    pop(s);
    display(s);
}