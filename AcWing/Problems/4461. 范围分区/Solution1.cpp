#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, N, X, Y;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> X >> Y;
        int sum = (1 + N) * N / 2;
        if (sum % (X + Y) != 0) cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        else {
            cout << "Case #" << t << ": POSSIBLE" << endl;
            vector<int> chosen;
            int target = sum / (X + Y) * X;
            for (int i = N; i > 0 && target; --i) {
                if (i <= target) {
                    chosen.insert(chosen.begin(), i);
                    target -= i;
                }
            }
            cout << chosen.size() << endl;
            for (auto num: chosen) cout << num << " ";
            cout << endl;
        }
    }
}