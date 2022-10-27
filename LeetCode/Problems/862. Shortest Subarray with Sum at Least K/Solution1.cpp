// mono-deque
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<long> pS(n + 1, 0);
        for (int i = 0; i < n; ++i) pS[i+1] = pS[i] + nums[i];
        deque<int> q;
        int res = -1;
        for (int i = 0; i <= n; ++i) {
            // 1. 扫描队头，检查子数组和有效性
            while (!q.empty() && pS[i] - pS[q.front()] >= k) {
                if (res == -1 || i - q.front() < res) res = i - q.front();
                q.pop_front();
            }
            // 2. 检查队尾，维护队列有序性
            while (!q.empty() && pS[i] <= pS[q.back()]) q.pop_back();
            // 3. 新元素入队
            q.push_back(i);
        }
        return res;
    }
};
