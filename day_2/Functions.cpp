#include <iostream>
using namespace std;

// call by value
int addTwoVariables(int a, int b) {
    return a+b;
}

// call by reference
void swapTwoVariables(int &a, int &b) {
    int *swap = &a;

    a = b;
    b = *swap;
}

int main() {

    int a, b, c;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;

    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;

    c = addTwoVariables(a, b);

    cout << "c = " << c << endl;

    swapTwoVariables(a,b);

    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;

    return 0;
}