class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            res.push_back({});
            for(int j = 0; j < m; ++j) {
                res[i].push_back(matrix[j][i]);
            }
        }
        return res;
    }
};