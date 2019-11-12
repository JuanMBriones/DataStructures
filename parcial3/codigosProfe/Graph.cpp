#include <iostream>
#include <list>

using namespace std;

class Nodo {
public:
    Nodo(string n) : nombre(n){}

    string nombre;
    list<Nodo*> adyacentes;
};

class Grafo {
public:
    list<Nodo*> listaNodos;
};

#include <algorithm>

int main()
{
    Grafo g;
    auto n1 = new Nodo{"n1"};
    auto n2 = new Nodo{"n2"};
    auto n3 = new Nodo{"n3"};
    auto n4 = new Nodo{"n4"};
    auto n5 = new Nodo{"n5"};

    g.listaNodos.push_back(n1);
    g.listaNodos.push_back(n2);
    g.listaNodos.push_back(n3);
    g.listaNodos.push_back(n4);
    g.listaNodos.push_back(n5);

    n1->adyacentes.push_back(n3);
    n3->adyacentes.push_back(n1);

    n2->adyacentes.push_back(n3);
    n3->adyacentes.push_back(n2);

    n4->adyacentes.push_back(n3);
    n3->adyacentes.push_back(n4);

    n5->adyacentes.push_back(n3);
    n3->adyacentes.push_back(n5);

    n2->adyacentes.push_back(n4);
    n4->adyacentes.push_back(n2);

    list<Nodo*> porVisitar;
    porVisitar.push_back(n1);
    list<Nodo*> visitados;
    while(!porVisitar.empty()) {
        auto actual = porVisitar.front();
        porVisitar.pop_front();
        cout << actual->nombre << endl;
        visitados.push_back(actual);
        for(auto nodo : actual->adyacentes) {
            if(std::find(visitados.begin(), visitados.end(), nodo)
                    == visitados.end() &&
               std::find(porVisitar.begin(), porVisitar.end(), nodo)
                    == porVisitar.end()) {
                porVisitar.push_back(nodo);
            }
        }
    }

    return 0;
}
