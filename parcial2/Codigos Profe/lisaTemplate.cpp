#include <iostream>

using namespace std;

template <typename T>
class Nodo {
public:
    T valor;
    Nodo<T>* siguiente = nullptr;
};

template <typename T>
class Lista {
public:
    Lista() {
    }

    ~Lista(){
        auto actual = cabeza;
        while(actual) {
            auto temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }

    void agregar(T valor) {
        auto siguienteNodo = new Nodo<T>;
        siguienteNodo->valor = valor;
        siguienteNodo->siguiente = cabeza;

        cabeza = siguienteNodo;
    }

    bool esVacia() {
        return !cabeza;
    }

    T sacar() {
        if(esVacia()) {
            return 0;
        }

        auto viejaCabeza = cabeza;
        auto resultado = viejaCabeza->valor;

        cabeza = viejaCabeza->siguiente;
        delete viejaCabeza;
        return resultado;
    }

    void imprimir() {
       auto actual = cabeza;
        while(actual) {
            cout << actual->valor << endl;
            actual = actual->siguiente;
        }
    }

private:
    Nodo<T>* cabeza = nullptr;
};

//int main()
//{
//    NodoEntero* cabezathis-> = nullptr;
//    cout << cabeza << endl;
//    cabeza = new NodoEntero;
//    cout << cabeza << endl;
//
//    (*cabeza).entero = 10;
//
//    auto siguienteNodo = new NodoEntero;
//    siguienteNodo->entero = 9;
//
//    cabeza->siguiente = siguienteNodo;
//
//    imprimir(cabeza);
//
//    return 0;
//}

int main()
{
    Lista<float> lista;
    lista.agregar(10.0);
    lista.agregar(20.0);
    lista.agregar(30.0);

    lista.imprimir();

    cout << "sacar" << lista.sacar() << endl;
    cout << "sacar" << lista.sacar() << endl;
    cout << "sacar" << lista.sacar() << endl;

    cout << (lista.esVacia() ? "vacia" : "no vacia");

    return 0;
}
