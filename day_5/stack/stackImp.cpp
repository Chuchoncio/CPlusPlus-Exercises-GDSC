#include <iostream>
using namespace std;

int stack[7];
int tamStack = 7;
int topStack = -1;

void push(int data) {
    if(topStack >= tamStack)
        cout << "Stack is full" << endl;
    else{
        topStack++;
        stack[topStack] = data;
    }
}

void pop() {
    if(topStack == -1)
        cout << "Stack is empty" << endl;
    else {
        //cout << "Deleted element from the stack is: " << arr[top] << endl;
        stack[topStack] = 0;
        topStack--;
    }
}

int peak() {
    if(topStack == -1){
        cout << "Stack is empty" << endl;
        return -1;
    }
    else {
        return stack[topStack];
    }
}

void display() {
    if(topStack == -1)
        cout << "Stack is empty" << endl;
    else {
        cout << "Stack elements are the follow: --- ";
        for(int i = topStack; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << "\n";
    }
}

int isEmpty() {
    return topStack == -1;
}