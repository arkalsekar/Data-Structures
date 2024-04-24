#include <iostream>
using namespace std;

class Stack {
    public:
        int top;
        int capacity;
        int *arr;

        Stack(int top, int capacity) {
            int *arr = (int*) malloc(capacity * sizeof(int));
        }

        // Push in the Stack
        void push(int data) {
            top = top + 1;
            arr[top] = data;
        }

        void printStack() {
            for (int i = 0; i <= top + 1; i++)
            {
                cout << arr[i] << " \t";
            }
            
        }
};

int main () {
    Stack* s = new Stack(-1, 100);
    s->push(1);
    s->push(2);
    s->push(3);

    // s->printStack();
    return 0;
}