// optimized slide windows
class Solution {
public:
    string minWindow(string s, string t) {
        const int n = s.size(); 
        unordered_map<char, int> tcnt, scnt;
        for (const auto& c: t) tcnt[c] += 1;
        int start = -1, len, l = 0, r = 0, need = tcnt.size(), fill = 0;
        while (r < n) {
            // 扩大窗口，只统计关键字符
            scnt[s[r]] ++;
            // 若关键字符数量刚好满足，则满足条件数量加一
            if (tcnt.count(s[r]) && scnt[s[r]] == tcnt[s[r]]) fill ++;
            ++r;
            // 窗口满足条件，触发切换窗口
            if (fill == need) {
                // 跳过可跳过字符，包括非关键字符和冗余字符
                while (l < r && (tcnt.count(s[l]) == 0 || scnt[s[l]] > tcnt[s[l]])) 
                    scnt[s[l++]] --;
                if (start == -1 || len > r - l) {
                    start = l;
                    len = r - l;
                }
                // 收缩窗口，左边界缩至不满足条件为止
                do {
                    scnt[s[l]] --;
                    // 若关键字符数量刚好不满足，则满足条件数量减一
                    if (tcnt.count(s[l]) && scnt[s[l]] < tcnt[s[l]]) fill --;
                    ++l;
                } while (fill == need);
                // 跳过中间的非关键字符
                while (l < r && tcnt.count(s[l]) == 0) 
                    scnt[s[l++]] --;
            }
        }
        return start >= 0 ? s.substr(start, len) : "";
    }
};
