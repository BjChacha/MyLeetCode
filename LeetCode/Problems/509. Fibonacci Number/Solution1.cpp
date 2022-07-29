//dp 
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int first = 0, second = 1, tmp;
        for (int i = 2; i <= n; ++i) {
            tmp = second;
            second += first;
            first = tmp;
        }
        return second;
    }
};