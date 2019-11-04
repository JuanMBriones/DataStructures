#include <bits/stdc++.h>

using namespace std;

template<typename T>
class nodo {
 public:
  T valor;
  nodo<T> *sig =  nullptr;
};

template<typename T>
class Deque {
    public:
        Deque() {

        }
        ~Deque() {
            auto actual = cabeza;
            while(actual) {
                auto temp = actual;
                actual = actual->sig;
                delete temp;
            }
        }

        void agregarFin(T data) {
            if(esVacia()) {
                cabeza = new nodo<T>;
                cabeza->valor = data;
                return;
            }
            auto actual = cabeza;
            while(actual->sig != nullptr) {
                actual = actual->sig;
            }

            auto nuevonodo = new nodo<T>;
            nuevonodo->valor = data;
            actual->sig = nuevonodo;

        }

        T quitarFin() {
            if(esVacia()) {
                return -1;
            }
            else {
                auto actual = cabeza;
                auto pasado = cabeza;
                while(actual->sig != nullptr) {
                    pasado = actual;
                    actual = actual->sig;
                }
                int temp = actual->valor;
                pasado->sig = nullptr;
                delete actual;

                return temp;

            }
        }



        void agregarInicio(T valor) {
            auto signodo = new nodo<T>;
            signodo->valor = valor;
            signodo->sig = cabeza;

            cabeza = signodo;
        }

        T sacarInicio() {
            if(esVacia()) {
                return T();
            }

            auto viejaCabeza = cabeza;
            auto resultado = viejaCabeza->valor;

            cabeza = viejaCabeza->sig;
            delete viejaCabeza;
            return resultado;
        }

        int tam() { // cool
            auto actual = cabeza;
            int cont = 0;
            while(actual) {
                cont++;
                actual = actual->sig;
            }
            return cont;
        }

        void imprimir() {
            auto actual = cabeza;
            while(actual) {
                cout << actual->valor << endl;
                actual = actual->sig;
            }
        }

        bool esVacia() { // cool
            return !cabeza;
        }
      T sacarFin() {
        if(esVacia()) {
            return T();
        }

        if(!cabeza->sig) {
            auto viejaCabeza = cabeza;
            cabeza = nullptr;
            auto valor = cabeza->valor;
            delete viejaCabeza;
            return valor;
        }

        auto actual = cabeza;
        while(actual->sig->sig != nullptr) {
            actual = actual->sig;
        }
        auto penultimo = actual;

        auto ultimo = penultimo->sig;
        penultimo->sig = nullptr;

        auto valor = ultimo->valor;
        delete ultimo;

        return valor;

        }


    private:
        nodo<T> *cabeza = nullptr;
};

int main() {
        Deque<int> a;

        cin.get();
    return 0;
}
