#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversal of Linked List
void traverse(struct Node *head)
{
    struct Node *currentNode = head;

    while (currentNode != NULL)
    {
        printf("%d \t", currentNode->data);
        currentNode = currentNode->next;
    }
}

// Case 2. Delete a Node At an Index
void deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    };
    
    p->next = q->next;
    q->next = NULL;
    free(q);

}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = fourth;

    fourth->data = 44;
    fourth->next = fifth;

    fifth->data = 55;
    fifth->next = NULL;

    deleteAtIndex(head, 2);
    
    traverse(head);
    return 0;
}