#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "Print the multiplication table of a number up to 10:" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Input a number: ";
    cin >> n;
    for(int i=1; i<11; i++) {
        cout << n << " x " << i << " = " << n*i << endl;
    }
    cin.get();
    return 0;
}
