#include <bits/stdc++.h>
using namespace std;

int solver(int a, int b) {
    if (a == b) return a;
    else if (a > b) return solver(a / 2, b);
    else return solver(a, b / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x, y;
    cin >> x >> y;
    cout << solver(x, y) << endl;

    return 0;
}
