#include <iostream>
using namespace std;

int main() {

    int a, c, i;
    cout << "Enter a number: ";
    cin >> a;

    i = 1;
    do{
        cout << a << "X" << i << "=" << a*i << endl;
        i++;
    }while(i <= 10);

    return 0;
}