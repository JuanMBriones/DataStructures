#include <iostream>

using namespace std;

int main() {
    double n;
    double e = 0.0001;
    double squareRoot = 1.0;
    cin >> n;
    while(squareRoot*squareRoot < n) {
        squareRoot += e;
    }
    cout << squareRoot << endl;
    cin.get();
    return 0;
}
