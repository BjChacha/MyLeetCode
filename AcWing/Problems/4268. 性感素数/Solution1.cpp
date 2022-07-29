#include <bits/stdc++.h>
using namespace std;

bool judge(int x) {
    if (x <= 1) return false;
    for (int i = 2; i <= (int)sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    if (judge(n)) {
        if (judge(n - 6)) {
            cout << "Yes" << endl;
            cout << n - 6 << endl;
        } else if (judge(n + 6)) {
            cout << "Yes" << endl;
            cout << n + 6 << endl;
        } else {
            cout << "No" << endl;
            while (true) {
                n ++;
                if (judge(n) && (judge(n - 6) || judge(n + 6))) {
                    cout << n << endl; 
                    break;
                }
            }
        }
    } else {
        cout << "No" << endl;
        while (true) {
            n ++;
            if (judge(n) && (judge(n - 6) || judge(n + 6))) {
                cout << n << endl; 
                break;
            }
        }
    }
    return 0;
}