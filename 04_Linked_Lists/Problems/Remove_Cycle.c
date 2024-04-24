#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

// Creating the Node
struct Node
{
    int data;
    struct Node *next;
};

// Creating a Function for Traversal of Node
void traverse(struct Node *node)
{
    struct Node *current_node = node;
    while (current_node != NULL)
    {
        printf("%d \t", current_node->data);
        current_node = current_node->next;
    }
}

// Case 3. Insert at End
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *currentNode = head;

    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    newNode->data = data;
    newNode->next = NULL;
    currentNode->next = newNode;

    // printf("%d", currentNode->data);
    return head;
}

// Creates a Cycle
void makeCycle(struct Node *head, int index)
{
    struct Node *current = head;
    struct Node *cycleNode;

    int i = 0;
    while (current->next != NULL)
    {
        if (i == index)
        {
            cycleNode = current;
        }

        current = current->next;
        i++;
    }
    current->next = cycleNode;
}

// Detects a Cycle using Floyd Warshall's Algorithm / Rabbit and Tortosie Algorithm
int detectCycle(struct Node *head)
{
    // Slow Pointer / Tortoise
    struct Node *slow = head;
    // Fast Pointer / Rabbit
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        // Move Slow 1 Step
        slow = slow->next;
        // Move Fast 2 Step
        fast = fast->next->next;

        // Check if they both Meet
        if (fast == slow)
        {
            return 1;
        }
    }
    // Else Return No Cycle Detected
    return 0;
}

// Remove a Cycle
void removeCycle(struct Node *head)
{
    // Detect Cycle
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            // printf("Found a Cycle \n");
            /* Once we Found a Loop; We will reset Fast to Head*/
            fast = head;
            break;
        }
    }

    // Removal of Cycle
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // When the Above Loop will get Over; we Will have the Node where the Loop started;

    while (slow->next != fast)
    {
        slow = slow->next;
    }

    slow->next = NULL;
    printf("Removed Cycle Successfully \n");
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    insertAtEnd(head, 20);
    insertAtEnd(head, 92);
    insertAtEnd(head, 52);
    insertAtEnd(head, 31);

    // Cycle Creation
    makeCycle(head, 3);

    printf("Cycle Detection %d \n", detectCycle(head));
    removeCycle(head);

    traverse(head);
    return 0;
}