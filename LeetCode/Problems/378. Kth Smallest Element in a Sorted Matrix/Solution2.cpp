// binary search 2
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n-1][n-1], mi, cnt, tmp;
        while (lo < hi) {
            mi = (lo + hi) >> 1;

            // count the elements that less or equal than mi
            cnt = 0, tmp = n - 1;
            for (int i = 0; i < n; ++i) {
                while (tmp >= 0 && matrix[i][tmp] > mi) --tmp;
                cnt += tmp + 1;
            }

            if (cnt >= k) hi = mi;
            else lo = mi + 1;
        }
        return lo; 
    }
};
