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

int main()
{
    //question_1();

    //question_2();

    //question_3();

    //question_4();

    question_5();

    return 0;
}
