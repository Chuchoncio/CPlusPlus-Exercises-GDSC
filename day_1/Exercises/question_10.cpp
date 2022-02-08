#include <iostream>
using namespace std;

int main() {

    int num;

    cout << "Enter a number: ";
    cin >> num;

    if(num > 5) {
        cout << "The number is greater than 5" << endl;
    }
    else {
        cout << "The number is NOT greater than 5" << endl;
    }
}