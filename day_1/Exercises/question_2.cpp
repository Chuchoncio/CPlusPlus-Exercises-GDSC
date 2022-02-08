#include <iostream>

using namespace std;

int main() {

    int year;

    year = 2016;

    cout << "The year is " << year << endl;

    if( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << "Year leap!";
    } else {
        cout << "Year not leap!";
    }

    return 0;
}