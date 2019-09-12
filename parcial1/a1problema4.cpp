#include <bits/stdc++.h>

using namespace std;

int power(int a, int b) {
    if(b==1) {
        return a;
    }
    else {
        return power(a, b-1)*a;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << power(a, b) << endl;
    // si dejas power(int a, int b) sin nada dentro te arrojara 4354254 que es el limite de un int de 4 bits
    cin.get();
    return 0;
}
