#include <iostream>

using namespace std;

int calculateFact(int num) {
    int fact = num;
    while(--num) {
        fact *= num;
    }

    return fact;
}

int main() {

    int number;

    cout << "Enter a number to calculate factorial: ";
    cin >> number;
    cout << "The factorial of that number is: " << calculateFact(number) << endl;

    return 0;
}