// min heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> counter;
        priority_queue<pair<int, int>, vector<pair<int, int>>,  less<pair<int, int>>> hq;
        
        for (const int& num: nums) counter[num] ++;
        
        for (const pair<int, int>& pair: counter) {
            hq.push({pair.second, pair.first});
            if (hq.size() > k) hq.pop();
        }
        
        while (!hq.empty()) {
            res.push_back(hq.top().second);
            hq.pop();
        }
        return res;
    }
};