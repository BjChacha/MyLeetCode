// accumulate
class NumMatrix {
private:
    int accu[202][202] = {0};
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                accu[i][j] = accu[i-1][j] + accu[i][j-1] - accu[i-1][j-1] + matrix[i-1][j-1];;
                
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return accu[row2+1][col2+1] - accu[row2+1][col1] - accu[row1][col2+1] + accu[row1][col1]; 
    }
};