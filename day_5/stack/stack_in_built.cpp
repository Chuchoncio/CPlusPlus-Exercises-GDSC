#include <bits/stdc++.h>
using namespace std;

// En definitiva es la misma implementacion
//  que la del array en cuanto a usar los metodos
//  se trata (a diferencia de la implementacion 
//  que vi en la facultad, esto es mucho mas simple)

int main() {
    
    stack<int> st;
    int arr[] = {1,2,3,4,5};
    
    //Reverse without using any extra array
    
    for(int i = 0; i < 5; i++)
        st.push(arr[i]);
        
    st.top();
    
    int k = 0;
    
    while(!st.empty()) {
        arr[k] = st.top();
        st.pop();
        k++;
    }
    
    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    
    return 0;   
}