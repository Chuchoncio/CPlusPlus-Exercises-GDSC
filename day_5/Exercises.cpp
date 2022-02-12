#include <iostream>
#include "stack\stackImp.cpp"
#include <math.h>
#include <stdio.h>
using namespace std;


void printNumR(int num)
{
    if (num == 0)
        return;
    else
    {
        printNumR(num-1);
        cout << num << " ";
    }
}

void question_1()
{

    int num;
    cout << "Enter a number: ";
    cin >> num;

    printNumR(num);
}

void displayArray(int* arr, int sizeArr) {
    int i;

    for(i = 0; i < sizeArr; i++) {
        cout << "[" << arr[i] << "] ";
    }

    cout << "\n";
}

void fillArrayWithInput(int* arr, int sizeArr) {
    int i;

    for(i = 0; i < sizeArr; i++) {
        cout << "Ingrese elemento de la pos " << i << ": ";
        cin >> arr[i];
    }
        cout << "\n";
}

void pushArrayToStack(int* arr, int n) {

    for (int i = 0; i < n; i++)
    {
        push(arr[i]);
    }
}

void popAndPrint() {
    while(!isEmpty()) {
        cout << peak() << " ";
        pop();
    }
}

void question_2() {

    int n;
    cout << "Array size: ";
    cin >> n;

    int arr[n];
    fillArrayWithInput(arr, n);

    pushArrayToStack(arr, n);
    popAndPrint();
}

void fillArray(int* arr, int sizeArr) {
    int i;

    for(i = 0; i < sizeArr; i++) {
        arr[i] = rand() % 100;
    }
}

void deleteMiddleOfStack(int sizeArr) {

    int i = sizeArr/2;

    while(i != sizeArr-1) {
        stack[i] = stack[i+1];
        i++;
    }

    pop();
}

void question_3() {

    int n;
    cout << "Array size: ";
    cin >> n;

    int arr[n];
    fillArray(arr, n);

    pushArrayToStack(arr, n);
    display();
    deleteMiddleOfStack(n);
    display();
}

void reverse_dig(int* num1) {
    int numAux = 0;

    while(*num1 > 0) {
        int remain = *num1 % 10;
        numAux = (numAux * 10) + remain;
        *num1 = *num1 / 10;
    }

    *num1 = numAux;
}

void power_reverse(int num, int reverseNum) {
    long res = pow(num, reverseNum);

    printf("res (%%E) - %E: \n", res);
}

void question_4() {

    int num, reverseNum;

    cout << "Enter a number: ";
    cin >> num;

    reverseNum = num;

    reverse_dig(&reverseNum);
    power_reverse(num, reverseNum);  
}

string reverseString(string cad) {
    string res;

    res = "";

    for(char ch : cad) {
        push(ch);
    }

    while(!isEmpty())
    {
        res += peak();
        pop();
    }

    return res;
}

void question_5() {

    string cad, cadRes;

    cout << "Enter a string: ";
    getline(cin, cad);

    cadRes = reverseString(cad);

    cout << cadRes << endl;
}

void fillStack() {
    for (int i = 0; i < 5; i++) {
        push(rand() % 100);
    }
}

void sortStack() {
    int aux;

    
}

void question_6() {

    fillStack();
    sortStack();
}

int main()
{
    //question_1();

    //question_2();

    //question_3();

    //question_4();

    //question_5();

    question_6();

    return 0;
}
