// linear search
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        const int n = matrix.size();
        if (n == 0) return false;
        const int m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (matrix[i][j] < target) i++;
            else if (matrix[i][j] > target) j--;
            else return true;
        } 
        return false;
    }
};