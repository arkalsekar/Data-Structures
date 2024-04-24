#include <all.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

// Create a New Node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder Traversal
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d \t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// level Order Traversal of the Tree // Very Naive Approach.
int levelOrder(struct Node *root)
{

    if (root->left != NULL || root->right != NULL)
    {
        printf("%d ", root->data);
        printf("%d ", root->left->data);
        printf("%d ", root->right->data);
        levelOrder(root->left);
        levelOrder(root->right);
    }
}

int main()
{

    struct Node *root = createNode(10);
    struct Node *first = createNode(20);
    struct Node *second = createNode(30);
    struct Node *child1 = createNode(40);
    struct Node *child2 = createNode(50);
    struct Node *child3 = createNode(60);
    struct Node *child4 = createNode(70);

    root->left = first;
    root->right = second;

    first->left = child1;
    first->right = child2;

    second->left = child3;
    second->right = child4;

    // Main Code Goes Here
    levelOrder(root);
    return 0;
}