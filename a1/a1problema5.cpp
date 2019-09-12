#include <bits/stdc++.h>

using namespace std;

/*
Current Value = 0
0) Exit
1) Add
2) Substract
3) Multiply
4)Divide
Select operation: 1
How much: 100

Current value = 100
0) Exit
*/

void operations(int operation, double value, double &number) {
    if(operation==1) {
        number += value;
    }
    else if(operation==2) {
        number -= value;
    }
    else if(operation==3) {
        number *= value;
    }
    else {
        number /= value;
    }
}

int main() {
    double currentValue = 0, tempNumber = 0;
    int operation;
    while(operation) {
        cout << "Current value = " << currentValue << endl;
        cout << "0) Exit\n1) Add\n2) Substract\n3) Multiply\n4)Divide" << endl;
        cout << "Select operation: ";
        cin >> operation;
        if(operation) {
            cout << "How much: ";
            cin >> tempNumber;
            operations(operation, tempNumber, currentValue);
            cout << endl;
        }
    }

    return 0;
}
