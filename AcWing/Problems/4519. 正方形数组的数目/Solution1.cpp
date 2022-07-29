#include<bits/stdc++.h>
#define S 13
using namespace std;

int N, res = 0;
int nums[S];
bool vis[S];

bool judge(int x) {
    int i = (int)sqrt(x);
    return i * i == x;
}

void dfs(int last, int remain) {
    if (remain == 0) ++res;
    else {
        for (int i = 1; i <= N; ++i) {
            if (vis[i] || (!vis[i-1] && nums[i-1] == nums[i])) continue;
            if (last == -1 || judge(last + nums[i])) {
                vis[i] = true;
                dfs(nums[i], remain - 1);
                vis[i] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> nums[i];
    nums[0] = -1;
    sort(nums + 1, nums + N + 1);
    dfs(-1, N);
    cout << res;
    return 0;
}