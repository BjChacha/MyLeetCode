#include<bits/stdc++.h>
using namespace std;

int t, n, g, p, c;

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) { 
        cin >> n;
        int cities[5002] {0};
        for (int j = 0; j < n; ++j) {
            int a, b;
            cin >> a >> b;
            cities[a] ++;
            cities[b+1] --;
        }
        for (int j = 1; j < 5002; ++j) {
            cities[j] += cities[j-1];
        }
        cin >> p;
        cout << "Case #" << i << ":";
        while (p--){
            cin >> c;
            cout << " " << cities[c];
        }
        cout << endl;
    }
    return 0;
}