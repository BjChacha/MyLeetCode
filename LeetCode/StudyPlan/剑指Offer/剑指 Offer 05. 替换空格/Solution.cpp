// two-pointers, in-place
class Solution {
public:
    string replaceSpace(string s) {
        int spaceCnt = 0;
        int n = s.size();
        for (const auto& c: s) {
            if (c == ' ') ++spaceCnt;
        }
        s.resize(n + 2 * spaceCnt);
        int i = n - 1, j = s.size() - 1;
        while (i >= 0) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
                --i;
            } else {
                s[j--] = s[i--];
            }
        }
        return s;
    }
};