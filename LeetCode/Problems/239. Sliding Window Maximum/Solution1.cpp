// priority queue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        int n = nums.size(), top;
        vector<int> res(n - k + 1);
        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                while (!q.empty() && q.top().second <= i-k) q.pop();
            }
            q.push({nums[i], i});
            if (i >= k - 1) res[i-k+1] = q.top().first;
        }
        return res;
    }
};
