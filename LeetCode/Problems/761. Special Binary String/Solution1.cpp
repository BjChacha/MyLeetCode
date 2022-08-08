// recursion
class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> list;
        int cnt = 0, pre = 0, i = 0, n = s.length();
        if (n == 0) return "";
        while (i < n) {
            if (s[i] == '1') cnt ++;
            else {
                cnt --;
                if (cnt == 0) {
                    // 如果只有一对有效括号，直接返回，避免无限递归
                    if (list.size() == 0 && i == n - 1) return "1" + makeLargestSpecial(s.substr(1, n - 2)) + "0";
                    string ss = makeLargestSpecial(s.substr(pre, i - pre + 1));
                    list.push_back(ss);
                    pre = i + 1;
                }
            }
            ++i;
        }
        sort(list.begin(), list.end(), greater<string>());
        string res = "";
        for (const auto& item: list) res += item;
        return res;
    }
};
