#include <bits/stdc++.h>
#define opt_io cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;
/**
int mcd(int a, int b) {
    cout << "a= " << a << "  b= " << b << "    \n";
    if(b==0) {
        return a;
    }
    return mcd(b, a%b);
    //return (b, a%b)  PARA 133, 15 RETORNA 13
}*/

int mcd(int a, int b) {
    return ((!b)? a : mcd(b, a%b) );
}

// FUNCION DE ACKERMAN

int main() {
    opt_io
    int a, b;
    cin >> a >> b;
    cout << "\n" << "------------" << mcd(a, b) << "\n";
    cin.get();
    return 0;
}
