#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Traversal of the Linked List
void traversal(struct Node* ptr){
	struct Node* current = ptr;
	while (current != NULL) {
		printf("%d \t", current->data);
		current = current->next;
	}
}

int main () {
	// Structure Node
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    struct Node *first = (struct Node*) malloc(sizeof(struct Node));
    struct Node *second = (struct Node*) malloc(sizeof(struct Node));
    
    (*head).data = 1;
    (*head).next = first;
	
    (*first).data = 2;
    (*first).next = second;
	
    (*second).data = 3;
    (*second).next = NULL;
		
	// Traversal
	traversal(head);
	
    return 0;
}