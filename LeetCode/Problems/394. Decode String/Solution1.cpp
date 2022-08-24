// simulation
class Solution {
public:
    string decodeString(string s) {
        const int n = s.size();
        stack<string> strStk;
        stack<int> numStk;
        strStk.push("");
        string cur = "", tmp;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '[') {
                numStk.push(cnt);
                strStk.push(cur);
                cur = "";
                cnt = 0;
            } else if (s[i] == ']') {
                cnt = numStk.top();
                numStk.pop();
                
                if (cur.size() == 0) {
                    cur = strStk.top();
                    strStk.pop();
                }
                tmp = strStk.top();
                strStk.pop();
                while (cnt--) tmp += cur;
                cur = tmp;
                
                cnt = 0;
            } else {
                if (s[i] >= '0' && s[i] <= '9') {
                    cnt = cnt * 10 + (s[i] - '0');
                } else {
                    cur += s[i];
                }
            }
        }
        return cur;
    }
};
