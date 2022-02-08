#include <iostream>

using namespace std;

// Global int stack implementation
int arr[5];
int n = 5;
int top = -1;

void push(int data) {
    if(top >= n)
        cout << "Stack is full" << endl;
    else{
        top++;
        arr[top] = data;
    }
}

void pop() {
    if(top == -1)
        cout << "Stack is empty" << endl;
    else {
        cout << "Deleted element from the stack is: " << arr[top] << endl;
        top--;
    }
}

void peak() {
    if(top == -1)
        cout << "Stack is empty" << endl;
    else {
        cout << "The first element from the stack is: " << arr[top] << endl;
    }
}

void display() {
    if(top == -1)
        cout << "Stack is empty" << endl;
    else {
        cout << "Stack elements are the follow: --- ";
        for(int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}

int isEmpty() {
    return top == -1;
}

int main2() {
    
    display();
    push(1);
    push(2);
    push(9);
    push(9);
    push(9);
    push(8);
    push(7);
    display();
    pop();
    pop();
    pop();
    peak();
    
    return 0;
}

