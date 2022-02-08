#include <iostream>
using namespace std;

int main() {
    int a,b,n;

    while(n != 5) {
        cout << "\nEnter 1 to add.\n";
        cout << "Enter 2 to subtract.\n";
        cout << "Enter 3 to multiply.\n";
        cout << "Enter 4 to divide.\n";
        cout << "Enter 5 to exit.\n";
        cout << "Enter a choice: ";
        cin >> n;
        switch(n) {
            case 1: cout << "\nEnter two numbers: ";
                    cin >> a >> b;
                    cout << "Addition of two numbers is: " << a+b << endl;
                    break;

            case 2: cout << "\nEnter two numbers: ";
                    cin >> a >> b;
                    cout << "Subtract of two numbers is: " << a-b << endl;
                    break;

            case 3: cout << "\nEnter two numbers: ";
                    cin >> a >> b;
                    cout << "Multiply of two numbers is: " << a*b << endl;
                    break;

            case 4: cout << "\nEnter two numbers: ";
                    cin >> a >> b;
                    if(b == 0) {
                        cout << "Cannot divide by 0." << endl;
                    } else {
                        cout << "Divide of two numbers is: " << a/b << endl;
                    }
                    break;

            case 5: exit(0);

            default: cout << "Invalid choice";
        }
    }

    return 0;
}