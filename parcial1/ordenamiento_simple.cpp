#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b) {
    int temp = b;
    b = a;
    a = temp;
}

void selection_sort(int *arr, int tamano) {
    for(int i=0; i<tamano; i++) {
            int menor = i;
            for(int j=i; j<tamano; j++) {
                if(arr[j]<arr[menor]) {
                    menor = j;
                }
            }
            swap(arr[menor], arr[i]);
    }
}

void bubble_sort(int *arr, int tamano) {
    bool flagIntercambios = 1;
    while(flagIntercambios) {
        flagIntercambios = false;
        for(int i=0; i<(tamano-1); i++) {
            if(arr[i+1]<arr[i]) {
                swap(arr[i], arr[i+1]);
                flagIntercambios = true;
            }
        }
        /*for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
        } cout << endl;*/
    }
}

int main() {
    /*int n;
    cin >> n;*/
    int x[5] = {42, 5, 1, 9, 10};
    //selection_sort(x, 5);
    bubble_sort(x, 5);
    for(int i=0; i<5; i++) {
        cout << x[i] << " ";
    }
    cin.get();
    return 0;
}
