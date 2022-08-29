// set
class Solution {
private:
    string encode(string s) {
        int cnt[10]{0};
        for (const auto& c: s) cnt[c-'0'] ++;
        string r = "";
        for (int i = 0; i < 10; ++i) r += '0' + cnt[i];
        return r;
    }
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> possibles;
        int r = 1;
        while (1) {
            possibles.insert(encode(to_string(r)));
            if (r > 500000000) break;
            r *= 2;
        }
        return possibles.count(encode(to_string(n))) > 0;
    }
};
