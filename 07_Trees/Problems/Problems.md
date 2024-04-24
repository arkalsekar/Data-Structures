# Standard Problems on Binary Trees



## Below are some of the Standard Problems based on Trees or Binary Trees (Mostly Solved by Recurions)

1. Size of the Binary Tree ie (No of Nodes)
```C 
int size(root) {
    if (root == NULL) {
        return 0;
    }    
    return size(root->right) + size(root->left) + 1;
}
``` 

2. Height of the Binary Tree
```C 
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Recursive Leap of Faith 
int height(root) {
    if(root != NULL) {
        return (max(height(root->left), height(roo->right)) + 1);
    }
}
```

3. Minimum / Maximum Number from a Tree

4. Level Order Traversal of the Tree
It is Implemented using a Queue

5. View of a Tree 
Similar to Level Order Traversal. Print on the Left Most Element. 

6. Check if the Given Tree is a BST or Not

7. Search in a BST (Iteratively and Recursively)

8. Insertion in a BST

9. Deletion in a BST

10. Invert a Binary Search Tree.

## Resources
