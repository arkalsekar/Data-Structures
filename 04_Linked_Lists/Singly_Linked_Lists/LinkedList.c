// A simple C program for
// traversal of a linked list

#include <stdio.h>
#include <stdlib.h>

// Multiple Nodes Come together to form a Linked List
struct Node {
	int data;
	struct Node* next;
};

// This function prints contents of linked list starting from the given node
void printList(struct Node* n)
{
	// Can be done using For Loop as Well and a Do While Loop as Well
	/*
	for (int i = 0; i < n->next; i ++){
		printf("%d \t", n->data);
	}
	*/
	
	while (n != NULL) {
		printf(" %d \t", n->data);
		n = n->next;
	}
}

int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* fourth = NULL;

	// allocate 3 nodes in the heap
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1; // assign data in first node
	head->next = second; // Link first node with second

	second->data = 2; // assign data to second node
	second->next = third;

	third->data = 3; // assign data to third node
	third->next = fourth;
	
	fourth->data = 4; // assign data to third node
	fourth->next = NULL;

	// Function call
	printList(head);

	return 0;
}
