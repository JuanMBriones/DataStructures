#include <bits/stdc++.h>
#define opt_io cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int A(m, n) {
    if(!m) {
        return n+1;
    }
    if(m>0 && !n) {
        return A(m-1, 1);
    }
    if(m>0 && n>0) {
        return A(m-1, A(m, n-1));
    }
}

int main() {
    opt_io

    cin.get();
    return 0;
}
