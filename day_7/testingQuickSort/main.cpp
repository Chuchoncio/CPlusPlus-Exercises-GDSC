#include <iostream>
#include <vector>

using namespace std;

int particion(vector<int> &vec, int ini, int fin) {
    int pivote = vec[ini];
    int i = ini + 1;

    for(int j = i; j <= fin; j++) {
        if(vec[j] < pivote) {
            swap(vec[i], vec[j]);
            i++;
        }
    }
    swap(vec[ini], vec[i-1]);
    return i-1;
}

void quicksort(vector<int> &vec, int ini, int fin) {
    if(ini < fin) {
        int pivote = particion(vec, ini, fin);
        quicksort(vec, ini, pivote-1);
        quicksort(vec, pivote+1, fin);
    }
}

void imprimirVec(vector<int>vec) {
    for(int i = 0; i < (int)vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> vec = {15,0,2,10,20,17,5};
    imprimirVec(vec);
    quicksort(vec, 0, vec.size()-1);
    imprimirVec(vec);

    system("pause");
}
