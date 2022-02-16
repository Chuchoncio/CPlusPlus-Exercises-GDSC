#include <iostream>
//#include "queue_operations.cpp"
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} tNode;

tNode* head = NULL;
tNode* rear = NULL;
tNode* temp;

// Question 1 //
void enqueue(int val) {
    if (rear == NULL) {
        rear = (tNode*)malloc(sizeof(tNode));
        rear->next = NULL;
        rear->data = val;
        head = rear;
    } else {
        temp = (tNode*)malloc(sizeof(tNode));
        rear->next = temp;
        temp->data = val;
        temp->next = NULL;
        rear = temp;
    }
}

int dequeue() {
    int retValue;
    temp = head;
    if(head == NULL) {
        cout << "Underflow" << endl;
        retValue = -1;
    }
    else if(temp->next != NULL) {
        temp = temp->next;
        retValue = head->data;
        free(head);
        head = temp;
    }
    else {
        retValue = head->data;
        free(head);
        head = NULL;
        rear = NULL;
    }
    return retValue;
}

void display() {
    temp = head;
    if( (head == NULL) && (rear == NULL) ) {
        cout << "The queue is empty" << endl;
        return ;
    }
    cout << "Queue elements are: " << endl;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
// Question 1 //

int countNodesQueue() {
    int counter = 0;
    temp = head;
    while(temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

void reverseQueue() {
    tNode* current = head,
         * prev = NULL,
         * next = NULL;
    
    while(current != NULL) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    rear = head;
    head = prev;
}

void question_3() {

    enqueue(1);
    enqueue(5);
    enqueue(7);
    enqueue(9);
    display();
    reverseQueue();
    display();
}

void question_4() {
    enqueue(1);
    enqueue(5);
    enqueue(7);
    enqueue(9);
    display();
    cout << "The element dequeued is " << dequeue() << endl;
    display();
}

int main() {

    question_3();
    //question_4();

    return 0;
}
