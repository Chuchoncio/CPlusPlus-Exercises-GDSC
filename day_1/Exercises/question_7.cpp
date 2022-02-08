#include <iostream>
using namespace std;

int main() {

    int num, cont = 0;

    cout << "Enter a number: ";
    cin >> num;

    for (int i = 1; i < num; i++)
    {
        if( num % i == 0 ) {
            cont += i;
        }
    }
    
    if(num == cont) {
        cout << cont << " is a perfect number." << endl;
    }
    else {
        cout << num << " is NOT a perfect number." << endl;
    }
}