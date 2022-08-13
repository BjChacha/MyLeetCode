// hash table
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> counter;
        int n = words.size();
        int k = words[0].length();

        if (s.length() < n * k) return {};

        for (const auto& w: words) counter[w] = counter.count(w) ? counter[w] + 1 : 1;

        for (int i = 0; i <= s.length() - n * k; ++i) {
            if (counter.count(s.substr(i, k))) {
                unordered_map<string, int> counterTemp = counter;
                bool success = true;
                for (int j = i; j < i + n * k; j += k) {
                    string ss = s.substr(j, k);
                    if (counterTemp.count(ss) == 0 || counterTemp[ss] == 0) {
                        success = false;
                        break;
                    }
                    counterTemp[ss] --;
                }

                if (success) res.push_back(i);
            }
        } 
        return res;
    }
};
