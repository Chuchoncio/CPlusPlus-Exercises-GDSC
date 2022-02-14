#include <iostream>
using namespace std;

int stackDouble[100];
int tamStack1 = 50;
int tamStack2 = 100;
int topStack1 = -1;
int topStack2 = 49;

void push1(int data) {
    if(topStack1 >= tamStack1)
        cout << "Stack is full" << endl;
    else{
        topStack1++;
        stackDouble[topStack1] = data;
    }
}

int pop1() {
    if(topStack1 == -1)
        return -1;
    else {
        int prevElem = stackDouble[topStack1];
        stackDouble[topStack1] = 0;
        topStack1--;
        return prevElem;
    }
}

void push2(int data) {
    if(topStack2 >= tamStack2)
        cout << "Stack is full" << endl;
    else{
        topStack2++;
        stackDouble[topStack2] = data;
    }
}

int pop2() {
    if(topStack2 == 49)
        return -1;
    else {
        int prevElem = stackDouble[topStack2];
        stackDouble[topStack2] = 0;
        topStack2--;
        return prevElem;
    }
}