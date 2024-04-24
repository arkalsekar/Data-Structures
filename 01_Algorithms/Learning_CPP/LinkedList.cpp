#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    class Node *next;
    Node()
    {
        cout << "Node created Successfully" << endl;
    }
};

class LinkedList
{
public:
    class Node *head;
    LinkedList()
    {
        cout << "Linked List Initialised successfully " << endl;
    }

    // Prints the Data
    void printData()
    {
        class Node *current = head;
        while (current != NULL)
        {
            cout << current->data << "\t";
            current = current->next;
        }
        cout << "\n";
    }

    // Print data of the head;
    void getHead()
    {
        if (head != NULL)
        {
            cout << "Data of Head is " << head->data << endl;
        }
        else
        {
            cout << "Head is not Initialised Properly" << endl;
        }
    }

    // Insert a New Node at the Head
    void insertAtHead(int data)
    {
        class Node *newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Insert a New Node at the End
    void insertAtEnd(int data)
    {
        class Node *current = head;
        class Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
    }

    // Insert a New Node at an Index
    void insertAtIndex(int data, int index)
    {
        class Node *current = head;
        class Node *newNode = new Node;
        newNode->data = data;

        int i = 0;
        while (i < index-1 && current->next != NULL)
        {
            current = current->next;
            i++;
        }
        class Node* temp = current->next;
        current->next = newNode;
        newNode->next = temp;

        if (current == NULL)
        {
            cout << "OverFLow" << endl;
        }
        
        // current->next = newNode;
    }

    // Deletion
    void deleteAtHead() {
        class Node* newHead = head->next;
        free(head);
        head = newHead;
    }

    void deleteAtEnd() {
        class Node* current = head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        class Node* temp = current->next;
        free(temp);
        current->next = NULL;
    }

    // Delte at an Index 
    void deleteAtIndex(int index) {
        class Node* current = head;
        int i = 0;
        while (current != NULL && i < index - 1)
        {
            current = current->next;
            i++;
        }
        class Node* tempNext = current->next;
        class Node* currentNext = current->next->next;
        current->next = currentNext;
        free(tempNext);
    }
};

int main()
{

    class Node *head = new Node;
    class Node *first = new Node;
    class Node *second = new Node;

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = NULL;

    class LinkedList *myList = new LinkedList;
    myList->head = head;

    myList->printData();

    // Methods for the Insertion
    myList->insertAtHead(11);
    myList->insertAtHead(22);
    
    myList->insertAtEnd(4);
    myList->insertAtEnd(5);  
    
    myList->insertAtIndex(200, 3);
    myList->insertAtIndex(243, 2);

    // Deletion
    myList->deleteAtHead();
    myList->deleteAtEnd();
    myList->deleteAtIndex(2);
    
    myList->printData();

    return 0;
}