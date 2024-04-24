#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

// Creating the Node
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

// Case 3. Insert at End
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

// Given Node needs tobe Deleted
int deleteNodeWithoutHead(struct Node* node) {
    struct Node* prev = node;
    struct Node* current = node->next;
    struct Node* currentNext = node->next->next;

    if (current == NULL)
    {
        printf("Invalid Node for Deletion \n");
        return -1;
    }
    
    prev->data = current->data;
    prev->next = currentNext;
    current->next = NULL;
    free(current);
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    insertAtEnd(head, 20);
    insertAtEnd(head, 92);
    insertAtEnd(head, 52);
    insertAtEnd(head, 31);

    printf("Traversal Before Deletion \n");
    traverse(head);
    
    deleteNodeWithoutHead(third);

    printf("\nTraversal After Deletion \n");
    traverse(head);
    
    return 0;
}