#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Creating the Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data =data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main () {
    // Creating the Head Node
    struct Node* root = createNode(23);
    struct Node* first = createNode(12);
    struct Node* second = createNode(52);

    // Linking the Nodes
    root->left = first; 
    root->right = second;

    printf("Data of Root is : %d \n", root->data);
    printf("Data of First is : %d \n", first->data);
    printf("Data of Second is : %d \n", second->data);
    
    return 0;
}