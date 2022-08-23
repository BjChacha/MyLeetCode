// recursion
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1) return true;
        if (n <= 0 || n / 4 * 4 != n) return false;
        else return isPowerOfFour(n / 4);
    }
};
