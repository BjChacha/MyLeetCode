// KMP
class Solution {
public:
    bool rotateString(string s, string goal) {
        const int n = s.size();
        
        vector<int> next(n, -1);
        int i = 0, j = -1;
        while (i < n - 1) {
            if (j == -1 || s[i] == s[j]) next[++i] = ++j;
            else j = next[j];
        }
        
        s += s;
        i = 0, j = 0;
        while (i < n * 2 && j < n) {
            if (j == -1 || s[i] == goal[j]) {
                ++i, ++j;
                if (j == n) return true;
            } else {
                j = next[j];
            }
        }
        return false;
    }
};