#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node * reverseKNodes(struct Node* head, int k) {
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* tempNext;

	int i = 1;
    while (current != NULL)
    {   
        tempNext = current->next;
        current->next = prev;
        prev = current;
        current = tempNext;
		i++;
		if (i == k)
		{
			break;
		}
    }
	struct Node* newHead = reverseKNodes(current, k);
    prev->next = newHead;
	return prev;
}

void traversal(struct Node* head) {
    struct Node* current = head;
    while (current != NULL)
    {
        printf("%d \n", current->data);
        current = current->next;
    }
    
}

int main () {
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* first = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));
    struct Node* third = (struct Node*) malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*) malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node*) malloc(sizeof(struct Node));
    
    head->data = 1;
    head->next = first;
    
    first->data = 2;
    first->next = second;
    
    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = fourth;
    
	fourth->data = 5;
    fourth->next = fifth;
    
	fifth->data = 6;
    fifth->next = NULL;

    // struct Node* newHead = reverseKNodes(head, 2);
    traversal(head);   
    return 0;
}