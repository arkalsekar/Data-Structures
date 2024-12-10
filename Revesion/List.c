#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head) {
    struct Node* currentHead = head;
    while(currentHead != NULL) {
        printf("Data : %d \n", currentHead->data);
        currentHead = currentHead->next;
    }
}

// Insertion At Head 
struct Node* insertionAtHead(struct Node* head, int data) {
    struct Node* newHead = createNode(data);
    newHead->next = head;
    return newHead;
}

// Insertion at last 
int insertionAtLast(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* currentHead = head;
    if (currentHead!= NULL) {
        while (currentHead->next != NULL)
        {
            currentHead= currentHead->next;
        }   
        currentHead->next = newNode;
        return 1;
    }
    return 0;
}

struct Node* deleteAtHead (struct Node* head) {
    struct Node* newHead = head->next;
    free(head);
    return newHead;
}

void deletionAtEnd (struct Node * head) {
    if (head != NULL) {
        struct Node* currentHead = head;
        while (currentHead->next->next != NULL)
        {
            printf("Createi \n");
        }
        
    }
}

int main () {
    struct Node* a = createNode(10);
    struct Node* b = createNode(20);
    struct Node* c = createNode(30);
    struct Node* d = createNode(40);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    // Display 
    printf("Display Before Insertion \n");
    display(a);

    printf("Display After Insertion At End \n");
    insertionAtLast(a, 60);
    display(a);

    printf("Display After Insertion at head \n");
    display(insertionAtHead(a, 50));

    printf("Display After Deletion at head \n");
    display(deleteAtHead(a));



    return 0;
}