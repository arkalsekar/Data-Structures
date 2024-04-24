#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Traversal of the Linked List
int traversal(struct Node* head){
    struct Node* current = head;

	// while (current->next != head) {
	// 	printf("%d \t", current->data);
	// 	current = current->next;
	// }
	// printf("%d \t", current->data);
    do
    {
        printf("%d \t", current->data);
        current = current->next;
    } while (current != head);
    
}

int main () {
	// Structure Node
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    struct Node *first = (struct Node*) malloc(sizeof(struct Node));
    struct Node *second = (struct Node*) malloc(sizeof(struct Node));
    
    head->data = 1;
    head->next = first;
	
    first->data = 2;
    first->next = second;
	
    second->data = 3;
    second->next = head;
		
	// Traversal
	traversal(head);
	
    return 0;
}