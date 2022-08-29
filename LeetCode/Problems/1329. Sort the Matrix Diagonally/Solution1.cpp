// simulation
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        vector<int> tmp;
        int i = m - 1, j = 0, k;
        while (i >= 0 && j < n) {
            tmp = {};
            for (int x = i, y = j; x < m && y < n; ++x, ++y) tmp.push_back(mat[x][y]);
            sort(tmp.begin(), tmp.end());
            k = 0;
            for (int x = i, y = j; x < m && y < n; ++x, ++y) res[x][y] = tmp[k++];
            i > 0 ? --i : ++j;
        }
        return res;
    }
};
