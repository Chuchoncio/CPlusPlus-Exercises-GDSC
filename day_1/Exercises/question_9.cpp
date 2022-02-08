#include <iostream>
using namespace std;

int main() {

    int diceFace, oppDiceFace;

    cout << "Ingrese la cara del dado: ";
    cin >> diceFace;

    if(diceFace >= 1 && diceFace <= 3) {
        oppDiceFace = diceFace + 3;
    }
    else if(diceFace >= 4 && diceFace <= 6) {
        oppDiceFace = diceFace - 3;
    }
    else {
        cout << "That dice face belongs to another dice";
        return 1;
    }

    cout << "The opposite face of " << diceFace << " is " << oppDiceFace << endl; 

    return 0;
}