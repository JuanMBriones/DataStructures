#include <bits/stdc++.h>
#define opt_io cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;
// Process returned -1073741571 (0xC00000FD)
int A(int m, int n) {
    cout << m << "~" << n << " ";
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
    int n, m;
    cin >> n >> m;
    cout << A(m, n) << endl;
    cin.get();
    return 0;
}
