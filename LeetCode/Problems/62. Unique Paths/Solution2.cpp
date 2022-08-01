// math
class Solution {
public:
    int uniquePaths(int m, int n) {
        long res = 1;
        for (int i = 1; i <= m - 1; ++i) 
            res = res * (n + i - 1) / i;
        return res;
    }
};
