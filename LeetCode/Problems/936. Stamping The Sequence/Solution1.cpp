// string match
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = stamp.size(), m = target.size();
        bool found = true, success, hasAlpha;
        int remain = m;
        vector<int> res; 
        while (found) {
            found = false;
            for (int i = 0; i <= m - n; ++i) {
                success = true;
                hasAlpha = false;
                for (int j = 0; j < n; ++j) {
                    if (target[i+j] != '?') {
                        hasAlpha = true;
                        if (target[i+j] != stamp[j]) {
                            success = false;
                            break;
                        }
                    }
                }
                if (success && hasAlpha) {
                    found = true;
                    res.push_back(i);
                    for (int j = 0; j < n; ++j) {
                        if (target[i+j] != '?') {
                            remain --;
                            target[i+j] = '?';
                        }
                    }
                }
            }
            // cout << target << " " <<  found << " " << success << " " << hasAlpha << endl;
            if (remain == 0) {
                if (res.size() > 10 * target.size()) return {};
                reverse(res.begin(), res.end());
                return res;
            }
        }
        return {};
    }
};
