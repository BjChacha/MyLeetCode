// dp
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n < 3) return 1;
        int first = 0, second = 1, third = 1, tmp;
        for (int i = 3; i <= n; ++i) {
            tmp = third;
            third += first + second;
            first = second;
            second = tmp;
        }
        return third;
    }
};