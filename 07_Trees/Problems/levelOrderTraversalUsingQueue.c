#include <all.h>
 
 
// Creating a Node
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

// Creating a Queue
struct Queue
{
    int front;
    int rear;
    struct Node * arr;
    int capacity;
};

// Implement a Queue
bool isFull(struct Queue *q)
{
    if (q->front > q->capacity - 1)
    {
        return true;
    }
    return false;
}   

bool isEmpty(struct Queue *q)
{
    if (q->front == q->rear)
    {
        return true;
    }
    return false;
}

void enqueue(struct Queue *q, struct Node data)
{
    if (!isFull(q))
    {
        q->front = q->front + 1;
        q->arr[q->front] = data;
        printf("Enqueued : %d \n", data);
    }
}

struct Node dequeue(struct Queue* q) {
    if (!isEmpty(q))
    {
        struct Node val; 
        val = q->arr[q->rear];
        q->rear = q->rear + 1;    
        printf("Dequeued : %d \n", val.data);
        return val;
    }
}

void traverseQueue(struct Queue* q) {
    for (int i = q->rear; i <= q->front; i++)
    {
        printf("%d \t", q->arr[i]);
    }
}

void levelOrderTraversal(struct Node* root) {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    q->capacity = 50;
    q->arr = (struct Node *) malloc(q->capacity * sizeof(struct Node));

    enqueue(q, *root);

    while (!isEmpty(q))
    {
        struct Node current = dequeue(q);
        printf("%d", current.data);
        
        // if (current.left != NULL)
        // {
        //     enqueue(q, *current.left);
        // }
        // if (current.right != NULL)
        // {
        //     enqueue(q, *current.right);
        // }
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
    // struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    // q->front = -1;
    // q->rear = 0;
    // q->capacity = 50;
    // q->arr = (struct Node *) malloc(q->capacity * sizeof(struct Node));

    levelOrderTraversal(root);

    return 0;
}