#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversal of the Linked List
void traversal(struct Node *head)
{
    struct Node *current = head;
    do
    {
        printf("%d \t", current->data);
        current = current->next;
    } while (current != head);
}

// Deletion at the Beginning
struct Node* deleteAtHead(struct Node* head) { 
    struct Node* newHead = head->next;

    struct Node* current = head->next;
    
    while (current->next != head)
    {
        current = current->next;
    }

    current->next = newHead;
    free(current);
    return newHead;
}

// Deletion at the End
struct Node* deleteAtEnd(struct Node* head) {
    struct Node* previous = head;
    struct Node* current = head->next;
    
    while (current->next != head)
    {
        current = current->next;
        previous = previous->next;
    }

    previous->next = head;
    current->next = NULL;
    free(current);
    // printf("%d", previous->data);
    // printf("%d", current->data);

    return head;
}


// Deletion at the Index
struct Node* deleteAtIndex(struct Node* head, int index) {
    struct Node* previous = head;
    struct Node* current = head->next;
    
    int i = 0;
    while (i < index - 1)
    {
        current = current->next;
        previous = previous->next;
        i++;
    }

    struct Node* temp = current->next;
    previous->next = temp;

    free(current);

    printf("Insertion at the Index was Succesfull");
    // printf("%d", previous->data);
    // printf("%d", current->data);

    return head;
}

int main()
{
    // Structure Node
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = first;

    first->data = 22;
    first->next = second;

    second->data = 33;
    second->next = third;

    third->data = 44;
    third->next = fourth;

    fourth->data = 55;
    fourth->next = head;

    // Traversal Before the Deletion
    // traversal(head);

    // Deletion at the beginning
    // struct Node* newHead = deleteAtHead(head);
    
    // Deletion at the End
    // struct Node* newHead = deleteAtEnd(head);

    // Deletion at a Given Index
    struct Node* newHead = deleteAtIndex(head, 2);
    
    // Traversal After the Deletion
    traversal(newHead);

    return 0;
}