// dfs
class Solution {
private:
    void dfs(vector<int>& res, int cur, int remain, int& k) {
        if (remain == 0) {
            res.push_back(cur);
        } else {
            int last = cur % 10;
            if (last - k >= 0) dfs(res, cur * 10 + last - k, remain - 1, k);
            if (k != 0 && last + k < 10) dfs(res, cur * 10 + last + k, remain - 1, k);
        }
    } 
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for (int i = 1; i < 10; ++i) {
            dfs(res, i, n - 1, k);
        }
        return res;
    }
};
