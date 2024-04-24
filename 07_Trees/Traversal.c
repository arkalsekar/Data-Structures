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

// PreOrder Traversal 
void preOrder(struct Node* root) {
    if (root != NULL)
    {
        printf("%d \t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
} 

// PostOrder Traversal 
void postOrder(struct Node* root) {
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d \t", root->data);
    }    
}

// Inorder Traversal
void inOrder(struct Node* root) {
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d \t", root->data);
        inOrder(root->right);
    }
}



int main () {
    // Creating the Head Node
    struct Node* root = createNode(23);
    struct Node* first = createNode(12);
    struct Node* second = createNode(52);

    // Linking the Nodes
    root->left = first; 
    root->right = second;

    printf("Below is the PreOrder Traversal \n");
    preOrder(root);
        
    printf("\nBelow is the PostOrder Traversal \n");
    postOrder(root);
        
    printf("\nBelow is the inOrder Traversal \n");
    inOrder(root);

    return 0;
}