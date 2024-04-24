#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Creating a Function for Traversal of Node
void traverse(struct Node *node)
{
    struct Node *current_node = node;
    while (current_node != NULL)
    {
        printf("%d \t", current_node->data);
        current_node = current_node->next;
    }
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *currentNode = head;

    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    newNode->data = data;
    newNode->next = NULL;
    currentNode->next = newNode;

    // printf("%d", currentNode->data);
    return head;
}

struct Node *reverse(struct Node *head)
{
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *tempNext;

    while (current != NULL)
    {
        tempNext = current->next;
        current->next = prev;
        prev = current;
        current = tempNext;
    }

    return prev;
}

int isPalindrome(struct Node *head)
{
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow = reverse(slow->next);
    fast = head;

    while (slow->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;

        if (fast->data != slow->data)
        {
            return 0;
        }
        
    }

    return 1;
}

void main()
{
    printf("Checking Whether it is a Palindrome \n");
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = NULL;

    insertAtEnd(head, 3);
    // insertAtEnd(head, 3);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);

    if (isPalindrome(head))
    {
        printf("The Given Linked List is a Palindrome \n");
    }
    else {
        printf("The Given Linked List is not a Palindrome \n");
    }
    
    // traverse(head);
}