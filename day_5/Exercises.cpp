#include <iostream>
using namespace std;

#include "stack\stackImp.cpp"

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

int main()
{
    //question_1();

    //question_2();

    question_3();

    return 0;
}
