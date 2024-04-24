#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Traversal of the Linked List
void traversalOne(struct Node* head){
    struct Node* current = head;

	while (current->next != head) {
		printf("%d \t", current->data);
		current = current->next;
	}
	printf("%d \t", current->data);    
}

// Traversal of the Linked List
void traversalTwo(struct Node* head){
    struct Node* current = head;
    
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
    traversalOne(head);
	
    // A Newline Character
    printf("\n");
    
    // Effective and Clean Traversal
    traversalTwo(head);
    return 0;
}