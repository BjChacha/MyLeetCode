// dp
#define MOD 1000000007
class Solution {
private:
    int dp[1000];
    
    long solver(vector<int>& arr, int i) {
        if (i == arr.size()) return 0;
        if (dp[i] == 0) {
            long res = 1, l, r;
            for (int j = i + 1, k; j < arr.size(); ++j) {
                if (arr[i] % arr[j] == 0) {
                    k = find(arr.begin() + j, arr.end(), arr[i] / arr[j]) - arr.begin();
                    if (k < arr.size()) {
                        l = solver(arr, j);
                        r = solver(arr, k);
                        res = j == k ? (res + l * r) % MOD : (res + 2 * l * r) % MOD;
                    };
                } 
            }
            dp[i] = res;
        }
        return dp[i];
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        memset(dp, 0, 1000 * sizeof(int));
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) res = (res + solver(arr, i)) % MOD;
        return res;
    }
};
