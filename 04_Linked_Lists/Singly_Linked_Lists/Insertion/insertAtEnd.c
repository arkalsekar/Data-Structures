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
	struct Node* newHead = insertAtEnd(head, 500);
		
	traverse(newHead);
	return 0;	
}