#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

// Creating the Node 
struct Node
{
	int data;
	struct Node* next;
};

// Creating a Function for Traversal of Node
void traverse(struct Node* node) {
	struct Node* current_node = node;
	while (current_node != NULL)
	{
		printf("%d \t", current_node->data);
		current_node = current_node->next;
	}
}

// Insertion in a Linked List
// Case 4. Insert at a Given Index
struct Node* insertAfter(struct Node* current, int data) {
	/* 
	It has a Big of (1) 
	*/

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode->data = data;
	newNode->next = current->next;

	current->next = newNode;
	return newNode;
}

int main () {
	struct Node * head = (struct Node*) malloc(sizeof(struct Node));
	struct Node * second = (struct Node*) malloc(sizeof(struct Node));
	struct Node * third = (struct Node*) malloc(sizeof(struct Node));
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;
	
	// traverse(head);
	struct Node* newHead = insertAfter(second, 500);
		
	traverse(head);
	return 0;	
}