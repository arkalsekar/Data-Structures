#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        class Node* left;
        class Node* right;
        Node(int newData, Node* prev, Node* next) {
            data = newData;
            left = prev;
            right = next;
        }
};

class BST {
    public:
        BST() {
            cout << "Binary Search Tree initialised " << endl;
        }

        void inOrderTraversal(struct Node* root) {
            if (root != NULL)
            {
                inOrderTraversal(root->left);
                cout << root->data << endl;
                inOrderTraversal(root->right);
            }
            
        }
};

int main () {
    Node* child4 = new Node(10, NULL, NULL);
    Node* child3 = new Node(10, NULL, NULL);
    Node* child2 = new Node(10, NULL, NULL);
    Node* child1 = new Node(10, NULL, NULL);
    Node* second = new Node(10, child3, child4);
    Node* first = new Node(10, child1, child2);
    Node* root = new Node(10, first, second);

    class BST myBST;
    myBST.inOrderTraversal(root);

    return 0;
}