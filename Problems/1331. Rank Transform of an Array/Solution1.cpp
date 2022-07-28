class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res(arr);
        unordered_map<int, int> rank;
        sort(arr.begin(), arr.end());
        for (auto& a: arr) 
            rank.emplace(a, rank.size() + 1);
        for (int i = 0; i < arr.size(); ++i) 
            res[i] = rank[res[i]];
        return res;
    }
};