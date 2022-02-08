#include <iostream>
using namespace std;

int queue[100];
int n = 100;
int front = -1;
int rear = -1;

void Enqueue(int element) {
    if(rear == n-1) {
        cout << "Queue overflow";
    }
    else if(front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = element;
}

void Dequeue() {
    if(front == -1 && rear == -1) {
        cout << "Queue empty";
    }
    else if(front == rear) {
        front = rear = -1;
    }
    else {
        cout << "The deleted element from the queue is: " << queue[front] << endl;
        front++;
    }
}

void Display() {
    if(front == -1)
        cout << "Queue is empty" << endl;
    else {
        cout << "Queue elements are: --- ";
        for(int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }
}

void isEmpty() {
    if(front == -1) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Queue is not empty" << endl;
    }
}

void isFull() {
    if(rear == n-1) {
        cout << "Queue is full" << endl;
    }
    else {
        cout << "Queue is not full" << endl;
    }
}

void Peek() {
    if(front == -1 && rear == -1) {
        cout << "There is no peak element in the queue" << endl;
    } else {
        cout << "Peak element is: " << queue[front];
    }
}

void Bottom() {
    if(front == -1 && rear == -1) {
        cout << "There is no bottom element in the queue" << endl;
    } else {
        cout << "Bottom element is: " << queue[rear];
    }
}

int main() {

    Enqueue(4);
    Enqueue(5);
    Enqueue(8);
    Enqueue(67);
    Display();
    Dequeue();
    Dequeue();
    Peek();
    Bottom();

    return 0;
}