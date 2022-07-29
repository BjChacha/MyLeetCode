class Solution {
public:
    int reverse(int x) {
        int res = 0, tmp;
        while (x) {
            tmp = x % 10;
            if (x > 0 && res > (INT_MAX - tmp) / 10) return 0;
            if (x < 0 && res < (INT_MIN - tmp) / 10) return 0;
            res = res * 10 + tmp;
            x /= 10;
        }
        return res;
    }
};