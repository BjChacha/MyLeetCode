// memo + recursion
#define MOD 1000000007

class Solution {
private:
    unordered_map<int, long> memo;
public:
    long findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n) return 1;
        else if (maxMove == 0) return 0;
        else {
            int key = (maxMove << 12) + (startRow << 6) + startColumn;
            if (memo.count(key) == 0) {
                memo[key] = (findPaths(m, n, maxMove - 1, startRow - 1, startColumn) + \
                            findPaths(m, n, maxMove - 1, startRow + 1, startColumn) + \
                            findPaths(m, n, maxMove - 1, startRow, startColumn - 1) + \
                            findPaths(m, n, maxMove - 1, startRow, startColumn + 1)) % MOD;
            }
            return memo[key];
        }
    }
};