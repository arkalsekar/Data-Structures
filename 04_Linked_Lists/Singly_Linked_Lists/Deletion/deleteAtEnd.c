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

// Delete a Node at End
struct Node* deleteAtEnd (struct Node* head) {
    struct Node* previousNode = head;
    struct Node* currentNode = head->next;

    int i = 0;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        previousNode = previousNode->next;
        i++;
    }

    previousNode->next = NULL;
    free(currentNode);

    // currentNode = NULL;
    // free(currentNode);
    // printf("%d", previousNode->data);
    // printf("%d", currentNode->data);

    // free(head);
    return head;
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

    // traverse(head);
    
    struct Node* newHead = deleteAtEnd(head);
    
    traverse(newHead);

    return 0;
}