#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct Node
{
    char* data;
    struct Node* next;
    struct Node* prev;
};

void traversal(struct Node* head) {
    struct Node* current = head;
    while (current != NULL)
    {
        printf("%s \n", current->data);
        current = current->next;
    } 
}

// Get Values from teh Cache
struct Node* get(struct Node* head, char data[]) {
    // Get the Index of the Data
    struct Node* current = head;
    struct Node* dataNode = (struct Node*) malloc(sizeof(struct Node));

    dataNode->prev = NULL;
    dataNode->next = head;
       
    while (current != NULL)
    {
        if (current->data == data)
        {
            // Checking if the Required Element is the Head
            if (current == head)
            {
                // printf("It is a head Peice \n");
                return head;
            }

            // Checking if the Required Element is the Last Element
            else if (current->next == NULL) {
                // This was an Edge Case
                current->prev->next = NULL;
                
                current->prev = NULL;
                current->next = head;
                return current;
                // printf("Its an End Piece \n");
            }

            // printf("Previous Node is %d \n", current->prev->data);
            // printf("Next Node is %d \n", current->next->data);
            // printf("Got the data %s \n", data);
            current->prev->next = current->next;
            current->next->prev = current->prev;
            // current->next = NULL;
            // current->prev = NULL;
            // tempNode->next = current->next;
            // current->prev = tempNode; 
            // current->prev = NULL;
            // current->next= NULL;
            // free(tempNode);
            dataNode->data = data;
            free(current);
            return dataNode;
        }

        current = current->next;
        
    }

    return head;

}


// Set Values from teh Cache
struct Node* set(struct Node* head, char data[]) {
    struct Node* current = head;
    
    // Creating a New Node at the Head
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    // Removing a Node from the Last to maintain the Capacity
    while (current->next != NULL)
    {
        current = current->next;
    }
    
    current->prev->next = NULL;
    free(current);

    return newNode;

}


int main () {
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* first = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));
    struct Node* third = (struct Node*) malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*) malloc(sizeof(struct Node));
    
    head->data = "Javascript"; 
    head->prev = NULL;
    head->next = first;

    first->data = "C";
    first->prev = head;
    first->next = second;
    
    second->data = "CPP";
    second->prev = first;
    second->next = third;

    third->data = "PHP";
    third->prev = second;
    third->next = fourth;
    
    fourth->data = "Python";
    fourth->prev = third;
    fourth->next = NULL;

    // struct Node* newHead1 = get(head, "Python");
    // struct Node* newHead2 = get(newHead1, "C");

    // struct Node* newHead1 = set(head, "Python");   
    // struct Node* newHead2 = set(newHead1, "New Node");     
    
    traversal(head);

    return 0;
}