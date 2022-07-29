#include <bits/stdc++.h>
using namespace std;
int T, N, K;

int main() {
    cin >> T;
    for (int x = 1; x <= T; ++x) {
        cin >> N >> K;
        int arr[N];
        for (int i = 0; i < N; ++i) cin >> arr[i];
        int i = 0, res = 0; 
        while (i < N) {
            if (arr[i] == K) {
                while (i + 1 < N && arr[i+1] == arr[i] - 1) {
                    ++i;
                    if (arr[i] == 1) {
                        ++res; 
                        break;
                    }
                }
            }
            ++i;
        }
        printf("Case #%d: %d\n",x ,res);
    }
    return 0;
}