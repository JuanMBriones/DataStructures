#include <bits/stdc++.h>

using namespace std;


class Animal{
public:
    Animal() {
            cout << "const def" << endl;
    }
    Animal(int edad)
        : m_edad(edad){ // listas de inicializacion

            cout << "const edad" << endl;
    }
    ~Animal() {
            cout << "destruct" << endl;
    }
    int edad() {
        return m_edad;
    }
private:
    int m_edad = 10;
};


// variables viven en hip(o heep) o en el stack, tiempo de vida de las variables
int main() {
    Animal ani(1);
    cout << ani.edad() << endl;

    Animal* a2 = new Animal(); // con apuntadores la locacion de memoria es manual, tienes que destruirlo manualmente
    delete a2; // con destruct puedes eliminar de la memoria manualmente


    // es mejor dejar explicit el constructor
    /*
        con esto se puede
        a = 10;
        cout << a.edad():

        a=10 seria lo mimso a Animal(10); cout << a.edad();

        por lo que es mas sencilo y lo que busca el primer constrcutor que utiliza un valor numerico, en este caso Animal(int edad)
    */
    return 0;
}
