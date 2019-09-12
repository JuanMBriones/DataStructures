#include <bits/stdc++.h>

using namespace std;

// atd:swap

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arreglo[], int inicio, int fin) {
    int pivote = fin;
    int siguienteMenor = 0;

    for(int j=inicio; j<fin-1; ++j) {
        if(arreglo[j]<arreglo[pivote]) {
            swap(arreglo[j], arreglo[pivote]);
            ++siguienteMenor;
        }
    }

    swap(arreglo[siguienteMenor], arreglo[pivote]);
    return siguienteMenor;
}

int quicksort(int arreglo[], int inicio, int fin) {
    if(fin < inicio) {
        return;
    }

    int posicionFinalPivote = partition(arreglo, inicio, fin);
    quicksort(arreglo, inicio, posicionFinalPivote-1);
    quicksort(arreglo, posicionFinalPivote+1, fin);
}



int main() {


    return 0;
}
