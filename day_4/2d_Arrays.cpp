#include <iostream>

using namespace std;

int main() {

    int i,j;
    int mat[3][3];

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cout << "mat[" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cout << "[" << mat[i][j] << "] ";
        }
        cout << "\n";
    }


    return 0;
}