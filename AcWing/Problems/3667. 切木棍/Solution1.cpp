#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    while (cin >> n) cout << (n % 2 == 0 ? ((n >> 1) - 1 >> 1) : 0) << endl; 
}
