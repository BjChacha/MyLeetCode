// ?
class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for (char& d: n) res = max(d - '0', res);
        return res;
    }
};