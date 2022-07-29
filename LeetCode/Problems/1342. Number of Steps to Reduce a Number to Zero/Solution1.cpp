// bit operation
class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        while (num) {
            if (num > 1 && num & 1) ++res;
            ++res;
            num >>= 1;
        }
        return res;
    }
};