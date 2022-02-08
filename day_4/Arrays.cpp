#include <iostream>

using namespace std;

int main() {

    int array[6];

    //int *array = new int(5);

    for(int i = 0; i < 6; i++) {
        cout << "array[" << i << "]: ";
        cin >> array[i];
    }

    for(int i = 0; i < 6; i++) {
        cout << "[" << array[i] << "]";
    }

    cout << "\n";
    cout << 4[array] << endl;
    cout << *(array+4) << endl;

    return 0;
}