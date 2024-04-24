#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

// Creating the Node 
struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
};

// Creating a Function for Traversal of Node
void traverse(struct Node* head) {
	struct Node* current_node = head;

	while (current_node != NULL)
	{
		printf("%d \t", current_node->data);
		current_node = current_node->next;
	}
}


// Creating a Function for Reverse Traversal of Doubly Linked List
void reverseTraversal(struct Node* head) {
	struct Node* current_node = head;

	while (current_node != NULL)
	{
		printf("%d \t", current_node->data);
		current_node = current_node->prev;
	}
}


// Insertion in a Linked List
// Case 1. Insertion at Head
struct Node* insertAtHead(struct Node* head, int data) {
	struct Node* prevHead = head;
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	
    newNode->prev = NULL;
    newNode->data = data;
	newNode->next = head;

    prevHead->prev = newNode;

	return newNode; 
}

// Case 2. Insert at an Index
struct Node* insertAtIndex(struct Node* head, int data, int index) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	
    // Current Node
	struct Node* currentNode = head;

	int i = 0;
	while (i != index - 1)
	{
		currentNode = currentNode->next;
		i++;
	}
	
    newNode->next = currentNode->next;
    newNode->prev = currentNode;

	printf("%d", currentNode->data);
	return head;
}

// Case 3. Insert at End
struct Node* insertAtEnd(struct Node* head, int data) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
    newNode->next = NULL;

    struct Node* currentNode = head;

	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}

    currentNode->next = newNode;
    newNode->prev = currentNode;

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
	
	head->prev = NULL;
	head->data = 1;
	head->next = second;
	
	second->prev = head;
	second->data = 2;
	second->next = third;

	third->prev = second;
	third->data = 3;
	third->next = NULL;
	
    // Normal Traversal of the Doubly Linked List
	// traverse(head);

    // Reverse Traversal of the Doubly Linked list
    // reverseTraversal(third);
	
    // Inserting at the Head
    // struct Node* newHead = insertAtHead(head, 500);
	
    // Insertion at a given Index
    // struct Node* newHead = insertAtIndex(head, 500, 1);

    // Insertion After a Given Index
	// struct Node* newHead = insertAfter(second, 500);
	
    // Insertin at the End
    // struct Node* newHead = insertAtEnd(head, 50000);

	// traverse(newHead);
	return 0;	
}