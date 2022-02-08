#include <iostream>
using namespace std;
#define ISVOWEL(X) ( (X) == 'a' || (X) == 'A' ? 1 : \
                     (X) == 'e' || (X) == 'E' ? 1 : \
                     (X) == 'e' || (X) == 'I' ? 1 : \
                     (X) == 'o' || (X) == 'O' ? 1 : \
                     (X) == 'u' || (X) == 'U' ? 1 : 0)

int main() {

    char character;

    cout << "Ingrese una cadena: ";
    cin >> character;

    if(ISVOWEL(character)) {
        cout << "Your character is a vowel" << endl;
    } else {
        cout << "Your character is not a vowel" << endl;
    }   

    return 0;
}