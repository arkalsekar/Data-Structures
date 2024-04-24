# Trees Data Structure 
Non Linear Data Structure 

## Terminologies 
* Root : The Root Node
* Node : 
* Edge : 
* Leaf Node : 
* Parent / Child : 
* Ancestors / Decendents : 
* Internal / External Node : 
* 
* 

## Types of Binary Trees 
1. Full / Strict Binary Tree
2. Complete Binary Tree
3. Degenerate Tree 
* Right Skew Tree 
* Left Skew Tree 
4. Binary Search Trees

Properties of the Binary Search Trees : 
* Root Node has Exactly Two Childrens 
* 
* 
* InOrder Traversal of a Binary Search Tree is Sorted. 

## Representation of a Binary Tree
1. Array Representation (Bekar Representation)
2. Linked Representation (Effective Representation)

## Linked Representation Implementation 

``` C
struct Node {
    struct Node* left;
    int data;
    struct Node* right;
} 
```

``` CPP
class Node {
    public: 
        int data;
        class Node* left;
        class Node* right;

        Node(int data) {
            data = data;
            left = NULL;
            right = NULL;
        }
}
```

## Traversal of a Binary Trees
1. PreOrder Traversal of a Binary Tree : 
ROOT | LEFT | RIGHT

2. PostOrder Traversal of a Binary Tree : 
LEFT | RIGHT | ROOT

3. InOrder Traversal of a Binary Tree : 
LEFT | ROOT | RIGHT

4. LevelOrder Traversal of a Binary Tree : 
Level By Level Order

## Search in BST (Iteratively and Recursively) 
1. Recursive Approach 
```C
// Recursive Approach
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
```

2. Iterative Approach 
```C
// Iterative Approach 
int searchInBSTIteratively(struct Node* root, int data) {
    if (root == NULL)
    {
        return -1;
    }
    while (root != NULL)
    {
        if (data == root->data) {
            return 1;
        }
        else if (data < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return -1;   
}
```

## Insertion in a BST 
```C
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
    // printf("Previous is %d \n", prev->data);
    if (data > prev->data)
    {
        prev->right = newNode;
    }
    else {
        prev->left = newNode;
    }
    
}

```

## Deletion in a BST 
```C

```

## Size of a BST 
```C 
// Size of the Tree
int size(struct Node* root) {
    if (root == NULL)
    {
        return 0;
    }
    return size(root->left) + size(root->right) + 1;
}
```

## Height of a BST 
```C 
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
```


## Resources 
1. CodeWithHarry YT Channel
2. 