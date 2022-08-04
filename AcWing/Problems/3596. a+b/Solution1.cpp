#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    while (cin >> a >> b) {
        string res = "";
        int ia = a.length(), ib = b.length(), adv = 0, sm = 0;
        while (ia && ib) {
            sm = (a[--ia] - '0') + (b[--ib] - '0') + adv;
            adv = sm >= 10;
            res = to_string(sm % 10) + res;
        } 
        while (ia) {
            sm = (a[--ia] - '0') + adv;
            adv = sm >= 10;
            res = to_string(sm % 10) + res;
        }
        while (ib) {
            sm = (b[--ib] - '0') + adv;
            adv = sm >= 10;
            res = to_string(sm % 10) + res;
        }
        if (adv) res = "1" + res;
        cout << res << endl;
    }
    return 0;
}
