#include <bits/stdc++.h>

using namespace std;

class NodoEntero {
  public:
    int entero;
    NodoEntero* siguiente = nullptr;
};

void imprimir(NodoEntero* cabeza) {
  auto actual = cabeza;
  while(actual) {
    cout << actual->entero << endl;
    actual = actual->siguiente;
  }
}

int main() {
  NodoEntero* cabeza = new NodoEntero;
  cout << cabeza << endl;

  // los pointers apuntan a una direccion de memoria
  (*cabeza).entero = 10;  // pointer a cabeza.entero
  cout << cabeza << endl;
  //cout << *cabeza << endl;

  auto siguienteNodo = new NodoEntero;
  // el tipo auto(C++11), es que deduzca el tipo de variable(tipo *var* de JS)
  siguienteNodo->entero = 9; // la -> es para referenciar y utilizar

  cabeza->siguiente = siguienteNodo;

}
