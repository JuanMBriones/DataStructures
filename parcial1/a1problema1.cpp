#include <bits/stdc++.h>
//#define io ios_base::sync_with_stdio(0);cin.tie(0);
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

/*
 Write a program that lets the user convert from Celsius to Farenheit.
Welcome!
1. Farenheit to Celsius
2. Celsius to Farenheit
Selection: 1
Ammount: -40
Result: -40 C
*/

double F2C(double farenheit) { // (5 °F − 32) × 5/9
    return (double)((farenheit-32.0)*(5.0/9.0));
}

double C2F(double celsius) {
    return (double)(celsius*(9.0/5.0))+32.0; // (0 °C × 9/5) + 32
}

int main() {
    //optimizar_io
    while(1) {
        int opt;
        double temp;
        cout << "Introduzca su opcion celsius-a-farenheit[1] o farenheit-a-celsius[2]: ";
        cin >> opt;
        cout << "Introduce la temperatura en " << ((opt==1)? "Celsius" : "Farenheit") << ": ";
        cin >> temp;
        cout << ((opt==1)? C2F(temp) : F2C(temp)) << endl;
        system("pause");
        system("cls");
    }
    cin.get();
    return 0;
}
