#include <iostream>

using namespace std;

void showArray(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i++) {
        cout << "[" << arr[i] << "]";
    } 
}

int main() {

    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";

    for(int i = 0; i < n; i++) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "\n";
    showArray(arr, n);
    cout << "\n";    

    for(int i = 0; i < n/2; i++) {
        int aux;

        aux = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = aux;
    }

    showArray(arr, n);
    cout << "\n";

    return 0;
}