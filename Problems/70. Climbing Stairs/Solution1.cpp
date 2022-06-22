// dp
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int first = 1, second = 2, tmp;
        for (int i = 2; i < n; ++i) {
            tmp = second;
            second += first;
            first = tmp;
        }
        return second;
    }
};