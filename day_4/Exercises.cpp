#include <iostream>
#include <string.h>
#include <cstdlib>
#include <math.h>
using namespace std;
#define SIZE_ARR 10
#define TAM_CAD 20

void fillArray(int* arr, int sizeArr) {
    int i;

    for(i = 0; i < sizeArr; i++) {
        arr[i] = rand() % 100;
    }
}


void displayArray(int* arr, int sizeArr) {
    int i;

    for(i = 0; i < sizeArr; i++) {
        cout << "[" << arr[i] << "] ";
    }

    cout << "\n";
}

void reverseString(char* cad, int tamCad) {

    int i;
    char auxCad[tamCad];

    for(i = tamCad-1; i >= 0; i--) {
        auxCad[tamCad-1-i] = cad[i]; 
    }

    for(i = 0; i < tamCad; i++) {
        cad[i] = auxCad[i];
    }

}

void question_4() {

    char cadena[TAM_CAD];

    cout << "Ingrese cadena: " << endl;
    gets(cadena);

    reverseString(cadena, strlen(cadena));

    cout << cadena;
}

void rotateAnArrayByOne(int* arr, int sizeArr) {
    int i, auxElem, storedElem, lastElem;

    lastElem = arr[sizeArr-1];
/*     auxElem = arr[0];

    // De izquierda a derecha
    for(i = 1; i < sizeArr; i++) {
        storedElem = arr[i];
        arr[i] = auxElem;
        auxElem = storedElem;
    } */

    // De derecha a izquierda
    for(i = sizeArr-1; i > 0; i--) {
        arr[i] = arr[i-1];        
    }

    arr[0] = lastElem;
}

int verifyBelonging(int* arr, int findNum, int sizeArr) {
    int i;

    for(i = 0; i < sizeArr; i++) {
        if(findNum == arr[i])
            return 1;
    }
    return 0;
}

int* findDuplicates(int* arr, int* arrDup, int sizeArr) {

    int i, j, k, actualNum;

    k = 0;

    for(i = 0; i < sizeArr-1; i++) {
        actualNum = arr[i];
        for(j = i+1; j < sizeArr; j++) {
            if(verifyBelonging(arrDup, actualNum, sizeArr) == 1)
                break;
            else if(arr[j] == actualNum) {
                arrDup[k] = actualNum;
                k++;
                break;
            }
        }
    }
}

void fillArrayWithInput(int* arr, int sizeArr) {
    int i;

    for(i = 0; i < sizeArr; i++) {
        cout << "Ingrese elemento de la pos " << i << ": ";
        cin >> arr[i];
    }
        cout << "\n";
}

void cleanArr(int* arr, int sizeArr) {
    int i;

    for(i = 0; i < sizeArr; i++) {
        arr[i] = 0;
    }
}

void question_3() {
    int arr[SIZE_ARR], min, max;
    int arr_dup[SIZE_ARR];

    //fillArray(arr, SIZE_ARR);
    fillArrayWithInput(arr, SIZE_ARR);
    displayArray(arr, SIZE_ARR);
    cleanArr(arr_dup, SIZE_ARR);
    findDuplicates(arr, arr_dup, SIZE_ARR);
    cout << "The following numbers are duplicated in the array: " << endl;
    displayArray(arr_dup, SIZE_ARR);
}

void question_2(){
    int arr[SIZE_ARR], min, max;

    fillArray(arr, SIZE_ARR);
    displayArray(arr, SIZE_ARR);
    rotateAnArrayByOne(arr, SIZE_ARR);
    cout << "The array rotated is: " << endl;
    displayArray(arr, SIZE_ARR);
}

int findMaximumInArray(int* arr, int sizeArr) {
    int i, max_elem = arr[0];

    for(i = 1; i < sizeArr; i++) {
        if(max_elem < arr[i])
            max_elem = arr[i];
    }

    return max_elem;
}

int findMinimumInArray(int* arr, int sizeArr) {
    int i, min_elem = arr[0];

    for(i = 1; i < sizeArr; i++) {
        if(min_elem > arr[i])
            min_elem = arr[i];
    }

    return min_elem;
}

void question_1() {
    
    int arr[SIZE_ARR], min, max;

    fillArray(arr, SIZE_ARR);
    displayArray(arr, SIZE_ARR);
    min = findMinimumInArray(arr, SIZE_ARR);
    max = findMaximumInArray(arr, SIZE_ARR);

    cout << "Minimum element of the array: " << min << endl;
    cout << "Maximum element of the array: " << max << endl;
}

void question_6() {

    int n = 6;
    int arr[n];

    fillArray(arr, n);
    displayArray(arr, n);
}

int sumElemsOfArray(int* arr, int arrSize) {

    int sum = 0;

    for (int i = 0; i < arrSize; i++)
    {
        sum += arr[i];
    }

    return sum;
}

void question_7() {

    int n = 10, sum;
    int arr[n];

    fillArray(arr, n);
    displayArray(arr, n);
    sum = sumElemsOfArray(arr, n);
    cout << "The sum of all elements in the array is: " << sum << endl;
}

void calculateAndDisplayEvensAndOddsArray(int* arr, int arrSize) {

    int countOdd = 0, countEven = 0;

    for (int i = 0; i < arrSize; i++)
    {
        if(arr[i] % 2 == 0){
            countEven++;
        } else {
            countOdd++;
        }
    }

    cout << "The number of odd elements is: " << countOdd << endl;
    cout << "The number of even elements is: " << countEven << endl;
}

void question_8() {

    int n = 10;
    int arr[n];

    fillArray(arr, n);
    displayArray(arr, n);
    calculateAndDisplayEvensAndOddsArray(arr, n);
}

void printReverseArray(int* arr, int arrSize) {

    for (int i = arrSize-1; i >= 0; i--)
    {
        cout << "[" << arr[i] << "] ";
    }
    cout << "\n";
}

void question_9() {

    int n = 10;
    int arr[n];

    fillArray(arr, n);
    displayArray(arr, n);
    printReverseArray(arr, n);
}

// I implemented pow like this because the original
//  pow function from math.h library is useless
//  using double or float values to return when i need
//  an integer
int _pow(int base, int exp)
{
    return exp == 0 ? 1 : base * _pow(base, exp - 1);
}

int convertFive(int num) {
    int numRes = 0, i = 0, firstCalc = 0;

    while(num > 0) {
        int remain = num % 10;
        if(remain == 0)
	        remain = 5;
        numRes = (_pow(10, i) * remain) + numRes;
        num = num / 10;
        i++;
    }

    return numRes;
}

void question_10() {

    int n = 1354;
    cout << n << endl;
    n = convertFive(n);
    cout << n << endl;
}

int main()
{
    //question_1();

    //question_2();

    //question_3();

    //question_4();

    //question_5();

    //question_6();

    //question_7();

    //question_8();

    //question_9();

    question_10();

    return 0;
}