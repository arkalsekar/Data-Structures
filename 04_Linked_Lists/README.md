# Linked Lists
Linked Lists are similar to Array but comes with few advantages and disadvantages.

## Pros of a Linked List over an Array
1. Insertion at Head Takes Big O (1)
2. Dynamic Sizing 

## Cons of a Linked List over an Array
1. To get a Value at an Index, You need to iterate through out the List
2. 

## Types of Linked List
1. Singly Linked List
A List with only the next pointer.

2. Doubly Linked List
A Linked List with both next and prev pointers.

3. Circular Linked List
Last Node Points towards the head instead of NULL.

4. Doubly Circular Linked List
A Linked List with both next and prev pointers and last node pointing towards the head node.

## Sample Node
```C
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}
```

```Python
class Node:
    def __init__(self, data, next, prev):
        self.data = data
        self.next = next
        self.prev = prev

class LinkedList:
    def __init__(self, head):
        self.head = Node(1, first, None)
        self.first = Node(2, second, head)
        self.second = Node(2, None, first)
```


## Operations on a Linked List
1. Creation of a Linked List using Structures / Classes:
A Linked List can be created using many ways by using Structures / Classes. A Linked List is made up of Multiple Nodes. A Single Node can be created as follows.

``` C 

``` 

2. Traversal of a Linked List
Below are the Steps tobe followed for Traversing a Linked List.
* This is Step 1
* 
* 

3. Insertion in a Linked List


4. Deletion in a Linked List


## Standard Problems
1. Reverse a Linked List
2. Traversal of a Linked List
3. LRU Cache Implementation using Doubly Linked List
4. Browser History Implementation using Doubly Linked List
5. Reverse K Nodes 
6. Detect and Remove Loop / Cycle from a Linked List (Floyd Warshall's Algorithm)

## Resources
