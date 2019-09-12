#include <bits/stdc++.h>

using namespace std;

void shake(int *a, int tam) {
    bool swapped = 0;
    do {
        swapped = 0;
        for(int i=0; i<(tam-1); i++) {
            if(a[i]>a[i+1]) {
                swap(a[i], a[i+1]);
                swapped = 1;
            }
        }

        if(!swapped) {
            break;
        }
        swapped = 0;
        for(int i=(tam-2); i>=0; i--) {
            if(a[i]>a[i+1]) {
                swap(a[i], a[i+1]);
                swapped = 1;
            }
        }

    }while(swapped);
}

int main() {
    int tam = 8;
    int x[] = {1952, 5, 3, 82, 0, -6, 562, 5};
    shake(x, tam);

    for(int i=0; i<tam; i++) {
        cout << x[i] << " ";
    }
    cin.get();
    return 0;
}
