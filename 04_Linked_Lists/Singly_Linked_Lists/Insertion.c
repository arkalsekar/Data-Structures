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
// Case 1. Insertion at Head
struct Node* insertAtHead(struct Node* head, int data) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = head;
	return newNode;
}

// Case 2. Insert at an Index
struct Node* insertAtIndex(struct Node* head, int data, int index) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	// Current Node
	struct Node* currentNode = head;

	int i = 0;
	while (i != index - 1)
	{
		currentNode = currentNode->next;
		i++;
	}
	
	
	newNode->data = data;
	newNode->next = currentNode->next;
	currentNode->next= newNode;
	return head;
}

// Case 3. Insert at End
struct Node* insertAtEnd(struct Node* head, int data) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	struct Node* currentNode = head;

	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}

	newNode->data = data;
	newNode->next = NULL;
	currentNode->next = newNode;

	// printf("%d", currentNode->data);
	return head;
}

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

	// struct Node* newHead = insertAtHead(head, 500);
	// struct Node* newHead = insertAtIndex(head, 500, 1);
	// struct Node* newHead = insertAfter(second, 500);
	// struct Node* newHead = insertAtEnd(head, 500);
		
	traverse(head);
	return 0;	
}