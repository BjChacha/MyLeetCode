#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios::sync_with_stdio(0);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        int a[N];
        for (int i = 0; i < N; i++) cin >> a[i];
        int res;
        if (N == 1) res = 1;
        else {
            int pre = -1, i = 0;
            res = 0;
            for (int i = 0; i < N; ++i) {
                if ((i == 0 && a[i] > a[i+1] || i == N - 1 && a[i] > a[i-1] || a[i] > a[i-1] && a[i] > a[i+1]) && a[i] > pre) {
                    res++;
                }
                pre = max(pre, a[i]);
            }
        }
        cout << "Case #" << t << ": " << res << endl;
    }
}
