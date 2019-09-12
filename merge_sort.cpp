#include <bits/stdc++.h>

using namespace std;

void merge(int arreglo[], int inicio, int pivote, int fin) {
    int n1 = pivote - inicio + 1;
    int n2 = fin - pivote;

    int t1[n1], t2[n2];

    for(int i=0; i<n1; ++i) {
        t1[i] = arreglo[inicio+i];
    }

    for(int i=0; i<n2; ++i) {
        t2[i] = arreglo[pivote+1+i];
    }

    int indiceT1 = 0;
    int indiceT2 = 0;
    int indiceSalida = inicio;

    while(indiceT1 < n1 && indiceT2 < n2) {
        if(t1[indiceT1] < t2[indiceT2]) {
            arreglo[indiceSalida] = t1[indiceT1];
            indiceT1++;
            indiceSalida++;
        }
        else {
            arreglo[indiceSalida] = t2[indiceT2];
            indiceT2++;
            indiceSalida++;
        }
    }


    while(indiceT1 < n1) {
        arreglo[indiceSalida] = t1[indiceT1];
        indiceT1++;
        indiceSalida++;
    }
    while(indiceT2 < n2) {
        arreglo[indiceSalida] = t2[indiceT2];
        indiceT2++;
        indiceSalida++;
    }
}

void merge_sort(int *arreglo, int inicio, int fin) {
    if(fin<=inicio) {
        return;
    }

    int pivote = inicio + (fin-inicio)/2;
    merge_sort(arreglo, inicio, pivote);
    merge_sort(arreglo, pivote+1, fin);
    merge(arreglo, inicio, pivote, fin);
}

int main() {
    int arr[] = {9,156, 2, 813, 30};
    merge_sort(arr, 0, 4);

    for(int i=0; i<5; ++i) {
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}
