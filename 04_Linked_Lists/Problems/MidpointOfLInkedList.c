#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node * reverseLinkedList(struct Node* head) {
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* tempNext;

    while (current != NULL)
    {   
        tempNext = current->next;
        current->next = prev;
        prev = current;
        current = tempNext;
    }
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

int midPoint(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
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

    // struct Node* newHead = reverseLinkedList(head);
    // traversal(newHead);   
    printf("Mid Element of the List is %d \n", midPoint(head));
    return 0;
}