// slide window
class Solution {
private:
    bool isEnough(unordered_map<char, int>& scnt, unordered_map<char, int>& tcnt) {
        for (const auto& item: tcnt) {
            if (scnt.count(item.first) == 0 || scnt[item.first] < item.second) 
                return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        const int n = s.size(); 
        unordered_map<char, int> tcnt, scnt;
        for (const auto& c: t) tcnt[c] += 1;
        int start = -1, len, l = 0, r = 0;
        while (r < n) {
            // 扩大窗口，只统计关键字符
            scnt[s[r++]] ++;
            // 窗口满足条件，触发切换窗口
            if (isEnough(scnt, tcnt)) {
                // 跳过可跳过字符，包括非关键字符和冗余字符
                while (l < r && (tcnt.count(s[l]) == 0 || scnt[s[l]] > tcnt[s[l]])) 
                    scnt[s[l++]] --;
                if (start == -1 || len > r - l) {
                    start = l;
                    len = r - l;
                }
                // 收缩窗口，左边界缩至不满足条件为止
                do {scnt[s[l++]] --;}
                while (isEnough(scnt, tcnt));
                // 跳过中间的非关键字符
                while (l < r && tcnt.count(s[l]) == 0) scnt[s[l++]] --;
            }
        }
        return start >= 0 ? s.substr(start, len) : "";
    }
};
