#include <bits/stdc++.h>

using namespace std;

inline int binarySearch(int *arr, int dato, int bajo, int alto) {
    int index = (alto+bajo)/2;
    if(arr[index]==dato) {
      return index;
    }
    if(alto<bajo) {
      return -1;
    }
    if(arr[index]>dato) {
      binarySearch(arr, dato, 0, index-1);
    }
    else if(arr[index]<dato) {
      binarySearch(arr, dato, index+1, alto);
    }

}

int main() {
  int x[5] { 0, 2, 5, 9, 70 };
  int tam = 5;
  int buscar = 5;
  //while(cin >> buscar)
  cout << binarySearch(x, buscar, 0, tam-1) << endl;
  return 0;
}
