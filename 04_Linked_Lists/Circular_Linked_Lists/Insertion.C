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

// Insertion at the Beginning
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 
    newNode->data = data;
    newNode->next = head;

    struct Node* current = head->next;
    
    while (current->next != head)
    {
        current = current->next;
    }

    current->next = newNode;
    return newNode;
}


// Insertion at the Last
struct Node* insertAtLast(struct Node* head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 
    newNode->data = data;
    newNode->next = head;

    struct Node* current = head->next;
    
    while (current->next != head)
    {
        current = current->next;
    }

    current->next = newNode;
    return head;
}


// Insertion at the Index
struct Node* insertAtIndex(struct Node* head, int data, int index) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 
    newNode->data = data;
    newNode->next = head;

    struct Node* current = head->next;
    
    int i = 0;
    while (i < index - 2)
    {
        current = current->next;
        i++;
    }

    struct Node* temp = current->next;
    current->next = newNode;
    newNode->next = temp;
    
    printf("Insertion at the Index was Succesfull");
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

    // Traversal Before the Insertion
    // traversal(head);

    // Insertion at the beginning
    // struct Node* newHead = insert(head, 43);
    
    // Insertion at the End
    // struct Node* newHead = insertAtLast(head, 43);

    // Insertion at a Given Index
    struct Node* newHead = insertAtIndex(head, 233, 2);
    
    // Traversal After the Insertion
    traversal(head);

    return 0;
}