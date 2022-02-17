#include <iostream>
//#include "queueWithTwoStacks.cpp"
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} tNode;

tNode* head = NULL;
tNode* rear = NULL;
tNode* temp;

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

int isEmpty() {
    return (head == NULL) && (rear == NULL);
}

void enqueueToEnd(int val) {
    temp = (tNode*)malloc(sizeof(tNode));
    rear->next = temp;
    temp->data = val;
    temp->next = NULL;
    rear = temp;
}

void popFrontElement() {
    if(!isEmpty()) {
        int frontElem = dequeue();
        cout << "The first elem is: " << frontElem << endl;
    }
    else
        cout << "-1" << endl;
}

void printSizeOfQueue() {
    int countElem = 0;
    temp = head;
    while(temp) {
        countElem++;
        temp = temp->next;
    }
    cout << "The queue has " << countElem << " elementes" << endl;
}

void printFrontElem() {
    if(!isEmpty()) {
        int frontElem = head->data;
        cout << "Front elem: " << frontElem << endl;
    }
    else
        cout << "-1" << endl;
}

void printLastElem() {
    if(!isEmpty()) {
        int lastElem = rear->data;
        cout << "Last elem: " << lastElem << endl;
    }
    else
        cout << "-1" << endl;
}

int countNodesQueue() {
    int counter = 0;
    temp = head;
    while(temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

void enqueueVariousElem() {
    enqueue(6);
    enqueue(2);
    enqueue(4);
    enqueue(3);
    enqueue(6);
    enqueue(2);
    enqueue(4);
    enqueue(6);
    enqueue(2);
    enqueue(4);
    enqueue(7);
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

    enqueueVariousElem();
    display();
    reverseQueue();
    display();
}

void question_4() {
    enqueueVariousElem();
    display();
    cout << "The element dequeued is " << dequeue() << endl;
    display();
}

void question_6() {
    enqueueVariousElem();
    display();
    enqueueToEnd(8);
    display();
    popFrontElement();
    display();
    printSizeOfQueue();
    printFrontElem();
    printLastElem();
}

void fillArray(int* arr, int arrSize, int elem) {
    for(int i = 0; i < arrSize; i++)
        arr[i] = elem;
}

int isElemInArray(int* arr, int sizeArr, int elem) {
    for (int i = 0; i < sizeArr; i++)
    {
        if(arr[i] == elem)
            return true;
    }
    return false;
}

void printSolution(int* freqElem, int* elemDisposed, int cantElem) {
    int i = 0;
    while(elemDisposed[i] != -1 && i < cantElem) {
        cout << "Freq. of " << elemDisposed[i] << " is " << freqElem[i] << endl;
        i++;
    }
}

void findFrequencyElements() {
    int cantElem = countNodesQueue();
    int freqElem[cantElem];
    int elemDisposed[cantElem];
    int i = 0;
    tNode* curr;

    curr = head;
    fillArray(elemDisposed, cantElem, -1);

    while(curr != NULL) {
        temp = curr;
        int dataToFind = temp->data;
        if(!isElemInArray(elemDisposed, cantElem, dataToFind)) {
            elemDisposed[i] = dataToFind;
            freqElem[i] = 0;
            while(temp != NULL) {
                if(dataToFind == temp->data)
                    freqElem[i]++;
                temp = temp->next;
            }
            i++;
        }

        curr = curr->next;
    }

    printSolution(freqElem, elemDisposed, cantElem);
}

void question_7() {
    enqueueVariousElem();
    findFrequencyElements();
}

int main() {

    //question_3();
    //question_4();
    //question_6();
    //question_7();

    return 0;
}
