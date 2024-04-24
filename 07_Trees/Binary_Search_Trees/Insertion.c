#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Creating the Node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// inorder traversla
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Inserting in a BST
void insert(struct Node *root, int data)
{
    struct Node *prev = NULL;
    struct Node *current = root;
    struct Node* newNode = createNode(data);

    if (current == NULL)
    {
        return;
    }

    while (current != NULL)
    {
        prev = current;
        if (data == current->data)
        {
            printf("Data Already Exists \n");
            return;
        }

        else if (data < current->data)
        {
            current = current->left;
        }

        else
        {
            current = current->right;
        }
    }
    printf("Previous is %d \n", prev->data);
    if (data > prev->data)
    {
        prev->right = newNode;
    }
    else {
        prev->left = newNode;
    }
    
}

int main()
{
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

    second->left = child3;
    second->right = child4;

    // Main Code
    insert(root, 80);

    inOrder(root);
    return 0;
}