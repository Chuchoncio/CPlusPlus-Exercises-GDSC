#include <iostream>
#include <string.h>

using namespace std;

/*
    minCapitalLetter = 65;
    maxCapitalLetter = 90;
    minLowerCase = 97;
    maxLowerCase = 122;
*/

#define detectAlterChar(X) (((X) < 65) || ((X) > 90 && (X) < 97) || \
                            ((X) > 122))

void printReverseString(char *cadena, int tamCad)
{

    int i;

    for (i = tamCad; i >= 0; i--)
    {
        cout << cadena[i];
    }
}

void question_1()
{

    char cadena[10];

    cout << "Enter an string: " << endl;
    cin >> cadena;

    printReverseString(cadena, strlen(cadena));
}

void removeVowels(char *cadena, int tamCad)
{

    int i;

    for (i = 0; i < tamCad; i++)
    {
        if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' ||
            cadena[i] == 'o' || cadena[i] == 'u')
        {
            cadena[i] = ' ';
        }
    }
}

void question_2()
{

    char cadena[10];

    cout << "Enter an string: " << endl;
    cin >> cadena;

    removeVowels(cadena, strlen(cadena));

    cout << cadena;
}

void stringToLowerCase(char *cadena, int tamCad)
{

    int i, diffToAccessToLowKey, minCapitalLetter, maxCapitalLetter;

    diffToAccessToLowKey = 32;
    minCapitalLetter = 65;
    maxCapitalLetter = 90;

    for (i = 0; i < tamCad; i++)
    {
        if (cadena[i] >= minCapitalLetter && cadena[i] <= maxCapitalLetter)
        {
            cadena[i] += diffToAccessToLowKey;
        }
    }
}

void question_3()
{

    char cadena[30];

    cout << "Enter an string: " << endl;
    cin >> cadena;

    stringToLowerCase(cadena, strlen(cadena));

    cout << cadena;
}

void deleteAlternateChars(char *cad, int tamCad)
{

    int i;

    for (i = 0; i < tamCad; i++)
    {
        if (detectAlterChar(cad[i]))
        {
            cad[i] = ' ';
        }
    }
}

void question_4()
{

    char cadena[15];

    cout << "Enter an string: " << endl;
    cin >> cadena;

    deleteAlternateChars(cadena, strlen(cadena));

    cout << cadena;
}

int haveSpaces(char *cad, int tamCad)
{
    for (int i = 0; i < tamCad; i++)
    {
        if (cad[i] == ' ')
            return 1;
    }
    return 0;
}

void removeSpacesString(char *cad, int tamCad) {

    char* iniCad = cad;

    while(haveSpaces(cad, tamCad) == 1) {
        if(*cad == ' ') {
            while(*cad) {
                *cad = *(cad+1);
                cad++;
            }
            cad = iniCad;
        }
        cad++;
    }
}

void question_5()
{
    char cadena[50];

    cout << "Enter an string: " << endl;
    gets(cadena);

    removeSpacesString(cadena, strlen(cadena));

    cout << cadena;
}

string input() {
    string cad;
    cin.sync();
    cout << "Enter string: ";
    getline(cin, cad);
    return cad;
}

void ifLongestThenAssign(string& name, string& longestName) {
    if(longestName < name)
        longestName = name;
}

void question_6() {

    string name, longestName;
    int n;

    cout << "Enter the numbers of inputs you wish: ";
    cin >> n;

    name = input();
    longestName = name;

    while(--n) {
        ifLongestThenAssign(name, longestName);
        name = input();
    }

    cout << "The longest name is: " << longestName;
}

int isCharactersTheSame(string cad) {
    char firstCar = cad.at(0);

    for (int i = 1; i < cad.length(); i++) {
        char actualCar = cad.at(i);

        if(firstCar != actualCar) {
            return 0;
        }
    }
    return 1;
}

void question_7() {

    string cad;

    cad = input();

    if(isCharactersTheSame(cad))
        cout << "Yes";
    else
        cout << "No";
}

string concatenateStrings(string cad1, string cad2) {
    string resCad;
    resCad.append(cad1);
    resCad.append(cad2);
    return resCad;
}

string reverseString(string cad) {
    string inverString;
    int sizeCad = cad.length();
    inverString.clear();

    for (int i = sizeCad-1; i >= 0; i--) {
        //inverString.push_back(cad.at(i));
        inverString[i] = cad[i];
    }
    return inverString;
}

void question_8() {

    string cad1, cad2, fullCad, revString;

    cout << "Enter two strings: " << endl;
    cad1 = input();
    cad2 = input();

    fullCad = concatenateStrings(cad1, cad2);
    revString = reverseString(fullCad);

    cout << revString;
}

int calcSum(int n1, int n2, int n3) {
    return n1 + n2 + n3;
}

void question_9() {
    
    int num1, num2, num3, sum;

    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    sum = calcSum(num1, num2, num3);

    cout << "The sum is: " << sum;
}

void reverse_dig(int* num1, int* num2) {
    int numAux = 0, numAux2 = 0;

    while(*num1 > 0) {
        int remain = *num1 % 10;
        numAux = (numAux * 10) + remain;
        *num1 = *num1 / 10;
    }

    while(*num2 > 0) {
        int remain = *num2 % 10;
        numAux2 = (numAux2 * 10) + remain;
        *num2 = *num2 / 10;
    }

    *num1 = numAux;
    *num2 = numAux2;
}

void swap(int* num1, int* num2) {
    *num1 += *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

void question_10() {

    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    reverse_dig(&num1, &num2);
    swap(&num1, &num2);

    cout << "Num1: " << num1 << "\nNum2: " << num2 << endl;
}

int main() {
    question_10();

    return 0;
}
