class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < groupSizes.size(); ++i) {
            if (m.count(groupSizes[i]) == 0) m[groupSizes[i]] = {};
            m[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        vector<int> tmp;
        int i;
        for (const auto& p: m) {
            i = 0;
            while (i < p.second.size()) {
                tmp = {};
                for (int j = 0; j < p.first; ++j, ++i) {
                    tmp.push_back(p.second[i]);
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};
