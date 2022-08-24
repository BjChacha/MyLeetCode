// mono stack
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        for (int i = 0; i < num.size(); ++i) {
            while (!stk.empty() && k && stk.top() > num[i]) {
                stk.pop();
                k--;
            }
            if (stk.empty() && num[i] == '0') continue;
            stk.push(num[i]);
        }
        while (k-- && !stk.empty()) stk.pop();
        if (stk.empty()) return "0";
        
        string res = "";
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
