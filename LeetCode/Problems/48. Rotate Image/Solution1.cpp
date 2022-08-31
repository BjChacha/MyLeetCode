// math
class Solution {
private:
    void swap(int& a, int& b) {
        int t = move(a);
        a = move(b);
        b = move(t);
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                swap(matrix[i][j], matrix[j][n-i-1]);
                swap(matrix[n-j-1][i], matrix[i][j]);
                swap(matrix[n-i-1][n-j-1], matrix[n-j-1][i]);
            }
        }
        return ;
    }
};
