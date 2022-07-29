// simulation
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        bool inversed = true;
        int m = mat.size(), n = mat[0].size(), x = 0, y = 0;
        while (x != m - 1 || y != n - 1) {
            res.push_back(mat[x][y]);
            if (inversed) {
                if (y + 1 == n) ++x, inversed = false;
                else if (x == 0) ++y, inversed = false;
                else --x, ++y;
            } else {
                if (x + 1 == m) ++y, inversed = true;
                else if (y == 0) ++x, inversed = true;
                else ++x, --y;
            }
        }
        res.push_back(mat[m-1][n-1]);
        return res;
    }
};