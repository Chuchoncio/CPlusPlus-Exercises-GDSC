#include <iostream>
using namespace std;

int main() {

    int age;

    cout << "Enter your age: ";
    cin >> age; // >> -> extraction operator

    // age = 16

    if(age > 15 || age < 21) {
        cout << "Good";
    }
    else {
        cout << "Bad";
    }

    return 0;
}