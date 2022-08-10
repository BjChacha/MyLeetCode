#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int res = 0;
    while (cin >> s) {
        res = 0 ;
        for (auto const c: s) res += c - '0';

        while (res > 9) {
            res = res % 10 + res / 10;
        }
        if (res == 0) continue;
        cout << res << endl;
    }
}
