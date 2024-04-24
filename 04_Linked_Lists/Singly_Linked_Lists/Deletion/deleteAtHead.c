#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Traversal of Linked List
void traverse(struct Node* head) {
    struct Node* currentNode = head;
    
    while (currentNode != NULL)

    {
        printf("%d \t", currentNode->data);
        currentNode = currentNode->next;
    }
    
}

struct Node* deleteAtHead (struct Node* head) {
    struct Node* newHead = head->next;
    head->next = NULL;
    free(head);
    return newHead;
} 


int main () {
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));
    struct Node* third = (struct Node*) malloc(sizeof(struct Node));
    
    head->data = 11;
    head->next = second;
    
    second->data = 22;
    second->next = third;
    
    third->data = 33;
    third->next = NULL;

    printf("\nLinked List Before Deletion \n");
    traverse(head);
    
    struct Node* newHead = deleteAtHead(head);
    
    printf("\nLinked List After Deletion \n");
    traverse(newHead);
    return 0;
}