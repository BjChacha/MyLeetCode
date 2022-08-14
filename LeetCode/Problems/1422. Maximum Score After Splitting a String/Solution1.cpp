class Solution {
public:
    int maxScore(string s) {
        int tmp = count(s.begin() + 1, s.end(), '1') + (s[0] == '0');
        int res = tmp;
        for (int i = 1; i < s.length() - 1; ++i) {
            if (s[i] == '0') tmp += 1;
            else tmp -= 1;
            res = max(res, tmp);
        }
        return res;
    }
};
