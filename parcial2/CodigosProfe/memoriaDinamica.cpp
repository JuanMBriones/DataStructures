#include <bits/stdc++.h>

using namespace std;

/**
--Memoria--
  Statica -> Stack
  Dinamica -> Heap

Siempre que en C pones unas llaves {} estas creando un nuevo contexto
  se destruye el objeto
**/

int f() {
  int i;
  //return &i; // <--- Ya no es valida porque esa direccion ya no existe
}

class ejemplo{
  public:
    ejemplo() {
      cout << "\ncreada\n";
    }
    ~ejemplo() {
      cout << "\ndestruida\n";
    }
};

/*
      En C++              En C
      new       ->        malloc() & inicialization()
      delete    ->        ~Destructor() & free()
*/
int main() {
  /*{
    int i = 8;
  }*/
  //cout << i << endl; // da error, porque no es parte del contexto
  ejemplo* e = nullptr; // es mejor practica inicializarlo asi
  { // este es el inicio de un contexto; "scope" = alcance del pointer
    e = new ejemplo();
    cout << "hola" << endl;
    delete e;
  } // fin del contexto
  //delete e; // nos da error porque no forma parte del contexto
  return 0;
}
