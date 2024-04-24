// Parenthesis Matching Problems
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

struct Stack
{
    int capacity;
    int top;
    char *arr;
};

// Checks if the Stack is Empty
bool isEmpty(struct Stack *s)
{
    if (s->top <= -1)
    {
        return true;
    }
    return false;
}

// Checks if the Stack is Full
bool isFull(struct Stack *s)
{
    if (s->top >= s->capacity - 1)
    {
        return true;
    }
    return false;
}

// Pushes new Elements into the Stack
int push(struct Stack *s, char data)
{
    // Checks if the Stack is not Full
    if (!isFull(s))
    {
        s->top = s->top + 1;
        s->arr[s->top] = data;
        return 1;
    }

    printf("StackOverFlow \n");
    return -1;
}

void pop(struct Stack *s)
{
    // Checks if the Stack is not Empty
    if (!isEmpty(s))
    {
        char value = s->arr[s->top];
        // s->arr[s->top] = 'A';
        s->top = s->top - 1;
    }
    // return -1;
}

bool singleParenthesisMatch(char *exp)
{
    // Creating a Dynamic Stack
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->capacity = sizeof(exp) / sizeof(char);
    s->top = -1;
    s->arr = (char *)malloc(s->capacity * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(s))
            {
                return false;
            }
            pop(s);
        }
    }

    if (isEmpty(s))
    {
        return true;
    }
    return false;
}

void displayStack(struct Stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%c \t", s->arr[i]);
    }
}

int main()
{
    char exp[] = "((((((( () () () )))))))";

    if (singleParenthesisMatch(exp))
    {
        printf("It is a Valid Expression \n");
    }
    else
    {
        printf("It is not a Valid Expression \n");
    }

    // displayStack(s);
    return 0;
}