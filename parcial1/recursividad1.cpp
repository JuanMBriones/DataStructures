#include <bits/stdc++.h>
#define opt_io cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

// WORKING IN MEMORIZATION

int fi[50] = {0};

int f(int n) {
    cout << n << " ";
    if(n<2) {
        return 1;
    }
    else if(::fi[n]!=0) {
        return ::fi[n];
    }
    else {
        return f(n-1)+f(n-2);
    }
}///

/*
int f(int n) {
    if(n<2) {
        return 1;
    }
    else {
        return f(n-1)+f(n-2);
    }
}
*/

int main() {
    opt_io
    int a;
    cin >> a;
    cout << "\n" << "------------" << f(a) << "\n";
    cin.get();
    return 0;
}
