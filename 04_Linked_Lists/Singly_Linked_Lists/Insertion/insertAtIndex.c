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

	struct Node* newHead = insertAtIndex(head, 500, 1);
		
	traverse(newHead);
	return 0;	
}