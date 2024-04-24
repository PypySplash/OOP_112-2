#include <iostream>
using namespace std;

const int CAPACITY = 10;



class Stack {
private:
    int* stackArray;    // Pointer to array of stack elements
    int top;            // Index of the top element in the stack
    // int capacity;       // Maximum number of elements stack can hold

public:
    // Constructor to initialize the stack with a default size if not specified
    Stack() {  // Default size is 10
        stackArray = new int[CAPACITY];  // Allocate memory for the stack
        // capacity = size;
        top = -1;  // Initialize top to -1 indicating the stack is empty
    }

    // Destructor to free memory allocated to the stack
    ~Stack() {
        delete[] stackArray;
    }

    // Function to add an element x to the stack
    void push(int x) {
        if (top == CAPACITY - 1) {
            cout << "Error: Stack Overflow" << endl;
            return;
        }
        stackArray[++top] = x;  // Place the element on top of the stack
    }

    // Function to remove the top element from the stack
    int pop() {
        if (top == -1) {
            cout << "Error: Stack is empty" << endl;
            return -1;  // Return -1 to indicate error
        }
        return stackArray[top--];  // Remove the top element from the stack
    }
};

int main() {
    Stack myStack;  // Default stack initialized with capacity 10
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);
    cout << myStack.pop() << endl;  // Output: 15
    cout << myStack.pop() << endl;  // Output: 10
    cout << myStack.pop() << endl;  // Output: 5
    myStack.pop();  // Outputs: "Error: Stack is empty" and returns -1
    return 0;
}