#include <bits/stdc++.h>

using namespace std;

// 1 5 6

// 5 2 6 2   7 9 3 1        sea el ultimo
//  8 9 3  2  1 9 6         que sea lo ultimo la mitad 7/2 = 3 index

// 1 9 6 8

bool isPal(string s, int i) {
    if(i==(s.size()/2)) {
        return 1;
    }
    if(s[i]==s[s.size()-i-1]) { // impar
        return isPal(s, i+1);
    }
    else {
        return 0;
    }

}

int main() {
    string s;
    cin >> s;
    //bool b = isPal(s, 0);
    //cout << "--------------" << b << endl;
    cout << "It is" << ((!isPal(s, 0))? " not " : " ") << "a palindrome\n";
    cin.get();
    return 0;
}
