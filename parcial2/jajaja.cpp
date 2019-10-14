#include <iostream>

using namespace std;

template<typename T>
class IteradorJava;

template <typename T>
class Nodo {
public:
    T valor;
    Nodo<T>* siguiente = nullptr;
    Nodo<T>* anterior = nullptr;
};

template <typename T>
class ListaDoble {
public:
    ListaDoble() {
    }

    ~ListaDoble(){
        auto actual = cabeza;
        while(actual) {
            auto temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }

    void agregarInicio(T valor) {
        agregar(valor, 0);
    }

    void agregarFin(T valor) {
        agregar(valor, tamano());
    }

    void agregar(T valor, int posicion) {
        if(esVacia()) {
            cabeza = new Nodo<T>;
            cabeza->valor = valor;
            return;
        }


        if(posicion <= 0) {
            auto nuevoNodo = new Nodo<T>;
            nuevoNodo->valor = valor;

            nuevoNodo->siguiente = cabeza;
            cabeza->anterior = nuevoNodo;

            cabeza = nuevoNodo;
            return;
        }

        if(posicion >= tamano()) {
            posicion = tamano()-1;
            return;
        }

        auto anterior = enesimoNodo(posicion-1);
        auto nuevoNodo = new Nodo<T>;
        nuevoNodo->valor = valor;
        nuevoNodo->siguiente = anterior->siguiente;
        nuevoNodo->anterior = anterior;
        anterior->siguiente = nuevoNodo;

        if(nuevoNodo->siguiente) {
            nuevoNodo->siguiente->anterior = nuevoNodo;
        }
    }

    bool esVacia() {
        return !cabeza;
    }

    T sacarInicio() {

    }

    T sacarFin() {

    }

    T sacar(int posicion) {

    }

    int tamano() {
        int cuenta = 0;
        auto actual = cabeza;
        while(actual) {
            cuenta++;
            actual = actual->siguiente;
        }
        return cuenta;
    }

    void imprimir() {
       auto actual = cabeza;
        while(actual) {
            cout << actual->valor << endl;
            actual = actual->siguiente;
        }
    }

    T valor(int posicion) {
        if(esVacia()) {
            return T();
        }

        if( posicion < 0) {
            posicion = 0;
        }
        int t = tamano();
        if(posicion > t) {
            posicion = t-1;
        }
        return enesimoNodo(posicion)->valor;
    }

private:
    template<typename U> friend class IteradorJava;

    Nodo<T>* enesimoNodo(int n) {
        int nodosPasados = 0;
        auto actual = cabeza;
        while(nodosPasados < n) {
            nodosPasados++;
            actual = actual->siguiente;
        }
        return actual;
    }

    Nodo<T>* cabeza = nullptr;
};

template< typename T>
class IteradorJava {
public:

    explicit IteradorJava(ListaDoble<T>* lista) {
        this->lista = lista;
    }

    bool hasNext() {
        if(!actual) {
            return !lista->esVacia();
        }

        return actual->siguiente;
    }

    T next() {
        if(!actual) {
            if(lista->esVacia()) {
                return T();
            }

            actual = lista->cabeza;
            return actual->valor;
        }

        if(!actual->siguiente) {
            return T();
        }

        actual = actual->siguiente;
        return actual->valor;
    }

private:
    Nodo<T>* actual = nullptr;
    ListaDoble<T>* lista = nullptr;
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
    ListaDoble<float> lista;
    lista.agregarInicio(10.0);
    lista.agregarInicio(20.0);
    lista.agregarFin(30.0);
    lista.agregar(40.0, 1);
    lista.agregarFin(50.0);

    lista.imprimir();

    float sumatoria = 0.0;

    IteradorJava<float> it(&lista);
    while(it.hasNext()) {
        sumatoria += it.next();
    }

    cout << "suma:" << sumatoria << endl;

    cout << "sacar" << lista.sacar(1) << endl;;
    cout << "sacar" << lista.sacarInicio() << endl; // 10
    cout << "sacar" << lista.sacarFin() << endl; // 30
    cout << "sacar" << lista.sacarInicio() << endl; // 40

    cout << (lista.esVacia() ? "vacia" : "no vacia");

    return 0;
}
