#include <bits/stdc++.h>

using namespace std;

class NodoEntero {
  public:
    int entero;
    NodoEntero* siguiente = nullptr;
};

class ListaEntero {
  public:
    ~ListaEntero() {

    }
    void agregar(int valor) {
      auto siguienteNodo = new NodoEntero;
      siguienteNodo->entero = valor;
      siguienteNodo->siguiente = cabeza;

      cabeza = siguienteNodo;
    }

    bool esVacia() {
      return !cabeza;
    }

    int sacar() {
      if(esVacia()) {
        return 0;
      }

      auto viejaCabeza = cabeza;
      auto resultado = viejaCabeza->entero;

      cabeza = viejaCabeza->siguiente;
      delete viejaCabeza;
      return resultado;
    }

    void imprimir() {
      auto actual = cabeza;
      while(actual) {
        cout << actual->entero << endl;
        actual = actual->siguiente;
      }
    }
  private:
    NodoEntero* cabeza = nullptr;
};

int main() {

  ListaEntero lista;
  lista.agregar(1);
  lista.agregar(6);
  lista.agregar(0);
  lista.imprimir();


  cout << "sacar " << lista.sacar() << endl;
  cout << "sacar " << lista.sacar() << endl;
  cout << "sacar " << lista.sacar() << endl;

  cout << (lista.esVacia()? "vacia" : "no vacia") << endl;

  return 0;
}
