#include <iostream>

using namespace std;

int main() {

    int num1, num2, temp;

    num1 = 10;
    num2 = 2;

    cout << "Swapping var num1: " << num1 << " and num2: " << num2 << endl;
    cout << "With temporary variable" << endl;

    temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "num1: " << num1 << " | num2: " << num2 << endl;

    int num3, num4;

    num3 = 80;
    num4 = 100;

    cout << "Swapping var num3: " << num3 << " and num4: " << num4 << endl;
    cout << "Without temporary variable" << endl;

    num3 = num3 + num4;
    num4 = num3 - num4;
    num3 = num3 - num4;

    cout << "num3: " << num3 << " | num4: " << num4 << endl;

    return 0;
}