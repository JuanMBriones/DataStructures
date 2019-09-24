#include <bits/stdc++.h>

using namespace std;

int swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int HoarePartition (int *a, int p, int r) {
    int x = a[p], i = p-1, j = r;
    while (true) {
        do {
          j--;
        }while(a[j] > x);
        do{
          i++;
        }while(a[i] < x);
        if(i < j) {
            swap(a[i], a[j]);
        }
        else {
            return j+1;
        }
    }
}

void QuickSort(int *a, int start, int end) {
    if ((end-start) < 2) return;
    int q = HoarePartition(a,start,end);
    QuickSort(a,start,q);
    QuickSort(a,q,end);
}

int main() {
  int tam = 6;
  int x[6] = {94, 12, 0, 15, 6, 56};
  QuickSort(x, 0, tam);
  for(int i=0; i<tam; i++) {
    cout << x[i] << " ";
  }
  return 0;
}
