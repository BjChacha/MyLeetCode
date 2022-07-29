// sliding window
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int n = s.length();
        if (n <= k) return false;
        
        int res = pow(2, k);
        vector<bool> existed(res, false);
        int cur = 0;
        int mask = (res >> 1) - 1;
        for (int i = 0; i < k; ++i) {
            cur <<= 1;
            if (s[i] == '1') cur += 1;
        }
        if (!existed[cur]) {
            --res;
            existed[cur] = true;
        }
        for (int i = k; i < n; ++i) {
            cur = (cur & mask) << 1;
            if (s[i] == '1') cur += 1;
            if (!existed[cur]) {
                --res;
                existed[cur] = true;
            }
            if (res <= 0) break;
        }
        return res == 0;
    }
};