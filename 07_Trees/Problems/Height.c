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

// inorder traversla 
void inOrder(struct Node* root) {
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int searchInBST(struct Node* root, int data) {
    if (root != NULL)
    {
        if (root->data == data)
        {
            return 1;
        }
        else if (data < root->data)
        {
            searchInBST(root->left, data);
        }
        else if (data > root->data)
        {
            searchInBST(root->right, data);
        }
    }
    return -1;
}

int max(int a, int b) {
    if (a > b)
    {
        return a;
    }
    return b;    
}

int height(struct Node* root) {
    if (root != NULL)
    {
        return (max(height(root->left), height(root->right))  + 1);
    }
    
}


int main () {
    // Creating the Head Node
    
    struct Node *root = createNode(50);
    struct Node *first = createNode(20);
    struct Node *second = createNode(60);
    struct Node *child1 = createNode(10);
    struct Node *child2 = createNode(30);
    struct Node *child3 = createNode(55);
    struct Node *child4 = createNode(70);

    root->left = first;
    root->right = second;
    
    first->left = child1;
    first->right = child2;

    child1->left = child3;
    child1->right = child4;
    
    // Main Code
    // inOrder(root);
   
    printf("Result is : %d \n", max(20, 400));
    printf("Result is : %d \n", max(100, 70));
    printf("Height of the Tree is : %d \n", height(root));     
    return 0;
} 