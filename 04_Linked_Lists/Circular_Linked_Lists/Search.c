#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Traversal of the Linked List
int search(struct Node* head, int value){
    struct Node* current = head;

    // Checking If Data Exists At the Head
    if (head->data == value) {
        return 1;
    }

    // Checking if Data Exists Between Head and Last Element
	while (current->next != head) {
       
        if (current->data == value)
        {
            return 1;
        }
		current = current->next;
        
	}

    // Checking if Data Exists in Last Element
    if (current->data == value)
    {
        return 1;
    }
    
    // Else returning -1
    return -1;
    
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
	int a = search(head, 3);
	printf("%d", a);

    return 0;
}