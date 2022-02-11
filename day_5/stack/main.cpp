#include <iostream>
#include "stackImp.cpp"
using namespace std;

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

