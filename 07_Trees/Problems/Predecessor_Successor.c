#include <stdio.h>
#include <stdlib.h>

// Creating a New Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function for Initializing new Node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// inorder traversal
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Search in a BST
int searchInBST(struct Node *root, int data)
{
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

struct Node *findPre(struct Node *root, int key)
{
    struct Node* current;
    if (root == NULL)
    {
        return NULL;
    }
    
    if (key == root->data)  
    {
        if (root->left != NULL)
        {
            current = root->left;
        }
        else {
            current = root;
        }

        if (root->left->right != NULL)
        {
            while (current->right != NULL)
            {
                current = current->right;
            }
            return current;
        }
        return current;
    }
    if (key < root->data)
    {
        return findPre(root->left, key);
    }

    if (key > root->data)
    {
        return findPre(root->right, key);
    }
}

// Find Predecessor
struct Node *findPredecessor(struct Node *root, int key, struct Node *pre, struct Node *suc)
{
    if (root != NULL)
    {
        struct Node *predecessor = NULL;
        if (key <= root->data)
        {
            struct Node *current;

            current = current->left;

            current = root->left;
            while (current->right != NULL)
            {
                current = current->right;
            }

            if (current != NULL)
            {
                return current;
            }
            else
            {
                return root;
            }
        }

        else if (key > root->data)
        {
            pre = root;
            findPredecessor(root->left, key, pre, suc);
            // return predecessor;
        }
        else
        {
            suc = root;
            findPredecessor(root->right, key, pre, suc);
            // return predecessor;
        }
    }
    return root;
}

int main()
{

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
    inOrder(root);
    printf("\n");

    int key = 30;
    struct Node *result = findPre(root, key);
    printf("Predecessor for %d is %d \n", key, result->data);
    return 0;
}