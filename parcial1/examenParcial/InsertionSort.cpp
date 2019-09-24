#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

inline void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

inline void Insertion(int *arr, int tam) {

  int index = 0;
  //bool noChanges = false;
  while(index<tam) {
    int j = index;
    while(j>0) {
      if(arr[j]<arr[j-1]) {
        swap(arr[j], arr[j-1]);
      }
      else {
        break;
      }
      j--;
    }
    index++;
  }
}

int main() {
  int x[5] { 65, 40, 2, 9, 84 };
  int tam = 5;
  Insertion(x, tam);
  for(int i=0; i<tam; i++) {
    cout << x[i] << " ";
  }
  return 0;
}
