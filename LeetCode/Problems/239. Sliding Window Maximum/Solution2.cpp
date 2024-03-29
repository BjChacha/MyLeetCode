class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            while (q.size() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);
        for (int i = k; i < n; ++i) {
            while (q.size() && q.front() <= i - k) q.pop_front();
            while (q.size() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};
