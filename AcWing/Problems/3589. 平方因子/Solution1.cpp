#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    bool found;
    while (cin >> n) {
        found = false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % (i * i) == 0) {
                cout << "Yes" << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << "No" << endl;
    }
}
