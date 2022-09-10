// memo dfs
class Solution {
private:
    int dfs(vector<int>& arr, vector<vector<int>>& memo, int l, int r) {
        if (memo[l][r] < 0) {
            int ls, rs, ms = 0;
            for (int i = l + 1; i < r; ++i) {
                ls = dfs(arr, memo, l, i);
                rs = dfs(arr, memo, i, r);
                ms = max(ms, arr[i] * arr[l] * arr[r] + ls + rs);
            }
            memo[l][r] = ms;
        }
        return memo[l][r];
    }
public:
    int maxCoins(vector<int>& nums) {
        const int n = nums.size() + 2;
        vector<int> arr(n, 1);
        for (int i = 1; i < n - 1; ++i) 
            arr[i] = nums[i-1];
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(arr, memo, 0, n - 1);
    }
};
