# Stacks
Stacks are 
* Linear Data Structures
* They Follow LIFO Pattern for insertion and deletion
* Allmost all the Opertions like Insertion and Deletion are Big O (1).

## Basic Operations on a Stack
There are some basic operations that allow us to perform different actions on a stack.

1. Push: Add an element to the top of a stack. Time Complexity Big O(1).
2. Pop: Remove an element from the top of a stack.  Time Complexity Big O(1).
3. IsEmpty: Check if the stack is empty. Time Complexity Big O(1).
4. IsFull: Check if the stack is full. Time Complexity Big O(1).
5. Peek: Get the value of the top element without removing it. Time Complexity Big O (n).

## Applications of a Stack
1. Call Stack used by Compilers of Languages like C / Javascript and etc.
2. Parenthesis Matching
3. Infix to Postfix

## Implementation of a Stack
1. Implementation of a Stack using Array.
``` C
struct Stack {
    int capacity;
    int top index;
    int *arr;
}
```

2. Implementation of a Stack using Linked List.
``` C
struct Node {
    int data;
    struct Node* next;
}

struct Stack {
    struct Node* top;
}
```

## Resources
1. https://www.programiz.com/dsa/stack
2. CodeWithHarry YT Channel