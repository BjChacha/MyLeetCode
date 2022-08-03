class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string res = s;
            for (int i = 1; i < s.length(); ++i) {
                string ns = s.substr(i, s.length() - i) + s.substr(0, i);
                if (ns < res) res = ns;
            }
            return res;
        } else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};
