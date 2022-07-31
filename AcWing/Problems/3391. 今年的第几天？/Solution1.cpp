#include <bits/stdc++.h>
using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int y, m, d;
    while (cin >> y >> m >> d) {
        int res = 0;
        for (int i = 0; i < m; ++i)
            res += days[i];
        if (m > 2 && y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
            res += 1;
        }
        cout << res + d << endl;
    }
}
