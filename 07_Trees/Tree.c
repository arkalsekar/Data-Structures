#include <all.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Left Traversal
void printLeftSkewTree(struct Node *head)
{
    struct Node *current = head;
    while (current->left != NULL)
    {
        printf("%d \n", head->data);
        current = current->left;
    }
}

// Right Traversal
void printRightSkewTree(struct Node *head)
{
    struct Node *current = head;
    while (current->right != NULL)
    {
        printf("%d \n", head->data);
        current = current->right;
    }
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

// Post Order Traversal
void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        preOrder(root->left);
        preOrder(root->right);
        printf("%d \t", root->data);
    }
}

// In Order Traversal
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        preOrder(root->left);
        printf("%d \t", root->data);
        preOrder(root->right);
    }
}

// Level Order Traversal

// Searching in a Binary Search Tree
struct Node* search(struct Node* head, int data) {
	struct Node* current = head;
	if (data == current->data) {
		return current; 
	}
	else if (data < current->data) {
		return search(current->left, data);
	}
	else if (data > current->data) {
		return search(current->right, data);
	}
	
	else {
		return NULL;
	}

}



int main()
{
	printf("Hello World  \n");
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));

    struct Node *first = createNode(20);
    struct Node *second = createNode(30);

    head->data = 10;
    head->right = second;
    head->left = first;
	
		
	// struct Node* searchResult = search(head, 20);
	printf("%s \n", head->left);
	printf("%s \n", head->right);
	printf("%s \n", first->right);
	printf("%s \n", first->right);
	
    // printf("\nBelow is the Preorder Traversal of the given Tree ! \n");
    // preOrder(head);

    // printf("\nBelow is the PostOrder Traversal of the given Tree ! \n");
    // postOrder(head);

    // printf("\nBelow is the InOrder Traversal of the given Tree ! \n");
    // inOrder(head);
		
	return 0;
}