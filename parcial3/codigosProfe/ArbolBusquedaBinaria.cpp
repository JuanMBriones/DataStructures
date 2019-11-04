#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node{
  T data;
  Node *sig = nullptr;
}

template <typename T>
class Tree{
public:

private:
  bool sacarRecursivo(Nodo<T>* actual, T buscado) {
    if(!actual) {
      return false;
    }

    if(actual->data == buscado) {
      if(!actual->right && actual->left) {
        delete actual;
        return true;
      }

      if(actual->left) {

      }
    }
    else if(buscado < actual->data) {
      return sacarRecursivo(actual->left, buscado);
    }
    else {
      return sacarRecursivo(actual->right, buscado);
    }
  }
}

int main() {

  cin.get();
  return 0;
}
