// binary search
class Solution {
private:
    int bisearchCol(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size() - 1, mi;
        while (lo <= hi) {
            mi = (lo + hi) >> 1;
            if (matrix[0][mi] <= target) lo = mi + 1;
            else hi = mi - 1;
        }
        return hi;
    }
    
    int bisearchRow(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size() - 1, mi;
        while (lo <= hi) {
            mi = (lo + hi) >> 1;
            if (matrix[mi][0] <= target) lo = mi + 1;
            else hi = mi - 1;
        }
        return hi;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n-1][n-1], mi;
        int col, row, cnt;
        while (lo <= hi) {
            mi = (lo + hi) >> 1;
            col = bisearchCol(matrix, mi);
            row = bisearchRow(matrix, mi);
            cnt = (col + 1) * (row + 1);
            for (int i = row; i >= 0 && matrix[i][n-1] >= mi; --i) {
                for (int j = col; j >= 0 && matrix[i][j] >= mi; --j) {
                    cnt --;
                }
            }
            if (cnt > k - 1) hi = mi - 1;
            else lo = mi + 1;
        }
        return hi;
    }
};
