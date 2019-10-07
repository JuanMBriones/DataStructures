#include <iostream>

using namespace std;

//posicionFinalPivote
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arreglo[], int inicio, int fin) {
    int pivote = fin;
    int siguienteMenor = inicio;

    for(int j = inicio; j < fin; ++j) {
        if(arreglo[j] < arreglo[pivote]) {
            swap(arreglo[j], arreglo[siguienteMenor]);
            ++siguienteMenor;
        }
    }

    swap(arreglo[siguienteMenor], arreglo[pivote]);
    return siguienteMenor;
}

void quicksort(int arreglo[], int inicio, int fin) {
    if(fin < inicio){
        return;
    }

    int posicionFinalPivote = partition(arreglo, inicio, fin);
    quicksort(arreglo, inicio, posicionFinalPivote-1);
    quicksort(arreglo, posicionFinalPivote+1, fin);
}

void imprimir(int arreglo[], int tamano) {
    for(int i = 0; i < tamano; ++i) {
        cout << arreglo[i] << ",";
    }
}

int main()
{
    int arreglo[] = {10, 90, 80, 70, 60, 50, 50, 42, 10, 9, 5, 1};
    cout << "antes:";
    imprimir(arreglo, 11);
    cout << "\n";
    quicksort(arreglo, 0, 10);

    cout << "\ndespues:";
    imprimir(arreglo, 11);

    return 0;
}
