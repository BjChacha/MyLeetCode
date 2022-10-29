class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, unordered_map<string, int>> counter;
        counter["type"] = {};
        counter["color"] = {};
        counter["name"] = {};
        for (auto e: items) {
            counter["type"][e[0]] += 1;
            counter["color"][e[1]] += 1;
            counter["name"][e[2]] += 1;
        }
        return counter[ruleKey][ruleValue];
    }
};
