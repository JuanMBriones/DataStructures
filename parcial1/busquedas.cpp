#include <bits/stdc++.h>

using namespace std;

int buscar_no_ordenado(int* arr, int tamano, int buscar) {
    for(int i=0; i<tamano; i++) {
        if(arr[i]==buscar) {
            return i;
        }
    }
    return -1;
}

int buscar_ordenado(int* arr, int tamano, int buscar) {
    for(int i=0; i<tamano; i++) {
        if(arr[i]>buscar) {
            break;
        }
        if(arr[i]==buscar) {
            return i;
        }
    }
    return -1;
}


int busqueda_bin(int buscar, int arr[], int alto, int bajo) {
    int piv = (alto+bajo)/2;
    for(int i=bajo; i<alto; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    if(bajo>alto) {
        return -1;
    }
    if(arr[piv]==buscar) {
        return piv;
    }
    if(arr[piv]>buscar) {
        alto = piv;
        busqueda_bin(buscar, arr, piv-1, bajo);
    }
    else if(arr[piv]<buscar) {
        busqueda_bin(buscar, arr, alto, piv+1);
    }

}


int main() {
    int arreglo[6] = {1, 10, 2, 101, 35};
    int arr[6] = {1, 2, 10, 35, 101, 93};
    int alto = 6, bajo = 0, piv = (alto+bajo)/2;
    int n;
    cin >> n;
    //cout << "esta en la posicion " << buscar_no_ordenado(arreglo, 6, n) << endl;
    cout << "esta en la posicion " << busqueda_bin(n, arr, alto, bajo) << endl;
    cin.get();
    return 0;
}
