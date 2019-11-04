#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T valor;
    Node<T>* sig = nullptr;
};

template <typename T>
class DummyList {
public:
    DummyList() {
    }

    ~DummyList(){
        auto actual = head;
        while(actual) {
            auto temp = actual;
            actual = actual->sig;
            delete temp;
        }
    }

    void add(int pos, T valor) {
        if(pos <= 0) {
            pos = 0;
            return;
        }

        if(pos > size()) {
            pos = size();
            return;
        }

        auto anterior = enesimoNode(pos-1);
        auto nuevoNode = new Node<T>;
        nuevoNode->valor = valor;
        nuevoNode->sig = anterior->sig;
        anterior->sig = nuevoNode;
    }

    T pop(int pos) {
        /*if(esVacia()) {
            return T();
        }*/

        auto anterior = enesimoNode(pos-1);
        auto sacado = anterior->sig;
        anterior->sig = sacado->sig;
        auto valor = sacado->valor;
        delete sacado;
        return valor;
    }

    bool esVacia() {
        return !head->sig;
    }

    int size() {
        int cuenta = 0;
        auto actual = head;
        while(actual) {
            cuenta++;
            actual = actual->sig;
        }
        return cuenta-1;
    }

    void imprimir() {
       auto actual = head->sig;
        while(actual) {
            cout << actual->valor << endl;
            actual = actual->sig;
        }
    }

    T valor(int pos) {
        if(esVacia()) {
            return T();
        }

        if( pos < 0) {
            pos = 0;
        }
        int t = size();
        if(pos > t) {
            pos = t-1;
        }
        return enesimoNode(pos)->valor;
    }

private:
    Node<T>* enesimoNode(int n) {
        if(n < 0) {
            return head;
        }

        int NodesPasados = 0;
        auto actual = head->sig;
        while(NodesPasados < n) {
            NodesPasados++;
            actual = actual->sig;
        }
        return actual;
    }

    Node<T>* head = new Node<T>;
};

int main()
{
    DummyList<int> myList;
    
    //myList.add(0, 54);
    myList.add(1, 8);
    myList.add(2, 0);
    myList.add(3, 1);

    myList.imprimir();

    cout << myList.size() << endl;

    //cout << myList.pop(3) << endl;


    cin.get();
    return 0;
}
